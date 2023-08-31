#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>

const double interestrate = 0.2;
double remaining_amount;
double Total;

using namespace std;

class office {
public:
    void processOrder() {
        double amountPaid;
        cout << "\n";
        cout << "THE AMOUNT BEING PAID: ";
        cin >> amountPaid;
        cout << "payment: " << amountPaid << endl;
        remaining_amount = Total - amountPaid;
        cout << "THE LOAN LEFT TO BE PAID: " << remaining_amount << endl;
    }

    void storeInfo(const string& Fname, const string& Sname, const string& work,
                   const string& address, const string& location, const string& phoneNumber) {
        ofstream file("loan.txt");
        if (file.is_open()) {
            file << "\n--------INFORMATION--------" << endl;
            file << "First Name\t\t" << Fname << endl;
            file << "Second Name\t\t" << Sname << endl;
            file << "Place of Work\t\t" << work << endl;
            file << "Address\t\t" << address << endl;
            file << "Location\t\t" << location << endl;
            file << "Phone Number\t\t" << phoneNumber << endl;
            file << "amountAwarded\t$" << Total << endl;
            file << "amountPaid\t" << Total - remaining_amount << endl;
            file << "amountRemaining to be Paid\t" << remaining_amount << endl;
            file.close();

            cout << "\nReceipt has been stored in loan.txt\n" << endl;
        } else {
            cout << "Unable to create the receipt file." << endl;
        }
    }
};

class customer {
public:
    void determine() {
        string Fname, Sname, work, address, location, phoneNumber;
        double requiredAmount, amountAwarded;

        cout << "YOUR FIRST NAME: ";
        cin >> Fname;
        cout << "YOUR SECOND NAME: ";
        cin >> Sname;
        cout << "YOUR TYPE OF WORK: ";
        cin.ignore();  // Clear newline from previous input
        getline(cin, work);
        cout << "YOUR ADDRESS: ";
        getline(cin, address);
        cout << "YOUR LOCATION: ";
        getline(cin, location);
        cout << "YOUR PHONE NUMBER: ";
        cin >> phoneNumber;
        cout << "AMOUNT REQUIRED: ";
        cin >> requiredAmount;

        if (requiredAmount <= 10000) {
            amountAwarded = 10000;
        } else if (requiredAmount > 10000 && requiredAmount <= 20000) {
            amountAwarded = 20000;
        } else if (requiredAmount > 20000 && requiredAmount <= 30000) {
            amountAwarded = 25000;
        } else {
            cout << "ENTER VALID DETAILS" << endl;
        }

        cout << "\nTHE AMOUNT AWARDED: $" << amountAwarded << endl;
        Total = amountAwarded + (amountAwarded * interestrate);

        office dataInf;
        dataInf.storeInfo(Fname, Sname, work, address, location, phoneNumber);
        customer cust;
        cust.display(Fname, Sname, work, address, location, phoneNumber);
    }

    void display(const string& Fname, const string& Sname, const string& work,
                 const string& address, const string& location, const string& phoneNumber) {
        double total = remaining_amount;
        cout << "--------INFORMATION--------" << endl;
        cout << "First Name\t\t" << Fname << endl;
        cout << "Second Name\t\t" << Sname << endl;
        cout << "Place of Work\t\t" << work << endl;
        cout << "Address\t\t\t" << address << endl;
        cout << "Location\t\t" << location << endl;
        cout << "Phone Number\t\t" << phoneNumber << endl;
        cout << "amountAwarded\t\t$" << Total << endl;
        cout << "amountRemaining to be Paid\t" << remaining_amount << endl;
    }
};

class admin {
private:
    double amountPaid;
    double amountAwarded;
    string password = "123";

public:
    void declarePaymentApproved() {
        cout << " Enter the password: ";

        // Use getch() to read the password without displaying it on the screen
        char ch;
        password = "";
        while ((ch = _getch()) != '\r') { // Read characters until Enter (carriage return) is pressed
            password.push_back(ch);
            cout << "*"; // Display asterisks for each character entered
        }
        cout << endl;

        if (password == "123") {
            if (amountPaid == amountAwarded) {
                cout << "LOAN PAID" << endl;
            } else {
                cout << "PAYMENT NOT COMPLETED";
            }
        } else {
            cout << "Enter the valid password";
        }
    }
};

int main() {
    string password;
    string role;
    cout << "---------------WELCOME TO STRAIGHTFORWARD CREDITS---------------\n";
    cout << "1.LOG-IN AS AN ('admin')\n";
    cout << "2.LOG-IN FOR A CLIENT ('client')\n";
    cout << "3.LOG-IN FOR PAYMENT ('pay')\n";
    cin >> role;

    if (role == "client") {
        customer cust;
        cust.determine();
    } else if (role == "pay") {
        office dataInf;
        dataInf.processOrder();
        dataInf.storeInfo("", "", "", "", "", "");
    } else if (role == "admin") {
        admin adInf;
        adInf.declarePaymentApproved();
    }

    return 0;
}
