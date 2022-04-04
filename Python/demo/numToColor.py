import cv2 as cv
import numpy as np
import math as mt
import random

R = 2
G = 1
B = 0

def sZoom(num):
    return (mt.sqrt(num*100/255)*10)*255/100

def numToColor(num):
    num = int(num)
    r = g = b = 0
    r = 255 - num
    g = num
    b = num if num < 125 else 255 - num
    r = sZoom(r)
    g = sZoom(g)
    b = sZoom(b)
    # r += b/2
    # g += b/2
    return (r, g, b)

def lineToPic(depth_img ,img):
    for indexI, i in enumerate(img):
        for indexJ, j in enumerate(i):
            j[R], j[G], j[B] = numToColor(depth_img[indexI][indexJ])
    return img
            

img = np.ones((30,256,3), np.uint8)
raw = np.ones((30,256,1), np.uint8)

for i in range(len(raw)):
    for j in range(len(raw[i])):
        raw[i][j] = random.randint(0,256)

cv.imwrite("pic.png", lineToPic(raw, img))

exit()

print(len(raw))
print(len(raw[0]))

for i in img:
    for index, j in enumerate(i):
        j[R], j[G], j[B] = numToColor(index)

for indexi, i in enumerate(img):
    if indexi > 14:
        break
    for indexj, j in enumerate(i):
        j[R], j[G], j[B] = numToColor(raw[indexi][indexj])
        if indexj == 114:
            print(j[R], j[G], j[B], raw[indexi][indexj])
            # print(j[R], j[G], j[B])


print(img[3][255])
print(img[3][126])

cv.imwrite("img.png", img)
