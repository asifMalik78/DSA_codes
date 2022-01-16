#include <bits/stdc++.h>
using namespace std;
class Graph {
	int v;
	list<pair<int , int>>*l;
public:
	Graph(int v) {
		this->v = v;
		l = new list<pair<int , int>>[v];
	}

	void addEdge(int u , int v , int wt) {
		l[u].push_back({v , wt});
		l[v].push_back({u , wt});
	}

	int dfsHelper(int node , bool *visited , int *count , int &ans) {
		visited[node] = true;
		count[node] = 1;
		for (auto nodePair : l[node]) {
			int nbr = nodePair.first;
			int wt = nodePair.second;
			if (!visited[nbr]) {
				count[node] += dfsHelper(nbr, visited , count , ans);
				int nx = count[nbr];
				int ny = v - nx;
				ans += 2 * min(nx , ny) * wt;
			}
		}

		return count[node];
	}
	int dfs() {
		bool *visited = new bool[v] {false};
		int *count = new int[v] {0};
		int ans = 0;
		int c = dfsHelper(0 , visited , count , ans);
		return ans;
	}
};
int main() {
	int n;
	cin >> n;
	Graph g(n);
	while(n>1){
		int x , y , wt;
		cin >> x >> y >> wt;
		g.addEdge(x , y , wt);
	}

	cout << g.dfs() << endl;
	return 0;
}