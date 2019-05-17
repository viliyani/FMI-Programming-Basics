/**
*
* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Viliyan Ivanov
* @idnumber 62219
* @task 3
* @compiler GCC
*
*/

#include <iostream>
using namespace std;

int main()
{
    // Declare variables
    int num1, num2, operation, result;

    cin >> num1;
    cin >> num2;
    cin >> operation;

    // Validation
    if(!((num1 >= 0 && num1 <= 15) && (num1 >= 0 && num1 <= 15)))
    {
        cout << "Wrong input";
        return 0;
    }
    if(!(operation >= 0 && operation <= 3))
    {
        cout << "Wrong input";
        return 0;
    }
    if(operation == 3 && num2 == 0)
    {
        cout << "Wrong input";
        return 0;
    }

    // Do calculations
    switch(operation)
    {
        case 0:
            result = num1 + num2;
            if(result > 15)
            {
                result = result - 16;
            }
            break;

        case 1:
            result = num1 - num2;
            if(result < 0)
            {
                result = result + 16;
            }
            break;

        case 2:
            result = num1 * num2;
            if(result > 15)
            {
                result = result / 16;
            }
            break;

        case 3:
            result = num1 / num2;
            break;

        default:
            result = -1;
            break;
    }

    cout << result;

    return 0;
}
