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
    string account_Type;
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
        
        cout << "Enter Account Type For (Saving Account Enter : S , Current Account Enter C , Fixed Deposit Account Enter : F) :- ";
        cin >> account_Type;
        if (account_Type == "S" || account_Type == "C" || account_Type == "F")
        {             
            cout << "Enter Initial Account Balance :- ";
            cin >> this->accountBalance;
            
            if (accountBalance <= 0)
            {
                cout << "Account Balance Should Be Positive"<< endl;
                cout << "Please Enter A Valid Account Balance :- ";
                cin >> this->accountBalance;
            }
        }
        else
        {
            cout << endl << "Wrong Input";
        }
       
        if (account_Type == "S")
        {
            cout << endl << "Saving Account is Sucessfully Created." << endl;
        }
        else if (account_Type == "C")
        {
            cout << endl << "Current Account is Sucessfully Created." << endl;
        }
        else if (account_Type == "F")
        {
            cout << endl << "Fixed Deposite Account is Sucessfully Created." << endl;
        }
        
    }
    
    void deposit()
    {
        cout << endl;
        cout << "Enter A Amount To Deposit :- ";
        cin >> this->deposit_amount;
        if (deposit_amount <= 0)
        {
            cout << "Deposit Amount Should Be Positive"<< endl;
            cout << "Please Enter A Valid Deposit Amount :- ";
            cin >> this->deposit_amount;
        }
        accountBalance = accountBalance + deposit_amount;
    }
    void withdraw()
    {
        cout << endl;
        cout << "Enter A Amount To Withdraw :- ";
        cin >> this->withdraw_amount;

        if (withdraw_amount <= 0)
        {
            cout << "Withdraw Amount Must be Positive Or Greater Than 0"<< endl;
            cout << "Please Enter A Valid Withdraw Amount :- ";
            cin >> this->withdraw_amount;
        }
        accountBalance = accountBalance - withdraw_amount;
        cout << "Withdraw Sucessfully..." << endl << "Current Balance Is :- " << accountBalance;
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
private:
    float intrest_rate;
public:
    void calculateIntrest()
    {
        cout << endl;
        intrest_rate = (accountBalance * 0.05);
        cout << "Your Bank Is Providing "<< intrest_rate <<" Rupees Of Intrest." << endl;
        cout << endl;
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
            cout << endl;
            cout << endl << "You Have Exceeced The Draft Limit.." << endl;
            cout << endl;
        }
        else
        {
            cout << endl;
            cout << endl << "You Haven't Exceeded The Draft Limit." << accountBalance;
            cout << endl;
        }
    }
};

class FixedDepositAmount : public BankAccount 
{
public:
    int term;
    float fixed_deposit_intrest = 0.15,intrest;
    void calculateIntrest()
    {
        cout << "Enter Time Duration (In Month's) :- ";
        cin >> term;
        intrest = (accountBalance * fixed_deposit_intrest) * term;
        cout << endl;
        cout << "Your Bank Will Provide "<< (accountBalance * fixed_deposit_intrest) * term <<" Rupees Of Intrest In "<< term <<" Months." << endl;
        cout << endl;
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

    int main_choice;
    if (obj.account_Type == "S")
        {
            int choice_S;
            do
                {
                    cout << endl << "---- Welcome To Saving Account Services ----";
                    cout << endl << "Press 1 To Deposit" << endl;
                    cout << "Press 2 To Withdraw" << endl;
                    cout << "Press 3 To Calculate Intrest" << endl;
                    cout << "Press 4 To Check Balance" << endl;
                    cout << "Press 5 For Account Details" << endl;
                    cout << "Press 0 To Exit" << endl;
                    cout << "Enter your Choice :- ";
                    cin >> choice_S;
                    cout << endl;

                    switch (choice_S)
                    {
                    case 0:
                        cout << "---- Exited Scucessfully ----";
                        break;
                    case 1:
                        obj.deposit();
                        break;
                    
                    case 2:
                        obj.withdraw();
                        break;

                    case 3:
                        Myobj_2.calculateIntrest();
                        break;
                    
                    case 4:
                        cout << "Current Balance :- " << obj.getBalance() << endl;
                        break;
                        
                    case 5:
                        obj.displayAccountInfo();
                        break;
                        
                    default:
                        cout << "Sorry Wrong Choice." << endl;
                        break;
                    }
                } 
                while 
                (choice_S != 0);
            }
            else if (obj.account_Type == "C")
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
                            cout << "---- Exited Scucessfully ----";
                            break;
                        case 1:
                            obj.deposit();
                            break;
                        
                        case 2:
                            obj.withdraw();
                            break;
                        
                        case 3:
                            Myobj_3.DraftCheaker();
                            break;
                        
                        case 4:
                            cout << "Current Balance :- " << obj.getBalance() << endl;
                            break;
                        
                        case 5:
                            obj.displayAccountInfo();
                            break;
    
                        default:
                            cout << "Sorry Wrong Choice." << endl;
                            break;
                        }
                    } 
                    while 
                    (choice_C != 0);
                }
                else if (obj.account_Type == "F")
                {
                    int choice_F;
                    do
                        {
                            cout << endl << "---- Welcome To Fixed Account Services ----";
                            cout << endl << "Press 1 To Deposit" << endl;
                            cout << "Press 2 To Withdraw" << endl;
                            cout << "Press 3 To Calculate Intrest" << endl;
                            cout << "Press 4 To Check Balance" << endl;
                            cout << "Press 5 For Account Details" << endl;
                            cout << "Press 0 To Exit" << endl;
                            cout << "Enter your Choice :- ";
                            cin >> choice_F;
                            cout << endl;
        
                            switch (choice_F)
                            {
                            case 0:
                                cout << "---- Exited Scucessfully ----";
                                break;
                            case 1:
                                obj.deposit();
                                break;
                            case 2:
                                if (Myobj_4.term >= 12)
                                {
                                    cout << "You Can Withdraw Your Balance.";
                                }
                                else
                                {
                                    cout << "You Can't Withdraw Your Balance. Until 1 Year";
                                }
                                break;
                            case 3:
                                Myobj_4.calculateIntrest();
                                break;

                            case 4:
                                cout << "Current Balance :- " << obj.getBalance() << endl;
                                break;

                            case 5:
                                obj.displayAccountInfo();
                                break;

                            default:
                                cout << "Sorry Wrong Choice." << endl;
                                break;
                            }
                        } 
                        while 
                        (choice_F != 0);
                }    
    return 0;
}