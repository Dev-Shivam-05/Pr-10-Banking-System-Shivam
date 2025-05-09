#include<iostream>
using namespace std;

class BankAccount
{
public:
    int accountNumber;
    string accountHolderName;
    double accountBalance;
    double deposit_amount;
    double withdraw_amount;
    double total_withdraw_amount = 0;
public:
    BankAccount()
    {
        cout << "Enter Account Number :- ";
        cin >> this->accountNumber;
        cin.ignore();
        cout << endl << "Enter Account Holder Name :- ";
        getline(cin, accountHolderName);
        cout << endl << "Enter Account Balance :- ";
        cin >> this->accountBalance;
    }

    void deposit(double deposit_amount)
    {
        cout << "Enter A Amount To Deposit :- ";
        cin >> this->deposit_amount;
        accountBalance = accountBalance + deposit_amount;
    }
    void withdraw(double withdraw_amount)
    {
        cout << "Enter A Amount To Withdraw :- ";
        cin >> this->withdraw_amount;
        total_withdraw_amount += withdraw_amount;
        accountBalance = accountBalance - withdraw_amount;
    }
    void getBalance()
    {
        cout << "Current Balance :- " << accountBalance << endl;
    }
    void displayAccountInfo()
    {
        cout << endl;
        cout << "Account Number :- " << accountNumber << endl;
        cout << "Account Holder Name :- " << accountHolderName << endl;
        cout << "Account Balance :- " << accountBalance << endl;
    }
};

class SavingAccount : public BankAccount 
{
protected:
    double intrestRate;

public:
    void calculateIntrest()
    {
        intrestRate = (accountBalance * 0.05) / 100;
        cout << "Your Bank Is Providing "<< intrestRate <<" Rupeess Of Intrest. " << endl;
    }
};

class CheckingAccount : public BankAccount
{
public:
    double overDraftLimit = 500000;
    void DraftCheaker()
    {
        if (total_withdraw_amount > overDraftLimit)
        {
            cout << endl << "You Have Exceeced The Draft Limit.." << endl;
        }
        else
        {
            cout << "You Haven't Exceeced The Draft Limit..";
        }
    }
};

class FixedDepositAmount : public BankAccount
{
public:
    int term;
    double Fixed_Deposite_Intrest;
    void calculateIntrest()
    {
        cout << "Enter Terms (Time Duration In Months) :- ";
        cin >> term;
        Fixed_Deposite_Intrest = (accountBalance * 0.02);
        cout << "Your Bank Is Providing "<< Fixed_Deposite_Intrest <<" Rupees Of Intrest.";
    }
};

int main()
{
    FixedDepositAmount obj3;
    obj3.calculateIntrest();
    return 0;
}