#include <bits/stdc++.h>
using namespace std;
class node {
public:
	char data;
	unordered_map<char , node*>children;
	bool terminal;
	node(char d) {
		data = d;
		terminal = false;
	}
};

class Trie {
public:
	node* root;
	int cnt;
	Trie() {
		root = new node('\0');
		cnt = 0;
	}

	void insert(char *str) {
		node *temp = root;
		for (int i = 0 ; str[i] != '\0' ; i++) {
			char ch = str[i];
			if (temp->children.count(ch)) {
				temp = temp->children[ch];
			}
			else {
				node *n = new node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;
	}

	bool find(char *str) {
		node *temp = root;
		for (int i = 0 ; str[i] != '\0' ; i++) {
			char ch = str[i];
			if (temp->children.count(ch) == 0) {
				return false;
			}
			else {
				temp = temp->children[ch];
			}
		}
		return temp->terminal;
	}
};
int main() {
	Trie t;
	char arr[][50] = {"a" , "hellow" , "not" , "news" , "apple"};
	char ch[10] = "hell";
	for (int i = 0 ; i < 5 ; i++) {
		t.insert(arr[i]);
	}
	if (t.find(ch)) {
		cout << "present"    << endl;
	}
	else {
		cout << "not present" << endl;
	}

	return 0;
}