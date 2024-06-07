#include <bits/stdc++.h>
using namespace std;

class CardHolder
{
    string name;
    string address;
    string email;
    string phoneNo;

    public :
    CardHolder(string name, string address, string email, string phoneNo)
    {
        this->name = name;
        this->address = address;
        this->email = email;
        this->phoneNo = phoneNo;
    }

};

void viewMenu()
{

    return;
}

void newUserMenu()
{
    
    return;
}
int main()
{
    while (true)
    {
        int ch;
        viewMenu();
        cin >> ch;

        switch (ch)
        {
        case 0:
            cout << "Shutting Down" << endl;
            exit(0);
            break;
        case 1:
            //New user
            newUserMenu();
            

            break;
        case 2:
            //renewal or replacement
            break;
        case 3:
            // transaction
            break;
        case 4:
            // monthly statement generation
        default:
            break;
        }
    }
    return 0;
}