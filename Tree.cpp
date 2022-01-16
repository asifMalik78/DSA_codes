#include <bits/stdc++.h>
using namespace std;

// 3 4 -1 6 -1 -1 5 1 -1 -1 -1
class node {
public :
	int data;
	node *left;
	node *right;
	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};


// Build A tree in a level order
node *buildtreeLevel()
{
	int d;
	cin >> d;
	queue<node*>q;
	node *root = new node(d);
	q.push(root);
	while (!q.empty()) {
		node *f = q.front();
		q.pop();
		int c1 , c2;
		cin >> c1 >> c2;
		if (c1 >= 0) {
			f->left = new node(c1);
			q.push(f->left);
		}

		if (c2 >= 0) {
			f->right = new node(c2);
			q.push(f->right);
		}
	}

	return root;
}

node *buildTree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}
	node *root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;
}

void printTreePreorder(node *root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	printTreePreorder(root->left);
	printTreePreorder(root->right);

	return;
}

void printTreePostorder(node *root) {
	if (root == NULL) {
		return;
	}
	printTreePostorder(root->left);
	printTreePostorder(root->right);
	cout << root->data << " ";

	return;
}

void printTreeInorder(node *root) {
	if (root == NULL) {
		return;
	}
	printTreeInorder(root->left);
	cout << root->data << " ";
	printTreeInorder(root->right);

	return;
}

// LEVEL ORDER TRAVERSAL

int height(node *root) {
	if (root == NULL) {
		return -1;
	}

	int ls = height(root->left);
	int rs = height(root->right);

	return max(ls , rs) + 1;
}

void printKthLevel(node *root , int k) {
	if (root == NULL) {
		return;
	}

	if (k == 0) {
		cout << root->data << " ";
		return;
	}

	printKthLevel(root->left , k - 1);
	printKthLevel(root->right , k - 1);

	return;
}
// worst case complexity = O(n^2)
void printAllLevel(node *root) {
	int H = height(root);
	for (int i = 1 ; i <= H ; i++) {
		printKthLevel(root , i);
		cout << endl;
	}

	return;
}

// optimized sol of printing level order traversal using BFS(Breath First Search)
void printAllLevelOptimized(node *root) {
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
			cout << res->data << " ";
			q.pop();
			if (res->left)
				q.push(res->left);
			if (res->right)
				q.push(res->right);
		}
	}

	return;
}

// Count and sum nodes of a tree problem solution
int count(node *root) {
	if (root == NULL) {
		return 0;
	}

	return count(root->left) + count(root->right) + 1;
}

int sum(node *root) {
	if (root->left == NULL or root->right == NULL) {
		return root->data;
	}
	return sum(root->left) + sum(root->right) + root->data;
}

// Diameter of Binary Tree Time complexity is O(n^2)
int diameter(node *root) {
	if (root == NULL) {
		return 0;
	}
	int h1 = height(root->left);
	int h2 = height(root->right);
	int op1 = h1 + h2;
	int op2 = diameter(root->left);
	int op3 = diameter(root->right);

	return max(op1 , max(op2 , op3));
}

// Diameter of Binary Tree Optimized of complexity O(n)
class Pair {
public :
	int height;
	int diameter;
};

Pair diameterOptimized(node *root) {
	Pair p;
	if (root == NULL) {
		p.height = p.diameter = 0;
		return p;
	}

	Pair left = diameterOptimized(root->left);
	Pair right = diameterOptimized(root->right);

	p.height = max(left.height , right.height) + 1;
	p.diameter = max(left.height + right.height , max(left.diameter , right.diameter));

	return p;
}

// Binary Tree Sum Replacement
int sumReplacement(node *root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL && root->right == NULL) {
		return root->data;
	}

	int leftSum = sumReplacement(root->left);
	int rightSum = sumReplacement(root->right);

	int temp = root->data;
	root->data = leftSum + rightSum;

	return temp + root->data;
}

// Height Balanced of Tree
class HBTree {
public :
	int height;
	bool balance;
};

HBTree isBalanceTree(node *root) {
	HBTree p;
	if (root == NULL) {
		p.height = 0;
		p.balance = true;
		return p;
	}

	HBTree left = isBalanceTree(root->left);
	HBTree right = isBalanceTree(root->right);

	p.height = max(left.height , right.height) + 1;
	if (abs(left.height - right.height) <= 1 && left.balance && right.balance) {
		p.balance = true;
	}
	else {
		p.balance = false;
	}

	return p;
}

// Make Balanced Tree from an Array
node* makeTreeFromArray(int *arr , int s , int e) {
	if (s > e) {
		return NULL;
	}

	int mid = (s + e) >> 1;
	node *root = new node(arr[mid]);

	root->left = makeTreeFromArray(arr , s , mid - 1);
	root->right = makeTreeFromArray(arr , mid + 1 , e);

	return root;
}

// Building a Tree from Preorder and Inorder Traversal

node* buildTreeFromPreAndIn(int *Inorder , int *Preorder , int s , int e) {
	static int i = 0;
	if (s > e) {
		return NULL;
	}

	node *root = new node(Preorder[i]);
	int index = -1;
	for (int j = s ; j <= e ; j++) {
		if (Preorder[i] == Inorder[j]) {
			index = j;
			break;
		}
	}

	i--;

	root->left = buildTreeFromPreAndIn(Inorder , Preorder , s , index - 1);
	root->right = buildTreeFromPreAndIn(Inorder , Preorder , index + 1 , e);

	return root;
}

// Print right view of a Tree
void printRightViewTree(node *root , int level , int &maxLevel) {
	if (root == NULL) {
		return;
	}

	if (maxLevel < level) {
		cout << root->data << " ";
		maxLevel = level;
	}

	printRightViewTree(root->right , level + 1 , maxLevel);
	printRightViewTree(root->left , level + 1 , maxLevel);

	return;
}

// Node at a distance k from the given node

int printKDistance(node *root , node *target , int k) {
	if (root == NULL) {
		return -1;
	}

	if (root == target) {
		printKthLevel(root , k);
		return 0;
	}

	int DL = printKDistance(root->left , target , k);

	if (DL != -1) {
		if (DL + 1 == k) {
			cout <<  root->data << " ";
		}
		else {
			printKthLevel(root->right , k - 2 - DL);
		}

		return DL + 1;
	}

	int DR = printKDistance(root->right , target , k);

	if (DR != -1) {
		if (DR + 1 == k) {
			cout << root->data << " ";
		}
		else {
			printKthLevel(root->left , k - 2 - DR);
		}

		return DR + 1;
	}

	return -1;
}

// Lowest Common Ancestor
node *lca(node *root , int a , int b) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == a or root->data == b) {
		return root;
	}

	node *left = lca(root->left , a, b);
	node *right = lca(root->right , a, b);

	if (left != NULL and right != NULL) {
		return root;
	}

	if (left != NULL) {
		return left;
	}
	else {
		return right;
	}
}

// Shortest Distance between two nodes in a tree
int search(node *root , int key , int level) {
	if (root == NULL) {
		return -1;
	}

	if (root->data == key) {
		return level;
	}

	int left = search(root->left , key , level + 1);
	if (left != -1) {
		return left;
	}

	return search(root->right , key , level + 1);
}

// Function to find the lowest distance between two nodes
int findDistance(node *root , int a , int b) {
	node *lcaNode = lca(root , a , b);
	int l1 = search(lcaNode , a , 0);
	int l2 = search(lcaNode , b , 0);

	return l1 + l2;
}
// Maximum sum path from any node  to any node in a given Binary Tree
class Pare {
public :
	int maxSum;
	int branchSum;

	Pare() {
		maxSum = 0;
		branchSum = 0;
	}
};

Pare maxSumPath(node *root) {
	Pare p;
	if (root == NULL) {
		return p;
	}

	Pare left = maxSumPath(root->left);
	Pare right = maxSumPath(root->right);

	int op1 = root->data;
	int op2 = left.branchSum + root->data;
	int op3 = right.branchSum + root->data;
	int op4 = left.branchSum + right.branchSum + root->data;

	int currentAnsThroughRoot = max(op1 , max(op2 , max(op3 , op4)));

	p.branchSum = max(left.branchSum , max(right.branchSum , 0)) + root->data;

	p.maxSum = max(currentAnsThroughRoot , max(left.maxSum , right.maxSum));

	return p;
}

// Function to print Binary Tree in 2d order
void print2DTree(node *root , int space) {
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
int main() {
	// node *root = buildTree();
	// printTreePreorder(root);
	// cout << endl;
	// printTreeInorder(root);
	// cout << endl;
	// printTreePostorder(root);
	// cout << endl << height(root) << endl;
	// printKthLevel(root , 3);
	// cout << endl;
	// cout << "All levels" << endl;
	// printAllLevel(root);
	// cout << endl;
	// printAllLevelOptimized(root);
	// cout << endl;
	// cout << count(root) << endl;
	// cout << sum(root) << endl;
	// cout << diameter(root) << endl;
	// Pair p=diameterOptimized(root);
	// cout << p.height << endl;
	// cout << p.diameter << endl;
	// cout << sumReplacement(root) << endl;
	// cout << endl;
	// printAllLevelOptimized(root);
	// if(isBalanceTree(root).balance){
	// 	cout << "Tree is Balanced" << endl;
	// }
	// else{
	// 	cout << "Tree is not Balanced" << endl;
	// }

	// int arr[7] = {1 , 2 , 3 , 4 , 5 , 6 , 7};
	// node *root = makeTreeFromArray(arr , 0 , 6);
	// printAllLevelOptimized(root);

	int Inorder[] = {3 , 2 , 8 , 4 , 1 , 6 , 7 , 5};
	int Preorder[] = {1 , 2 , 3 , 4 , 8 , 5 , 6 , 7};

	node *root = buildTreeFromPreAndIn(Inorder , Preorder , 0 , 7);
	// printAllLevelOptimized(root);
	// cout << endl;
	// int maxLevel = -1;
	// printRightViewTree(root , 0 , maxLevel);
	// node *target=root->left->right;
	// printKDistance(root , target , 3);
	// node *ans = lca(root , 3 , 4);
	// cout << ans->data << endl;
	print2DTree(root , 5);
	// cout << endl  <<  endl;
	// cout << maxSumPath(root).maxSum  << endl;
	// cout << findDistance(root , 6 , 1) << endl;
	// print2DTree(root , 5);
	return 0;
}