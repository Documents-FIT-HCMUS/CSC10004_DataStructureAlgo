#include "Doubly Linked List.h"


DNode* createDNode(int data)
{
	DNode* newNode = new DNode;
	newNode->key = data;
	newNode->next = newNode->prev = nullptr;
	return newNode;
}
void createDList(DList*& list, int data)
{
	DNode* node = createDNode(data);
	list->head = node;
	list->tail = node;
}
void printDList(DList* list)
{
	DNode* p = list->head;
	cout << "List: ";
	while (p != nullptr)
	{
		cout << p->key << " ";
		p = p->next;
	}
	cout << endl;
}

DNode* findDNode(DList* list, int data)
{
	DNode* p = list->head;
	while (p != nullptr)
	{
		if (p->key == data) return p;
		p = p->next;
	}
	return nullptr;
}
void addDNodeHead(DList*& list, int data)
{
	DNode* node = createDNode(data);
	node->next = list->head;
	list->head->prev = node;
	list->head = node;
}
void addDNodeTail(DList*& list, int data)
{
	DNode* node = createDNode(data);
	list->tail->next = node;
	node->prev = list->tail;
	list->tail = node;

}
void addBeforeDNode(DList*& list, int data, int keyValue) // Add data BEFORE keyValue
{
	DNode* node = findDNode(list, keyValue);

	// If cannot find the place to insert, add node at the head
	if (node == nullptr || node == list->head)
	{
		addDNodeHead(list, data);
		return;
	}
	// Add node between two nodes
	DNode* prevNode = node->prev;
	DNode* newNode = createDNode(data);
	prevNode->next = newNode;
	node->prev = newNode;
	newNode->next = node;
	newNode->prev = prevNode;
}
void addAfterDNode(DList*& list, int data, int keyValue) // Add data AFTER keyValue
{
	DNode* node = findDNode(list, keyValue);

	// If cannot find the place to insert, add node at the tail
	if (node == nullptr || node == list->tail) 
	{
		addDNodeTail(list, data);
		return;
	}
	// Add node between two nodes
	DNode* nextNode = node->next;
	DNode* newNode = createDNode(data);
	node->next = newNode;
	nextNode->prev = newNode;
	newNode->next = nextNode;
	newNode->prev = node;
}

void removeHead(DList*& list)
{
	DNode* temp = list->head;
	list->head = temp->next;
	temp->next->prev = nullptr;
	delete temp;
}
void removeTail(DList*& list)
{
	DNode* temp = list->tail;
	list->tail = temp->prev;
	temp->prev->next = nullptr;
	delete temp;
}
void removeDNode(DList*& list, int data)
{
	DNode* node = findDNode(list, data);
	if (node == list->head)
	{
		removeHead(list);
		return;
	}
	if (node == list->tail)
	{
		removeTail(list);
		return;
	}
	DNode* nextNode = node->next;
	DNode* prevNode = node->prev;
	prevNode->next = nextNode;
	nextNode->prev = prevNode;
	delete node;
}