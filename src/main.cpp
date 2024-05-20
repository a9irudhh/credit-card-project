#include <iostream>
#include <ctime>
#include <random>

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

int main()
{
    srand(time(NULL));
    // expiryDate();
    CreditCard c;
    c.displayCard();
}