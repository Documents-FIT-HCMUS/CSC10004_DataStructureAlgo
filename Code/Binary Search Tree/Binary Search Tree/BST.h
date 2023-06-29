#pragma once
#include <iostream>
#define LEFT_CHILD true
#define RIGHT_CHILD false
using namespace std;

struct NODE
{
	int key;
	NODE* left;
	NODE* right;
};

//Create
NODE* createNode(int);
NODE* createTree(int[], int);

//Print
void printNLR(NODE*);
void printLNR(NODE* root);
void printLRN(NODE* root);
void printLevelOrder(NODE*);
void printLevel(NODE*, int);

//Find, insert and remove
NODE* search(NODE*, int);
void insert(NODE*&, int);

NODE* findParent(NODE*, int, bool&);
NODE* findMin(NODE*);
void remove(NODE*&, int);
void removeTree(NODE*&);

//Statistic
int height(NODE*);
int countNode(NODE*);
int countLeafNode(NODE*);
int sumNode(NODE*);
int heightNode(NODE*, int);
int level(NODE*, NODE*);
int countLess(NODE*, int);
int countGreater(NODE*, int);

//Check
bool isBST(NODE*);
bool isFullBST(NODE*);