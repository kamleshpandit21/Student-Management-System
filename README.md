Student Management System

Overview

The Student Management System is a C-based program designed to store, retrieve, search, and delete student records. It utilizes file handling to maintain a persistent database of student details.

Features

Add Student: Store student details such as name, age, city, percentage, and phone number.

Search Student: Find student details using their serial number.

View All Students: Display a list of all registered students.

Delete Student: Remove a student's record from the database.

Technologies Used

Programming Language: C

File Handling: Uses fwrite, fread, fopen, and fclose for data storage.

File Structure

Student_Management_System/
│
├── student_management.c  # Main program file
├── student_detail.txt    # File storing student records
├── tempFile.txt          # Temporary file for deletion operation
└── README.md             # Project documentation

How to Run

Compile the Program

gcc student_management.c -o student_management

Run the Executable

./student_management

Functions Explanation

add_student()

Prompts the user to enter student details.

Saves the data to student_detail.txt using fwrite.

search_student()

Asks for a serial number to search.

Reads the file and displays matching student records.

see_student()

Reads all records from student_detail.txt.

Displays each student’s details.

delete_student()

Asks for a serial number to delete.

Copies all records except the deleted one to a temporary file.

Replaces the original file with the updated file.

Example Usage

---------------------Choose Your Option--------------------
Enter 1 To Enter Student Details
Enter 2 To Search Student
Enter 3 To See Student List
Enter 4 To Delete Student Record
Enter 5 To EXIT
-----------------------------------------------------------
