#include "Review.h"

int main()
{
	//POINTER
	
	int* a, n, x, temp1, temp2;
	inputArray(a, n);
	printArray(a, n);
	cout << "Phan tu nho nhat la " << findMin(a, n) << endl;
	cout << "Phan tu co tri tuyet doi lon nhat " << findMaxModulus(a, n) << endl;
	if (isAscending(a, n)) cout << "Mang tang dan.\n";
	else cout << "Mang khong tang dan.\n";
	cout << "Tong mang la " << sumOfArray(a, n) << endl;
	cout << "So luong so nguyen to trong mang la " << countPrime(a, n) << endl;

	reverseArray(a, n);
	cout << "Dao mang: ";
	printArray(a, n);

	cout << "Nhap phan tu can tim: ";
	cin >> x;
	temp1 = linearSearch(a, n, x);
	cout << "Linear Search\n";
	if (temp1 > -1) cout << "- Vi tri: " << temp1 + 1 << endl;
	else cout << "- Khong ton tai!!!\n";
	cout << "Sentinel Linear Search\n";
	temp2 = sentinelLinearSearch(a, n, x);
	if (temp2 > -1) cout << "- Vi tri: " << temp2 + 1 << endl;
	else cout << "- Khong ton tai!!!\n";

	bubbleSort(a, n);
	cout << "Mang sap xep tang dan: ";
	printArray(a, n);
	temp1 = binarySearch(a, 0, n - 1, x);
	cout << "Binary Search\n";
	if (temp1 > -1) cout << "- Vi tri: " << temp1 + 1 << endl;
	else cout << "- Khong ton tai!!!\n";
	

	//RECURSION
	
	n = 10;
	int arr[5] = {0, 2, 3, 2, 1};
	cout << sumOfSquares(n) << endl;
	cout << GCD(360, 200) << endl;
	if (isPalindrome(arr, 5)) cout << "Doi xung.\n";
	else cout << "Khong doi xung.\n";
	cout << factorial(n) << endl;
	cout << countDigit(10) << endl;
	cout << fibonacci(n) << endl;
	

	//FILE I/O
	vector<Examinee> examnineeList = readExamineeList("data.txt");
	writeTotal(examnineeList, "data_out.txt");

	//LINKED LIST
	Node* node1 = createNode(5);
	cout << node1->value << ", ";
	cout << "Location: " << node1 << endl;
	List* list1 = createList(node1);
	addHead(list1, 2);
	addHead(list1, 3);
	addHead(list1, 2);
	addHead(list1, 2);
	addHead(list1, 2);
	addHead(list1, 1);
	addTail(list1, 5);
	addTail(list1, 3);
	addTail(list1, 0);
	printList(list1);
	removeHead(list1);
	removeTail(list1);
	//cout << list1->head->value;
	printList(list1);
	cout << "So luong:\t" << countElements(list1) << endl;
	List* list2 = reverseList(list1);
	printList(list2);
	removeElement(list1, 2);
	printList(list1);
	removeDups(list1);
	printList(list1);
	removeAll(list1);
	printList(list1);
	system("pause");
	
	
	//STACK
	List* stack = initStack(10);
	push(stack, 20);
	push(stack, 30);
	push(stack, 40);
	push(stack, 50);
	push(stack, 60);
	push(stack, 70);
	push(stack, 80);
	push(stack, 90);
	printList(stack);
	cout << pop(stack) << endl;
	printList(stack);
	cout << "Stack Size:\t" << countStack(stack) << endl;
	if (!isEmpty(stack)) cout << "Stack khong rong\n";
	else cout << "Stack rong.\n";

	//QUEUE
	List* queue = initQueue(100);
	enqueue(queue, 110);
	enqueue(queue, 120);
	enqueue(queue, 130);
	enqueue(queue, 140);
	enqueue(queue, 150);
	enqueue(queue, 160);
	enqueue(queue, 170);
	enqueue(queue, 180);
	enqueue(queue, 190);
	printList(queue);
	cout << dequeue(queue) << endl;
	printList(queue);
	cout << "Queue Size:\t" << countQueue(queue) << endl;
	if (!isEmpty(queue)) cout << "Queue khong rong\n";
	else cout << "Queue rong.\n";
}
