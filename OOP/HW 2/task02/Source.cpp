#include <iostream>
#include "Warrior.h"
#include "Guardian.h"
#include "Wizzard.h"
using namespace std;

int main()
{
	Warrior myWarrior;
	myWarrior.print();

	Guardian myGuardian;
	myGuardian.print();

	Wizzard myWizzard;
	myWizzard.print();

	myWarrior.getattacked(myWizzard.getPointsAttack());

	myWarrior.print();

	system("pause");
	return 0;
}
