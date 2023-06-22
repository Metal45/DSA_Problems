import pyautogui
import time
 
print("Ready to type")
time.sleep(5)
 
filePath= "C:/Users/METAL/New folder/DSA_Questions/pyhton/text.txt"

for line in open(filePath, "r"):
 
    pyautogui.typewrite(line)  
    pyautogui.press("enter")