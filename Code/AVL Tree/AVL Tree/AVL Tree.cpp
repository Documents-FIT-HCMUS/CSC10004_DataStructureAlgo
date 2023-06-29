#include "AVL Tree.h"

// CREATE, INSERT AND REMOVE
NODE* createNode(int data)
{
	NODE* node = new NODE;
	node->key = data;
	node->left = nullptr;
	node->right = nullptr;
	node->balance = 0;
    return node;
}
NODE* createAVLTreeFromArray(int a[], int n)
{
    NODE* newTree = createNode(a[0]);
    for (int i = 1; i < n; ++i)
    {
        refreshBalance(newTree);
        if (search(newTree, a[i]) == nullptr)
            insert(newTree, a[i]);
    }
    refreshBalance(newTree);
    return newTree;
}
void insert(NODE*& root, int data)
{
	if (root == nullptr)
	{
		root = createNode(data);
		return;
	}
	if (data < root->key) insert(root->left, data);
	if (data > root->key) insert(root->right, data);
    rebalance(root);
}
void remove(NODE*& root, int x) 
{
    if (root == nullptr) return;
    NODE* removeNode = search(root, x);
    if (removeNode == nullptr) return;

    bool position;
    NODE* parent = findParent(root, removeNode->key, position);

    if (removeNode->left == nullptr && removeNode->right == nullptr) 
    {
        if (parent == nullptr) root = nullptr;
        if (parent != nullptr)
        {
            if (position == LEFT) parent->left = nullptr;
            else if (position == RIGHT) parent->right = nullptr;
        }
        delete removeNode;
    }
    else if (removeNode->left != nullptr && removeNode->right != nullptr) 
    {
        NODE* min = findMin(removeNode->right);
        int minData = min->key;
        remove(root, min->key);
        removeNode->key = minData;
    }
    else 
    {
        if (parent == nullptr) 
        {	
            if (position == LEFT) root = removeNode->left;
            else root = removeNode->right;
        }
        if (parent != nullptr)
            if (removeNode->left != nullptr) 
            {
                if (position == LEFT) parent->left = removeNode->left;
                else parent->right = removeNode->left;
            }
            else 
            {
                if (position == LEFT) parent->left = removeNode->right;
                else parent->right = removeNode->right;
            }
        delete removeNode;
    }
    refreshBalance(root);
    rebalanceTree(root);
}

// UTILITY FUNCTIONS
NODE* findParent(NODE* root, int x, bool& position)
{
    if (root->key == x)
        return nullptr; //the root node of a tree doesn't have parent
    NODE* result, * p;
    result = nullptr;
    p = root;

    while (p != nullptr)
    {
        if (p->key == x) break; //if x is found, break out of the while loop
        if (p->key > x)         //if x is less than p's key, find x in left subtree
        {
            result = p;
            p = p->left;
            position = LEFT;
        }
        if (p->key < x)         //if x is greater than p's key, find x in right subtree
        {
            result = p;
            p = p->right;
            position = RIGHT;
        }
    }
    return result;
}
NODE* findMin(NODE* root)
{
    if (root->left == nullptr)
        return root;
    return findMin(root->left);
}
NODE* search(NODE* root, int x)
{
    if (root == nullptr)
        return root;
    if (root->key == x)
        return root;
    if (x < root->key) return search(root->left, x);
    return search(root->right, x);
}
int height(NODE* root)
{
    if (root == nullptr) return 0;  
    else
    {
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);

        if (leftHeight > rightHeight) return leftHeight + 1;
        else return rightHeight + 1;
    }
}
void leftRotate(NODE*& root)
{
    refreshBalance(root);
    NODE* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;
    refreshBalance(root);
}
void rightRotate(NODE*& root)
{
    refreshBalance(root);
    NODE* temp = root->right;
    root->right = temp->left;
    temp->left = root;
    root = temp;
    refreshBalance(root);
}

// PRINT
void printNLR(NODE* root)   //print tree preorder
{
    if (root == nullptr) return;
    cout << root->key << "(" << root->balance << ") ";
    printNLR(root->left);
    printNLR(root->right);
}
void printLNR(NODE* root)   //print tree inorder
{
    if (root == nullptr) return;
    printLNR(root->left);
    cout << root->key << "(" << root->balance << ") ";
    printLNR(root->right);
}
void printLRN(NODE* root)   //print postorder
{
    if (root == nullptr) return;
    printLRN(root->left);
    printLRN(root->right);
    cout << root->key << "(" << root->balance << ") ";
}
void printLevel(NODE* root, int currentLevel)
{
    if (root == nullptr) return;
    if (currentLevel == 1)
        cout << root->key << "(" << root->balance << ") ";
    else if (currentLevel > 1)
    {
        printLevel(root->left, currentLevel - 1);
        printLevel(root->right, currentLevel - 1);
    }
}
void printLevelOrder(NODE* root)
{
    if (root == nullptr)
    {
        cout << "TREE IS EMPTY!" << endl;
        return;
    }
    int maxHeight = height(root);
    for (int i = 1; i <= maxHeight; ++i)
        printLevel(root, i);
    if (isAVL(root)) cout << endl << "THIS IS AVL!" << endl << endl;
    else cout << endl << "THIS IS NOT AVL!" << endl << endl;
}

// AVL
void refreshBalance(NODE* root)
{
    if (root == nullptr) return;
    root->balance = height(root->right) - height(root->left);
    refreshBalance(root->left);
    refreshBalance(root->right);
}
void rebalance(NODE*& root)
{
    if (root == nullptr) return;
    refreshBalance(root);
    if (root->balance < -1)
    {
        if (root->left->balance <= -1) // LL case
            leftRotate(root);
        else if (root->left->balance >= 1) // LR case
        {
            rightRotate(root->left);
            leftRotate(root);
        }
        else leftRotate(root);
    }
    else if (root->balance > 1)
    {
        if (root->right->balance >= 1) // RR case
            rightRotate(root);
        else if (root->right->balance <= -1) // RL case
        {
            leftRotate(root->right);
            rightRotate(root);
        }
        else rightRotate(root);
    }
    refreshBalance(root);
}
void rebalanceTree(NODE*& root)
{
    if (root == nullptr) return;
    rebalance(root);
    rebalanceTree(root->left);
    rebalanceTree(root->right);
}
bool isAVL(NODE* root)
{
    if (root == nullptr) return true;
    int balance = abs(height(root->left) - height(root->right));
    if (isAVL(root->left) == true && isAVL(root->right) == true)
        if (balance < 2) return true;
    return false;
}