#include <vector>
#include <iostream>

using namespace std;
typedef int KeyType;

// treap def
struct Node 
{ 
    int key, priority; 
    Node *left, *right; 
}; 

Node* rightRotate(Node* y)
{
    Node* x = y->left, *T2 = x->right;

    x->right = y;
    y->left = T2;

    return x;
}

Node* leftRotate(Node* x)
{
    Node* y = x->right, *T2 = y->left;

    y->left = x;
    x->right = T2;

    return y;
}

Node* newNode (int key)
{
    Node* temp = NULL;
    temp->key = key;
    temp->priority = rand()%100;
    temp->left = temp->right = NULL;
    return temp;
}

Node* insert(Node* root, int key)
{
    if (!root)
        return newNode(key);

    if (key <= root->key)
    {
        root->left = insert(root->left, key);

        if (root->left->priority > root->priority)
            root = rightRotate(root);
    }
    else
    {
        root->right = insert(root->right, key);

        if (root->right->priority > root->priority)
            root = leftRotate(root);
    }
    return root;
}

void inorder(Node* root)
{
	if (root)
	{
		inorder(root->left);
		cout<< "Key : " << root->key << " | priority: %d " << root->priority;
		if (root->left)
			cout << " | left child : " << root->left->key;
		if (root->right)
			cout << " | right child : " << root->right->key;
		cout << endl;
		inorder(root->right);
	}
}

int main()
{
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 40);
    root = insert(root, 30);
    root = insert(root, 20);

	inorder(root);

    return 0;
}
