# Maintainer: Florian Pritz <bluewind@xinu.at>
# Contributor: Dan McGee <dan@archlinux.org>

pkgname=pacman-mirrorlist
pkgver=20240717
pkgrel=1
pkgdesc="Arch Linux mirror list for use by pacman"
arch=('any')
url="https://www.archlinux.org/mirrorlist/"
license=('GPL')
backup=(etc/pacman.d/mirrorlist)
source=(mirrorlist)
md5sums=('b275439b1695e2f7db9c251554d6cd0f')
sha256sums=('a62f64c8e6e87a55f939475a5d3fa3f73b78c15cf6e1e135c21c08eb3e5ba294')

# NOTE on building this package:
# * Run bash -c ". PKGBUILD; updatelist"
# * Update the checksums, update pkgver
# * Build the package

updatelist() {
  rm -f mirrorlist
  curl -o mirrorlist https://archlinux.org/mirrorlist/all/
}

package() {
  mkdir -p "$pkgdir/etc/pacman.d"
  install -m0644 "$srcdir/mirrorlist" "$pkgdir/etc/pacman.d/"
}
