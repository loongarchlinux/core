/* vi: set sw=4 ts=4 sts=4 expandtab wrap ai: */
/*
 * kver.c: This file is part of ____
 *
 * Copyright (C) 2021 yetist <yetist@archlinux>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 * */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

static char version[28] = "Linux version ";

#define MZ_MAGIC	0x5a4d	/* "MZ" */
#define ZIMG_TYPE       0x676d697a /* "zimg" */
#define MAX_LENGTH	14

struct zboot_header
{
  uint16_t magic; 	/* MZ magic code */
  uint32_t type;  	/* zstd image code */
};

int check_zimage_kernel (char *filename)
{
    FILE *fd;
    int ok = 0;

    if ((fd = fopen (filename, "rb")) == NULL) {
        perror ("open failed!");
        exit (1);
    }

    struct zboot_header header;

    fread (&header, sizeof(struct zboot_header), 1, fd);

    if (header.magic == MZ_MAGIC && header.type == ZIMG_TYPE) {
	    ok = 1;
    }
    fclose (fd);

    return ok;
}

void write_file(char *filename, const char* kver)
{
	FILE *fd;

	if ((fd = fopen (filename, "rb+")) == NULL) {
		perror ("open failed!");
		exit (1);
	}

	(void) fseek (fd, 0x1f, SEEK_SET);
	strncat (version, kver, MAX_LENGTH);
	fwrite (version, sizeof (version), 1, fd);

	fclose (fd);
}

int main(int argc, char** argv)
{
	if (argc != 3) {
		exit (1);
	}

	if (! check_zimage_kernel (argv[1])) {
		printf ("Error: \"%s\" is not a compressed efi stub kernel file.\n", argv[1]);
		exit (1);
	}

	if (strlen (argv[2]) > MAX_LENGTH) {
		printf ("kernel version is too long, max length is 14.\n");
		exit (1);
	}
	write_file (argv[1], argv[2]);
	return 0;
}
