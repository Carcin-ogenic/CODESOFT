#include <bits/stdc++.h>
using namespace std;
void calculator()
{
    int N1, N2;
    cout << "ENTER FIRST NUMBER : ";
    cin >> N1;
    cout << "ENTER SECOND NUMBER : ";
    cin >> N2;
    cout << "CHOOSE AN OPERATION TO PERFORM(+,-,*,/) : ";
    char c;
    cin >> c;
    switch (c)
    {
    case '+':
        cout << "THE SUM OF GIVEN NUMBERS IS : " << N1 + N2;
        break;

    case '-':
        cout << "THE DIFFERENCE BETWEEN THE GIVEN NUMBERS IS : " << N1 - N2;
        break;

    case '*':
        cout << "THE PRODUCT OF GIVEN NUMBERS IS : " << N1 * N2;
        break;

    case '/':
        if (N2 == 0)
        {
            cout << "MATH ERROR : ATTEMPTED TO DIVIDE BY ZERO!";
        }
        else
            cout << "THE QUOTIENT AFTER DIVISION IS : " << N1 / N2;
        break;

    default:
        cout << "ENTER A VALID OPERATION.";
        break;
    }
}
int main()
{
    cout << "----------------------------SIMPLE CALCULATOR---------------------------------";
    cout << endl;
    calculator();
    cout << endl
         << endl;

    cout << "ENTER 'Y' TO CONTINUE AND 'N' TO BREAK : ";
    char ans;
    cin >> ans;
    cout << endl;

    while (ans != 'N')
    {
        calculator();
        cout << endl
             << endl;
        cout << "ENTER 'Y' TO CONTINUE AND 'N' TO BREAK : ";
        cin >> ans;
        cout << endl;
    }
    cout << "THANK YOU ! ";
    return 0;
}