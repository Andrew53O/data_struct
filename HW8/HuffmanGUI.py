from tkinter import *
from tkinter import filedialog
import os
import subprocess
from subprocess import Popen, PIPE, STDOUT

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
    outputLabel = Label(root, text="Output Save as =" + outputFileName, font=("Arial", 16))
    outputLabel.pack()

def clear_entry():
    e.delete(0, 'end')

def encode():
    global outputFileName
    print("filename->", filename)
    # need to run in the copilot folder
    subprocess.call(['./copilot', '-c', '-i', filename, '-o', outputFileName]) #call the c++ 


# def decode():
#     global outputFileName
#     print("outputfilename = ", outputFileName)
#     subprocess.call(['./copilot.exe', '-u', '-i', filename, '-o', outputFileName]) #call the c++ 
    

button = Button(text="Select input file", command=openFile)
button.place(x = 5, y = 5)

def wrap_encode():
    inputOutputName()
    encode()

# def wrap_decode():
#     inputOutputName()
#     decode()
    
button_Encode = Button(text="Encode", command=wrap_encode)
button_Encode.pack()

description = Label(text="Write the output file name plus file extension")
description.pack()

e = Entry(root, width=50)
e.pack()
button_clear= Button(root, text="Clear", command=clear_entry)
button_clear.pack()

# button_decode = Button(root, text="decode", command=wrap_decode)
# button_decode.pack()


root.geometry("800x600")
root.title("Huffman Algorithm")






root.mainloop()