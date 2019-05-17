/**
*
* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Viliyan Ivanov
* @idnumber 62219
* @task 1
* @compiler GCC
*
*/

#include <iostream>
using namespace std;

int main()
{
    // Declare variables
    short num;
    short min;
    short max;
    short counter = 0;

    // Enter first number
    cin >> num;

    // Increase counter
    counter++; // now it shows that there is 1 entered number

    // Set Default Min and Max equals to first number
    min = num;
    max = num;

    // Loop for entering numbers WHILE user enter negative number
    while(num >= 0)
    {
        cin >> num;

        if(num >= 0)
        {
            if(num < min)
            {
                // We have new min number
                min = num;
            }

            if(num > max)
            {
                // We have new max number
                max = num;
            }

            // Increase counter of total numbers
            counter++;
        }

    }

    if(counter == 1)
    {
        // That means only 1 number is entered
        cout << "Please insert at least 2 numbers";
    }else{
        // Show total
        if(min < max)
        {
            cout << "|max - min| = " << "|" << max << " - "
                <<  min << "| = " << (max - min);
        }else{
            // In this case, maybe never will be executed
            cout << "|min - max| = " << "|" << min << " - "
                <<  max << "| = " << (min - max);
        }
    }

    return 0;
}
