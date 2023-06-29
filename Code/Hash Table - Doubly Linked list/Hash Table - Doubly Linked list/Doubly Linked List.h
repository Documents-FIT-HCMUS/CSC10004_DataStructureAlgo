#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

struct DNode
{
	int key;
	DNode* next;
	DNode* prev;
};
struct DList
{
	DNode* head;
	DNode* tail;
};

//DOUBLY LINKED LIST
DNode* createDNode(int);
void createDList(DList*&, int);
void printDList(DList*);

DNode* findDNode(DList*, int);
void addDNodeHead(DList*&, int);
void addDNodeTail(DList*&, int);
void addBeforeDNode(DList*&, int, int);
void addAfterDNode(DList*&, int, int);

void removeHead(DList*&);
void removeTail(DList*&);
void removeDNode(DList*&, int);