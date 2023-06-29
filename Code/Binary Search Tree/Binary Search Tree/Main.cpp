#include "BST.h"

int main()
{
	int a[9] = { 9, 6, 4, 2, 3, 5, 1, 7, 10 };
	int x = 7;
	NODE* tree = createTree(a, 9);
	NODE* tree1 = createNode(100);
	printLevelOrder(tree);
	cout << "There are " << countNode(tree) << " nodes." << endl;
	cout << "There are " << countLeafNode(tree) << " leaf nodes." << endl;
	cout << "Sum of all nodes is " << sumNode(tree) << endl;
	cout << "Height of " << x << " is " << heightNode(tree, x) << endl;
	cout << "There are " << countLess(tree, 5) << " node less than 5." << endl;
	cout << "There are " << countGreater(tree, 5) << " node greater than 5." << endl;
	if (isBST(tree)) cout << "This is a BST." << endl;
	else cout << "This is NOT a BST." << endl;
	if (isFullBST(tree)) cout << "This is a Full BST." << endl;
	else cout << "This is NOT a Full BST." << endl;

	/*NODE* node = search(tree, 1);
	if (node == nullptr) cout << "KEY NOT FOUND!!!" << endl;
	else cout << "Key is at: " << node << endl;*/

	/*cout << endl;
	remove(tree, 3);
	remove(tree, 8);
	printLevelOrder(tree);
	cout << "There are " << countNode(tree) << " nodes." << endl;
	cout << "There are " << countLeafNode(tree) << " leaf nodes." << endl;
	cout << "Sum of all nodes is " << sumNode(tree) << endl;
	cout << "Height of " << x << " is " << heightNode(tree, x) << endl;
	cout << "There are " << countLess(tree, 5) << " node less than 5." << endl;	
	cout << "There are " << countGreater(tree, 5) << " node greater than 5." << endl;
	if (isBST(tree)) cout << "This is a BST." << endl;
	else cout << "This is NOT a BST." << endl;
	if (isFullBST(tree)) cout << "This is a  Full BST." << endl;
	else cout << "This is NOT a Full BST." << endl;

	cout << "Input key: ";
	cin >> x;
	NODE* temp = search(tree, x);
	if (temp != nullptr) cout << "Level of " << x << " is " << level(tree, temp) << endl;
	else cout << "NODE NOT FOUND!!!" << endl;*/

	return 0;
}