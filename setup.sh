# /bin/bash
# my own archlinux setup bash
lsblk
echo -e "\033[31mPlease check your efi partion is mounted on /boot/efi(y/N):\033[0m"
read confirm

if [ $confirm ]
then
    case $confirm in
        y)
        ;;
        n) exit
        ;;
        N) exit
        ;;
        *) echo "Wrong input!"
            exit
        ;;
    esac
fi

if [ ! $1 ]
then
    echo "Please enter a username!(sh setup.sh [username])"
    exit
fi

pacman -Sy --needed --noconfirm neovim ranger zsh openssh

ln -sf /usr/share/zoneinfo/Asia/Shanghai /etc/localtime

timedatectl set-ntp true

hwclock --systohc

echo "en_US.UTF-8 UTF-8" >> /etc/locale.gen
echo "zh_CN.UTF-8 UTF-8" >> /etc/locale.gen

locale-gen

echo "LANG=en_US.UTF-8" > /etc/locale.conf

echo "$1" > /etc/hostname

echo "127.0.0.1        localhost" >> /etc/hosts
echo "::1               localhost" >> /etc/hosts
echo "127.0.1.1        $1" >> /etc/hosts

echo "Please enter passwd for root:\n"

passwd root

pacman -S --needed --noconfirm intel-ucode grub efibootmgr

grub-install --target=x86_64-efi --efi-directory=/boot/efi

sed -i 's/loglevel=3 quiet/loglevel=5 nowatchdog/g' /etc/default/grub
echo "GRUB_DISABLE_OS_PROBER=FALSE" >> /etc/default/grub

grub-mkconfig -o /boot/grub/grub.cfg

useradd -m -G wheel -s /bin/zsh $1

echo "Please enter passwd for $1\n"

passwd $1

systemctl enable dhcpcd

echo "%wheel ALL=(ALL:ALL) ALL\n\
Defaults rootpw" >> /etc/sudoers

pacman -S --needed --noconfirm ntfs-3g adobe-source-han-serif-cn-fonts wqy-zenhei noto-fonts-cjk noto-fonts-emoji noto-fonts-extra fcitx5-im fcitx5-chinese-addons

echo "GTK_IM_MODULE=fcitx\n\
QT_IM_MODULE=fcitx\n\
XMODIFIERS=@im=fcitx\n\
SDL_IM_MODULE=fcitx" >> /etc/environment

echo "[multilib]\n\
Include = /etc/pacman.d/mirrorlist\n\
[archlinuxcn]\n\
Server = https://mirrors.ustc.edu.cn/archlinuxcn/\$arch" >> /etc/pacman.conf

pacman -Sy --needed --noconfirm archlinuxcn-keyring
pacman -S --needed --noconfirm yay
yay -Sy --needed --noconfirm nerd-fonts-source-code-pro microsoft-edge-dev-bin

pacman -S --needed --noconfirm htop 

# bash -c "$(curl -Ssfv https://gitee.com/mo2/zsh/raw/master/zsh.sh)"
