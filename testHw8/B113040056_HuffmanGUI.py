from tkinter import *
from tkinter import filedialog
import os
import subprocess
from subprocess import Popen, PIPE, STDOUT

# Set basic information
root = Tk() # create a Tk object
root.geometry("500x500")
root.title("Huffman Algorithm")

input_text = StringVar()
filename = None


def openFile():
    global filename
    filepath = filedialog.askopenfile(title="Select the file", filetypes=(("text files", "*.txt"), ("all files", "*.*")))
    filename = os.path.basename(filepath.name)
    file = open(filepath.name,'r')
    # print(file.read()) output the file data
    file.close()
     # Update the label's text
    file_label.config(text="Selected file=" + filename)
    
    enable_button() # to make it enable

def inputOutputName():
    global outputFileName
    global output_panel
    outputFileName = e.get()
    # print("output file name" + outputFileName)
    
    outputLabel = Label(root)
    outputLabel.config(text="Output Save as =" + outputFileName, font=("Ubuntu", 12))
    outputLabel.place(x = 5, y = 180)

def clear_entry():
    e.delete(0, 'end')

def openActualFile():
    os.startfile(outputFileName) # open the file 
    
# Function to update the output panel
def update_output_panel():
    # If the output panel is not empty, show the button
    if output_panel.get('1.0', 'end').strip():
        button_openActualFile.place(x = 5, y = 430)
    else:
        button_openActualFile.place_forget()
        
          
def enable_button(*args):
    if input_text.get() and filename:
        button_Encode.config(state = 'normal')
        button_decode.config(state = 'normal')
    else:
        button_Encode.config(state='disabled')
        button_decode.config(state = 'disabled')
        
def encode():
    global outputFileName
    # need to run in the ./HW8-B113040056 exist folder
    process = Popen(['./HW8-B113040056', '-c', '-i', filename, '-o', outputFileName], stdout=PIPE, stderr=STDOUT)
    for line in process.stdout:
        output_panel.insert('end', line)
        output_panel.see('end')

def decode():
    global outputFileName
    subprocess.call(['./HW8-B113040056', '-u', '-i', filename, '-o', outputFileName]) #call the c++ 
    


def wrap_encode():
    inputOutputName()
    output_panel.delete('1.0', 'end') # clear panel
    
    encode()
    update_output_panel()

    

def wrap_decode():
    inputOutputName()
    decode()
    # Clear the text in the output panel
    output_panel.delete('1.0', 'end')
    output_panel.insert('end', 'Decoding Complete.. Please check the file \n (Below there is a Open file Button)')
    update_output_panel()
    
    

########################### GUI 

button = Button(text="Select input file", command=openFile)
button.place(x = 5, y = 5)

# input field
e = Entry(root, width=50, textvariable=input_text)
e.place(x=5, y= 100)

# Selected file
file_label = Label(root, font=("Ubuntu", 12))
file_label.place(x = 5, y = 40)


button_Encode = Button(text="Encode", command=wrap_encode, state='disabled')
button_Encode.place(x = 300, y = 100)

description = Label(text="Write the output file name plus file extension")
description.place(x = 5, y = 75)


button_clear= Button(root, text="Clear", command=clear_entry)
button_clear.place(x = 5,  y = 120)

button_decode = Button(root, text="Decode", command=wrap_decode, state='disabled')
button_decode.place(x = 370, y = 100)

# Create a label for the output panel
label_stdout = Label(root, text="Standard Output:")
label_stdout.place(x = 5, y = 220)

# Panel
output_panel = Text(root, width=50, height=10)
output_panel.place(x = 5, y = 250)

button_openActualFile = Button(root, text="Open the file", command=openActualFile)

button_openActualFile.place_forget()

input_text.trace('w', enable_button) # enable button if input field is filled




root.mainloop()


