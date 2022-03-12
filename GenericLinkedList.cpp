#include <iostream>
#include <stdlib.h>
#include <cstdlib> //for random numbers
#include "Card.cpp" //for cards info
using namespace std;
// declaring node class
template<class T>
struct node {
  node<T>* next;
  T data;
};
// declaring linked list class of generic type so you can use it for any type
template<class T>
class LinkedList
{
public:
  node<T>* head;
  node<T>* last;
  LinkedList<T>() {
    head = NULL;
    last = NULL;
  }

  // add a node at last
  void add(T data) { 
    if(!head) {
      // when there is no element in the list
      head = new node<T>;
      head->data = data;
      head->next = NULL;
      last = head;
    } else {
      // when the list is not empty
      if(last == head) {
        // when the list has one element
        last = new node<T>;
        last->data = data;
        last->next = NULL;
        head->next = last;
      } else {
        // when the list has more than one element
        node<T>* insdata = new node<T>;
        insdata->data = data;
        insdata->next = NULL;
        last->next = insdata;
        last = insdata;
      }
    }
  }

// Delete a node at first
T pop() {
    T obj;

    if (head) {
    obj = head->data;
    node<T>* tmp = head;
    head = head->next;
    delete tmp;
    }

    return obj;
}

// Delete all nodes in the list
void deleteAllNodes(){
    node<T>* tmp = new node<T>;
  while(head != NULL) {
    tmp = head;
    head = head->next;
    free(tmp);
  }
cout << "== all nodes Deleted Successfully ==";
}

// return the size of list
int getSize(){
    int counter = 0;
node<T>* curr = head;
while(curr!= NULL){
    counter++;
    curr = curr->next;
}
return counter;
}

// remove first matching element if match data
void remove(T data) {
    node<T>* temp = head;
    node<T>* curr = head->next;
  if(head->data == data){ //first element
    head = head->next;
    return;
  } else {
  while (curr != NULL && curr->data != data) {
    temp = curr;
    curr = curr->next;
    }
  if(curr == NULL){
    cout << "Can't remove value: no match found.\n";
    }
  else{
  temp->next = curr->next;
  delete curr;
   } 
  } 
  // If the data is not present
  if (curr == NULL) {
      cout << "curr is null" << endl;
  }
  // Remove the node
  if(curr->data == data) {
  temp->next = curr->next;
  curr->next = NULL;
  return;
  }
}

// retrieve list element in specefic index
  T get(int index) {
    if(index == 0) {
      // returning the head element
      return this->head->data;
    } else {
      // Get the index'th element
      node<T>* curr = this->head;
      for(int i = 0; i < index; ++i) {
        curr = curr->next;
      }
      return curr->data;
    }
  }

// shuffles the whole list using random indexing to the list, then locate that element remove it 
// then add it again at last element --> this is a O(n) so all elements are likly to be shuffled
void shuffle(){
int low_dist  = 0;
int high_dist = this->getSize()-1;
if(high_dist == 0){ //if list contains 1 element only
    return; 
}
  srand((unsigned int) time(nullptr)); //srand() is a function to prepare shuffling
  for(int i = 0; i < high_dist; ++i){
   int shuffeledIndex = low_dist + rand() % ( high_dist - low_dist ); //rand() is returning a random number between 0 -> (size of list)
    T obj1 = this->get(shuffeledIndex); //select element randomly
    this->remove(obj1);
    this->add(obj1); //add the element as last
    }
}

// split List to a half --> we'll use it in CardDeck to split cards to player and PC
void splitList(LinkedList<T> source, LinkedList<T> &one, LinkedList<T> &two){
    node<T>* curr = this->head;
    for(int i=0;i<source.getSize()/2;i++){ //adding until 26 cards from deck to player 1
        one.add(curr->data);
        curr = curr->next;
    }
    while(curr!= NULL){
        two.add(curr->data);
        curr = curr->next;
    }
}

// prints all elements in list
 void displayElements(){
    node<T>* curr = this->head;
    while(curr != NULL){
        cout << curr->data << " --> ";
        curr = curr->next;
    } cout << "null\n";
 }

// operator for make comparing so the complier dosen't be confused
  T operator[](int index) {
    return get(index);
  }

};

// operator for make comparing so the complier dosen't be confused
//operators overloading when comparing Card objects on (==)
bool operator==(const Card& lhs, const Card& rhs) {
	if(lhs.shape == rhs.shape && lhs.value == rhs.value) { //this is the comparing inside object we want
		return true;
	} else {
		return false;	
	}
}
//operators overloading when comparing Card objects on (!=)
bool operator!=(const Card& lhs, const Card& rhs) {
	if(lhs.shape != rhs.shape || lhs.value != rhs.value) {
		return true;
	} else {
		return false;	
	}
}
//operators overloading when comparing Card objects on (>)
bool operator>(const Card& lhs, const Card& rhs) {
	if(lhs.value > rhs.value) {
		return true;
	} else {
		return false;	
	}
}
//operators overloading when comparing Card objects on (<)
bool operator<(const Card& lhs, const Card& rhs) {
	if(lhs.value < rhs.value) {
		return true;
	} else {
		return false;	
	}
}

//operators overloading when comparing Card objects on (<<)
// this is used while printing an object
ostream& operator<<(ostream& os, const Card& card) 
{
    os << card.shape << '/' << card.value;
    return os;
}