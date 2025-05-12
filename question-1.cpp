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
public:
    void setDetails()
    {
        cout << "Enter Account Number :- ";
        cin >> this->accountNumber;
        cin.ignore();
        cout << endl << "Enter Account Holder Name :- ";
        getline(cin, accountHolderName);
        cout << "Enter Account Balance :- ";
        cin >> this->accountBalance;
    }

    void deposit()
    {
        cout << endl;
        cout << "Enter A Amount To Deposit :- ";
        cin >> this->deposit_amount;
        accountBalance = accountBalance + deposit_amount;
    }
    void withdraw()
    {
        cout << endl;
        cout << "Enter A Amount To Withdraw :- ";
        cin >> this->withdraw_amount;
        accountBalance = accountBalance - withdraw_amount;
    }
    double getBalance()
    {
        return accountBalance;
    }
    void displayAccountInfo()
    {
        cout << endl;
        cout << "Account Number :- " << accountNumber << endl;
        cout << "Account Holder Name :- " << accountHolderName << endl;
        cout << "Account Balance :- " << accountBalance << endl;
        cout << endl;
    }
};

class SavingAccount : public BankAccount 
{
public:
    double intrest_rate;

    void calculateIntrest()
    {
        cout << endl;
        intrest_rate = (accountBalance * 0.05) / 100;
        cout << "Your Bank Is Providing "<< intrest_rate <<" Rupees Of Intrest." << endl;
        cout << endl;
    }
};

class CheckingAccount : public BankAccount
{
public:
    double overDraftLimit = 5000;
    void DraftCheaker()
    {
        if (accountBalance < overDraftLimit)
        {
            cout << endl;
            cout << endl << "You Have Exceeced The Draft Limit.." << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << "You Haven't Exceeced The Draft Limit..";
            cout << endl;
        }
    }
};

class FixedDepositAmount : public BankAccount 
{
public:
    int term;
    float fixed_deposit_intrest;
    void calculateIntrest()
    {
        cout << "Enter Time Duration (In Month's) :- ";
        cin >> term;
        fixed_deposit_intrest = (accountBalance * 0.02);
        cout << endl;
        cout << "Your Bank Will Provide "<< fixed_deposit_intrest <<" Rupees Of Intrest In "<< term <<" Months." << endl;
        cout << endl;
    }
};

int main()
{
    BankAccount obj;
    obj.setDetails();

    SavingAccount Myobj_2;
    CheckingAccount Myobj_3;
    FixedDepositAmount Myobj_4;

    int main_choice;
    cout << endl << "----- Welcome To Our Bank -----" << endl;
    do
    {
        cout << endl << "Press 1 For Deposit / Withdraw Or Account Details" << endl;
        cout << "Press 2 For Saving Accounts" << endl;
        cout << "Press 3 For Over draft Checking" << endl;
        cout << "Press 4 For FD (Fixed Deposit)" << endl;
        cout << "Press 0 To Exit" << endl;
        cout << "Enter your Choice :- ";
        cin >> main_choice;

        switch (main_choice)
        {
            case 0:
                cout << endl << "---- Program Is Scucessfully Exited----" << endl;
                break;
            case 1:
                int choice_1;
                do
                {
                    cout << endl << "Press 1 To Deposit" << endl;
                    cout << "Press 2 To Withdraw" << endl;
                    cout << "Press 3 To Check Balance" << endl;
                    cout << "Press 4 For Account Details" << endl;
                    cout << "Press 0 To Exit" << endl;
                    cout << "Enter your Choice :- ";
                    cin >> choice_1;
                    cout << endl;

                    switch (choice_1)
                    {
                    case 0:
                        cout << endl << "---- Exited Scucessfully ----";
                        break;
                    case 1:
                        obj.deposit();
                        break;
                    
                    case 2:
                        obj.withdraw();
                        break;

                    case 3:
                        cout << "Current Balance :- " << obj.getBalance() << endl;
                        break;
                    
                    case 4:
                        obj.displayAccountInfo();
                        break;

                    default:
                        cout << "Sorry Wrong Choice." << endl;
                        break;
                    }
                } 
                while 
                (choice_1 != 0);
                break;
            case 2:
                Myobj_2.calculateIntrest();
                break;   

            case 3:
                Myobj_3.DraftCheaker();
                break;   

            case 4:
                Myobj_4.calculateIntrest();
                break;   

            default:
                cout << "Sorry Wrong Choice." << endl;
                break;
        }
    } while (main_choice !=0);
    
    return 0;
}