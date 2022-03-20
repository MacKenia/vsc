import requests

user = ["20130942","20200045","20130889","20148407","2020051615308","2021051615296"]
passwd = ["031960","013145","050044","ddm2018","11243913","727503"]

choice = 4
print(user[choice])
print(passwd[choice])

url_old = "http://10.0.251.18:801/eportal/?c=ACSetting&a=Login&wlanacip=&lanacname=&redirect=&session=&vlanid=0&ssid=&port=&iTermType=1&protocol=http:&queryACIP=0"

url_new_login_raw = "http://10.0.254.125:801/eportal/portal/login?callback=dr1011&login_method=1&user_account=,1,2020051615308@telecom&user_password=11243913&wlan_user_ip=10.252.33.117&wlan_user_ipv6=&wlan_user_mac=000000000000&wlan_ac_ip=&wlan_ac_name=&jsVersion=4.1.3&terminal_type=2&lang=zh-cn&v=5185&lang=zh"

url_new_login = "http://10.0.254.125:801/eportal/portal/login"

url_new_logout_raw = "http://10.0.254.125:801/eportal/portal/mac/unbind?callback=dr1003&user_account=&wlan_user_mac=000000000000&wlan_user_ip=184295797&jsVersion=4.1.3&v=5389&lang=zh"

url_new_logout = "http://10.0.254.125:801/eportal/portal/mac/unbind"

datas_old = {
    "DDDDD":",0,"+user[choice]+"@telecom",
    "upass": passwd[choice],
    "R1":"0",
    "R2": "",
    "R6": "0",
    "para": "00",
    "0MKKey": "123456"
}

data_new_stu_login = {
    "callback": "dr1011",
    "login_method": "1",
    "user_account": ",1,"+user[choice]+"@telecom",
    "user_password": passwd[choice],
    "wlan_user_mac": "000000000000"
}

data_new_tea_login = {
    "callback": "dr1011",
    "login_method": "1",
    "user_account": ",0,"+user[choice]+"@xyw",
    "user_password": passwd[choice],
    "wlan_user_mac": "000000000000"
}

data_new_logout = {
    "callback": "dr1003",
    "user_account": "",
    "wlan_user_mac": "000000000000",
    "wlan_user_ip": "",
    "jsVersion": "4.1.3",
    "v": "5389",
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
    "Accept-Language": "zh-CN,zh;q=0.9,en;q=0.8,en-GB;q=0.7,en-US;q=0.6",
    "Connection": "keep-alive",
    "DNT": "1",
    "Host": "10.0.254.125:801",
    "Referer": "http://10.0.254.125",
    "User-Agent": "Mozilla/5.0 (Linux; Android 11; HuaWei) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/98.0.4758.102 Mobile Safari/537.36 EdgA/98.0.1108.62"
}

r = requests.get(url_new_login, params=data_new_stu_login, headers=header_phone_new)
print(r.status_code)
