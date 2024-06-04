#include<iostream>
#include<string>
#include<exception>
#include<vector>

using namespace std;



class CustomError: public runtime_error {
    public:
        CustomError(): runtime_error("Error Message") {}
};


// void printline() {
//     cout << "TARGET is here\n";
// }

// class Card {
//     public:
//         string cName;
//         int num;

//         Card() {
//             num = 1999;
//             cName = giveName();
//             printline();
//         }

//         string giveName() {
//             string name = "TARGET1999";
//             return name;
//         }
// };

class Test {
    public:
        int abc;
        Test(int a): abc(a) {} 

};



int main() {
    vector<Test> state;

    state.push_back(Test(69));

    cout << state[0].abc << endl;
}






// int main() {
//     int ch, n;
//     while(1) {
//         cin >> ch;
//         switch (ch)
//         {
//         case 1: 
//             try{
//                 cin >> n;
//                 if(!n)
//                     throw ChutiyaAniSK();
//                 cout << n << endl;
//             }
//             catch(ChutiyaAniSK &e)
//             {
//                 cerr << e.what() << endl;
//             }
//             /* code */
//             break;
        
//         default:
//             cout << "Lmao default" << endl;
//             break;
//         }
//     }
// }