#include <bits/stdc++.h>
using namespace std;

int randomNum() {
    return rand() % 10;
}

class INVALID_PIN: public runtime_error {
    public:
        INVALID_PIN(): runtime_error("PIN entered is not in format") {}
};

class INCORRECT_PIN_ERROR: public runtime_error {
    public:
        INCORRECT_PIN_ERROR(): runtime_error("PIN Mismatch") {}
};

class INSUFFICIENT_BALANCE: public runtime_error {
    public:
        INSUFFICIENT_BALANCE(): runtime_error("Insufficient Amount") {}
};


class Transaction {
    public:
        string To;
        double amt;
        
        Transaction(string receiver, double amount): To(receiver),amt(amount) {}
};


class CreditCard {
    protected:
        string cardNo;
        int cvv;
        string bankName;
        int PIN;

    public:
        double spendLimit;
        double outstandingBalance;
        string expiryDate;
        int multipler;
        vector <Transaction> statement;

    friend int randomNum();

    CreditCard(string bName)
    {
        //Name of Bank
        bankName = bName;
        PIN = -1;

        //CARD NUMBER GENERATION
        for (int x=0; x<16; x++)
            cardNo.append(to_string(randomNum()));

        //CVV GENERATION
        string temp = "";
        for (int x=0; x<3; x++)
            temp.append(to_string(randomNum()));
        cvv = stoi(temp);

        
        //EXPIRE DATE
        expiryDate = expireDate();
    }

    void displayCard() {
        cout << "Card No: " << cardNo << endl;
        cout << "CVV: " << cvv << endl;
        cout << "Exp Date: " << expiryDate << endl;
    }


    void genaratePIN() {
        // code to generate pin for credit card
        // change the pin
        int tempPIN;

        if(PIN == -1) {
            try {
                cout << "Enter New PIN: " << endl;
                cin >> tempPIN;
                if(PIN<1000 || PIN>9999) 
                    throw INVALID_PIN();           //EXCEPTION EXCEPTION EXCEPTION
                else {
                    PIN = tempPIN;
                }
            }
            catch(INVALID_PIN& e) {
                cout << e.what() << endl;
            }
        }
        else {
            cout << "PIN ALREADY GENERATED" << endl;
        }
    }

    void changePIN() {
        int tempPIN;
            try {
                cout << "Enter Current PIN: ";
                cin >> tempPIN;
                if(PIN != tempPIN) 
                    throw INCORRECT_PIN_ERROR();    
                else {
                    cout << "Enter New PIN: ";
                    cin >> tempPIN;
                    if(PIN<1000 || PIN>9999) 
                        throw INVALID_PIN();        
                    else {
                        PIN = tempPIN;
                    }
                }
            }
            catch(INCORRECT_PIN_ERROR& e) {
                cout << e.what() << endl;
            }
            catch(INVALID_PIN& e) {
                cout << e.what() << endl;
            }
    }

    string expireDate()
    {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        int year = 1900 + ltm->tm_year + 5; // assuming the credit card validity is 5 years;
        int month = 1 + ltm->tm_mon;

        string expDate;

        if (month < 10)
        {
            expDate = "0" + to_string(month);
        }
        else
        {
            expDate = to_string(month);
        }
        expDate.append("/"); // expDate += '/';
        expDate.append(to_string(year).substr(2, 4));
        return expDate;
    }

};

class SilverCard: public CreditCard {
    public:
        string cName;
        int rewardPoints;

        SilverCard() {
            cName = "Silver Card";
            multipler = 0.01;
            rewardPoints = 0;
        }
};

class GoldCard: public CreditCard {
    public:
        string cName;
        int rewardPoints;

        GoldCard() {
            cName = "Gold Card";
            multipler = 0.02;
            rewardPoints = 0;
        }
};


class PlatinumCard: public CreditCard {
    public:
        string cName;
        double multipler;
        int rewardPoints;

        PlatinumCard() {
            cName = "Platinum Card";
            multipler = 0.05;
            rewardPoints = 0;
        }
};

class CardHolder {
    public:
        string name;
        string address;
        string email;
        string phoneNo;
        vector<CreditCard> Cards;
        CreditCard* CurrCard;
        int creditScore;

        CardHolder(string n, string a, string e, string p, int c): name(n), address(a), email(e), phoneNo(p), creditScore(c) {}
        {
            if(c>800)
                //allocate platinmum
            else if(c>675)
                //allocate gold
            else
                //allocate silver

            // add the card to Cards vector as well
        }

        void pay(string receiver, double amt) {
            try {
                if(CurrCard->outstandingBalance + amt <= CurrCard->spendLimit) {
                    CurrCard->outstandingBalance += amt;
                    CurrCard->statement.pushback(Transaction(receiver,amt));
                }
                else {
                    throw INSUFFICIENT_BALANCE();
                }
            }
            catch(INSUFFICIENT_BALANCE& e) {
                cout << "Available Limit: " << CurrCard->spendLimit - CurrCard->outstandingBalance << endl;
                cout << e.what() << endl;
            }
        }

}


class cardHolder
{
    string name;
    string address;
    string email;
    string phoneNo;
    Card card;

    public :
    cardHolder(string name, string address, string email, string phoneNo)
    {
        this->name = name;
        this->address = address;
        this->email = email;
        this->phoneNo = phoneNo;
    }

    int addCard()
    {
        return 0;
    }

    int removeCard()
    {
        return 0;
    }

    void viewTransactions()
    {
    }
};

class Bank
{
    string name;
    string address;
    string email;
    string phoneNo;
    string ifsc;

    public :
    Bank(string name, string address, string email, string phoneNo)
    {
        this->name = name;
        this->address = address;
        this->email = email;
        this->phoneNo = phoneNo;
    }

    int authorizeTransaction()
    {
        return 0;
    }

    int authorizeRefund()
    {
        return 0;
    }

    int authorizeCard()
    {
        return 0;
    }

    int addCardHolder()
    {
        return 0;
    }

    int removeCardHolder()
    {
        return 0;
    }

    void viewTransactions()
    {
    }
};

class Merchant
{
    string name;
    string address;
    string email;
    string phoneNo;
    vector<cardHolder> cardHolders;

    public :
    Merchant(string name, string address, string email, string phoneNo)
    {
        this->name = name;
        this->address = address;
        this->email = email;
        this->phoneNo = phoneNo;
    }

    int initiateTransaction()
    {
        return 0;
    }

    int verifyMerchant()
    {
        return 0;
    }
};


class Transactions{
    string transactionId;
    string transactionDate;
    string transactionTime;
    string transactionType;
    string transactionAmount;
    string transactionStatus;
    
    public:
    Transactions(string transactionId, string transactionDate, string transactionTime, string transactionType, string transactionAmount, string transactionStatus){
        this->transactionId = transactionId;
        this->transactionDate = transactionDate;
        this->transactionTime = transactionTime;
        this->transactionType = transactionType;
        this->transactionAmount = transactionAmount;
        this->transactionStatus = transactionStatus;
    }

    int processTransaction()
    {
        return 0;
    }

    int validateTransaction()
    {
        return 0;
    }

};


int main()
{
    return 0;
}