#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;
    int guess = 0;
    int numberOfGuesses = 0;  //counter

    cout << "Guess a number from (1-100)";

    do
    {
        cin >> guess;
        numberOfGuesses++;

        if(guess < secretNumber)
        {
            cout << "Number entered is too low"<<endl;
        }
        else if(guess > secretNumber)
        {
            cout << "Number entered is too high"<<endl;
        }
        else
        {
            cout << "You guessed it! , the number was "<< secretNumber << endl;
            cout << "It took you " << numberOfGuesses << " guess(es)"<<endl;
        }
    }while (guess != secretNumber);





    return 0;
}

