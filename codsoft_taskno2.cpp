#include <iostream>
using namespace std;
int main(){
    
    double num1 , num2;
    char op;
    cout << "Enter first number: ";
    cin >> num1 ;
    cout << "Enter second number: ";
    cin >> num2 ;
    cout << "Enter the operator ( + , - , * , / ): ";
    cin >> op;
    
    switch(op){
        case '+': cout << num1 << '+' << num2 << '=' << num1+num2 << endl;
                  break;
        case '-': cout << num1 << '-' << num2 << '=' << num1-num2 << endl;
                  break;
        case '*': cout << num1 << '*' << num2 << '=' << num1*num2 << endl;
                  break;
        case '/': cout << num1 << '/' << num2 << '=' << num1/num2 << endl;
                  break;
        default : cout << "PLease enter a valid operator ";
    }

    return 0;
}
