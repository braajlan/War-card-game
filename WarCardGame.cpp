#include <iostream>
#include <algorithm>
#include <string>
#include "CardDeck.cpp"

using namespace std;
	int main(int argc, const char * argv[])  { //main function
	int selectedOption; // for main menu
	char input= 'y'; // input validation
	CardDeck deck;
	LinkedList<Card> player; //Card linkedList for player
	LinkedList<Card> pc; //Card linkedList for pc
	deck = CardDeck(player,pc); // create a cardDeck

	cout << "Welcome to the War Card Game!" << endl;

	//loop to create a menu
	 while (selectedOption != 4) {
		cout << "1. Start a new game" << endl;
		cout << "2. show your remaining cards" << endl;
		cout << "3. Shuffle your cards" << endl;
		cout << "4. Exit" << endl;
		cin >> selectedOption;
		cout << endl;

		switch (selectedOption){
		case 1: //Begin War
			do{
				if(deck.getPlayerLoser()){
					cout << "Player loser" << endl;
					break;
				}
				else if(deck.getPC_Loser()){
					cout << "PC loser" << endl;
					break;
				} else {
				deck.war(player,pc);
			cout << "=============================" << endl;
			cout << "Remaining number of Player cards: (" << player.getSize() << ") Cards\n";
			cout << "=============================" << endl;
			cout << "Remaining number of PC cards: (" << pc.getSize() << ") Cards\n";;
			cout << "=============================" << endl;
					}
				//Player will be asked to play as many times as he/she wants
				cout << "Do you want to play again?(y/n)" << endl;
				cin >> input;

			} while (input != 'n');
				break;

		case 2: // show the cards in the deck for player&pc
			cout << "=============================" << endl;
			cout << "Remaining number of Player cards: (" << player.getSize() << ") Cards\n";
			player.displayElements();
			cout << "=============================" << endl;
			cout << "Remaining number of PC cards: (" << pc.getSize() << ") Cards\n";;
			pc.displayElements();
			cout << "=============================" << endl;
			break;

		case 3: // shuffle the deck
			cout << "=============================" << endl;
			cout << "Shuffling....." << endl;
			player.shuffle();
			pc.shuffle();
			cout << "Shuffled successfully" << endl << endl;
			cout << "=============================" << endl;
			break;

		//Exits the menu
		case 4:
			cout << "Thank you for playing war game!" << endl;
			cout << endl;
			break;

		default:
			do{
				cout << "Invalid entry.  Please enter a number between 1 and 5." << endl;
				cin >> selectedOption;
			} while (selectedOption > 4);
			break;
		}
	}
	return 0;
}