#include <bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	node *left;
	node *right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}

};

node *insertNode(node *root , int d) {
	if (root == NULL) {
		return new node(d);
	}

	if (d <= root->data) {
		root->left = insertNode(root->left , d);
	}
	else {
		root->right = insertNode(root->right , d);
	}

	return root;
}
node *buildTree() {
	int d;
	cin >> d;
	node *root = NULL;
	while (d != -1) {
		root = insertNode(root , d);
		cin >> d;
	}

	return root;
}
void bfs(node *root) {
	queue<node*>q;
	q.push(root);
	q.push(NULL);
	while (!q.empty()) {
		node *res = q.front();
		if (res == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		}
		else {
			q.pop();
			cout << res->data << " ";
			if (res->left) {
				q.push(res->left);
			}
			if (res->right) {
				q.push(res->right);
			}
		}
	}

	return;
}

void inorder(node *root) {
	if (root == NULL) {
		return;
	}

	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);

	return;
}

void print2DTree(node *root , int space = 5) {
	static int globalSpace = 5;
	if (root == NULL) {
		return;
	}
	space += globalSpace;
	print2DTree(root->right , space);
	cout << endl;
	for (int i = globalSpace ; i < space ; i++) {
		cout << " ";
	}
	cout << root->data << endl;

	print2DTree(root->left , space);

	return;
}

bool searchIteratively(node *root , int key) {
	node *temp = root;
	while (temp != NULL) {

		if (temp->data == key) {
			return true;
		}
		if (key > temp->data) {
			temp = temp->right;
		}
		else {
			temp = temp->left;
		}

	}
	return false;
}

bool searchRecursively(node *root , int key) {
	if (root == NULL) {
		return false;
	}

	if (root->data == key) {
		return true;
	}

	if (key <= root->data) {
		return searchRecursively(root->left , key);
	}
	else {
		return searchRecursively(root->right , key);
	}
}

// Deletion in BST
node *deletionInBST(node *root , int key) {
	if (root == NULL) {
		return NULL;
	}

	if (key < root->data) {
		root->left = deletionInBST(root->left , key);
		return root;
	}
	else if (key == root->data) {
		if (root->left == NULL && root->right == NULL) {
			delete root;
			return NULL;
		}
		if (root->left != NULL && root->right == NULL) {
			node *temp = root->left;
			delete root;
			return temp;
		}

		if (root->left == NULL && root->right != NULL) {
			node *temp = root->right;
			delete root;
			return temp;
		}


		node *replace = root->right;
		while (replace->left != NULL) {
			replace = replace->left;
		}
		root->data = replace->data;
		root->right = deletionInBST(root->right , replace->data);

		return root;
	}
	else {
		root->right = deletionInBST(root->right , key);
		return root;
	}
}

// Check whether the BST is balance or not
bool isBalance(node *root , int minV = INT_MIN , int maxV = INT_MAX) {
	if (root == NULL) {
		return true;
	}

	if (root->data >= minV && root->data <= maxV && isBalance(root->left , minV , root->data) && isBalance(root->right , root->data , maxV)) {
		return true;
	}

	return false;
}

// Convert a BST into a linear data structure (Linked List)
class LinkedList {
public:
	node *head;
	node *tail;
};

LinkedList flatten(node *root) {
	LinkedList l;
	if (root == NULL) {
		l.head = l.tail = NULL;
		return l;
	}

	if (root->left == NULL and root->right == NULL) {
		l.head = l.tail = root;
		return l;
	}

	if (root->left != NULL and root->right == NULL) {
		LinkedList left = flatten(root->left);
		left.tail->right = root;
		l.head = left.head;
		l.tail = root;
		return l;
	}

	if (root->left == NULL and root->right != NULL) {
		LinkedList right = flatten(root->right);
		root->right = right.head;
		l.head = root;
		l.tail = right.tail;
		return l;
	}

	LinkedList left = flatten(root->left);
	LinkedList right = flatten(root->right);
	left.tail->right = root;
	root->right = right.head;

	l.head = left.head;
	l.tail = right.tail;

	return l;
}

// Print ZIG-ZAG Level order of a bst (using two stack)
void printZigZag(node *root) {

	stack<node*>currLevel;
	stack<node*>nextLevel;
	bool leftToRight = true;
	currLevel.push(root);
	while (!currLevel.empty()) {
		node *temp = currLevel.top();
		currLevel.pop();
		if (temp) {
			cout << temp->data << " ";
			if (leftToRight) {
				if (temp->left) {
					nextLevel.push(temp->left);
				}
				if (temp->right) {
					nextLevel.push(temp->right);
				}
			}
			else {
				if (temp->right) {
					nextLevel.push(temp->right);
				}
				if (temp->left) {
					nextLevel.push(temp->left);
				}
			}
		}

		if (currLevel.empty()) {
			swap(currLevel , nextLevel);
			leftToRight = !leftToRight;
		}
	}
}

// Build a Bst from preorder traversal optimized O(n)
node *buildBSTFromPreorder(node *root , int *preorder , int &idx , int data , int n , int minV = INT_MIN , int maxV = INT_MAX) {

	if (idx >= n) {
		return NULL;
	}

	if (data > minV and data < maxV) {
		root = new node(data);
		idx++;

		if (idx < n) {
			root->left = buildBSTFromPreorder(root->left , preorder , idx , preorder[idx] , n , minV , data);
		}

		if (idx < n) {
			root->right = buildBSTFromPreorder(root->right , preorder , idx , preorder[idx] , n , data , maxV);
		}

	}


	return root;
}

int main() {
	// node *root = buildTree();
	// inorder(root);
	// cout << endl;
	// bfs(root);
	// cout << endl;
	// print2DTree(root , 5);
	// cout << endl << endl;
	// if(searchRecursively(root , 8)){
	// 	cout << "present" << endl;
	// }
	// else{
	// 	cout << "not present" << endl;
	// }
	// node *res = deletionInBST(root , 7);
	// bfs(root);
	// print2DTree(res);
	// cout << endl << endl;
	// if (isBalance(root)) {
	// 	cout << "Tree is Balance" << endl;
	// }
	// else {
	// 	cout << "Tree is not Balance" << endl;
	// }
	// print2DTree(root);
	// cout << "zig-zag level oreder traversal" << endl;
	// printZigZag(root);
	// LinkedList res = flatten(root);
	// node *temp = res.head;
	// while (temp != NULL) {
	// 	cout << temp->data << "-->";
	// 	temp = temp->right;
	// }
	// cout << "NULL" << endl;

	// cout << endl;
	int n;
	cin >> n;
	int p[n];
	for (int i = 0 ; i < n ; i++) {
		cin >> p[i];
	}
	int idx = 0;
	node *root = NULL;
	root = buildBSTFromPreorder(root , p , idx , p[0] , n );
	print2DTree(root);

	return 0;
}