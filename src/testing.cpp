#include<iostream>
#include<string>

using namespace std;

class Card {
    public:
        string cName;
        int num;

        Card() {
            num = 1999;
            cName = giveName();
        }

        string giveName() {
            string name = "TARGET";
            return name;
        }
};

int main() {
    Card c;

    cout << c.cName << endl;
}