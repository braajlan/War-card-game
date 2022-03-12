#include <iostream>
#include <string>
using namespace std;

class Card {
public:
char shape;
int value;

Card(){ //empty constructor
}

Card(char shp, int val){ //initilizar constroctur
	//Initiliazes the values of value and shape
	this->shape = shp;
	this->value = val;
}

int getValue(){	//Returns value of the card
	if (value <= 10){ //all cards values except cards with faces 
		return value;
	}
	
	//Queen,King,Jack have the same value 10
	else{
		return 10;
	}
}

void displayCard(){ //gives String for shape,value
	string valString, shapeString;

	//cards values in each case
	switch (value){
	case 1:
		valString = "1";
		break;
	case 2:
		valString = "2";
		break;
	case 3:
		valString = "3";
		break;
	case 4:
		valString = "4";
		break;
	case 5:
		valString = "5";
		break;
	case 6:
		valString = "6";
		break;
	case 7:
		valString = "7";
		break;
	case 8:
		valString = "8";
		break;
	case 9:
		valString = "9";
		break;
	case 10:
		valString = "10";
		break;
	case 11:
		valString = "Jack 10";
		break;
	case 12:
		valString = "Queen 10";
		break;
	case 13:
		valString = "King 10";
		break;
	}
	//Using the shape value in CardDeck
	switch (shape){
	case 'S':
		shapeString = "S";
		break;
	case 'C':
		shapeString = "C";
		break;
	case 'D':
		shapeString = "D";
		break;
	case 'H':
		shapeString = "H";
		break;
	}
	//Outputs the card
	cout << valString << " / " << shapeString << endl;
}

};
