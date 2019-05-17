/**
*
* Solution to homework assignment 2
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

void doMove(int *arr, int M, int L)
{
    int arrMoved[100];
    int indexOneFrom = 0;
    int indexOneTo = 0;
    int indexTwoFrom = 0;
    int indexTwoTo = 0;
    int indexForMovedArray = 0;

    if(M > L || (-M) > L)
    {
        cout << "Error!";
        return;
    }

    if(M > 0)
    {
        indexOneTo = 0;
        indexOneTo = L - M - 1;
        indexTwoFrom = L - M;
        indexTwoTo = L - 1;
    }else if(M < 0)
    {
        indexOneTo = 0;
        indexOneTo = (M*(-1)) + 1;
        indexTwoFrom = M*(-1);
        indexTwoTo = L - 1;
    }
    else
    {
        // M == 0
        indexOneTo = 0;
        indexOneTo = 0;
        indexTwoFrom = 0;
        indexTwoTo = L - 1;
    }

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

    cout << "Arr = {";
    for(int i = 0; i < L; i++)
    {
        cout << arrMoved[i] << ", ";
    }
    cout<<'\b';
    cout<<'\b';
    cout<<"}";
}

int main()
{
    int arr[100] = {6,5,6,0,3};
    int L = 5;
    int M = 0;

    cout << "Arr = {";
    for(int i = 0; i < L; i++)
    {
        cout << arr[i] << ", ";
    }
    cout<<'\b';
    cout<<'\b';
    cout<<"}, Length = " << L << ", M = ";

    cin >> M;

    doMove(arr, M, L);

    return 0;
}
