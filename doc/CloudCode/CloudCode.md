[toc]

> 利用Github Desktop客户端将自己的代码托管到Gitee（码云）、Github或者GitLab，将代码储存到云端，不用再担心自己的代码放在U盘丢失和数据损坏的问题了，还可以更好的管理自己的代码



# Github Desktop

这是由GitHub开发，用于替代git的客户端，它可以替代git完成大部分工作，众所周知git是纯命令操作的代码管理系统，而GitHub Desktop就不一样了，它是不仅有GUI界面而且美观

Github Desktop:
[![github desktop](https://desktop.github.com/images/github-desktop-screenshot-windows.png)](https://desktop.github.com)

Git:
[![git](https://support.huaweicloud.com/qs-codehub/zh-cn_image_0242788747.png)](https://git-scm.com/downloads)



# 代码仓库 :package:

代码仓库即储存代码的地方，它类似于网盘，但是它更偏向储存代码，而不是各种媒体，对代码的管理，共享等都有特殊的优化。仓库会储存你每一次提交的代码，显示你与之前代码的区别等等。

目前较大的有[**Github**](https://github.com)和[**Gitee**](https://gitee.com)还有[**GitLab**](https://about.gitlab.com/)，你现在所在的就是Gitee(Github你可能打不开)，但我更推荐使用Github



# 创建属于自己的代码仓库:package:

## 注册仓库账号 :bust_in_silhouette:

### Github :telescope:

> 由于是国外的平台，如果你连接不上，属于正常现象，特别是移动的网络，可以更换联通或者电信网络后重试，即使这样我也推荐你使用Github

#### 打开 :link: [官网](https://github.com)

#### 点击 :link: [Sign up](https://github.com/signup?ref_cta=Sign+up)

#### 输入你的邮箱账号

> 最好不要用QQ邮箱

#### 输入密码

#### 验证邮箱（腾讯邮箱可能收不到邮件）

### Gitee

> 国内的平台，好处是稳定至少不会连不上，但我还是推荐使用Github。

#### 点击 :link: [Sign up](https://gitee.com/signup) 注册

### GitLab

> 国外的平台，访问速度据说还不错（大家可以自己尝试）

#### 点击 :link: [Sign up](https://gitlab.com/users/sign_in) 注册

### 创建一个仓库:package:

#### Github :telescope:

> 点击左上角的加号后点击**New repository** 

![github-crrepo](img/github-crrepo.png)



> 填写要创建的仓库的相关信息
>
> README.md 文件用于填写仓库相关内容，创建是会将描述框内的内容写入README.md 
>
> 开源协议选择GPL协议，一旦有人使用自己的代码，对方的程序代码也将无条件公开

![github-crepo](img/github-crepo.png)




> 创建完成后

![github-repo](img/github-repo.png)





#### Gitee

> 在右上角**创建仓库**

![gitee-crrepo](img/gitee-crrepo.png)



> 填写相关信息
>
> :white_check_mark: 初始化仓库
>
> :white_check_mark: Readme 文件
>
> :white_check_mark: 分支模型

![gitee-crepo](img/gitee-crepo.png)





### 下载 :link: [Github Desktop](https://desktop.github.com)



### 与代码仓库同步 :clock12:

#### Github :telescope:

> 打开 **Github Desktop** 点击 **Sign in to Github.com** 就会跳转到浏览器

![wellcome](img/wellcome.png)




> 点击打开，即可登陆成功

![github-login](img/github-login.png)




> 此处信息为git的配置信息，可以保持默认

![github-config](img/github-config.png)




> 进入主界面之后，选择之前创建的仓库
>
> 点击 **Clone** 将云端已经创建的仓库克隆到本地

![github-pull](img/github-spull.png)




> 打开本地仓库，在里面创建任意文件测试
>
> 默认仓库位置: 
>
> Windows:
>
> ​	C盘的Document目录下的Github文件夹下
>
> Mac:
>
> ​	Document目录下的Github文件夹下

![github-mkfile](img/github-mkfile.png)




> 此时 **Github Desktop** 检测到本地仓库变动的文件
>
> 填写必填的 **Summary** 
>
> 然后 **commit to master** 将更改合并到主分支

![github-commit](img/github-commit.png)




>点击 **Push origin** 将修改同步到云端，便完成了一次提交，你的代码也就托管到了云端 :cloud:

![github-push](img/github-push.png)




> 接下来只需要将你之前的代码全部搬到这个文件夹，再提交一次便可以将你的所有代码托管到云 :cloud:
>
> 你也可以设置 :link:  [.gitignore](https://github.com/github/gitignore) 来将不需要的文件排除

![github-check](img/github-check.png)






#### Gitee

> 复制仓库的 :link:

![gitee-link](img/gitee-link.png)






> 选择 **Skip this step ** 

![wellcome](img/wellcome.png)




> 在此处填写 Git 配置，填写与 Gitee 账户相关的内容，当然也可以随便填写，完成后点击 **Finsh**

![gitee-setconfig](/home/mackenia/Documents/vsc/doc/CloudCode/img/gitee-setconfig.png)




> 如果你在上一步填写了注册  **Gitee** 时使用的 **邮箱**
>
> 则需要到 **Gitee的个人设置** 中关闭下图中的选项

![gitee-error](img/gitee-error.png)






> 选择 **Clone a repository from the internet...** 

![gitee-pul](/home/mackenia/Documents/vsc/doc/CloudCode/img/gitee-pul.png)






> 选择 **URL** 填写之前复制的仓库链接，点击 **Clone** 将云端仓库克隆到本地

![gitee-pull](img/gitee-pull.png)






> 打开本地仓库，在里面创建任意文件测试
>
> 默认仓库位置: 
>
> Windows:
>
> ​	C盘的Document目录下的Github文件夹下
>
> Mac:
>
> ​	Document目录下的Github文件夹下 

![gitee-mkfile](img/gitee-mkfile.png)




> 此时 **Github Desktop** 检测到本地仓库变动的文件
>
> 填写必填的 **Summary** 
>
> 然后 **commit to master** 将更改合并到主分支

![gitee-commite](img/gitee-commite.png)




> 点击 **Push origin** 

![gitee-push](img/gitee-push.png)




> 此时填写你的 gitee 账户和密码，点击 **Save and retry** 

![gitee-login](img/gitee-login.png)


>便完成了提交，你的代码也就托管到了云端 :cloud: ，此后也不会要求输入密码



### 删除仓库 :

> 从入门到删除

> ❗❗❗ 仓库一旦删除将无法恢复，但是本地仓库不会受到影响

#### Github :telescope:

> 打开要删除的仓库的设置

![github-delete](img/github-delete.png)

![github-delet](img/github-delet.png)




> 向滚动到底部选择 **Delete this repository** 后面的 **Delete this repository** 

![github-del](img/github-del.png)


> 按照提示输入对应信息即可删除

![github-dele](img/github-dele.png)




![github-de](img/github-de.png)




#### Gitee

> 打开要删除的仓库的管理页面

![gitee-delete](img/gitee-delete.png)




> 在左边的仓库设置中找到 **删除仓库** ，按照提示删除即可

![gitee-delet](img/gitee-delet.png)


# 总结

本教程仅仅讲到了如何操作，具体后面的原理以及git的操作并未提及，你可以自己探索如何使用命令来提交代码，可以有助于你了解其中的原理。



