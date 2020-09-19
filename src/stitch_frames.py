import os
import cv2
images_path = "" #location of images
#Python Script for Stitching Rendered Frames into Video
directory = os.fsencode(images_path)
height = 0
width = 0
directory_list = os.listdir(directory)
n = len(directory_list)
sorted_file_list = [None] * n

for file in os.listdir(directory):
    filename = os.fsdecode(file)
    if filename.endswith(".ppm"):
        #set height and width for video
        img = cv2.imread(images_path+filename)
        if height == 0 and width == 0:
            height, width, layers = img.shape;
        #get which frame it is (frame_num -1 would be the index to place it at)
        frame_num = int(filename[:len(filename)-4])
        index = frame_num-1
        sorted_file_list[index] = filename

fourcc = cv2.VideoWriter_fourcc(*'MP4V')
video = cv2.VideoWriter(images_path+"video.mp4", fourcc, 24, (width,height))



for file in sorted_file_list:
    if file != None:
        filename = os.fsdecode(file)
    if filename.endswith(".ppm"):
        img = cv2.imread(images_path+filename)
        video.write(img)
        # os.remove(images_path+filename)

print("Video Stitching Complete")
