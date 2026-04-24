# 🏦 Banking Management System (C++)

## 📌 Overview

This is a **console-based Banking Management System** developed using **C++**.

The system allows users to perform banking operations with **role-based access**:

* 👨‍💼 Admin
* 👤 Customer

It uses **vector (dynamic array)** to store account records and provides secure operations using **PIN verification**.

---

## 🚀 Features

### 👨‍💼 Admin

* 🆕 Open new bank account
* 🔍 View account details
* 💰 Deposit money
* 💸 Withdraw money
* ✏️ Edit account details
* ❌ Delete account

### 👤 Customer

* 🆕 Create account
* 🔍 View own account (with PIN)
* 💰 Deposit money
* 💸 Withdraw money

---

## 🛠️ Technologies Used

* **Language:** C++
* **Concepts Used:**

  * Object-Oriented Programming (OOP)
  * Encapsulation
  * STL (vector)
  * Functions
  * Menu-driven programming

---

## 🧠 Data Structure Used

* **Vector (Dynamic Array)**

  * Stores multiple bank accounts
  * Supports dynamic resizing

---

## 📂 Project Structure

```id="projstruct"
BANKING_SYSTEM/
│── main.cpp
│── README.md
```

---

## ⚙️ How to Run

### 💻 Using Terminal (GCC)

```bash id="cmd1"
g++ main.cpp -o bank
```

```bash id="cmd2"
./bank
```

---

## 🧪 Program Flow

```id="flow"
1. Select Role (Admin / Customer)
2. Perform operations based on role
3. Use Back option to return to main menu
4. Exit program
```

---

## 🧾 Sample Menu

```id="menu"
===== MAIN MENU =====
1. Admin
2. Customer
3. Exit

--- ADMIN MENU ---
1. Open Account
2. View Account
3. Deposit
4. Withdraw
5. Edit Account
6. Delete Account
7. Back

--- CUSTOMER MENU ---
1. Create Account
2. View Account
3. Deposit
4. Withdraw
5. Back
```

---

## 🔐 Security

* PIN verification is required for account access
* Prevents unauthorized operations

---

## ⚠️ Important Notes

* Data is stored temporarily (no database/file storage)
* Account number is auto-generated
* Console-based application

---

## 📈 Future Improvements

* 💾 File handling for permanent storage
* 🔐 Login system (Admin & Customer)
* 💸 Transfer money feature
* 🖥️ GUI version

---

## 👩‍💻 Author

**Your Name**

---

⭐ If you like this project, give it a star on GitHub!
