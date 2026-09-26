# PF-Project

## Phonebook Management System

A console-based phonebook management system developed in C as a Programming Fundamentals group project.

The program allows users to add, search, display, update, delete, and clear contacts through a menu-driven console interface.

## Features

- Add new contacts
- Prevent exact duplicate contacts
- Validate names and phone numbers during input
- Search contacts by:
  - Name
  - Email address
  - Phone number
- Display all stored contacts
- Update a selected contact's:
  - Name
  - Phone number
  - Email address
- Delete selected contacts with confirmation
- Clear all contacts with confirmation
- Handle invalid menu and selection input
- Store up to 1,000 contacts during a program session

## Data Storage

The project uses fixed-size two-dimensional character arrays to store contact information in memory:

- `name[1000][100]`
- `email[1000][100]`
- `number[1000][100]`

Contacts are **not saved permanently**. All data is lost when the program exits.

## Project Structure

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

### Source Files

The `src/` directory contains the project's modular source files. Each file is responsible for a particular part of the phonebook system.

### Submission File

`submission/FINAL.c` is the consolidated version of the project, containing the main program and all functions in a single C source file.

## Contributors

### Maryam Saleem
- Main program
- Search by phone number
- Clear contacts

### Aiman Misbah
- Add contact
- Search by name
- Display contacts

### Umaima Manzoor
- Search by email
- Delete contact
- Update contact

## Technologies

- C
- Standard C library functions
- Console-based user interface

## Notes

- Contact data is stored only in memory while the program is running.
- The project uses fixed-size arrays rather than dynamic memory allocation.
- The current implementation uses Windows-specific console commands such as `system("cls")` and therefore is not presented as cross-platform software.
