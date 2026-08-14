# Exam System

A console-based **C++ Examination Management System** that provides separate functionalities for students and teachers. Students can register, log in, attempt MCQ and essay exams, and view their results. Teachers can review and grade essays, monitor MCQ results, view average scores, and manage their credentials.

## Features

### Student Features
- Student registration and login
- Automatic roll number generation
- MCQ examination with automatic scoring
- Essay examination submission
- View MCQ results
- View essay results after teacher evaluation
- Compare performance with the class average
- Sign out functionality

### Teacher Features
- Teacher/admin login
- Review submitted essays
- Assign essay marks from 0 to 10
- View students' MCQ results
- Calculate average MCQ marks
- Calculate average essay marks
- Change teacher password
- Sign out functionality

## Technologies Used

- **C++**
- Object-Oriented Programming (OOP)
- File Handling
- Exception Handling
- Inheritance
- Polymorphism
- Encapsulation
- Virtual Functions
- Standard C++ Libraries

## OOP Concepts Demonstrated

The project uses a base `Person` class with specialized `Student` and `Teacher` classes.

- **Inheritance:** `Student` and `Teacher` inherit from `Person`.
- **Polymorphism:** Virtual functions are used for login, menus, exams, and result-related operations.
- **Encapsulation:** Student information and exam-related data are managed through class members and getter/setter functions.
- **Abstraction:** Common functionality is defined in the `Person` base class while student and teacher-specific functionality is implemented in their respective classes.

## Examination Workflow

### Student

1. Select **Student** from the main menu.
2. Register a new account or log in with an existing account.
3. After successful login, access the student menu.
4. Attempt the MCQ exam.
5. View the MCQ score after completing the exam.
6. Attempt the essay exam.
7. Wait for the teacher to evaluate the essay.
8. View the essay result after evaluation.

### Teacher

1. Select **Teacher** from the main menu.
2. Log in using the teacher credentials.
3. Access the teacher menu.
4. Review submitted essays and assign marks.
5. View students' MCQ results.
6. View average MCQ and essay marks.
7. Change the teacher password when required.

## Data Storage

The system uses text files for persistent data storage rather than a database.

The program creates and reads files inside the `Data` directory, including:

- `Database.txt` for student login information
- `<username>_data.txt` for student information and examination status/results
- `<username>essay.txt` for submitted essays
- `T_students.txt` for the total number of students
- `admin_credentials.txt` for teacher credentials

Make sure the required data files and `Data` directory are available in the correct location when running the program.

## Input Validation

The project includes input validation through the `ExceptionCin()` function. It handles non-numeric input for menu choices and other numeric fields by clearing the input stream and asking the user to enter a valid numeric value.

## Project Structure

```text
Exam-System/
│
├── Data/
│   ├── Database.txt
│   ├── T_students.txt
│   └── <student data files>
│
├── admin_credentials.txt
├── main.cpp
└── README.md
```

> The exact file names may vary depending on how the project is organized.

## How to Run

### 1. Clone the Repository

```bash
git clone <YOUR_REPOSITORY_URL>
cd Exam-System
```

### 2. Compile the Program

Using `g++`:

```bash
g++ main.cpp -o exam_system
```

### 3. Run the Program

On Windows:

```bash
exam_system.exe
```

On Linux/macOS:

```bash
./exam_system
```

## Main Menu

When the application starts, users can choose between:

```text
WELCOME TO EXAM SYSTEM

1. Student
2. Teacher
3. Exit
```

### Student Menu

Students can:

```text
1. Take MCQs Test / Check MCQs Numbers
2. Take Essay Test / Check Essay Numbers
3. Sign Out
```

### Teacher Menu

Teachers can:

```text
1. Check the Essays of Students
2. Check the Results of MCQs of Students
3. Check the Average Marks of MCQs and Essays
4. Change Password
5. Sign Out
```

## MCQ Examination

The MCQ exam contains **10 questions**. The system automatically increments the student's score when the correct option is selected.

After completing the examination, the student receives their score and the result is saved to the student's data file.

## Essay Examination

Students can submit an essay on the topic:

> **Democracy**

The submitted essay is stored in a separate text file. Teachers can later review the essay and assign marks between **0 and 10**.

## Result Analysis

The system calculates:

- Number of students who attempted the MCQ exam
- Average MCQ marks
- Number of students whose essays were evaluated
- Average essay marks

Students can also determine whether their score is **above average, below average, or equal to the average**.

## Important Notes

- This is a console-based application.
- Data is stored locally using text files.
- The project is designed primarily as an educational demonstration of C++ OOP and file handling.
- The application uses `system("cls")`, so the current implementation is oriented toward Windows environments.
- Credentials are stored in plain text and are intended for educational use, not production deployment.

## Learning Objectives

This project demonstrates how C++ can be used to build a complete menu-driven application while applying:

- Classes and objects
- Inheritance
- Polymorphism
- Encapsulation
- Abstract behavior through virtual functions
- File input/output
- Exception handling
- User authentication
- Persistent application data
- Basic examination and result management

## Author

Developed as a C++ Object-Oriented Programming project.

## License

This project is intended for educational purposes.

