[toc]

# linux快速入门指南

## 对Linux简介

> Linux严格来说是单指操作**系统的内核**，因操作系统中包含了许多用户图形接口和其他实用工具。如今Linux常用来指基于Linux的**完整操作系统**，内核则改以Linux内核称之。


> 通常情况下，Linux被打包成供个人计算机和服务器使用的Linux发行版，一些流行的主流Linux发布版，包括Debian（及其派生版本Ubuntu、Linux Mint）、Fedora（及其相关版本Red Hat Enterprise Linux、CentOS）、Arch Linux（及相关版本Manjaro、Chakra）和openSUSE等。

## 各发行版系统展示

### Debian

> 好，包管理器为pkg

### Ubuntu

> 基于debain的发行版，算是很知名的的发行版了，包管理器为apt



### Deepin

> 深度系统，基于Ubuntu的国产Linux发行版，桌面风格更偏向Mac，包管理器为apt



### Fedora

> 基于Redhat，桌面使用的是gnome40，包管理器为dnf



### Arch Linux

> 超级轻的Linux发行版，滚动更新，安装麻烦，全命令行操作，包管理器为pacman



### openSUSE

> 俗称大蜥蜴，支持滚动更新，包管理器为zypper



# 尝试Linux的途径

目前有三种途径：`WSL` `虚拟机` `实体机` 

论方便性排序：`WSL` > `虚拟机` > `实体机`

论性能则恰恰相反：`实体机` > `虚拟机` > `WSL`

> 再慢也比我写代码快

我个人推荐 `WSL` 主要是方便，无论是安装还是卸载

## WSL(Windows Subsystem for Linux)

> 注意非Win10用户无法使用

1. 按在搜索中搜索功能
2. 找到 `适用于Windows的Linux子系统` 勾选上，并重启电脑
3. 打开微软商店,搜索 `Linux` ,目前提供 `Debian`、`Ubuntu`、`Kali`、`openSUSE` 等发行版，我以下载Ubuntu为例。
4. 打开下载好的Ubuntu，等待其初始化
5. 输入用户名和密码，注意在输密码是是不会有回显的，也就是不会显示任何字符。
6. 在控制台输入 `bash -c "$(curl -Lv gitee.com/mo2/linux/raw/2/2)"`
> 脚本由这位大佬提供L：[Moe](https://gitee.com/mo2)
7. 等待跑码，
8. 输入刚刚设置的密码，回车
9. 选择简体中文
10. 回车
11. 等待跑码
12. 选择 `*°▽°* Update:更新`，基础设置就完成了，之后便可退出，下次输入`tmoe`即可再次打开此界面
13. 安装开发环境，输入`sudo apt install default-jdk lsb-core -y`，便会自动安装Python、C/C++、JAVA8的开发环境
14. 终端环境搭建就完成了，可以使用Vscode来连接WSL进行程序的编写

## 虚拟机

## 实体机



