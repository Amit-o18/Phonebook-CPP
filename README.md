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

## 2️⃣ Add “How Data Is Stored” (Very Useful)

Add this small section after Features:

```md
## 💾 Data Storage

- Contact data is stored in a text file (`phone_book.txt`)
- Data is loaded into memory when the program starts
- Data is saved back to the file after add, update, or delete operations
- The data file is ignored on GitHub to protect user data

## 🎯 Learning Outcomes

- Implemented OOP concepts in a real project
- Learned file persistence vs memory storage
- Used binary search on sorted data
- Improved string handling and searching techniques
- Gained experience with Git and GitHub


## 🛠️ Technologies Used

- **C++**
- **OOP (Classes & Objects)**
- **STL (vector)**
- **File Handling (fstream)**
- **Binary Search Algorithm**
- **String manipulation**

---

## 📂 Project Structure

Phonebook-CPP/<br>
│── phonebook.cpp # Main source code<br>
│── README.md # Project documentation<br>
│── .gitignore # Ignored files<br>
│── phone_book.txt # Data file (ignored on GitHub)<br>
