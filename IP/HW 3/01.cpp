/**
*
* Solution to homework assignment 3
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
#include <cstdlib>
#include <Windows.h>
using namespace std;

void doMove(char arr[])
{
    char arrMoved[59];
    int M = 1;
    int L = 59;
    int indexOneFrom = 0;
    int indexOneTo = 0;
    int indexTwoFrom = 0;
    int indexTwoTo = 0;
    int indexForMovedArray = 0;

    indexOneTo = 0;
    indexOneTo = L - M - 1;
    indexTwoFrom = L - M;
    indexTwoTo = L - 1;

    for(int i = indexTwoFrom; i <= indexTwoTo; i++)
    {
        arrMoved[indexForMovedArray] = arr[i];
        indexForMovedArray++;
    }

    for(int i = indexOneFrom; i <= indexOneTo; i++)
    {
        arrMoved[indexForMovedArray] = arr[i];
        indexForMovedArray++;
    }

    for(int i = 0; i < L; i++)
    {
        arr[i] = arrMoved[i];
    }
}

void doMove2(char arr[][59])
{
    doMove(arr[0]);
    doMove(arr[1]);
    doMove(arr[2]);
    doMove(arr[3]);
    doMove(arr[4]);
}

void printLabel(char elements[][59])
{
    for(int k = 0; k < 5; k++)
    {
        cout << endl;
    }

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < 59; j++)
        {
            cout << elements[i][j];
        }
        cout << endl;
    }

    for(int k = 0; k < 5; k++)
    {
        cout << endl;
    }
}

int main()
{
    char elements[5][59] =
    {
        {'H',' ',' ',' ','H',' ',' ',' ','E','E','E','E','E',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ','O',' ',' ',' '},
        {'H',' ',' ',' ','H',' ',' ',' ','E',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ',' ','O',' ',' ',' ','O',' '},
        {'H','H','H','H','H',' ',' ',' ','E','E','E','E','E',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','O',' ',' ',' ',' ',' ','O'},
        {'H',' ',' ',' ','H',' ',' ',' ','E',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ','L',' ',' ',' ',' ',' ',' ',' ',' ','O',' ',' ',' ','O',' '},
        {'H',' ',' ',' ','H',' ',' ',' ','E','E','E','E','E',' ',' ',' ','L','L','L','L','L',' ',' ',' ','L','L','L','L','L',' ',' ',' ',' ',' ',' ','O',' ',' ',' '},
    };

    doMove2(elements);

    printLabel(elements);

    for(int p = 0; p < 500; p++)
    {
        Sleep(300);
        system("CLS");

        doMove2(elements);

        printLabel(elements);
    }

    return 0;
}
