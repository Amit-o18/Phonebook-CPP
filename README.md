# Phonebook-CPP
A C++ OOP-based phonebook application with file persistence and search features.

# 📞 Phonebook-CPP

A **console-based Phonebook Management System** developed in **C++** using **Object-Oriented Programming (OOP)** concepts, STL containers, and file handling for persistent data storage.

---

## 🚀 Features

- Add new contacts (name & phone number)
- Display all saved contacts
- Search contacts:
  - 🔍 Binary search by phone number
  - 🔤 Case-insensitive & partial search by name
- Update contact details
- Delete contacts
- Contacts are always stored in **sorted order**
- Data persistence using file handling (`phone_book.txt`)

---

## ▶️ How to Run the Project

1. Clone the repository
```bash
git clone https://github.com/Amit-018/Phonebook-CPP.git

Navigate to the project folder
cd Phonebook-CPP

Compile the program
g++ phonebook.cpp -o phonebook

Run the program
./phonebook


📌 This is a **big plus** for recruiters.

---

## ▶️ How to Run the Project

1. Clone the repository
```bash
git clone https://github.com/Amit-018/Phonebook-CPP.git
cd Phonebook-CPP
g++ phonebook.cpp -o phonebook
./phonebook

---

## 💾 Data Storage

- Contact data is stored in a text file (`phone_book.txt`)
- Data is loaded into memory when the program starts
- Data is saved back to the file after add, update, or delete operations
- The data file is ignored on GitHub to protect user data

---
```
## 📁 Project Structure

Phonebook-CPP/
│── phonebook.cpp # Main source code 
│── README.md # Project documentation 
│── .gitignore # Ignored files 
│── phone_book.txt # Data file (ignored on GitHub) 
