import requests
for i in range(100):
    print(f"正在爬区第{i+1}张图片")
    with open(f"{i:0>2d}.jgp", "wb") as f:
        r = requests.get("https://imgapi.xl0408.top/index.php")
        f.write(r.content)
        f.close()