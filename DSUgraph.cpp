#include <bits/stdc++.h>
using namespace std;
// implimenting using edge list
class Graph {
	int V;
	list<pair<int , int>>l;
public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int u , int v) {
		l.push_back({u , v});
	}
	// finding the set element we want to join
	int find(int i , int *parent) {
		if (parent[i] == -1) {
			return i;
		}

		// return find(parent[i] , parent);
		// optimization
		return parent[i] = find(parent[i] , parent);
	}
	// merging the set
	// void unionSet(int a , int b , int *parent) {
	// 	int s1 = find(a , parent);
	// 	int s2 = find(b , parent);

	// 	// merging
	// 	if (s1 != s2) {
	// 		parent[s1] = s2;
	// 	}
	// }

	// bool checkCycle() {
	// 	int *parent = new int[V];
	// 	for (int i = 0 ; i < V ; i++) {
	// 		parent[i] = -1;
	// 	}

	// 	for (auto edge : l) {
	// 		int i = edge.first;
	// 		int j = edge.second;

	// 		int s1 = find(i , parent);
	// 		int s2 = find(j , parent);
	// 		if (s1 != s2) {
	// 			unionSet(s1 , s2 , parent);
	// 		}
	// 		else {
	// 			cout << "same parent" << s1 << " " << s2 << endl;
	// 			return true;
	// 		}
	// 	}

	// 	delete[] parent;
	// 	return false;
	// }

	// optimized operations
	void unionSet(int a , int b , int *parent , int *rank) {
		int s1 = find(a , parent);
		int s2 = find(b , parent);

		// merging
		if (s1 != s2) {
			if (rank[s1] < rank[s2]) {
				parent[s1] = s2;
				rank[s2] += rank[s1];
			}
			else {
				parent[s2] = s1;
				rank[s1] += rank[s2];
			}
		}
	}

	bool checkCycle() {
		int *parent = new int[V];
		int *rank = new int[V];

		for (int i = 0 ; i < V ; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for (auto edge : l) {
			int i = edge.first;
			int j = edge.second;

			int s1 = find(i , parent , rank);
			int s2 = find(j , parent , rank);
			if (s1 != s2) {
				unionSet(s1 , s2 , parent , rank);
			}
			else {
				cout << "same parent" << s1 << " " << s2 << endl;
				return true;
			}
		}

		delete[] parent;
		return false;
	}
};
int main() {
	Graph g(4);
	g.addEdge(1 , 2);
	g.addEdge(2 , 3);
	g.addEdge(3 , 4);
	g.addEdge(4 , 1);
	if (g.checkCycle()) {
		cout << "cycle is present" << endl;
	}
	else {
		cout << "cycle is not present" << endl;
	}
	return 0;
}