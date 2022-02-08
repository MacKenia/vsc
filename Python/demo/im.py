import cv2
from PIL import Image
import numpy as np

class_names = []

# Load the class_names
with open('classes.txt', 'r') as f:
    for line in f.readlines():
        class_names.append(line.strip())

print(class_names)

# deep learning network
net = cv2.dnn.readNet("yolov4-tiny.weights", "yolov4-tiny.cfg")

model = cv2.dnn_DetectionModel(net)
model.setInputParams(size=(320, 320), scale=1/255.0)

cap = cv2.VideoCapture(0)
cap.set(cv2.CAP_PROP_XI_HEIGHT, 1280)
cap.set(cv2.CAP_PROP_XI_WIDTH, 720)
cap.set(cv2.CAP_PROP_EXPOSURE, -1.0)

while True:
    ret, frame = cap.read()
    frame = Image.fromarray(cv2.cvtColor(frame,cv2.COLOR_BGR2RGB))
    frame = frame.transpose(Image.FLIP_LEFT_RIGHT)
    frame = cv2.cvtColor(np.array(frame), cv2.COLOR_RGB2BGR)
    class_ids, scores, bboxes = model.detect(frame)
    for class_id, score, bbox in zip(class_ids, scores, bboxes):
        x, y, w, h = bbox
        cv2.putText(frame, class_names[class_id], (x,y-10), cv2.FONT_HERSHEY_COMPLEX,1, (0,0,255), 2)
        cv2.rectangle(frame, (x, y),(x+w, y+h), (0, 255, 0), 2)

    cv2.imshow('frame', frame)
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break