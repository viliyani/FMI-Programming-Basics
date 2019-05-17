/**
*
* Solution to homework assignment 2
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

// Function that return count of digits of given number
int getDigitsCount(int num)
{
    if(num == 0)
    {
        return 1;
    }

    int counter = 0;

    while(num != 0)
    {
        counter++;
        num = num / 10;
    }

    return counter;
}

// Function that create array with digits from given number
int* getDigitsArr(int digits[], int num)
{
    if(num == 0)
    {
        digits[0] = 0;
        return digits;
    }

    // Get Digits From Number
    int digitsTemp[6] = {-1};
    int digitTempIndex = 0;
    int digitIndex = 0;

    int temp = num;
    while(temp != 0)
    {
        digitsTemp[digitTempIndex] = temp % 10;
        temp = temp / 10;
        digitTempIndex++;
    }

    for(int i = (digitTempIndex - 1); i >= 0; i--)
    {
        digits[digitIndex] = digitsTemp[i];
        digitIndex++;
    }

    return digits;
}

int getCountOfFoundsHelper(int *arr, int *digits, int &totalDigits)
{
    bool inFounding = false;

    int currentCounter = 0;
    int maxCounter = 0;

    int indexDigits = 0;

    for(int i = 0; i < 6; i++)
    {
        if(inFounding == false && arr[i] == digits[indexDigits])
        {
            inFounding = true;
        }

        if(inFounding == true && arr[i] != digits[indexDigits])
        {
            inFounding = false;
            if(currentCounter > maxCounter)
            {
                maxCounter = currentCounter;
            }
            currentCounter = 0;
            indexDigits = 0;
        }

        if(arr[i] == digits[indexDigits] && inFounding == true)
        {
            indexDigits++;
            if(totalDigits == indexDigits)
            {
                currentCounter++;
                indexDigits = 0;
            }
        }
    }

    if(inFounding == true && indexDigits == 0)
    {
        if(currentCounter > maxCounter)
        {
            maxCounter = currentCounter;
        }
    }

    if(maxCounter == 0)
    {
        return 0;
    }else
    {
        return maxCounter;
    }
}

int getCountOfFounds(int *arr, int *digits, int &totalDigits)
{
    int temp[6];
    int tempIndex = 0;
    int totalCounter = 0;
    int leftCounter = 0;
    int rightCounter = 0;

    leftCounter = getCountOfFoundsHelper(arr, digits, totalDigits);

    for(int i = 5; i >= 0; i--)
    {
        temp[tempIndex] = arr[i];
        tempIndex++;
    }
    rightCounter = getCountOfFoundsHelper(temp, digits, totalDigits);

    totalCounter = leftCounter + rightCounter;
    return totalCounter;
}

int matrixMagic(int *arr, int M)
{
    int totalDigits = getDigitsCount(M);

    int tempDigits[6] = {-1, -1, -1, -1, -1, -1};
    int *digits = getDigitsArr(tempDigits, M);
    int tempArr[6];
    int tempNum = 0;
    int totalFounds = 0;

    for(int i = 0; i < 6; i++)
    {
        totalFounds += getCountOfFounds((arr + i * 6), digits, totalDigits);
    }

    for(int j = 0; j < 6; j++)
    {
        for(int i = 0; i < 6; i++)
        {
            tempNum = *(arr + i * 6 + j);
            tempArr[i] = tempNum;
        }
        totalFounds += getCountOfFounds(tempArr, digits, totalDigits);
    }

    return totalFounds;
}

int main()
{
    int M;
    bool hasError = false;
    int totalFounds = 0;
    int arr[6][6] = {
                        {5,4,3,8,0,6},
                        {9,4,5,1,0,2},
                        {8,5,8,0,6,1},
                        {0,9,6,8,4,2},
                        {6,1,0,2,6,1},
                        {2,1,8,4,2,6},
                    };

    // Show Matrix
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Enter M
    cout << endl << "M = ";
    cin >> M;

    // Validation
    if(getDigitsCount(M) > 6)
    {
        cout << "Invalid Input. Please enter number with maximum 6 digits!";
        return 0;
    }

    // Check if is simple matrix
    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            if(!(arr[i][j] >= 0 && arr[i][j] <= 9))
            {
                hasError = true;
                break;
            }
        }
    }

    if(hasError == true)
    {
        cout << "The Matrix is not simple!";
        return 0;
    }else
    {
        // Everything is OK => Calculate founds!
        totalFounds = matrixMagic((int*)arr, M);
        cout << totalFounds;
    }

    return 0;
}
