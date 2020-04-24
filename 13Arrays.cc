#include <iostream>

using namespace std;

int main()
{   
    // INITIALISING INTEGER ARRAY
    cout << "Initializing integer array" << endl;
	cout << "==========================" << endl;

    int values[3];
    
    // values[0] = 12;
    // values[1] = 132;
    values[2] = 122;

    // VERY BAD IDEA! [SINCE THE INDEX IS MORE THAN THE SIZE OF THE ARRAY]
    cout << "BAD IDEA! JUNK VALUE IS PUT HERE!" << values[3] << endl;

    // IF NOT INITIALIZED, ARRAY VALUES TAKE GARBAGE VALUES JUST LIKE OTHER VARIABLES
    cout << values[0] << endl;
    cout << values[1] << endl;
    cout << values[2] << endl;
    
    // INITIALIZING DOUBLE ARRAY
    cout << endl << "Initializing double array" << endl;
	cout << "=========================" << endl;

    double floats[4] = {12.3, 3.4, 2.0, 21.2};

    for (int i = 0; i < 4; i++)
    {
        cout << floats[i] << endl;
    }
    
    // INITIALISING WITH ZERO VALUES
    cout << endl << "Initializing with zero values" << endl;
	cout << "=============================" << endl;

    // ARRAY OF INT ZERO VALUES
	int numberArray[8] = { };

	for (int i = 0; i < 8; i++) {
		cout << "Element at index " << i << ": " << numberArray[i] << endl;
	}

    // INITIALISING WITH STRINGS
	cout << endl << "Initializing with strings" << endl;
	cout << "=========================" << endl;

	// ARRAY OF STRINGS
	string texts[] = { "apple", "banana", "orange" };

	for (int i = 0; i < 3; i++) {
		cout << "Element at index " << i << ": " << texts[i] << endl;
	}    

    return 0;   
}