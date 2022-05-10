# pip install requests beautifulsoup4 pyDes
import requests as rts
import base64 as bs
import time
from pyDes import des, ECB, PAD_PKCS5
import bs4 as Bss
import json

class BookYourDream:
    def __init__(self):
        self.D_ONE = 141 # 梦一厅
        self.D_TWO = 142 # 梦二厅
        self.D_THREE = 261 # 梦三厅

        self.main_se = rts.session()

        self.index_url = "http://202.202.209.15:8081/index.html"

        self.ver_image = "https://csxrz.cqnu.edu.cn:443/cas/verCode?random=="

        self.login_url = "https://csxrz.cqnu.edu.cn/cas/login?service=https://csxmh.cqnu.edu.cn/PersonalApplications/viewPage?active_nav_num=1"
        self.login_url = "https://csxrz.cqnu.edu.cn/cas/login?service=http%3A%2F%2F202.202.209.15%3A8081%2Findex.html"

        self.inquire_url = "http://202.202.209.15:8081/product/findtime.html"

        self.double_url = "http://202.202.209.15:8081/product/doublingTimeVer.html?stockid="

        self.book_url = "http://202.202.209.15:8081/order/tobook.html"

        self.normal_headers = {
            "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/83.0.4103.116 Safari/537.36"
        }


    def deVer(self, ver):
        """
        验证码解析接口
        https://market.aliyun.com/products/57124001/cmapi027426.html?spm=5176.2020520132.101.1.45ab72185BHAcX#sku=yuncode2142600000
        注册成功后 复制APPCODE
        粘贴到headers 中
        示例：注意空格
        "Authorization":"APPCODE 你的APPCODE" 
        """
        ascii_ver = bs.b64encode(ver).decode('ascii')
        headers = {
            "image":ascii_ver,
            "type":"1001",
            "Authorization":"APPCODE cad56c434d124a17a7d990ae746ffa07"
        }
        url = "https://302307.market.alicloudapi.com/ocr/captcha"
        res = rts.post(url, headers=headers)
        if res and res.json()["code"] == 0:
            return res.json()["data"]["captcha"]
        else:
            return False


    def encrypt_des(self, data, key):
        k = des(key, ECB, key, pad=None, padmode=PAD_PKCS5)
        en = k.encrypt(data.encode('utf-8'), padmode=PAD_PKCS5)
        return str(bs.b64encode(en), 'utf-8')
        

    def login(self, user, passwd):
        ping = self.main_se.get(self.index_url, headers=self.normal_headers)

        pings = Bss.BeautifulSoup(ping.text, "html.parser")

        # print(type(pings))

        ping_inputs = pings.find_all("input")

        ver_img = self.main_se.get(self.ver_image + str(int(time.time()*100)), headers=self.normal_headers)

        ver_code = self.deVer(ver_img.content)
        
        # ver_code = False

        if not ver_code:
            with open("验证码.jpg", "wb") as f:
                f.write(ver_img.content)
            ver_code = input("验证码解析失败\n请手动输入:")
        print(ver_code)
            

        key = ping_inputs[4].get("value")[:8]
        execution = ping_inputs[5].get("value")

        password = self.encrypt_des(passwd, key)

        data = {
            "username":user,
            "password":password,
            "authCode":ver_code,
            "lt": ping_inputs[4].get("value"),
            "execution":execution,
            "_eventId":"submit",
            "isQrSubmit":"false",
            "isMobileLogin":"false",
            "qrValue":""
        }

        login_res = self.main_se.post(self.login_url, data=data, headers=self.normal_headers)
        # print(login_res.text)
        if login_res.content.decode('utf-8').find("梦厅") != login_res.content.decode("utf-8").find("场地"):
            print("登录成功")
            return True
        else:
            print("登录失败")
            return False

    def inquire(self, room, date, allday=False):
        params = {
            "type":"day",
            "s_dates":date,
            "serviceid":room
        }
        r = self.main_se.get(self.inquire_url, params=params)
        print(r.json()["object"])

        reserve = {}

        for i in r.json()["object"]:
            if not allday:
                print(f"{i['TIME_NO']}\n剩余数量 {i['SURPLUS']}")
                c = input("是否预定?(y/n)").strip()
            if allday or c == "y" or c == "Y" or c == "":
                reserve[str(i['ID'])] = "1"
        return reserve

    def book(self, table):
        data = {
            "param": json.dumps({
                "stock": table,
                "extend": {}
            }),
            "json": True
        }

        r = self.main_se.post(self.book_url, data=data)
        print(r.text)

    def main(self):
        room = [self.D_ONE, self.D_TWO, self.D_THREE]
        user = input("账号:")
        passwd = input("密码:")
        cRoom = int(input("1. 梦一厅\n2. 梦二厅\n3. 梦三厅\n场地:"))
        date = input("日期(yyyy-mm-dd):")
        if self.login(user, passwd):
            reserve = self.inquire(room[cRoom], date)
            if reserve:
                self.book(reserve)


if __name__ == "__main__":
    y = BookYourDream()
    y.login("2020051615308","")
    r = y.inquire(y.D_ONE, "2022-05-14", True)
    y.book(r)

    cy = BookYourDream()

    cy.login("201800605010","")
    r = cy.inquire(cy.D_ONE, "2022-05-15", True)
    cy.book(r)
    r = cy.inquire(cy.D_ONE, "2022-05-14", True)
    cy.book(r)
