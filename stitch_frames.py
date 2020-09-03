import os
import cv2
images_path = "/Users/rishipandey125/Desktop/RayTracedContent/"

directory = os.fsencode(images_path)
height = 0 width = 0
for file in os.listdir(directory):
    filename = os.fsdecode(file)
    if filename.endswith(".ppm"):
        img = cv2.imread(images_path+filename)
        height, width, layers = img.shape;
        break

video = cv2.VideoWriter(images_path+"video.avi", 0, 1, (width,height))

for file in os.listdir(directory):
     filename = os.fsdecode(file)
     if filename.endswith(".ppm"):
         img = cv2.imread(images_path+filename)
         video.write(img)
         os.remove(images_path+filename)

print("Video Stitching Complete")
