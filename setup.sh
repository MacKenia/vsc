#bash

ls -s /usr/share/zoneinfo/Asia/Shanghai > /etc/localtime
hwclock --systohc
echo "en_US.UTF-8 UTF-8" > /etc/local.gen
echo "zh_CN.UTF-8 UTF-8" > /etc/local.gen
local-gen
echo "LANG=en_US.UTF-8" > /etc/local.conf
export LANG=en_US.UTF-8

echo "Mac-Arch" > /etc/hostname


pacman -S 
adduser -m -G wheel /bin/bash mackenia


bash -c "$(curl -Lv gitee.com/mo2/liunx/raw/2/2)"

