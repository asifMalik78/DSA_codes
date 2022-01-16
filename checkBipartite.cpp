#include <bits/stdc++.h>
using namespace std;
bool dfsHelper(vector<int>v[] , int node , int *visited , int parent , int color) {
	// come to node
	visited[node] = color;
	for (auto nbr : v[node]) {
		if (visited[nbr] == 0) {
			bool subprob = dfsHelper(v , nbr , visited , node , 3 - color);
			if (!subprob) {
				return false;
			}
		}
		else if (nbr != parent and color == visited[nbr]) {
			return false;
		}
	}

	return true;
}
bool dfs(vector<int>v[] , int N) {
	int visited[N] = {0}; // 0 means not visited 1 and 2 means visited
	int ans = dfsHelper(v , 0 , visited , 0 , 1);
	for (int i = 0 ; i < N ; i++) {
		cout <<  i << " -color " << visited[i] << endl;
	}
	return ans;
}
int main() {
	int n , m ;
	cin >> n >> m;
	vector<int> graph[n];
	while (m--) {
		int x ,  y;
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	if (dfs(graph , n)) {
		cout << "Bipartite graph " << endl;
	}
	else {
		cout << "Not a Bipartite graph " << endl;
	}

	//input
	// 5 4
	// 0 1
	// 0 2
	// 1 3
	// 2 4

	return 0;
}