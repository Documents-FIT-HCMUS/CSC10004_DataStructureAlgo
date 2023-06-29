#include "AVL Tree.h"

int main()
{
	const int n = 10;
	int a[n] = { 4, 5, 1, 7, 3, 2, 6, 9, 9, 9 };
	int b[n] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
	NODE* tree1 = createAVLTreeFromArray(a, n);
	printLevelOrder(tree1);
	NODE* tree2 = createAVLTreeFromArray(b, n);
	printLevelOrder(tree2);
	
	remove(tree1, 2);
	remove(tree1, 3);
	remove(tree1, 10);
	printLevelOrder(tree1);
	return 0;
}