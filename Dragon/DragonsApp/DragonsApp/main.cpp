/*******************************************
* Do not modify anything after this line.
*******************************************/
#include <iostream>
#include "Dragons.h"

using namespace std;

void Battle(Dragon &dragon, Hidra &hidra){
	hidra.injectPoison(dragon);
	dragon.breathOn(hidra);
}

int main()
{
	Dragon dragon("Red Dragon", 2, 10, 3, 6, 0);
	Hidra  Hidra("Bad Hidra", 2, 10, 1, 10, 1, 42);

	dragon.showData();
	cout << "ready to battle with :" << endl;
	Hidra.showData();

	cout << endl;
	cout << "1st Battle :" << endl;
	cout << "    creatures are not in range, they can't fight yet."
		<< endl;
	Battle(dragon, Hidra);

	cout << "After battle:" << endl;
	dragon.showData();
	Hidra.showData();

	cout << endl;
	cout << "The Dragon fly close to Hidra:" << endl;
	dragon.fly(Hidra.getPosition() - 1);
	dragon.showData();

	cout << endl;
	cout << "Hidra get back one step:" << endl;
	Hidra.move(1);
	Hidra.showData();

	cout << endl;
	cout << "2nd Battle :" << endl;
	cout << "+ Hidra attack Dragon with a 3 points attack [ level (2) * force (1) + poison (1) = 3 ] ;\n\
+ Dragon attack Hidra with an 6 points attack [ level (2) * force (3) = 6 ] ;\n\
+ during his attack, the dragon loses 2 life points\n\
[ correspondent to the distance between Dragon and Hidra: 43 - 41 = 2 ].\ " << endl;
	Battle(dragon, Hidra);

	cout << "After battle:" << endl;
	dragon.showData();
	Hidra.showData();

	cout << endl;
	cout << "Dragon advance one step:" << endl;
	dragon.move(1);
	dragon.showData();

	cout << endl;
	cout << "3rd Battle :" << endl;
	cout << "\+ Hidra attack Dragon with a 3 points attack\n\[ level (2) * force (1) + poison (1) = 3 ] ;\n\
+ the Dragon attack Hidra with a 6 points attack [ level (2) * force (3) = 6 ] ;\n\
+ during attack the Dragon loses 1 life point\n[ correspondent to the distance between Dragon and Hidra: 43 - 42 = 1 ] ;\n\
+ Hidra is defeated and the Dragon upgrade to level 3.\ " << endl;
	Battle(dragon, Hidra);

	cout << "After battle:" << endl;
	dragon.showData();
	Hidra.showData();

	cout << endl;
	cout << "4th Battle :" << endl;
	cout << " when a creature is beaten, nothing happen." << endl;
	Battle(dragon, Hidra);

	cout << "After battle:" << endl;
	dragon.showData();
	Hidra.showData();

	return 0;
}