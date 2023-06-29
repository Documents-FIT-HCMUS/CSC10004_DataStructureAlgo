#pragma once
#include <iostream>
#define LEFT true
#define RIGHT false
#define LEFT_CHILD true
#define RIGHT_CHILD false
using namespace std;

struct NODE
{
	int key;
	NODE* left;
	NODE* right;
	int balance;
};

// INSERT AND REMOVE
NODE* createNode(int);
NODE* createAVLTreeFromArray(int[], int);
void insert(NODE*&, int);
void remove(NODE*&, int);

// UTILITY FUNCTIONS
NODE* findMin(NODE*);
NODE* findParent(NODE*, int, bool&);
NODE* search(NODE*, int);
int height(NODE*);
void leftRotate(NODE*&);
void rightRotate(NODE*&);

// PRINT
void printNLR(NODE*);
void printLNR(NODE*);
void printLRN(NODE*);
void printLevel(NODE*, int);
void printLevelOrder(NODE*);

// AVL
void refreshBalance(NODE*);
void rebalance(NODE*&);
void rebalanceTree(NODE*&);
bool isAVL(NODE*);