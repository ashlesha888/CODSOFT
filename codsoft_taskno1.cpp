#include <iostream>
using namespace std;
#include <ctime>

int main(){

    srand(time(0));
    int number = rand() % 100 - 1;
    int guess , attempts = 0;
    
    cout << "Welcome to the Number Guessing Game" << endl;
    do{
        cout << "Enter your guess(0-100): " ;
        cin>>guess;
        attempts++;
        if ( guess < number ){
            cout << "Too low. Please try again " << endl;
        }else if( guess > number ){
            cout << "Too high. Please try again" << endl;
        }else{
            cout << "Congratulation! You guessed the secret number in "<< attempts << " attempts"<< endl;
        }   
     }while ( guess != number );
    return 0;
}
