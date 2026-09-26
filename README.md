<div align="center">

# 📱 PF-Project

### Phonebook Management System

A menu-driven **console application written in C** for a Programming Fundamentals group project.

<p>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C">
  <img src="https://img.shields.io/badge/Project-Programming%20Fundamentals-6C63FF?style=for-the-badge" alt="Programming Fundamentals">
  <img src="https://img.shields.io/badge/Interface-Console-333333?style=for-the-badge" alt="Console Application">
</p>

</div>

---

## 📖 About

**PF-Project** is a console-based phonebook management system developed in C. It provides a simple menu-driven interface for managing contact information during a program session.

The system supports creating, viewing, searching, updating, and deleting contacts, along with confirmation prompts and basic input validation.

> **Note:** Contacts are stored in memory only. They are not saved to a file or database, so all contact data is lost when the program exits.

---

## ✨ Features

| Feature | Description |
|---|---|
| ➕ **Add Contacts** | Add a contact with a name, email address, and phone number |
| 🔎 **Search Contacts** | Search by name, email address, or phone number |
| 📋 **Display Contacts** | View all currently stored contacts |
| ✏️ **Update Contacts** | Modify a contact's name, phone number, or email |
| 🗑️ **Delete Contacts** | Select and delete a matching contact with confirmation |
| 🧹 **Clear Contacts** | Remove all stored contacts after confirmation |
| 🛡️ **Input Validation** | Validate names, phone numbers, menu choices, and confirmations |
| 🚫 **Duplicate Prevention** | Prevent storing an exact duplicate of an existing contact |
| 📦 **Capacity** | Supports up to 1,000 contacts during a program session |

---

## 🔍 Search Options

The phonebook provides three search methods:

- **By Name** — supports partial name matching
- **By Email** — supports partial email matching
- **By Phone Number** — supports partial number matching

When multiple contacts match a search, the program displays the results so the user can select the required contact for operations such as updating or deleting.

---

## 🗃️ Data Storage

The project uses fixed-size two-dimensional character arrays to store contact information:

```c
name[1000][100]
email[1000][100]
number[1000][100]
```

Each contact is represented across the three parallel arrays.

### Storage characteristics

- Maximum capacity: **1,000 contacts**
- Storage type: **In-memory**
- Data structure: **Fixed-size 2D character arrays**
- Persistent storage: **None**
- Dynamic memory allocation: **Not used**

---

## 🏗️ Project Structure

```text
PF-Project/
├── README.md
├── src/
│   ├── AddContact.c
│   ├── ClearContacts.c
│   ├── DeleteContact.c
│   ├── DisplayContacts.c
│   ├── SearchByEmail.c
│   ├── SearchByName.c
│   ├── SearchByNumber.c
│   ├── UpdateContact.c
│   └── main.c
└── submission/
    └── FINAL.c
```

### `src/`

Contains the modular implementation of the phonebook system. Each source file handles a specific part of the program:

| File | Responsibility |
|---|---|
| `main.c` | Program entry point and main menu |
| `AddContact.c` | Adding and validating contacts |
| `DeleteContact.c` | Searching for and deleting contacts |
| `UpdateContact.c` | Updating existing contact information |
| `SearchByName.c` | Searching contacts by name |
| `SearchByEmail.c` | Searching contacts by email |
| `SearchByNumber.c` | Searching contacts by phone number |
| `DisplayContacts.c` | Displaying stored contacts |
| `ClearContacts.c` | Clearing all stored contacts |

### `submission/`

Contains `FINAL.c`, the **consolidated version** of the project with the main program and all functions combined into a single C source file.

---

## 🖥️ Program Flow

```text
                    ┌───────────────────┐
                    │  Phonebook System │
                    └─────────┬─────────┘
                              │
                    ┌─────────▼─────────┐
                    │    Main Menu      │
                    └─────────┬─────────┘
                              │
        ┌──────────┬──────────┼──────────┬──────────┐
        ▼          ▼          ▼          ▼          ▼
      Add       Search      Update     Delete     Clear
        │          │          │          │          │
        └──────────┴──────────┴──────────┴──────────┘
                              │
                              ▼
                       Display / Exit
```

---

## 👥 Contributors

| Contributor | Contributions |
|---|---|
| **Maryam Saleem** | Main program · Search by phone number · Clear contacts |
| **Aiman Misbah** | Add contact · Search by name · Display contacts |
| **Umaima Manzoor** | Search by email · Delete contact · Update contact |

---

## 🛠️ Technologies

- **C**
- **Standard C library**
- **Console-based user interface**
- **Fixed-size arrays**
- **String handling and input validation**

---

## ⚠️ Implementation Notes

- Contact information is stored only for the current program session.
- There is no file, database, or other persistent storage.
- The program uses fixed-size arrays rather than dynamic memory allocation.
- The current implementation uses Windows-specific console behaviour such as `system("cls")`.
- The project is therefore **not presented as cross-platform software**.

---

<div align="center">

### 🎓 Programming Fundamentals Project

Built as a group project to practise core C programming concepts, functions, arrays, strings, input handling, and program structure.

</div>
