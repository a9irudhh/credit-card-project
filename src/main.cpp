#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int randomGen() {
    random_device rd; // Obtain a random number from hardware
    mt19937 eng(rd()); // Seed the generator
    uniform_int_distribution<> distr(0, 9); // Define the range

    return distr(eng); // Generate and return the number
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
        cardNo;
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
};

int main()
{
    // expiryDate();
    // CreditCard c;
    cout << randomGen();
}