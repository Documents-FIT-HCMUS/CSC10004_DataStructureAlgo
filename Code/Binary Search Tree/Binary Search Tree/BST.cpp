#include "BST.h"

//CREATION
NODE* createNode(int data)
{
	NODE* newNode = new NODE;
	newNode->key = data;
	newNode->left = newNode->right = nullptr;
    return newNode;
}
NODE* createTree(int a[], int n)
{
    NODE* newTree = createNode(a[0]);   //create a root using the first element of the array
    for (int i = 1; i < n; ++i)
        insert(newTree, a[i]);
    return newTree;
}

//PRINT TREES
void printNLR(NODE* root)   //print tree preorder
{
    if (root == nullptr) return;
    cout << root->key << " ";   //print the key of current node "root"
    printNLR(root->left);       //print the key of left subtree
    printNLR(root->right);      //print the key of right subtree
}
void printLNR(NODE* root)   //print tree inorder
{
    if (root == nullptr) return;
    printLNR(root->left);       //print the key of left subtree
    cout << root->key << " ";   //print the key of current node "root"
    printLNR(root->right);      //print the key of right subtree
}
void printLRN(NODE* root)   //print postorder
{
    if (root == nullptr) return;
    printLRN(root->left);       //print the key of left subtree
    printLRN(root->right);      //print the key of right subtree
    cout << root->key << " ";   //print the key of current node "root"
}

void printLevel(NODE* root, int currentLevel)   //print all values of current tree
{
    if (root == NULL) return;
    if (currentLevel == 1)
        cout << root->key << " ";   //if this is the lowest level, print its values
    else if (currentLevel > 1)      //if this is not, print all values of subtrees recursively
    {
        printLevel(root->left, currentLevel - 1);   //print all values of left subtree
        printLevel(root->right, currentLevel - 1);  //print all values of right subtree
    }
}
void printLevelOrder(NODE* root)
{
    if (root == nullptr)
    {
        cout << "TREE IS EMPTY";
        return;
    }
    int h = height(root);   //calculate the height of current tree
    for (int i = 1; i <= h; ++i)
        printLevel(root, i);    //print the tree's value levels by levels
    cout << endl;
}

//FIND, INSERT AND REMOVE
NODE* search(NODE* root, int x) //find X in tree
{
    if (root == nullptr) return root;
    else if (root->key == x) return root; //if current node is null or we found x, return the node
    else if (root->key > x)  //if current node's key is greater than x, find x in the left subtree
        return search(root->left, x);
    else return search(root->right, x); //finally, find x in the right subtree
}
void insert(NODE*& root, int data)  //insert data into tree
{
    if (root == nullptr)    //if current node is leaf, create new node with key = data
    {
        root = createNode(data);
        return;
    }
    //if current node's key is greater than data, find a place to insert in left subtree
    if (root->key > data)
        insert(root->left, data);
    //if current node's key is less than data, find a place to insert in right subtree
    if (root->key < data)
        insert(root->right, data);
}

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
            position = LEFT_CHILD;
        }
        if (p->key < x)         //if x is greater than p's key, find x in right subtree
        {
            result = p;
            p = p->right;
            position = RIGHT_CHILD;
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
void remove(NODE*& root, int x)
{
    if (root == nullptr) return;
    NODE* removeNode = search(root, x); //find the node that needs to be removed
    bool position;
    if (removeNode == nullptr) return;  //if not found x, exit
    NODE* parent = findParent(root, x, position);   //find the parent node of x
    
    //Case 1: if the node that needs removing has no child
    if (removeNode->left == nullptr && removeNode->right == nullptr)
    {
        //node that needs to remove is the root, and this means the tree has only 1 node
        if (parent == nullptr) root = nullptr;
        //node that needs to remove is the left child of parent
        else if (LEFT_CHILD) parent->left = nullptr;
        //node that needs to remove is the right child
        else if (RIGHT_CHILD) parent->right = nullptr;
        delete removeNode;
    }
    //Case 2: if the node that needs removing has 2 children
    else if (removeNode->left != nullptr && removeNode->right != nullptr)
    {
        NODE* min = findMin(root->right);   //find min node in the right subtree for replacement
        int temp = min->key;
        remove(root, min->key);     //remove min node
        removeNode->key = temp;     //replace node needing removing with min's kry
    }
    //Case 3: if the node that needs removing has only 1 child
    else
    {
        if (parent == nullptr)
        {
            if (removeNode->left != nullptr) root = removeNode->left;
            else root = removeNode->right;
        }
        else if (removeNode->left != nullptr)
        {
            if (LEFT_CHILD) parent->left = removeNode->left;
            else parent->right = removeNode->left;
        }
        else if (removeNode->right != nullptr)
        {
            if (LEFT_CHILD) parent->left = removeNode->right;
            else parent->right = removeNode->right;
        }
        delete removeNode;
    }
}
void removeTree(NODE*& root)
{
    if (root == nullptr) return;
    removeTree(root->left);
    removeTree(root->right);
    remove(root, root->key);
}

//STATISTIC
int height(NODE* root)  //calculate the height of current tree
{
    if (root == nullptr) return 0;  //if node is leaf, its height is 0
    else
    {
        int leftHeight = height(root->left);    //calculate left subtree's height
        int rightHeight = height(root->right);  //calculare right subtree's height

        //the current tree's height will be the max of its two subtree's height
        if (leftHeight > rightHeight) return leftHeight + 1;
        else return rightHeight + 1;
    }
}
int countNode(NODE* root)
{
    if (root == nullptr) return 0;
    return countNode(root->left) + countNode(root->right) + 1;
}
int countLeafNode(NODE* root)
{
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    else return countLeafNode(root->left) + countLeafNode(root->right);
}
int sumNode(NODE* root)
{
    if (root == nullptr) return 0;
    if (root->left == nullptr && root->right == nullptr)
        return root->key;
    return sumNode(root->left) + sumNode(root->right) + root->key;
}
int heightNode(NODE* root, int x)
{
    NODE* resultNode = search(root, x);
    if (resultNode == nullptr) return -1;
    int resultHeight = height(resultNode);
    return resultHeight;
}
int level(NODE* root, NODE* p)
{
    if (p == root) return 1;    //if x is root, its level will be 1
    bool position;
    NODE* parent = findParent(root, p->key, position);
    return level(root, parent) + 1;
}
int countLess(NODE* root, int x)
{
    if (root == nullptr) return 0;
    if (root->key < x)      //if current node is less than x, count and add it with result of subtress
        return countLess(root->left, x) + countLess(root->right, x) + 1;
    //if not, the result is the result of its subtress
    return countLess(root->left, x) + countLess(root->right, x);
}
int countGreater(NODE* root, int x)
{
    if (root == nullptr) return 0;
    if (root->key > x)
        return countGreater(root->left, x) + countGreater(root->right, x) + 1;
    return countGreater(root->left, x) + countGreater(root->right, x);
}

//CHECK
bool isBST(NODE* root)
{
    if (root == nullptr) return true;
    //if left node's key is greater than current node's key
    if (root->left != nullptr)
        if (root->left->key > root->key)
            return false;
    //if right node's key is less than current node's key
    if (root->right != nullptr)
        if (root->right->key < root->key)
            return false;
    //recursively checking the left and right subtree
    if (isBST(root->left) == false || isBST(root->right) == false)
        return false;
    return true;
}
bool isFullBST(NODE* root)
{
    if (root == nullptr) return true;
    //if current node is leaf, it's a full BST
    if (root->left == nullptr && root->right == nullptr)
        return true;
    //if both child of current node is available, check both subtree
    if (root->left != nullptr && root->right != nullptr)
        if (isFullBST(root->left) == true && isFullBST(root->right) == true)
            return true;
    //if none of above is correct, it's not a full BST
    return false;
}