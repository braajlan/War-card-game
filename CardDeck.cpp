#include <iostream>
#include <string>
#include "GenericLinkedList.cpp"
using namespace std;
bool isPCLoser = false; //boolean used in warCardGame
bool isPlayerLoser = false; //boolean used in warCardGame
class CardDeck {
public:
LinkedList<Card> deck;
CardDeck(){

}

bool getPC_Loser(){
	return isPCLoser;
}

bool getPlayerLoser(){
	return isPlayerLoser;
}

CardDeck(LinkedList<Card> &player, LinkedList<Card> &pc){ // default constroctur, player,pc are in WAR game class
	//Creating an array to hold character values for the shapes of each card
	char shapes[] = { 'S', 'C', 'D', 'H' };

	for (int i = 1; i < 14; i++){ // every shape has 14 cards
		for (int j = 0; j < 4; j++){ // 4 shapes
			Card card = Card(shapes[j],i);
			deck.add(card);
		}
	}
	// after adding all cards , we have to call shuffle()
	deck.shuffle();
	// now split cards to 2 players
	deck.splitList(deck, player, pc);
}

void displayCardAt(int i){
	deck.get(i).displayCard();
}

void war(LinkedList<Card> &player, LinkedList<Card> &pc){ // the main method for playing game, player,pc are in WAR game class
	Card playerCard;
	Card pcCard;

if(player.getSize() < 1) { // if player out of cards
	cout << "Player out of cards!!\n";
	isPlayerLoser = true;	
	return;
} else { // else continue playing and put a card
	cout << "=======================" << endl;
	cout << "PLAYER card is ==> ";
	playerCard = player.pop();
	playerCard.displayCard();
}
if(pc.getSize() < 1) { // if pc out of cards
	cout << "PC out of cards!!\n";
	isPCLoser = true;	
	return;
	} else { // else continue playing and put a card
	cout << "=======================" << endl;
	cout << "PC card is ==> ";
	pcCard = pc.pop();
	pcCard.displayCard();
}

if(playerCard.getValue() > pcCard.getValue()) { // player takes all 2 cards
	player.add(playerCard); //add it in player's linkedList
	player.add(pcCard); //add it in player's linkedList
	cout << "== PLAYER WINS ==\n";
	} 
else if(pcCard.getValue() > playerCard.getValue()) { // pc takes all 2 cards
	pc.add(playerCard); //add it in PC's linkedList
	pc.add(pcCard); //add it in PC's linkedList
	cout << "== PC WINS ==\n";
	}
else if(playerCard.getValue() == pcCard.getValue()) { //when a Tie
	cout << "== Tie! ==" << endl;
	bool isTie = true; //boolean for break a loop when done
	//important explaination
	//we have to add the following:-
	//first 2 cards (in the table we're made above)
	//+ 3 cards (from pocket)
	//+ 1 card(from pocket flipped for war) => 10cards total
	LinkedList<Card> warList; // we create a list to contain all cards we'll playing in this war
	warList.deleteAllNodes(); // make sure that warList is cleaned
	while(isTie){ // start loop
	if(player.getSize() <4) { // if out of cards in WAR
	cout << "Player out of cards in WAR!!\n";
	cout << "Player loses WAR!!\n";
	isPlayerLoser = true;
	return;
	}
	if(pc.getSize() <4) { // if out of cards in WAR
	cout << "PC out of cards in WAR!!\n";
	cout << "PC loses WAR!!\n";
	isPCLoser = true;
	return;
	}
	warList.add(playerCard); // add first two first cards
	warList.add(pcCard); // add first two first cards

	cout << " === Cards in war is:- (Player) ===\n";
	for(int i = 0; i<3; i++){ // draw 3 cards from each player and store it in warList
		Card playerItem = player.pop();
		cout << playerItem << endl;
		warList.add(playerItem);
	}
	cout << " === Cards in war is:- (PC) ===\n";
		for(int i = 0; i<3; i++){ // draw 3 cards from each player and store it in warList
		Card pcItem = pc.pop();
		cout << pcItem << endl;
		warList.add(pcItem);
	}

	playerCard = player.pop(); // last 4th WAR card for player
	warList.add(playerCard);
	cout << "=============================" << endl;
	cout << playerCard << " Player's WAR CARD!" << endl;
	pcCard = pc.pop();
	warList.add(pcCard); // last 4th WAR card for PC
	cout << pcCard << " PC's WAR CARD!" << endl;
	cout << "=============================" << endl;

if(playerCard.getValue() > pcCard.getValue()) { // player takes all 10 cards
cout << "Player takes it all!" << endl;
while(warList.getSize()!=0){
	player.add(warList.pop());
}
	isTie = false;
	}
else if(pcCard.getValue() > playerCard.getValue()) { // PC takes all 10 cards
cout << "PC takes it all!" << endl;
while(warList.getSize()!=0){
	pc.add(warList.pop());
}
	isTie = false;
	}
else if(pcCard.getValue() == playerCard.getValue()) { //tie again ,repeat loop
		isTie = true;
			}
		}
	}
}
};
