import requests, pandas, json

user = ""
passwd = ""

url_new_login = "http://10.0.254.125:801/eportal/portal/login"

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

data_new_stu_login = {
    "callback": "dr1011",
    "login_method": "1",
    "user_account": ",1,"+user+"@telecom",
    "user_password": passwd,
    "wlan_user_mac": "000000000000"
}

data_new_logout = {
    "callback": "dr1003",
    "user_account": "",
    "wlan_user_mac": "000000000000",
    "wlan_user_ip": "",
    "jsVersion": "4.1.3",
    "lang": "zh"
}