#include <bits/stdc++.h>
using namespace std;

int randomNum() {
    return rand() % 10;
}

class Card
{
protected:
    string cardNo;
    int cvv;
    string bankName;

public:
    Card()
    {
        for (int x=0; x<16; x++)
            cardNo.append(to_string(randomNum()));

        string temp = "";
        for (int x=0; x<3; x++)
            temp.append(to_string(randomNum()));
        
        cvv = stoi(temp);
    }    

    friend int randomNum();

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
        expDate.append("/");
        expDate.append(to_string(year).substr(2, 4));
        return expDate;
    }
};

class CreditCard : public Card
{
public:
    int spendLimit;
    string expiryDate;

    CreditCard()
    {
        expiryDate = expireDate();
        cout << expiryDate;
    }
    void displayCard() {
        cout << "Card No: " << cardNo << endl;
        cout << "CVV: " << cvv << endl;
        cout << "Exp Date: " << expiryDate << endl;
    }
};


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