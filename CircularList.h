//
//  Name: Yuya Oguchi
//  COEN 70
//  Chapter 5, Project 17
//  2/03/2016
//  Circular linked list
//
#pragma once

class circularList{
public:
    circularList();
    ~circularList();

    int numItems();
    void addFirst(int x);
    void addLast(int x);
    int removeFirst();
    int removeLast();
    int getFirst();
    int getLast();
private:

    typedef struct node{
        int number;
        struct node *next;
        struct node *prev;
    } Node;

    int counter;
    Node *head;
};
