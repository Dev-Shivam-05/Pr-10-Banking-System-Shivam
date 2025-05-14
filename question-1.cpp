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
    int account_Type;

public:
    void setDetails()
    {
        cout << "Enter Account Number :- ";
        cin >> this->accountNumber;
        if (accountNumber <= 0)
        {
            cout << "Account Number Should Be Positive"<< endl;
            cout << "Please Enter A Valid Account Number :- ";
            cin >> this->accountNumber;
        }
        
        cin.ignore();
        cout << "Enter Account Holder Name :- ";
        getline(cin, accountHolderName);
        
        cout << "Enter Account Type :- " << endl << "Saving Account Enter : 1," << endl << "Current Account Enter 2," << endl << "Fixed Deposit Account Enter : 3," << endl << "Enter Your Choice :- ";
        cin >> account_Type;
        if (account_Type == 1 || account_Type == 2 || account_Type == 3)
        {             
            cout << "Enter Initial Account Balance :- ";
            cin >> this->accountBalance;
            
            while (accountBalance <= 0)
            {
                cout << "Account Balance Should Be Positive"<< endl;
                cout << "Please Enter A Valid Account Balance :- ";
                cin >> this->accountBalance;
            }
        }
        else
        {
            cout << "Invalid Account Type. Try Again." << endl;
        }

        switch (account_Type)
        {
            case 1:
                cout << "---- Saving Account Is Successfully Created. ----" << endl;        
                break;
            
            case 2:
                cout << "---- Current Account is Successfully Created. ----" << endl;
                break;
            case 3:
                cout << "---- Fixed Deposit Account is Successfully Created. ----" << endl;
                break;
            
            default:
                while (accountBalance <= 0)
                {
                    cout << "Account Must be Between (1-3) : "<< endl;
                    cout << "Please Enter A Valid Account Type :- ";
                    cin >> this->account_Type;
                }
                break;
        }
    }

    void deposit()
    {
        cout << "Enter A Amount To Deposit :- ";
        cin >> this->deposit_amount;
        while (deposit_amount <= 0)
        {
            cout << "Deposit Amount Should Be Positive"<< endl;
            cout << "Please Enter A Valid Deposit Amount :- ";
            cin >> this->deposit_amount;
        }
        accountBalance += deposit_amount;
    }

    void withdraw()
    {
        cout << "Enter A Amount To Withdraw :- ";
        cin >> this->withdraw_amount;

        while (withdraw_amount <= 0)
        {
            cout << "Withdraw Amount Must be Positive Or Greater Than 0"<< endl;
            cout << "Please Enter A Valid Withdraw Amount :- ";
            cin >> this->withdraw_amount;
        }
        accountBalance -= withdraw_amount;
        cout << "Withdraw Successfully... Current Balance Is :- " << accountBalance << endl;
    }

    double getBalance()
    {
        return accountBalance;
    }

    void displayAccountInfo()
    {
        cout << "Account Number :- " << accountNumber << endl;
        cout << "Account Holder Name :- " << accountHolderName << endl;
        cout << "Account Balance :- " << accountBalance << endl;
    }
};

class SavingAccount : public BankAccount 
{
private:
    double intrest_rate;

public:
    void calculateIntrest()
    {
        intrest_rate = (accountBalance * 0.05);
        cout << "Your Bank Is Providing " << intrest_rate << " Rupees Of Interest. Updated Balance: " << accountBalance << endl;
        accountBalance += intrest_rate;
    }
};

class CheckingAccount : public BankAccount
{
public:
    double overDraftLimit = 50000;

    void DraftCheaker()
    { 
        if (accountBalance > overDraftLimit)
        {       
            cout << "You Have Exceeded The Draft Limit. Your Current Balance Is: " << accountBalance << endl;
        }
        else
        {
            cout << "You Haven't Exceeded The Draft Limit. Your Current Balance Is: " << accountBalance << endl;
        }
    }
};

class FixedDepositAmount : public BankAccount 
{
public:
    double term, fixed_deposit_intrest = 0.15, intrest;

    void calculateIntrest()
    {
        intrest = (accountBalance * fixed_deposit_intrest) * term;
        cout << "Your Bank Will Provide " << intrest << " Rupees Of Interest In " << term << " Months. Updated Balance: " << accountBalance << endl;
        accountBalance += intrest;
    }
};
int main()
{
    cout << endl << "----- Welcome To Our Bank -----" << endl << endl;
    BankAccount obj;
    obj.setDetails();

    SavingAccount Myobj_2;                                                                                                                   
    CheckingAccount Myobj_3;
    FixedDepositAmount Myobj_4;

    if (obj.account_Type == 1)
    {
        int choice_S;
        do
        {
            cout << endl << "---- Welcome To Saving Account Services ----";
            cout << endl << "Press 1 To Deposit" << endl;
            cout << "Press 2 To Withdraw" << endl;
            cout << "Press 3 To Calculate Interest" << endl;
            cout << "Press 4 To Check Balance" << endl;
            cout << "Press 5 For Account Details" << endl;
            cout << "Press 0 To Exit" << endl;
            cout << "Enter your Choice :- ";
            cin >> choice_S;
            cout << endl;

            switch (choice_S)
            {
                case 0:
                    cout << "---- Exited Successfully ----";
                    break;
                case 1:
                    obj.deposit();
                    break;
                case 2:
                    obj.withdraw();
                    break;
                case 3:
                    Myobj_2.accountBalance = obj.getBalance();  
                    Myobj_2.calculateIntrest();
                    break;
                case 4:
                    cout << "Current Balance :- " << obj.getBalance() << endl;
                    break;
                case 5:
                    obj.displayAccountInfo();
                    break;
                default:
                    cout << "Sorry, Wrong Choice." << endl;
                    break;
            }
        } while (choice_S != 0);
    }
    else if (obj.account_Type == 2)
    {
        int choice_C;
        do
        {
            cout << endl << "---- Welcome To Current Account Services ----";
            cout << endl << "Press 1 To Deposit" << endl;
            cout << "Press 2 To Withdraw" << endl;
            cout << "Press 3 To Check Overdraft" << endl;
            cout << "Press 4 To Check Balance" << endl;
            cout << "Press 5 For Account Details" << endl;
            cout << "Press 0 To Exit" << endl;
            cout << "Enter your Choice :- ";
            cin >> choice_C;
            cout << endl;

            switch (choice_C)
            {
                case 0:
                    cout << "---- Exited Successfully ----";
                    break;
                case 1:
                    obj.deposit();
                    break;
                case 2:
                    obj.withdraw();
                    break;
                case 3:
                    Myobj_3.accountBalance = obj.getBalance();
                    Myobj_3.DraftCheaker();
                    break;
                case 4:
                    cout << "Current Balance :- " << obj.getBalance() << endl;
                    break;
                case 5:
                    obj.displayAccountInfo();
                    break;
                default:
                    cout << "Sorry, Wrong Choice." << endl;
                    break;
            }
        } while (choice_C != 0);
    }
    else if (obj.account_Type == 3)
    {
        int choice_F;
        cout << "Enter Time Duration Of Your Fixed Deposit Account (In Months) :- ";
        cin >> Myobj_4.term;

        do
        {
            cout << endl << "---- Welcome To Fixed Deposit Account Services ----";
            cout << endl << "Press 1 To Deposit" << endl;
            cout << "Press 2 To Withdraw" << endl;
            cout << "Press 3 To Calculate Interest" << endl;
            cout << "Press 4 To Check Balance" << endl;
            cout << "Press 5 For Account Details" << endl;
            cout << "Press 0 To Exit" << endl;
            cout << "Enter your Choice :- ";
            cin >> choice_F;
            cout << endl;

            switch (choice_F)
            {
                case 0:
                    cout << "---- Exited Successfully ----";
                    break;
                case 1:
                    obj.deposit();
                    break;
                case 2:
                    cout << "You can't withdraw before the term period ends." << endl;
                    break;
                case 3:
                    Myobj_4.accountBalance = obj.getBalance();
                    Myobj_4.calculateIntrest();
                    break;
                case 4:
                    cout << "Current Balance :- " << obj.getBalance() << endl;
                    break;
                case 5:
                    obj.displayAccountInfo();
                    break;
                default:
                    cout << "Sorry, Wrong Choice." << endl;
                    break;
            }
        } while (choice_F != 0);
    }

    return 0;
}
