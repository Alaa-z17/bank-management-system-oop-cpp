# 🏦 Bank Management System - Advanced C++ OOP Project

A comprehensive, production-ready **Bank Management System** built in C++ with enterprise-grade features including secure authentication, encrypted data storage, currency exchange, and complete transaction logging. Demonstrates advanced OOP concepts, security implementations, and real-world banking operations.

## 📺 Project Demo & Explanation

[![Watch the video](https://img.youtube.com/vi/YOUR_VIDEO_ID/0.jpg)](https://www.youtube.com/watch?v=YOUR_VIDEO_ID)

**Click the image above to watch a complete walkthrough** of the Bank Management System, including:

- System architecture and OOP design patterns
- Live demonstration of all banking operations
- Code explanation and key features
- Compilation and setup guide

## ✨ Features

### Core Banking Operations

- ✅ **Create New Account** - Open savings or current accounts with unique account numbers
- ✅ **Deposit Money** - Add funds to any existing account
- ✅ **Withdraw Money** - Withdraw funds with balance validation
- ✅ **Balance Inquiry** - Check current balance with account details
- ✅ **Fund Transfer** - Transfer money between accounts
- ✅ **Account Details** - View complete account information
- ✅ **Close Account** - Delete/remove existing accounts
- ✅ **View All Accounts** - Display all registered accounts
  
## ✨ Advanced Features

### 🔐 Security & Authentication

- ✅ **Login Screen** - Secure username/password authentication
- ✅ **Role-Based Access** - Admin, Manager, Teller, and Customer roles
- ✅ **Session Management** - Track user sessions and activities
- ✅ **Password Encryption** - custom Encryption for passwords (no library)
- ✅ **Account Lockout** - Automatic lockout after failed attempts

### 👥 User Management System

- ✅ **User Registration** - Create new user accounts with role assignment
- ✅ **Profile Management** - Update personal information and credentials
- ✅ **Access Control** - Granular permissions based on user roles
- ✅ **User Activity Tracking** - Monitor login history and actions
- ✅ **Password Recovery** - Secure password reset mechanism

### 👤 Client Management

- ✅ **Client Registration** - Create client profiles with complete KYC information
- ✅ **Client Search** - Search clients by ID, name, phone, or email
- ✅ **Client Details** - View complete client history and relationships
- ✅ **Multiple Accounts** - Clients can have multiple accounts
- ✅ **Client Status** - Active, inactive, or suspended status management
- ✅ **Contact Information** - Phone, email, address, and emergency contacts
- ✅ **Document Management** - Store KYC documents references

### 💰 Transaction Management

- ✅ **Deposit & Withdrawal** - All transactions with validation
- ✅ **Fund Transfer** - Internal and external transfers
- ✅ **Total Balances** - Showing total Balances
- ✅ **Transaction History** - Complete transaction log with search filters

### 💱 Currency Exchange System

- ✅ **Multi-Currency Support** - USD, EUR, GBP, JPY, CAD, AUD, and more
- ✅ **Currency Conversion** - Convert between any supported currencies
- ✅ **Exchange Rate History** - Track rate changes over time
- ✅ **Foreign Currency Accounts** - Maintain accounts in different currencies
- ✅ **Exchange Fee Calculator** - Automatic fee calculation based on amount

### 📊 Logging & Monitoring

- ✅ **Login Register Screen** - Track all login attempts (successful/failed)
- ✅ **Transfer Log Screen** - Complete audit trail of all transfers
- ✅ **Transaction Log Screen** - Comprehensive transaction logging
- ✅ **Admin Log Screen** - Track administrative actions
- ✅ **Error Log Screen** - Capture and log system errors
- ✅ **Export Logs** - Export logs to CSV for analysis
- ✅ **Log Rotation** - Automatic log file management

### 🔒 Data Encryption

- ✅ **File Encryption** - AES-256 encryption for all data files
- ✅ **Secure Key Management** - Encrypted key storage
- ✅ **Data Integrity** - Checksum verification for file integrity
- ✅ **Encrypted Backup** - Automatic encrypted backups
- ✅ **Secure Deletion** - Secure wipe for deleted records



## 🚀 Getting Started

### Prerequisites

- **C++ Compiler** (GCC 7+, Clang 5+, or MSVC 2019+)
- **CMake** (optional, for building)
- **Visual Studio** (if using the provided .slnx solution)

### Installation & Compilation

#### Option 1: Using Visual Studio (Windows)

1. Clone the repository:
bash git clone [https://github.com/Alaa-z17/bank-management-system-oop-cpp.git]
Open bank-management-system-oop-cpp.slnx in Visual Studio

Build the solution (Ctrl+Shift+B)

Run the executable (F5)

Option 2: Using GCC/Linux/Mac
Clone the repository:

bash
git clone [https://github.com/Alaa-z17/bank-management-system-oop-cpp.git]
cd bank-management-system-oop-cpp
Compile the program:

bash
g++ -std=c++17 *.cpp -o bank_system
Run the executable:

bash
./bank_system
💻 Usage Guide
Main Menu Options
text
═══════════════════════════════════════════
       BANK MANAGEMENT SYSTEM
═══════════════════════════════════════════

 [1] Show Client List.
 [2] Add New Client.
 [3] Delete Client.
 [4] Update Client Info.
 [5] Find Client.
 [6] Transactions.
 [7] Manage Users.
 [8] Login Register.
 [9] Logout.
 [10] Currency Exchange.
 [11] Exit.
═══════════════════════════════════════════
Enter your choice:

📁 Project Structure
text
bank-management-system-oop-cpp/
│
test/
├── Header Files/
│   ├── CoreLogic/
│   │   ├── clsBankClient.h
│   │   ├── clsCurrency.h
│   │   ├── clsPerson.h
│   │   └── clsUser.h
│   ├── Libraries/
│   │   ├── clsDate.h
│   │   ├── clsInputValidate.h
│   │   ├── clsString.h
│   │   └── clsUtility.h
│   └── Screens/
│       ├── ClientScreens/
│       │   ├── TransactionScreens/
│       │   │   ├── clsDepositScreen.h
│       │   │   ├── clsTotalBalances.h
│       │   │   ├── clsTransferScreen.h
│       │   │   └── clsWithDrawScreen.h
│       │   ├── clsAddNewClientScreen.h
│       │   ├── clsClientListScreen.h
│       │   ├── clsDeleteClientScreen.h
│       │   ├── clsFindClientScreen.h
│       │   ├── clsTransferLogScreen.h
│       │   └── clsUpdateClientScreen.h
│       ├── CurrencyScreens/
│       │   ├── clsCurrenciesListScreen.h
│       │   ├── clsCurrencyCalculatorScreen.h
│       │   ├── clsFindCurrencyScreen.h
│       │   └── clsUpdateCurrencyRateScreen.h
│       ├── UserScreens/
│       │   └── clsAddNewUserScreen
            └── clsChangeAdminCredsScreen
            └──clsDeleteUserScreen
            └──clsFindUserScreen
            └──clsListUserScreen
            └──clsUpdateUserScreen
│       ├── clsCurrencyExchangeMainScreen.h
│       ├── clsLoginRegisterScreen.h
│       ├── clsLoginScreen.h
│       ├── clsMainScreen.h
│       ├── clsManageUserScreen.h
│       ├── clsScreen.h
│       └── clsTransactionScreen.h
│   └── Global.h
└── Source Files/
    └── bank-management-system-oop-cpp.cpp
├── bank-management-system-oop-cpp.slnx  # Visual Studio solution
├── .gitignore              # Git ignore rules
└── LICENSE                 # MIT License
🎓 Learning Outcomes
This project demonstrates:

Object-Oriented Design - Proper class relationships and hierarchies

Polymorphism - Runtime binding through virtual functions

File I/O - Persistent data storage and retrieval

Exception Handling - Try-catch blocks for error management

STL Usage - Vectors, strings, and algorithms

Memory Management - Dynamic allocation and deallocation

Code Organization - Separation of concerns with header/source files

🔧 Future Enhancements
Add GUI using Qt or wxWidgets

Implement database integration (MySQL/PostgreSQL)

Add password authentication for accounts

Include transaction history logging

Add interest calculation for savings accounts

Implement monthly statements generation

Add email notifications for transactions

Create web-based REST API version

🤝 Contributing
Contributions are welcome! If you'd like to improve this project:

Fork the repository

Create your feature branch (git checkout -b feature/AmazingFeature)

Commit your changes (git commit -m 'Add some AmazingFeature')

Push to the branch (git push origin feature/AmazingFeature)

Open a Pull Request

📝 License
This project is licensed under the MIT License - see the LICENSE file for details.

👤 Author
Alaa Alkatshah

GitHub: @Alaa-z17

🙏 Acknowledgments
Inspired by real-world banking systems

Built as a learning project to master C++ OOP concepts

Thanks to the C++ community for excellent resources

📧 Contact
For questions or feedback, please open an issue on GitHub.

⭐ If you found this project helpful, please give it a star ! ⭐
