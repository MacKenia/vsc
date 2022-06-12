import random
import time
import requests
import os

def identify():
    ident = input("输入动态验证码: ")

    passwd = str("{:0>2d}".format(time.localtime().tm_mday)) + str("{:0>2d}".format(time.localtime().tm_hour)) + str("{:0>2d}".format(time.localtime().tm_min))
    passwd = list(passwd)
    # print(passwd)
    passwd[0], passwd[1], passwd[2], passwd[3], passwd[4], passwd[5] = passwd[1], passwd[2], passwd[0], passwd[3], passwd[5], passwd[4]
    passwd = ''.join(passwd)
    # print(passwd)

    if ident != passwd:
        exit()

user = [["20130942","20200045","20130889","20148407","20131050"],["2020051615308","2021051615296","2021051614025","201951603006","2020051615203","2019051604047","2019051611032"]]
passwd = [["031960","013145","050044","ddm2018","20131050"],["11243913","727503","030804","fzl20001106","xzqxzq520","2308811656","1947371704"]]


url_old_raw = "http://10.0.251.18:801/eportal/?c=ACSetting&a=Login&wlanacip=&lanacname=&redirect=&session=&vlanid=0&ssid=&port=&iTermType=1&protocol=http:&queryACIP=0"

url_new_login_raw = "http://10.0.254.125:801/eportal/portal/login?callback=dr1011&login_method=1&user_account=,1,2020051615308@telecom&user_password=11243913&wlan_user_ip=10.252.33.117&wlan_user_ipv6=&wlan_user_mac=000000000000&wlan_ac_ip=&wlan_ac_name=&jsVersion=4.1.3&terminal_type=2&lang=zh-cn&v=5185&lang=zh"

url_new_logout_raw = "http://10.0.254.125:801/eportal/portal/mac/unbind?callback=dr1003&user_account=&wlan_user_mac=000000000000&wlan_user_ip=184295797&jsVersion=4.1.3&v=5389&lang=zh"

url_old = "http://10.0.251.18:801/eportal/"

url_new_login = "http://10.0.254.125:801/eportal/portal/login"

url_new_logout = "http://10.0.254.125:801/eportal/portal/mac/unbind"

choice = [0, 0, 0]

choice[0] = int(input("1. 新网络(CQNU-NEW)\n2. 旧网络(CQNU)\n> "))
choice[1] = int(input("1. 教师\n2. 学生\n> "))

rand = random.randint(0, len(user[choice[1]-1])-1)

user = user[choice[1]-1][rand]
passwd = passwd[choice[1]-1][rand]

print(user)
print(passwd)

choice[2] = int(input("1. PC端\n2. 移动端\n> "))

if os.getcwd().lower().count("mackenia") != 1:
    identify()

data_old = {
    "DDDDD":",0,"+user+"@telecom",
    "upass": passwd,
    "R1":"0",
    "R2": "",
    "R6": "0",
    "para": "00",
    "0MKKey": "123456"
}

data_new_stu_login = {
    "callback": "dr1011",
    "login_method": "1",
    "user_account": ",1,"+user+"@telecom",
    "user_password": passwd,
    "wlan_user_mac": "000000000000"
}

data_new_tea_login = {
    "callback": "dr1011",
    "login_method": "1",
    "user_account": ","+str(choice[2]-1)+","+user+"@xyw",
    "user_password": passwd,
    "wlan_user_mac": "000000000000",
    "jsVersion": "4.1.3",
    "terminal_type": "1",
    "lang": "zh-cn",
    "lang": "zh"
}

data_new_logout = {
    "callback": "dr1003",
    "user_account": "",
    "wlan_user_mac": "000000000000",
    "wlan_user_ip": "",
    "jsVersion": "4.1.3",
    "lang": "zh"
}

header_desktop = {
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/avif,image/webp,image/apng,*/*;q=0.8,application/signed-exchange;v=b3;q=0.9",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9",
    "Cache-Control": "max-age=0",
    "Connection": "keep-alive",
    "Content-Length": "87",
    "Content-Type": "application/x-www-form-urlencoded",
    "Host": "10.0.251.18:801",
    "Origin": "http://10.0.251.18",
    "Referer": "http://10.0.251.18/",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.61 Safari/537.36 Edg/94.0.992.31"
}

header_desktop_new = {
    "Accept": "*/*",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
    "Connection": "keep-alive",
    "DNT": "1",
    "Host": "10.0.254.125:801",
    "Referer": "http://10.0.254.125",
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/94.0.4606.61 Safari/537.36 Edg/94.0.992.31"
}

header_phone = {
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9",
    "Cache-Control": "max-age=0",
    "Connection": "keep-alive",
    "Content-Type": "application/x-www-form-urlencoded",
    "Host": "10.0.251.18:801",
    "Origin": "http://10.0.251.18",
    "Referer": "http://10.0.251.18/",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (Linux; Android 10; HuaWei Mate Pro) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Mobile Safari/537.36 EdgA/98.0.1108.62"
}

header_phone_new = {
    "Accept": "*/*",
    "Accept-Encoding": "gzip, deflate",
    "Accept-Language": "zh-CN,zh;q=0.9",
    "Cache-Control": "max-age=0",
    "Connection": "keep-alive",
    "Content-Type": "application/x-www-form-urlencoded",
    "Host": "10.0.254.125:801",
    "Origin": "http://10.0.254.125",
    "Referer": "http://10.0.254.125/",
    "Upgrade-Insecure-Requests": "1",
    "User-Agent": "Mozilla/5.0 (Linux; Android 10; HuaWer Mate Pro) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Mobile Safari/537.36 EdgA/98.0.1108.62"
}

r = ""

if choice[0] == 2:
    if choice[2] == 1:
        r = requests.post(url_old, data=data_old, headers=header_desktop)
    else:
        r = requests.post(url_old, data=data_old, headers=header_phone)
else:
    if choice[1] == 1:
        if choice[2] == 1:
            r = requests.get(url_new_login, params=data_new_tea_login, headers=header_desktop_new)
        else:
            r = requests.get(url_new_login, params=data_new_tea_login, headers=header_phone_new)
    else:
        if choice[2] == 1:
            r = requests.get(url_new_login, params=data_new_stu_login, headers=header_desktop_new)
        else:
            r = requests.get(url_new_login, params=data_new_stu_login, headers=header_phone_new)

# r = requests.get(url_new_login, params=data_new_tea_login, headers=header_desktop_new)
# r = requests.get(url_new_logout, params=data_new_logout, headers=header_phone_new)
print(r.status_code)
