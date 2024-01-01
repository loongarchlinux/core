# Maintainer: Giancarlo Razzolini <grazzolini@archlinux.org>
# Maintainer: Morten Linderud <foxboron@archlinux.org>
# Contributor: Dave Reisner <dreisner@archlinux.org>
# Contributor: Thomas Bächler <thomas@archlinux.org>

pkgname=mkinitcpio
pkgver=37.1
pkgrel=2
pkgdesc="Modular initramfs image creation utility"
arch=('any')
url='https://gitlab.archlinux.org/archlinux/mkinitcpio/mkinitcpio'
license=('GPL')
depends=('awk' 'mkinitcpio-busybox>=1.19.4-2' 'kmod' 'util-linux>=2.23' 'libarchive' 'coreutils'
         'bash' 'binutils' 'diffutils' 'findutils' 'grep' 'filesystem>=2011.10-1' 'zstd' 'systemd')
checkdepends=('bats' 'bats-assert' 'lzop')
optdepends=('gzip: Use gzip compression for the initramfs image'
            'xz: Use lzma or xz compression for the initramfs image'
            'bzip2: Use bzip2 compression for the initramfs image'
            'lzop: Use lzo compression for the initramfs image'
            'lz4: Use lz4 compression for the initramfs image'
            'mkinitcpio-nfs-utils: Support for root filesystem on NFS')
provides=('initramfs')
backup=('etc/mkinitcpio.conf')
source=("https://sources.archlinux.org/other/$pkgname/$pkgname-$pkgver.tar.gz"{,.sig}
        test-use-system-library-loading-mechanism.patch)
install=mkinitcpio.install
sha512sums=('68fd36eb95317977dfb389be8bd1f6f09d455ca81b55cde8f64245fc59ceee74afa64b55dbb7e8b2e28abe8274397dbba2f4b021499f9ad6d662175ced678585'
            'SKIP'
            'c9a0dc49e7a22808f0556c79da3320edb93377d775c91343b2a1380aebde4e255b5e675e53a00192c73e4ea9a98a91b05b56c9d56d9e7537847274710115a6ae')
b2sums=('0b43d0d035fdba6195ca0e8facd654cbcff9c99d34d14b1f493c86cbea335c8f363e6117df7f0307e55b3e684fe7977d89ac226b79ed612270791e084b46aa4f'
        'SKIP'
        '11b8297ce18d47a0029490b950180801e5762ad7b7e36383d2f954cbc7aee10d3b901dd2703fd07b23b38aa6b74577b7d88a1d9eb5ff5633a665610c6fbec51b')
validpgpkeys=('ECCAC84C1BA08A6CC8E63FBBF22FB1D78A77AEAB'    # Giancarlo Razzolini
              'C100346676634E80C940FB9E9C02FF419FECBE16')   # Morten Linderud

prepare() {
  cd "$pkgname-$pkgver"
  patch -Np1 < ../test-use-system-library-loading-mechanism.patch
}

check() {
  make -C "$pkgname-$pkgver" check
}

package() {
  make -C "$pkgname-$pkgver" DESTDIR="$pkgdir" install
}
