#include "Review.h"

//POINTER
void inputArray(int*& a, int& n)
{
	cout << "Nhap n nguyen duong: ";
	cin >> n;
	a = new int[n];
	for (int i = 0; i < n; ++i)
	{
		cout << "Nhap phan tu " << i + 1 << ": ";
		cin >> a[i];
	}
}
void printArray(int* a, int n)
{
	if (a == NULL)
	{
		cout << "ARRAY IS EMPTY!!!\n";
		return;
	}
	for (int i = 0; i < n; ++i)
		cout << a[i] << " ";
	cout << endl;
}
void deallocateArray(int*& a, int& n)
{
	delete[]a;
	a = NULL;
}
int findMin(int* a, int n)
{
	if (n == 1) return a[n];
	int min = a[0];
	for (int i = 1; i < n; ++i)
		if (a[i] < min) min = a[i];
	return min;
}
int findMaxModulus(int* a, int n)
{
	if (n == 1) return a[n - 1];
	int max = abs(a[0]);
	for (int i = 1; i < n; ++i)
		if (abs(a[i]) > max) max = a[i];
	return max;
}
bool isAscending(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
		if (a[i] >= a[i + 1]) return false;
	return true;
}
int sumOfArray(int* a, int n)
{
	if (n == 1) return a[n - 1];
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i];
	return sum;
}
bool isPrime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i <= sqrt(x); ++i)
		if (x % i == 0) return false;
	return true;
}
int countPrime(int* a, int n)
{
	int d = 0;
	for (int i = 0; i < n; ++i)
		if (isPrime(a[i])) ++d;
	return d;
}
void reverseArray(int*& a, int n)
{
	for (int i = 0; i < n / 2; ++i)
		swap(a[i], a[n - 1 - i]);
}

int linearSearch(int* a, int n, int x)
{
	for (int i = 0; i < n; ++i)
		if (a[i] == x) return i;
	return -1;
}
int sentinelLinearSearch(int* a, int n, int x)
{
	a[n] = x;
	int i = 0;
	while (a[i] != x) ++i;
	if (i < n) return i;
	return -1;
}
void bubbleSort(int*& a, int n)
{

	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - i - 1; j++)
			if (a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
}
int binarySearch(int* a, int left, int right, int x)
{
	int mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x) return mid;
		else if (a[mid] < x) left = mid + 1;
		else if (a[mid] > x) right = mid - 1;
	}
	return -1;
}
int recursiveBinarySearch(int* a, int left, int right, int x)
{
	int mid;
	if (left <= right)
	{
		mid = (right - left) / 2;
		if (a[mid] == x) return mid;
		else if (a[mid] < x) return recursiveBinarySearch(a, mid + 1, right, x);
		else if (a[mid] > x) return recursiveBinarySearch(a, left, mid - 1, x);
	}
	return -1;
}

//RECURSION
int sumOfSquares(int n)
{
	if (n == 1) return 1;
	return n * n + sumOfSquares(n - 1);
}
int GCD(int a, int b)
{
	if (b == 0)
		return a;
	else return GCD(b, a % b);
 }
bool isPalindrome(int a[], int n)
{
	if (n <= 1) return true;
	if (a[0] == a[n - 1]) return isPalindrome((a + 1), n - 2);
	else return false;
}
long long int factorial(int n)
{
	if (n == 1) return 1;
	return n * factorial(n - 1);
}
int countDigit(int n)
{
	if (n < 10) return 1;
	return countDigit(n / 10) + 1;
}
int fibonacci(int n)
{
	if (n == 1 || n == 2) return 1;
	return fibonacci(n - 1) + fibonacci(n - 2);
}

//FILE I/O
void printExaminee(Examinee p)
{
	cout << p.id << " " << p.math << " " << p.literature << " " << p.physic << " " << p.chemistry 
		<< " " << p.biology << " " << p.history << " " << p.geography << " " << p.foreign_language 
		<< " " << p.civic_education << endl;
}
string split(int& i, int n, string s, char a)
{
	string buffer;
	while (i < n - 1)
	{
		if (s[i] == a)
		{
			++i;
			break;
		}
		buffer.push_back(s[i]);
		++i;
	}
	if (buffer.size() == 0) buffer = "0";
	return buffer;
}
Examinee readExaminee(string line_info)
{
	Examinee result;
	string dump;
	int n = line_info.size();
	int i = 0;
	result.id = split(i, n, line_info, ',');
	dump = split(i, n, line_info, ',');
	result.math = stof(split(i, n, line_info, ','));
	result.literature = stof(split(i, n, line_info, ','));
	result.physic = stof(split(i, n, line_info, ','));
	result.chemistry = stof(split(i, n, line_info, ','));
	result.biology = stof(split(i, n, line_info, ','));
	result.history = stof(split(i, n, line_info, ','));
	result.geography = stof(split(i, n, line_info, ','));
	result.civic_education = stof(split(i, n, line_info, ','));
	result.natural_science = stof(split(i, n, line_info, ','));
	result.social_science = stof(split(i, n, line_info, ','));
	result.foreign_language = stof(split(i, n, line_info, ','));
	dump = split(i, n, line_info, ',');
	dump = split(i, n, line_info, '\n');
	return result;
}
vector<Examinee> readExamineeList(string in_file_name)
{
	fstream fi;
	vector<Examinee> result;
	string s;
	fi.open(in_file_name, ios::in);
	fi.ignore(numeric_limits<streamsize>::max(), '\n');
	while (!fi.eof())
	{
		//fi >> s;
		getline(fi, s);
		result.push_back(readExaminee(s));
	}
	fi.close();
	return result;
}
void writeTotal(vector<Examinee>& list, string out_file_name)
{
	fstream fo;
	fo.open(out_file_name, ios::out);
	for (unsigned int i = 0; i < list.size(); ++i)
	{
		list.at(i).natural_science = list.at(i).physic + list.at(i).chemistry + list.at(i).biology;
		list.at(i).social_science = list.at(i).history + list.at(i).geography + list.at(i).civic_education;
		int sum, sum_1, sum_2;
		sum_1 = list.at(i).math + list.at(i).literature + list.at(i).foreign_language;
		sum_2 = list.at(i).natural_science + list.at(i).social_science;
		sum = sum_1 + sum_2;
		fo << list.at(i).id << " " << sum << endl;
	}
	fo.close();
}

//LINKED LIST
Node* createNode(int data)
{
	Node* newNode = new Node;
	newNode->value = data;
	newNode->next = nullptr;
	return newNode;
}
List* createList(Node* node)
{
	List* list = new List;
	list->head = list->tail = node;
	return list;
}
bool addHead(List*& list, int data)
{
	Node* temp = list->head;
	Node* newNode = createNode(data);
	newNode->next = temp;
	list->head = newNode;
	return true;
}
bool addTail(List*& list, int data)
{
	Node* temp = list->tail;
	Node* newNode = createNode(data);
	temp->next = newNode;
	list->tail = newNode;
	return true;
}
void removeHead(List* list)
{
	Node* temp = list->head;
	if (temp == nullptr) return;
	list->head = temp->next;
	temp->next = nullptr;
	delete temp;
}
void removeTail(List* list)
{
	Node* p = list->head;
	Node* temp;
	Node* dummy;
	if (p == nullptr) return;
	if (p->next == nullptr)
	{
		removeHead(list);
		return;
	}
	while (p->next->next != nullptr) p = p->next;
	temp = p;
	dummy = temp->next;
	temp->next = nullptr;
	list->tail = temp;
}
void removeAll(List* list)
{
	//Node* p = list->head;
	if (list->head == nullptr) return;
	while (list->head != nullptr) removeHead(list);
}
void printList(List* list)
{
	Node* p = list->head;
	if (p == nullptr)
	{
		cout << "Linked List is EMPTY!!!\n";
		return;
	}
	cout << "List:\t\t";
	while (p != nullptr)
	{
		cout << p->value << " ";
		p = p->next;
	}
	cout << endl;
}
int countElements(List* list)
{
	int result = 0;
	Node* p = list->head;
	if (p == nullptr) return result;
	while (p != nullptr)
	{
		++result;
		p = p->next;
	}
	return result;
}
List* reverseList(List* list)
{
	Node* p = list->head;
	Node* initNode = createNode(p->value);
	List* newList = createList(initNode);
	if (p->next == nullptr) return newList;
	p = p->next;
	while (p != nullptr)
	{
		addHead(newList, p->value);
		p = p->next;
	}
	return newList;
}
void removeDups(List*& list)
{
	Node* p1, * p2;
	Node* temp;
	p1 = list->head;
	while (p1 != nullptr && p1->next != nullptr)
	{
		p2 = p1;
		while (p2->next != nullptr)
		{
			if (p1->value == p2->next->value)
			{
				temp = p2->next;
				p2->next = p2->next->next;
				delete temp;
			}
			else p2 = p2->next;
		}
		p1 = p1->next;
	}
	//Source Code co su dung tai lieu tham khao tu website geeksforgeeks.org
	//Nov 2020, Copyright Reserved
}
bool removeElement(List*& list, int key)
{
	Node* p, * temp;
	p = list->head;
	//Remove n first elements equal to key
	while (p->value == key)
	{
		temp = p;
		p = p->next;
		list->head = p;
		delete temp;
	}
	while (p != nullptr && p->next != nullptr)
	{
		if (p->next->value == key)
		{
			temp = p->next;
			p->next = p->next->next;
			delete temp;
		}
		else p = p->next;
	}
	return true;
}

//STACK
List* initStack(int data)
{
	List* list = new List;
	Node* node = createNode(data);
	list->head = list->tail = node;
	return list;
}
void push(List*& list, int data)
{
	addTail(list, data);
}
int pop(List*& list)
{
	int result = list->tail->value;
	removeTail(list);
	return result;
}
int countStack(List* stack)
{
	int result = 0;
	Node* p = stack->head;
	if (p == nullptr) return result;
	while (p != nullptr)
	{
		++result;
		p = p->next;
	}
	return result;
}
bool isEmpty(List* stack)
{
	if (countStack(stack) > 0) return false;
	return true;
}

//QUEUE
List* initQueue(int data)
{
	List* list = new List;
	Node* node = createNode(data);
	list->head = list->tail = node;
	return list;
}
void enqueue(List*& queue, int data)
{
	addTail(queue, data);
}
int dequeue(List*& queue)
{
	int result = queue->head->value;
	removeHead(queue);
	return result;
}
int countQueue(List* queue)
{
	int result = 0;
	Node* p = queue->head;
	if (p == nullptr) return result;
	while (p != nullptr)
	{
		++result;
		p = p->next;
	}
	return result;
}