# 🏦 Bank Management System (C++ OOP)

A full-featured **console-based Bank Management System** developed in **C++ using Object-Oriented Programming (OOP)**.  
The system simulates real-world banking operations including client management, user authentication, financial transactions, and currency exchange.

This project was developed as part of a structured software development roadmap to practice **real-world system design using C++ and OOP principles**.

---

## 📌 Project Overview

The system is designed primarily for **bank employees (users)** to manage client accounts efficiently and securely.

Through a console interface, authorized users can:

- Manage client accounts
- Perform banking transactions
- Control system access through permissions
- Monitor user login activity
- Manage currency exchange rates

All system data is stored locally using **text files**, allowing persistent storage between program runs.

---

## ✨ Key Features

### 👥 Client Management

The system allows employees to manage bank clients through the following operations:

- Add new clients
- Update client information
- Delete clients
- Search for clients using account number
- Display all registered clients

Each client record includes:

- Account Number
- PIN Code
- Client Name
- Phone Number
- Account Balance

Client data is stored in:

```
Clients.txt
```

---

### 🔐 User Authentication & Management

The system includes a **secure login system** for bank employees.

Features include:

- Add new system users
- Update user credentials
- Manage user permissions
- Delete users
- Display all registered users

User data is stored in:

```
Users.txt
```

---

### 🧾 Login Activity Tracking

Every login attempt is automatically recorded for monitoring and auditing purposes.

Each record includes:

- Date
- Time
- Username
- Password
- Permission level

Login records are stored in:

```
LoginRegister.txt
```

---

### 💰 Financial Operations

The system supports several essential banking transactions:

- Deposit funds into client accounts
- Withdraw funds with balance validation
- Transfer funds between client accounts
- Display the **total balance across all bank accounts**

---

### 💱 Currency Exchange Module

The system also includes a currency exchange management module.

Features include:

- Display available currencies
- Search currencies by **code or name**
- Modify exchange rates *(Admin only)*
- Currency conversion calculator

Currency data is stored in:

```
Currencies.txt
```

---

## 🗂 Data Storage System

The application uses **text files as a lightweight database** to store and manage data.

| File | Description |
|-----|-------------|
| `Clients.txt` | Stores client account information |
| `Users.txt` | Stores system users |
| `Currencies.txt` | Stores currency exchange data |
| `LoginRegister.txt` | Stores login activity logs |

All records use a custom delimiter for easier parsing:

```
#//#
```

---

## 🏷 Example Data Format

### Client Record Structure

```
AccountNumber#//#PinCode#//#Name#//#Phone#//#Balance
```

Example:

```
A150#//#197008#//#Hamed Albqis#//#0536242467#//#20000
```

---

### User Record Structure

```
FirstName#//#LastName#//#Email#//#Phone#//#PasswordWithEncryption#//#Permissions
```

---

## 🧠 OOP Concepts Applied

This project demonstrates several **Object-Oriented Programming concepts**, including:

- Encapsulation
- Inheritance
- Polymorphism
- Abstraction
- Abstract classes and interfaces
- Modular class-based architecture

---

## ⚙ Technologies & Tools

- **Language:** C++
- **Programming Paradigm:** Object-Oriented Programming (OOP)
- **Data Storage:** File Handling (Text Files)
- **Application Type:** Console Application
