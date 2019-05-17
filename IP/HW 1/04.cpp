/**
*
* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Viliyan Ivanov
* @idnumber 62219
* @task 4
* @compiler GCC
*
*/

#include<iostream>
using namespace std;

int main()
{
    // Side size of the square
    int n;

    // Symbol that will be printed
    char c;

    // User input
    cin >> n;
    cin >> c;

    // Helper variables
    int start = 40; // This is the column number from where to start printing
    int perRow; // Number of symbols per row to be printed
    int len = n*2 - 1; // Total Rows that we will need to draw the rotated square
    int skipRows = (25 - len) / 2; // How much empty rows we need before and after the square

    // Validation, maximum length of side can be 13
    if(n > 13)
    {
        cout << "Please enter number less than 14!";
        return 0;
    }

    // Print empty rows
    for(int i = 1; i <= skipRows; i++)
    {
        cout << endl;
    }

    // Do all other print logic
    for(int i = 1; i <= 25 - skipRows; i++)
    {
        // We divide algorithm in two parts, before middle of the square and after
        if(i <= n)
        {
            start -= 2;

            for(int j = 1; j < start; j++)
            {
                cout << " ";
            }

            perRow = (i * 2) - 1;

            for(int j = 1; j <= perRow; j += 2)
            {
                cout << c << " ";
            }

            for(int j = perRow; j > 1; j -= 2)
            {
                cout << c << " ";
            }

        }else if(i > n && i <= len)
        {
            start += 2;

            for(int j = 1; j < start; j++)
            {
                cout << " ";
            }

            perRow -= 2;

            for(int j = 1; j <= perRow; j += 2)
            {
                cout << c << " ";
            }

            for(int j = perRow; j > 1; j -= 2)
            {
                cout << c << " ";
            }

        }else
        {
            cout << " ";
        }

        cout << endl;
    }
    return 0;
}
