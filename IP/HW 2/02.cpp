/**
*
* Solution to homework assignment 2
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
#include <string.h>
using namespace std;

void doFind(char *arrA, char *arrB, char *arrC){
    bool inFounding = false;

    int indexCurrent = 0;
    int indexMax = 0;

    int currentCounter = 0;
    int maxCounter = 0;

    int indexC = 0;

    int lengthB = strlen(arrB);
    int lengthC = strlen(arrC);

    for(int i = 0; i < lengthB; i++)
    {
        //cout << "----> arrB["<< i << "] = " << arrB[i] << endl;
        if(inFounding == false && arrB[i] == arrC[indexC])
        {
            //cout << "in first if, arrB["<< i << "] = " << arrB[i] << endl;
            inFounding = true;
            indexCurrent = i;
        }

        if(inFounding == true && arrB[i] != arrC[indexC])
        {
            //cout << "in second if, arrB[" << i << "] = " << arrB[i] << endl;
            inFounding = false;
            if(currentCounter > maxCounter)
            {
                maxCounter = currentCounter;
                indexMax = indexCurrent;
            }
            currentCounter = 0;
            indexC = 0;
        }

        if(arrB[i] == arrC[indexC] && inFounding == true)
        {
            //cout << "in 3rd if, arrB["<< i << "] = " << arrB[i] << endl;
            indexC++;
            if(lengthC == indexC)
            {
                currentCounter++;
                //cout << "in 4th if, arrB["<< i << "] = " << arrB[i] << endl;
                indexC = 0;
            }
        }
    }

    if(currentCounter > maxCounter)
    {
        maxCounter = currentCounter;
        indexMax = indexCurrent;
    }

    if(maxCounter == 0)
    {
        cout << "Index: " << -1 << endl << endl;
        cout << "Length: " << 0 << endl;
    }else
    {
        cout << "Index: " << indexMax << endl << endl;
        cout << "Length: " << maxCounter * lengthC << endl;
    }
}

int main()
{
    char arrA[100];
    char arrB[100];
    char arrC[100];

    cin >> arrB;
    cin >> arrC;

    doFind(arrA, arrB, arrC);

    return 0;
}
