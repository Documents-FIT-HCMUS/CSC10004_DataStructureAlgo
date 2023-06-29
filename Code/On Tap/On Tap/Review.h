#pragma once
#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#define MAX 1000
using namespace std;

struct Examinee
{
	string id;
	float math, literature, physic, chemistry, biology, history, geography, civic_education, natural_science,
		social_science, foreign_language;
};
struct Node
{
	int value;
	Node* next;
};
struct List
{
	Node* head;
	Node* tail;
};

//POINTER
void inputArray(int*&, int&);
void printArray(int*, int);
void deallocateArray(int*&, int&);
int findMin(int*, int);
int findMaxModulus(int*, int);
bool isAscending(int*, int);
int sumOfArray(int*, int);
bool isPrime(int);
int countPrime(int*, int);
void reverseArray(int*&, int);

int linearSearch(int*, int, int);
int sentinelLinearSearch(int*, int, int);
void bubbleSort(int*&, int);
int binarySearch(int*, int, int, int);
int recursiveBinarySearch(int*, int, int, int);

//RECURSION
int sumOfSquares(int);
int GCD(int, int);
bool isPalindrome(int[], int);
long long int factorial(int);
int countDigit(int);
int fibonacci(int);

//FILE I/O
void printExaminee(Examinee);
string split(int&, int, string, char);
Examinee readExaminee(string);
vector<Examinee> readExamineeList(string);
void writeTotal(vector<Examinee>&, string);

//LINKED LIST
Node* createNode(int);
List* createList(Node*);
bool addHead(List*&, int);
bool addTail(List*&, int);
void removeHead(List*);
void removeTail(List*);
void removeAll(List*);
void printList(List*);
int countElements(List*);
List* reverseList(List*);
void removeDups(List*&);
bool removeElement(List*&, int);

//STACK
List* initStack(int);
void push(List*&, int);
int pop(List*&);
int countStack(List*);
bool isEmpty(List*);

//QUEUE
List* initQueue(int);
void enqueue(List*&, int);
int dequeue(List*&);
int countQueue(List*);