import tkinter as tk
from tkinter import *
from tkinter import messagebox, ttk

class StudentRecord:
    def __init__(self, students):
        self.root = tk.Tk()
        self.root.geometry('1550x600')
        self.root.title("Student Records")
        self.students = students
        self.current_page = 1
        # self.records_per_page = 5

        self.departments = [
            {'code': 'CSE', 'name': 'Computer Science & Engineering'},
            {'code': 'ECE', 'name': 'Electronics & Communication Engineering'},
            {'code': 'EEE', 'name': 'Electrical & Electronics Engineering'},
            {'code': 'ME', 'name': 'Mechanical Engineering'},
            {'code': 'CE', 'name': 'Civil Engineering'},
        ]
        

        # Create the menu
        menu = tk.Menu(self.root)
        self.root.config(menu=menu)

        file_menu = tk.Menu(menu)
        menu.add_cascade(label="Menu", menu=file_menu)
        file_menu.add_command(label="Add", command=self.add_student)
        file_menu.add_command(label="Search", command=self.search_student)
        file_menu.add_command(label="Edit", command=self.edit_student)
        file_menu.add_command(label="Delete", command=self.delete_student)
        # file_menu.add_command(label="Display", command=self.display_all)

        self.create_widgets()

    def create_widgets(self):
        self.main_frame = ttk.Frame(self.root, padding="30 30 30 30")
        self.main_frame.grid(column=0, row=0)
        
        self.display_frame = ttk.Frame(self.main_frame, padding="30 30 30 30")
        self.display_frame.grid(column=0, row=0)
        
        self.display_student_details()

    def clear_frame(self,frame):
        for widgets in frame.winfo_children():
            widgets.destroy()
        
    def display_student_details(self):
        self.student_rows = 5  # Number of rows to display in one page
        self.total_pages = len(self.students) // self.student_rows + (1 if len(self.students) % self.student_rows else 0)
        
        # for i in range(self.student_rows):
        #     ttk.Label(self.display_frame, text="Roll").grid(column=0, row=i)
        #     ttk.Label(self.display_frame, text="Dept Code").grid(column=1, row=i)
        #     ttk.Label(self.display_frame, text="Name").grid(column=2, row=i)
        #     ttk.Label(self.display_frame, text="Address").grid(column=3, row=i)
        #     ttk.Label(self.display_frame, text="Phone").grid(column=4, row=i)

        
        
        self.update_student_details()

    def update_student_details(self):
        self.clear_frame(self.display_frame)
        header = ['Roll No', 'Name', 'Department', 'Address', 'Phone']

        for col, header_text in enumerate(header):
            header_label = tk.Label(self.display_frame, text=header_text, bg='blue', fg='white', width=20, height=2)
            header_label.grid(row=0, column=col, sticky='nsew')

        prev_button = Button(self.display_frame, text="Prev Page", command=lambda: self.prev_page(), bg='black', fg='white')
        prev_button.grid(row= 8,column=0,pady=200)
        next_button = Button(self.display_frame, text="Next Page", command=lambda: self.next_page(), bg='black', fg='white')
        next_button.grid(row= 8,column=4,pady=200)

        start_index = (self.current_page - 1) * self.student_rows
        end_index = start_index + self.student_rows
        students_to_display = self.students[start_index:end_index]
        
        for row, student in enumerate(students_to_display, start=1):
            for col, detail in enumerate(student):
                detail_label = tk.Label(self.display_frame, text=student[detail], width=35, height=2)
                detail_label.grid(row=row, column=col, sticky='nsew')

    def save_student(self,add_window, roll_entry, name_entry, address_entry, phone_entry, clicked):
        roll = roll_entry.get()
        dept_code = clicked.get()
        name = name_entry.get()
        address = address_entry.get()
        phone = phone_entry.get()
        
        # check if roll already exists
        for student in self.students:
            if student['roll'] == roll:
                messagebox.showerror("Error", "Roll already exists")
                return

        dept_name = ''
        for dept in self.departments :
            if dept['code'] == dept_code :
                dept_name = dept['name']
                break

        if dept_name == '':
            messagebox.showerror("Error", "Wrong department code")
        
        # add the new student
        new_student = {
            'roll': roll,
            'dept_name': dept_name,
            'name': name,
            'address': address,
            'phone': phone
        }
        self.students.append(new_student)

        self.update_student_details()
        
        # clear the entries
        roll_entry.delete(0, END)
        clicked.set('Enter department name')
        name_entry.delete(0, END)
        address_entry.delete(0, END)
        phone_entry.delete(0, END)
        
        messagebox.showinfo("Success", "Student added successfully")
        add_window.destroy()
        # pass

    def add_student(self):
        # Code to add a student to the list
        add_window = Toplevel(self.root)
        add_window.title("Add Student")

        # creating labels and entries for roll, name, address, phone, and dept
        roll_label = Label(add_window, text="Roll")
        roll_label.grid(row=0, column=0, padx=10, pady=10)
        roll_entry = Entry(add_window)
        roll_entry.grid(row=0, column=1, padx=10, pady=10)

        name_label = Label(add_window, text="Name")
        name_label.grid(row=1, column=0, padx=10, pady=10)
        name_entry = Entry(add_window)
        name_entry.grid(row=1, column=1, padx=10, pady=10)

        address_label = Label(add_window, text="Address")
        address_label.grid(row=2, column=0, padx=10, pady=10)
        address_entry = Entry(add_window)
        address_entry.grid(row=2, column=1, padx=10, pady=10)

        phone_label = Label(add_window, text="Phone")
        phone_label.grid(row=3, column=0, padx=10, pady=10)
        phone_entry = Entry(add_window)
        phone_entry.grid(row=3, column=1, padx=10, pady=10)

        dept_names = []
        for dept in self.departments:
            dept_names.append(dept['code'])

        clicked = StringVar()
        clicked.set('Enter department name')
        dept_label = Label(add_window, text="Department")
        dept_label.grid(row=4, column=0, padx=10, pady=10)
        dept_list = OptionMenu(add_window,clicked, *dept_names)
        dept_list.grid(row=4, column=1, padx=10, pady=10)


        # creating save and cancel buttons
        save_button = Button(add_window, text="Save", command=lambda: self.save_student(add_window, roll_entry, name_entry, address_entry, phone_entry, clicked))
        save_button.grid(row=5, column=0, padx=10, pady=10)

        cancel_button = Button(add_window, text="Cancel", command=add_window.destroy)
        cancel_button.grid(row=5, column=1, padx=10, pady=10)

        

    def search_student(self):
        # Code to search for a student
        search_window = Toplevel(self.root)
        search_window.title("Search Student")
        roll_label = Label(search_window, text="Roll")
        roll_label.grid(row=0, column=0, padx=10, pady=10)
        roll_entry = Entry(search_window)
        roll_entry.grid(row=0, column=1, padx=10, pady=10)

        save_button = Button(search_window, text="Search", command=lambda: self.display_student(search_window, roll_entry))
        save_button.grid(row=5, column=0, padx=10, pady=10)

    def display_student(self,search_window,roll_entry):
        found = False
        roll = roll_entry.get()
        for student in self.students:
            if student['roll'] == roll:
                # if the roll number exists, display the student details
                found = True
                header = ['Roll No', 'Name', 'Department', 'Address', 'Phone']

                for col, header_text in enumerate(header):
                    header_label = tk.Label(search_window, text=header_text, bg='black', fg='white', width=20, height=2)
                    header_label.grid(row=1, column=col, sticky='nsew')
                for col, detail in enumerate(student):
                    detail_label = tk.Label(search_window, text=student[detail], width=35, height=2)
                    detail_label.grid(row=2, column=col, sticky='nsew',pady=10)
                break

        # if the roll number does not exist, display a suitable message
        if not found :
            messagebox.showinfo("Search Result", "Student record not found")


    def edit_student(self):
        # Code to edit a student's information
        edit_window = Toplevel(self.root)
        edit_window.title("Edit Student")
        roll_label = Label(edit_window, text="Roll")
        roll_label.grid(row=0, column=0, padx=10, pady=10)
        roll_entry = Entry(edit_window)
        roll_entry.grid(row=0, column=1, padx=10, pady=10)

        save_button = Button(edit_window, text="Edit", command=lambda: self.edit_student_util(edit_window, roll_entry))
        save_button.grid(row=5, column=0, padx=10, pady=10)

    def edit_student_util(self,edit_window,roll_entry):
        roll = roll_entry.get()
        index = -1
        for i,student in enumerate(self.students):
            if student['roll'] == roll:
                index = i
                break
        
        if index == -1:
            messagebox.showinfo("Search Result", "Student record not found")
            edit_window.destroy()
            return

        edit_w = Toplevel(edit_window)
        edit_w.title('Edit Student Roll No. '+roll)
        name_label = Label(edit_w, text="Name")
        name_label.grid(row=1, column=0, padx=10, pady=10)
        name_entry = Entry(edit_w)
        name_entry.grid(row=1, column=1, padx=10, pady=10)

        address_label = Label(edit_w, text="Address")
        address_label.grid(row=2, column=0, padx=10, pady=10)
        address_entry = Entry(edit_w)
        address_entry.grid(row=2, column=1, padx=10, pady=10)

        phone_label = Label(edit_w, text="Phone")
        phone_label.grid(row=3, column=0, padx=10, pady=10)
        phone_entry = Entry(edit_w)
        phone_entry.grid(row=3, column=1, padx=10, pady=10)

        dept_names = []
        for dept in self.departments:
            dept_names.append(dept['code'])

        clicked = StringVar()
        clicked.set('Enter department name')
        dept_label = Label(edit_w, text="Department")
        dept_label.grid(row=4, column=0, padx=10, pady=10)
        dept_list = OptionMenu(edit_w,clicked, *dept_names)
        dept_list.grid(row=4, column=1, padx=10, pady=10)


        # creating save and cancel buttons
        save_button = Button(edit_w, text="Save", command=lambda: self.update_student(edit_w, index, name_entry, address_entry, phone_entry, clicked))
        save_button.grid(row=5, column=0, padx=10, pady=10)

        cancel_button = Button(edit_w, text="Cancel", command=edit_w.destroy)
        cancel_button.grid(row=5, column=1, padx=10, pady=10)

    def update_student(self,edit_w,index,name_entry,address_entry,phone_entry,clicked) :
        dept_code = clicked.get()
        name = name_entry.get()
        address = address_entry.get()
        phone = phone_entry.get()
        dept_name = ''

        for dept in self.departments :
            if dept['code'] == dept_code :
                dept_name = dept['name']
                break
        
        if name != '':
            self.students[index]['name'] = name

        if address != '':
            self.students['address'] = address
        if phone != '':
            self.students['phone'] = phone

        self.update_student_details()
        messagebox.showinfo("Success", "Student updated successfully")
        edit_w.destroy()
        

    def delete_student(self):
        # Code to delete a student from the list
        delete_window = Toplevel(self.root)
        delete_window.title("Delete Student")
        roll_label = Label(delete_window, text="Roll")
        roll_label.grid(row=0, column=0, padx=10, pady=10)
        roll_entry = Entry(delete_window)
        roll_entry.grid(row=0, column=1, padx=10, pady=10)

        save_button = Button(delete_window, text="Delete", command=lambda: self.delete_student_util(delete_window, roll_entry))
        save_button.grid(row=5, column=0, padx=10, pady=10)
    
    def delete_student_util(self,delete_window,roll_entry):
        roll = roll_entry.get()
        index = -1

        for i,student in enumerate(self.students):
            if student['roll'] == roll:
                index = i
                break

        if index == -1:
            messagebox.showinfo('Search Result','Student Record Not Found')
            delete_window.destroy()
            return

        self.students.pop(index)
        self.update_student_details()
        delete_window.destroy()


    def prev_page(self):
        # Code to display the previous page of students
        if self.current_page == 1:
            return
        self.current_page = self.current_page-1
        self.update_student_details()

    def next_page(self):
        # Code to display the next page of students
        tot = self.current_page*5
        l = len(self.students)
        if tot >= l:
            return
        self.current_page = self.current_page+1
        self.update_student_details()

    def run(self):
        self.root.mainloop()

if __name__ == "__main__":
    students = [{'roll':'88', 'dept_name':'Computer Science & Engineering','name':'Sugar','address':'Dressrosa','phone':'9845854222'},{'roll':'45', 'dept_name':'Computer Science & Engineering','name':'Kouzuki Oden','address':'Wano Country','phone':'7545443201'},{'roll':'23', 'dept_name':'Computer Science & Engineering','name':'Donquixote Dofflamingo','address':'Dressrosa','phone':'9845854222'}]
    app = StudentRecord( students)
    app.run()
