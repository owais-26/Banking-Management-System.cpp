#include <iostream>
#include <string>

#include <fstream>
using namespace std;

//**BANK CLASS**//
class BANK 
{
    // Declaring Variables
protected:
    string uName, pass = "", name, emailChecker, email, gender, logname, logpass, valname, valpass;
    char ch;
    int phone, choice;

public:
    string selOpt;

public:
    // Declaring function for checking email
    void checkEmail() 
    {
        if(emailChecker.find("@") == string::npos || emailChecker.find(".") == string::npos)
        {
            cout<<"Invalid email! \n";
            cout<<"Enter correct email: ";
            cin>>emailChecker;
            checkEmail();
        }      
    }

    void updUserRec()
    {
        ofstream output;
        output.open("/home/faiz/Desktop/C++/Project/record.txt", ios::app);

        // Getting Username
        cout << "Enter username: " << endl;
        cin >> uName;

        // Getting password
        cout << "Enter password: " << endl;
        cin >> pass;

        //Getting name
        cout << "Enter name: " << endl;
        cin >> name;

        //Getting email
        cout << "Enter email: " << endl;
        cin >> emailChecker;
        checkEmail();

        //Getting gender
        cout << "Enter gender: " << endl;
        cin >> gender;

        //Getting phone number
        cout << "Enter phone number: " << endl;
        cin >> phone;

        //Writing data in file
        output << endl
               << "Username: " << uName << endl
               << "Password: " << pass << endl
               << "Name: " << name << endl
               << "Password: " << pass << endl
               << "Email: " << email << endl
               << "Gender: " << gender << endl
               << "Phone: " << phone << endl;
        output.close();
        cout << "Registration complete!" << endl;
    }
    void verifyAccount()
    {
        updUserRec();
        //  login

        ifstream input("/home/faiz/Desktop/C++/Project/record.txt");

        if (!input)
        {
            cout << "Error creating file!";
        }

        cout << "Enter username:" << endl;
        cin >> logname;
        cout << "Enter password:" << endl;
        cin >> logpass;

        if (uName == logname && pass == logpass)
        {
            // input??uName trying to get to the file and read the already entered uName and match with the current entered name by user, same with pass
            cout << "Login successful" << endl;
            cout << "\n*Welcome To your Account*\nEnter The Option Number You want to Perform \n1) Customer \n2) Account \n3) ATM\n";
            cin >> selOpt;
        }
        else
        {
            cout << "Login failed!" << endl;
        }

        input.close();
    }
};

//**ATM CLASS**//
class ATM : public BANK
{
protected:
    string changepin, Y;
    int amount = 50000, ejected, added;

public:
    void display_screen()
    {
        cout << "\n*Welcome to ATM*" << endl;
    }
    void eject_cash()
    {
        cout << "Enter the amount you want to eject: ";
        cin >> ejected;
        amount = amount - ejected;
        cout << "You have ejected the cash amount: " << ejected << endl;
        cout << "Amount left in account: " << amount << endl;
    }
    void change_pin()
    {
        cout << "If you want to change password choose yes (Y/N): ";
        cin >> changepin;
        if (changepin == "Y" || changepin == "y")
        {
            cout << "Enter new password: ";
            cin >> pass;
            cout << "Your password has been changed\n";
        }
    }
    void verify_pin()
    {
        cout << "--------Welcome to your account--------\n";
        change_pin();
        cout << "You have " << amount << " in your account\n";
        eject_cash();
    }
};

//**ACCOUNT CLASS**//
class ACCOUNT
{
protected:
    float accBal;
    string accHolder, updAcc, deleteAcc;
    int accNum;

public:
    void editAcc()
    {
        cout << "Enter New Account Holder name: ";
        cin >> accHolder;
        accHolder = accHolder;
        cout << "Enter Your New Account Number: ";
        cin >> accNum;
        accNum = accNum;
        cout << "Enter the New Money you want to deposit: ";
        cin >> accBal;
        accBal = accBal;
        cout << "The account has been updated with name " << accHolder << "\nThe account number is " << accNum << "\nTotal Amount is " << accBal << endl;
    }
    void delAcc()
    {
        accBal = 0;
        accHolder = "";
        accNum = 0;
        cout << "**ACCOUNT HAS BEEN DELETED**" << endl;
    }
    void addAcc()
    {
        cout << "Enter Account Holder name: ";
        cin >> accHolder;
        cout << "Enter Your Account Number: ";
        cin >> accNum;
        cout << "Enter the Money you want to deposit: ";
        cin >> accBal;
        cout << "The account has been created with name " << accHolder << "\nThe account number is " << accNum << "\nTotal Amount is " << accBal << endl;
        cout << "Do you want to update your account details? (Y/N): ";
        cin >> updAcc;
        if (updAcc == "Y" || updAcc == "y")
        {
            editAcc();
        }
        cout << "Do you want to Delete your account details? (Y/N): ";
        cin >> deleteAcc;
        if (deleteAcc == "Y" || deleteAcc == "y")
        {
            delAcc();
        }
    }
};

//**SAVING ACCOUNT CLASS**//
class SAVING_ACCOUNT : public ACCOUNT
{
protected:
    string accTitle = "Saving account";

public:
    void addAcc()
    {
        cout << "*You are creating a saving account...*\n";
        ACCOUNT::addAcc();
    }
};

//**CURRENT ACCOUNT CLASS**//
class CURRENT_ACCOUNT : public ACCOUNT
{
protected:
    string accTitle = "Current account";

public:
    void addAcc()
    {
        cout << "*You are creating a current account...*\n";
        ACCOUNT::addAcc();
    }
};

//**CUSTOMER CLASS**//
class CUSTOMER
{
protected:
    string customer_name, customer_pass, acctype, edit_details;
    int customer_id, card_num, deposit, withdraw;

public:
    void withdrawal()
    {
        cout << "* WELCOME TO CASH WITHDRAWAL SECTION *" << endl;
        cout << "Enter the amount you want to withdraw: ";
        cin >> withdraw;
        deposit = deposit - withdraw;
        cout << "You have ejected the cash amount: " << withdraw << endl;
        cout << "Amount left in account: " << deposit << endl;

        if (withdraw > deposit)
        {
            cout << "Insufficient balance " << endl;
        }
        else
        {
            cout << "Withdrawal successful" << endl;
        }
    }
    void depositcash()
    {
        cout << "*WELCOME TO CASH DEPOSIT SECTION*" << endl;
        cout << "Enter the cash you want to deposit: ";
        cin >> deposit;
        cout << "\n\n Cash deposit of amount " << deposit << " successful " << endl;
    }
    void edit()
    {
        cout << "Enter customer name: ";
        cin >> customer_name;
        customer_name = customer_name;
        cout << "Enter customer id: ";
        cin >> customer_id;
        customer_id = customer_id;
        cout << "Enter account type(S/C): ";
        cin >> acctype;
        acctype = acctype;
    }
    void edit_detail()
    {
        cout << "*WELCOME TO ACCOUNT UPDATION SECTION*" << endl;
        cout << "Do you want to update your account details?(Y/N): ";
        cin >> edit_details;
        if (edit_details == "Y" || edit_details == "y")
        {
            edit();
        }
    }
    void display()
    {
        cout << "*THIS IS THE BANK STATEMENT FOR YOUR " << acctype << "ACCOUNT*" << endl;
        cout << "THE NAME OF THE BANK ACCOUNT HOLDER IS: " << customer_name << endl;
        cout << "THE CUSTOMER ID FOR " << customer_name << " is :" << customer_id << endl;
        cout << "YOUR ACCOUNT TYPE IS " << acctype << endl;
        cout << "Current deposit in your account is: " << deposit << endl;
        cout << "You have withdrawal an amount of:  " << withdraw << endl;
    }
    void createAcc()
    {
        cout << "*Enter your details to create an account*: " << endl;
        cout << "Enter the name as per your national identity card: " << endl;
        cin >> customer_name;
        cout << "Please enter your bank account number: " << endl;
        cin >> customer_id;
        cout << "Please enter the type of bank account(Savings/Current): " << endl;
        cin >> acctype;
        depositcash();
        withdrawal();
        edit_detail();
        display();
    }
};

//**MAIN**//
int main()
{
    string cont, accType;
    BANK B1;
    CUSTOMER C1;
    ATM A1;
    SAVING_ACCOUNT SA1;
    CURRENT_ACCOUNT CA1;
    cout << "******* WELCOME TO THE BANKING MANAGEMENT SYSTEM ********" << endl;
    cout << "*******     HOPE YOU WILL ENJOY OUR SERVICES     ********" << endl;
    B1.verifyAccount();
    if (B1.selOpt == "CUSTOMER" || B1.selOpt == "customer" || B1.selOpt == "Customer" || B1.selOpt == "1")
    {
        C1.createAcc();
    }
    else if (B1.selOpt == "ACCOUNT" || B1.selOpt == "account" || B1.selOpt == "Account" || B1.selOpt == "2")
    {
        cout << "Which type of account do you want to create? \n1) Saving Account (Write: 1) \n2) Current Account (Write: 2)\n ";
        cin >> accType;
        if (accType == "1")
        {
            SA1.addAcc();
        }
        else if (accType == "2")
        {
            CA1.addAcc();
        }
        else
        {
            cout << "Invalid input!!";
        }
    }
    else if (B1.selOpt == "ATM" || B1.selOpt == "atm" || B1.selOpt == "Atm" || B1.selOpt == "3")
    {
        A1.display_screen();
        A1.verify_pin();
    }
    else
    {
        cout << "Invalid input!!";
    }
    cout << "\nContinue using bank? (Y/N): ";
    cin >> cont;
    if (cont == "Y" || cont == "y")
    {
        B1.verifyAccount();
    }
    return 0;
}
