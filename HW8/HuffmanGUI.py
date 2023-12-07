from tkinter import *
from tkinter import filedialog
import os
import subprocess

root = Tk() # create a Tk object

def openFile():
    global filename
    filepath = filedialog.askopenfile(title="Select the file", filetypes=(("text files", "*.txt"), ("all files", "*.*")))
    filename = os.path.basename(filepath.name)
    file = open(filepath.name,'r')
    print(file.read())
    file.close()
    
    label = Label(root, text="Selected file=" + filename, font=("Arial", 16))
    label.place(x = 100, y = 5)

def inputOutputName():
    global outputFileName
    outputFileName = e.get()
    print("output file name" + outputFileName)
    outputLabel = Label(root, text="Output as =" + outputFileName, font=("Arial", 16))
    outputLabel.pack()

def encode():
    global outputFileName
    subprocess.call(['./copilot', '-c', '-i', filename, '-o', outputFileName]) #call the c++ 

button = Button(text="Select input file", command=openFile)
button.place(x = 5, y = 5)

def wrap_encode():
    inputOutputName()
    encode()

button_Encode = Button(text="Encode", command=wrap_encode)
button_Encode.pack()

description = Label(text="Write the output file name plus file extension")
description.pack()
e = Entry(root, width=50)
e.pack()


root.geometry("800x600")
root.title("Huffman Algorithm")






root.mainloop()