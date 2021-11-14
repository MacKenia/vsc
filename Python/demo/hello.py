import time
print("hello world!")
while True:
    date = time.localtime()
    print("[{}:{}:{}]".format(date[3], date[4], date[5]))
    time.sleep(1)
