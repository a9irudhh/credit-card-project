#include<iostream>
#include<string>

using namespace std;

void printline() {
    cout << "TARGET is here\n";
}

class Card {
    public:
        string cName;
        int num;

        Card() {
            num = 1999;
            cName = giveName();
            printline();
        }

        string giveName() {
            string name = "TARGET1999";
            return name;
        }
};

int main() {
    Card c;

    cout << c.giveName() << endl;
}