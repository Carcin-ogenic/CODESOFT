#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void check(int RandomNumber, int Guess, int &count)
{
    if (Guess == RandomNumber)
    {
        cout << "Congratulations, you have guessed the right number in " << count << (count == 1 ? " turn." : " turns.") << endl;
    }
    else if (Guess >= RandomNumber + 100)
    {
        cout << "The Number entered is TOO HIGH !" << endl;
    }
    else if (Guess >= RandomNumber - 10 && Guess <= RandomNumber + 10)
    {
        cout << "The Number entered is very close." << endl;
    }
    else if (Guess <= RandomNumber + 99 && Guess >= RandomNumber - 99)
    {
        cout << "The Number entered is close." << endl;
    }
    else if (Guess <= RandomNumber - 100)
    {
        cout << "The Number entered is TOO LOW !" << endl;
    }

    cout << "------------------------------------------------------------------" << endl;
    count++;
}
int main()
{
    srand((unsigned)time(NULL));
    int RandomNumber = rand() % 1000;
    // Here modulus 1000 denotes the upper limit of the random number.

    int count = 1;
    int Guess;
    cout << "----------------------NUMBER GUESSING GAME------------------------" << endl;
    cout << "ENTER A NUMBER : ";
    cin >> Guess;
    check(RandomNumber, Guess, count);

    while (Guess != RandomNumber)
    {
        cout << "ENTER A NUMBER : ";
        cin >> Guess;
        check(RandomNumber, Guess, count);
    }

    return 0;
}