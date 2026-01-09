from tkinter import*
from time import strftime

root = Tk()
root.title("Calculator with current date")
root.geometry("500x300+200+200")
root.config(bg="powderblue")


class MyWindow:
    def __init__(self, master):
        self.lbl1=Label(master, text='First number', font=("arial",15,"bold"),bg="powderblue")
        self.lbl1.place(x=10, y=50)

        self.lbl2=Label(master, text='Second number', font=("arial",15,"bold"),bg="powderblue")
        self.lbl2.place(x=10, y=100)

        self.lbl3=Label(master, text='Result', font=("arial",15,"bold"),bg="powderblue")
        self.lbl3.place(x=10, y=200)

        self.t1=Entry(bd=3,font=("arial", 12, "bold"))
        self.t1.place(x=200, y=50)

        self.t2=Entry(bd=3,font=("arial", 12, "bold"))
        self.t2.place(x=200, y=100)

        self.t3=Entry(font=("arial",16,"bold"),bg="powderblue")
        self.t3.place(x=200, y=200)

        self.b1=Button(master,width=10, text='Add', command=self.add,font=("arial",10,"bold"),bg="powderblue")
        self.b1.place(x=200, y=150)
        self.b2=Button(master,width=10, text='Substruct', command=self.sub,font=("arial",10,"bold"),bg="powderblue")
        self.b2.place(x=300, y=150)

    def add(self):
        self.t3.delete(0, 'end')
        num1=float(self.t1.get())
        num2=float(self.t2.get())
        result=num1+num2
        self.t3.insert(END, str(result))
    
    def sub(self):
        self.t3.delete(0, 'end')
        num1=float(self.t1.get())
        num2=float(self.t2.get())
        result=num1-num2
        self.t3.insert(END, str(result))
    
    
def time():
    string = strftime('%H:%M:%S %p\n %d %B')
    lbl.config(text=string)
    lbl.after(1000, time)

lbl = Label(root, font=('calibri', 10, 'bold'), background='purple', foreground='white')
lbl.pack(anchor='center')
time()

mywin=MyWindow(root)
root.mainloop()
