#include <bits/stdc++.h>
using namespace std;


int main()
{
    int choice;
    do
    {
        // viewMenu();
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Shutting Down.." << endl;
            break;
        case 1:
            // New user
            // newUserMenu();

            break;
        case 2:
            // renewal or replacement
            // replacementMenu();
            break;
        case 3:
            // transaction
            // transactionMenu();
            break;
        case 4:
            // monthly statement generation
            // statementGenMenu();
        default:
            break;
        }
    } while (choice != 0);

    return 0;
}