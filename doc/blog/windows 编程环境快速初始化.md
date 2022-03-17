# windows下使用包管理器快速初始化编程环境

> 支持 `win7` 及以上的 `windows` 系统,
> 将会用到开源第三方包管理器 *[`scoop`](https://scoop.sh/)*,
> 需要`PowerShell 5.x`以上以及`.Net Framework 4.5`及以上,
> 所有的文件都将安装到 `C:\Users\Username\scoop\apps`目录下

## 安装 *[`scoop`](https://scoop.sh/)*

打开 `PowerShell`

运行以下命令:

``` ps1
Set-ExecutionPolicy RemoteSigned -scope CurrentUser
iwr -useb get.scoop.sh | iex
```

输出以下内容

``` ps1
PS C:\Users\WDAGUtilityAccount> Set-ExecutionPolicy RemoteSigned -scope CurrentUser
Execution Policy Change
The execution policy helps protect you from scripts that you do not trust.
Changing the execution policy might expose   you to the security risks described in the about_Execution_Policies help topic at
https:/go.microsoft.com/fwlink/?LinkID=135170.
Do you want to change the execution policy?
[Y] Yes  [A] Yes to All  [N] No  [L] No to All  [S] Suspend  [?] Help (default is "N"): 
```

输入 `A` 后回车, 等待安装完成

运行:

``` ps1
scoop help
```

如果输入以下内容则安装成功:

``` ps1
PS C:\User\WDAGUtilityAccount scoop help
Usage: scoop <command> [<args>]

Some useful commands are:

alias       Manage scoop aliases
bucket      Manage Scoop buckets
cache       Show or clear the download cache
cat         Show content of specified manifest. If available, `bat` will be used to pretty-print the JSON.
checkup     Check for potential problems
cleanup     Cleanup apps by removing old versions
config      Get or set configuration values
create      Create a custom app manifest
depends     List dependencies for an app
download    Download apps in the cache folder and verify hashes
export      Exports (an importable) list of installed apps
help        Show help for a command
hold        Hold an app to disable updates
home        Opens the app homepage
info        Display information about an app
install     Install apps
list        List installed apps
prefix      Returns the path to the specified app
reset       Reset an app to resolve conflicts
search      Search available apps
shim        Manipulate Scoop shims
status      Show status and check for new app versions
unhold      Unhold an app to enable updates
uninstall   Uninstall an app
update      Update apps, or Scoop itself
virustotal  Look for app's hash on virustotal.com
which       Locate a shim/executable (similar to 'which' on Linux)


Type 'scoop help <command>' to get help for a specific command.
```

安装依赖 `git` `7-zip` 版本控制器和解压工具

``` ps1
scoop install git 7-zip
```

## 安装编程所需的环境

### 安装 `C++` 环境

``` ps1
scoop install mingw-winlibs
```

### 检查`gcc`版本

``` ps1
gcc -v
```

### 安装 `Python` 环境

``` ps1
scoop install python
```

### 检查`Python`版本

``` ps1
python -V
```

### 安装 `Java17` 环境

``` ps1
scoop bucket add java # 添加java的bucket
scoop install java/openjdk17
```

### 检查`Java`版本

``` ps1
java --version
```

java仍需自己手动配置`JAVA_HOME`

> 如果有其它`Java`版本需求可以在添加`bucket`之后
> 使用 `scoop search openjdk` 检索自己需要的版本之后安装

## 错误解决

### 无法以`administrator`运行

``` ps1
PS C:\Users\WDAGUtilityAccount> iwr -useb get.scoop.sh | iex                                                           
Initializing..                                                             
Running the installer as administrator is disabled by default, see https://github.com/ScoopInstaller/Install#for-admin for details.                                                    
Abort. 
```

更换安装命令:

``` ps1
iwr -useb get.scoop.sh -outfile 'install.ps1'
.\install.ps1 -RunAsAdmin
```
