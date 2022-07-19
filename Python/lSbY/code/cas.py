import tkinter as tk
from PIL import Image, ImageTk

# ...
def car(root):
    global canvas_avatar
    canvas_avatar = tk.Canvas(root, width=720, height=320) # root是整个窗口
    ele_avatar = canvas_avatar.create_image(0, 0, anchor='nw')
    pil_avatar = Image.open('C:\\Users\\MacKenia\\Pictures\\下载.png')
    canvas_avatar.img_avatar = ImageTk.PhotoImage(pil_avatar)
    canvas_avatar.itemconfig(ele_avatar, image=canvas_avatar.img_avatar)

    global icon101
    icon101 = canvas_avatar.create_text(193,129, text="🚌")

    global icon102
    icon102 = canvas_avatar.create_text(5,5,text="🚌")

    global icon103
    icon103 = canvas_avatar.create_text(5,5,text="🚌")

    canvas_avatar.pack()





    go101()
    go102()
    go103()

def go101():
    global x101
    x101 = 1
    global y101
    y101 = 1
    canvas_avatar.move(icon101, x101, y101)
    canvas_avatar.after(20,go101)

def go102():
    global x102
    x102 = 0
    global y102
    y102 = 1
    canvas_avatar.move(icon102, x102, y102)
    canvas_avatar.after(20,go102)

def go103():
    global x103
    x103 = 1
    global y103
    y103 = 0
    canvas_avatar.move(icon103, x103, y103)
    canvas_avatar.after(20,go103)

root = tk.Tk()
car(root)
root.mainloop()