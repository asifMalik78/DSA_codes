#include <bits/stdc++.h>
using namespace std;
class DSU {
	int *parent;
	int *rank;
public:
	DSU(int V) {
		parent = new int[V];
		rank = new int[V];
		for (int i = 0 ; i < V ; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	int find(int i) {
		if (parent[i] == -1) {
			return i;
		}

		return parent[i] = find(parent[i]);
	}

	void unite(int a , int b) {
		int s1 = find(a);
		int s2 = find(b);
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
};


class Graph {
	int V;
	vector<vector<int>>edgeList;
public:
	Graph(int V) {
		this->V = V;
	}

	void addEdge(int x , int y , int w) {
		edgeList.push_back({w , x , y});
	}
     
    // void print(){
    // 	for(auto i : edgeList){
    // 		cout << i[0] << " " << i[1] << " " << i[2] << endl;
    // 	}
    // }
	int krushkalAlgo() {
		DSU s(V);
		sort(edgeList.begin() , edgeList.end());
		int ans = 0;
		for (auto edge : edgeList) {
			int w = edge[0];
			int x = edge[1];
			int y = edge[2];
			if (s.find(x) != s.find(y)) {
				s.unite(x , y);
				ans += w;
			}
		}

		return ans;
	}
};
int main() {
	Graph g(4);
	g.addEdge(0 , 1 , 1);
	g.addEdge(1 , 3 , 3);
	g.addEdge(3 , 2 , 4);
	g.addEdge(2 , 0 , 2);
	g.addEdge(0 , 3 , 2);
	g.addEdge(1 , 2 , 2);

	cout << g.krushkalAlgo() << endl;
	// g.print();


	return 0;
}