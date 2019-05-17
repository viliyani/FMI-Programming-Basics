/**
*
* Solution to homework task 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2018/2019
*
* @author Viliyan Ivanov
* @idnumber 62219
* @task 5
* @compiler GCC
*
*/

#include <iostream>
#include <cmath>
using namespace std;

// Custom function that calculates distances between two points
double distance(double x1, double y1, double x2, double y2)
{
    double x3 = x2 - x1;
    double y3 = y2 - y1;

    double distance = sqrt((x3*x3) + (y3*y3));

    return distance;
}

int main()
{
    // Coordinates for user point
    double x, y;

    // Info for first circle with center (0,0) and radius 6 [the main circle]
    double C0x = 0.0, C0y = 0.0, R0 = 6.0;

    //[black] Circle with center (0,3), radius = 1;
    double C1x = 0.0, C1y = 3.0, R1 = 1.0;

    //[white] Circle with center (0,-3), radius = 1;
    double C2x = 0.0, C2y = -3.0, R2 = 1.0;

    //[white] Circle with center (0,3), radius = 2;
    double C3x = 0.0, C3y = 3.0, R3 = 2.0;

    //[black] Circle with center (0,-3), radius = 1;
    double C4x = 0.0, C4y = -3.0, R4 = 2.0;

    // ###### START WITH THE ALGORITHM ######

    // User enter point (x,y)
    cin >> x;
    cin >> y;


    // Calculate distance from user point and the main circle
    double dist = distance(x, y, C0x, C0y);

    // Validation that user point is in the circle
    if(dist > R0)
    {
        cout << "Outside";
        return 0;
    }
    if(dist == R0)
    {
        cout << "Undefined";
        return 0;
    }

    // ### First, we will check if point is on Ox or Oy

    if(y == 0 && (x > 0 && y < 6))
    {
        cout << "Black";
        return 0;
    }

    if(y == 0 && (x > -6 && x < 0))
    {
        cout << "White";
        return 0;
    }

    if(x == 0 && ((y > 0 && y < 2) || (y > 4 && y < 6)))
    {
        cout << "White";
        return 0;
    }

    if(x == 0 && ((y > 2 && y < 4) || (y > -4 && y < -6)))
    {
        cout << "Black";
        return 0;
    }

    if(x == 0 && (y == 2 || y == 4 || y == -2 || y == -4))
    {
        cout << "Undefined";
        return 0;
    }

    // ### Second, we will divide logic by Quadrants
    double dist1, dist2; // Just helpers

    // 1st Quadrant
    if(x > 0 && y > 0)
    {
        dist1 = distance(x, y, C1x, C1y);
        dist2 = distance(x, y, C3x, C3y);

        if(dist1 < R1)
        {
            cout << "Black";
            return 0;
        }

        if(dist1 == R1)
        {
            cout << "Undefined";
            return 0;
        }

        if(dist1 > R1)
        {
            if(dist2 < R3)
            {
                cout << "White";
                return 0;
            }

            if(dist2 == R3)
            {
                cout << "Undefined";
                return 0;
            }

            if(dist2 > R3)
            {
                cout << "Black";
                return 0;
            }
        }
    }

    // 2nd Quadrant
    if(x < 0 && y > 0)
    {
        dist1 = distance(x, y, C1x, C1y);

        if(dist1 > R1)
        {
            cout << "White";
            return 0;
        }else if(dist1 == R1)
        {
            cout << "Undefined";
            return 0;
        }else
        {
            cout << "Black";
            return 0;
        }
    }

    // 3rd Quadrant
    if(x < 0 && y < 0)
    {
        dist1 = distance(x, y, C2x, C2y);
        dist2 = distance(x, y, C4x, C4y);

        if(dist1 < R2)
        {
            cout << "White";
            return 0;
        }

        if(dist1 == R2)
        {
            cout << "Undefined";
            return 0;
        }

        if(dist1 > R2)
        {
            if(dist2 < R4)
            {
                cout << "Black";
                return 0;
            }

            if(dist2 == R4)
            {
                cout << "Undefined";
                return 0;
            }

            if(dist2 > R4)
            {
                cout << "White";
                return 0;
            }
        }
    }

    // 4th Quadrant
    if(x > 0 && y < 0)
    {
        dist1 = distance(x, y, C2x, C2y);

        if(dist1 > R2)
        {
            cout << "Black";
            return 0;
        }else if(dist1 == R2)
        {
            cout << "Undefined";
            return 0;
        }else
        {
            cout << "White";
            return 0;
        }
    }

    // ### Finally, if we accidentally miss any case, show undefined

    cout << "Undefined";

    return 0;
}
