#include <iostream>
#include "Point2D.h"
#include "Point3D.h"
#include "Entity.h"
using namespace std;

int Entity::nextID = 1;

int main()
{
	Point2D p(3, 5);
	Point2D q(8, 11);
	Point3D t(1, 2, 3);
	Point3D m(10, 20, 30);

	//p.print();
	//q.print();
	t.print();
	m.print();

	cout << "Distance is: " << t.getDistanceTo(m) << endl;

	system("pause");
	return 0;
}