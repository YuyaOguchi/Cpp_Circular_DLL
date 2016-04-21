//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 5, Project 17
//  2/03/2016
//  Circular linked list
//
#include <iostream>
#include "CircularList.h"
using namespace std;

circularList::circularList(){
    Node *list = new Node();
    list->number = -1;
    list->next = list;
    list->prev = list;

    counter = 0;
    head = list;
}

circularList::~circularList(){
    Node *temp = head;
    Node *next;

    do { //free each Node by running through  list
        next = temp->next;
        delete temp;
        temp = next;
    } while (temp != head);
}

int circularList::numItems(){
    return counter; // return the kept number of counter in
}

void circularList::addFirst(int x){
    Node *deck = new Node();
    deck->number = x; // allocate the number
    deck->next = head->next;// next four line set deck in to the beginning of list
    deck->prev = head;
    head->next->prev = deck;
    head->next = deck;
    counter++;//increment counter

}

void circularList::addLast(int x){
    Node *decklast = new Node();
    decklast->number = x;//give number to that Node
    decklast->next = head;//next four line set Node at the end of list and connect all links
    decklast->prev = head->prev;
    head->prev->next = decklast;
    head->prev = decklast;
    counter++; // increment counter
}


int circularList::removeFirst(){
    Node *deckrf = head->next;//temp Node

    head->next = deckrf->next; // link temp Node to keep all the linked list
    deckrf->next->prev = head;

    int temp = deckrf->number; // temp holder to delete the Node
    delete deckrf; // free the first one
    counter--; //decrement counter
    return temp; // return the value of the temp Node which you deleted
}

int circularList::removeLast(){
    Node *deckrl = head->prev; //temp Node

    head->prev = deckrl->prev; // connect temp Node to make sure link doesnt dissapear
    deckrl->prev->next = head;

    int temp = deckrl->number; //temp Node to delete
    delete deckrl;//delete that Node
    counter--;//decrement counter
    return temp;//return the value of deleted Node
}

int circularList::getFirst(){
    return head->next->number;//return the first Node number
}


int circularList::getLast(){
    return head->prev->number; // return the value of last Node by going prov from head
}



int main(){
    circularList s;
    s.addFirst(1);
    s.addFirst(5);
    s.addFirst(81);
    s.addLast(4);
    s.addLast(2);
    s.removeFirst();

    cout << s.getFirst() << endl;
    cout << s.getLast() << endl;


    return 0;
}
