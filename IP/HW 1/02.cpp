/**
*
* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Viliyan Ivanov
* @idnumber 62219
* @task 2
* @compiler GCC
*
*/

#include <iostream>
using namespace std;

int main()
{
    // Declare variables
    int num, k, temp, counter = 0;

    // Enter Number
    cin >> num;

    // Enter digit
    cin >> k;

    while(num != 0)
    {
        temp = num % 10;
        if(temp == k)
        {
            counter++;
        }
        num /= 10;
    }

    cout << endl;

    cout << "The digit " << k << " exists " << counter << " times in the number!";

    return 0;
}
