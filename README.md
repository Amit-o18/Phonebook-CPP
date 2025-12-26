# Phonebook-CPP

A console-based Phonebook Management System developed in C++, demonstrating the use of Object-Oriented Programming (OOP) principles, STL containers, and file handling for persistent data storage.

This project is suitable for showcasing core C++ concepts and clean program design to recruiters.

---

## Features

- Add new contacts (Name and Phone Number)
- Display all saved contacts
- Search contacts:
  - Binary search by phone number
  - Case-insensitive and partial search by name
- Update existing contact details
- Delete contacts
- Contacts are always stored in sorted order
- Persistent storage using file handling (`phone_book.txt`)

---

## Technologies Used

- C++ (Object-Oriented Programming)
- STL (`vector`, algorithms)
- File Handling (`fstream`)
- Binary Search

---

## How to Run the Project

1. Clone the repository
```bash
git clone https://github.com/Amit-018/Phonebook-CPP.git
cd Phonebook-CPP
g++ phonebook.cpp -o phonebook
./phonebook

```bash
This project demonstrates real-world C++ concepts and is a strong addition to a resume.

---

## Data Storage

- Contact data is stored in a text file named `phone_book.txt`
- Data is loaded into memory when the program starts
- Data is saved back to the file after add, update, or delete operations
- The data file is ignored on GitHub to protect user data

---

## How It Works (Internals)

- Contacts are stored in a `vector<Contact>` in memory
- Data is loaded from `phone_book.txt` at program startup
- New contacts are inserted in sorted order by phone number
- Binary search is used for fast phone number lookup
- Case-insensitive and partial matching is used for name searches
- After every modification, data is written back to the file

---

## Project Structure

Phonebook-CPP/<br>
│── phonebook.cpp # Main source code<br>
│── README.md # Project documentation<br>
│── .gitignore # Ignored files<br>
│── phone_book.txt # Data file (ignored on GitHub)<br>

---

## Why This Project Matters

- Demonstrates clean OOP-based design
- Uses efficient searching techniques
- Implements persistent file storage
- Shows practical use of STL and file handling
