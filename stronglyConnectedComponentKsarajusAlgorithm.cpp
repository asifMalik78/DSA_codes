#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int>graph[] , int i , bool *visited , vector<int>&stack) {
	visited[i] = true;
	for (auto nbr : graph[i]) {
		if (!visited[nbr]) {
			dfs(graph , nbr , visited , stack);
		}
	}
	// when function call is over we push back the vertices
	stack.push_back(i);
}
void dfs2(vector<int>graph[] , int i , bool *visited) {
	visited[i] = true;
	cout << i << " ";
	for (auto nbr : graph[i]) {
		if (!visited[nbr]) {
			dfs2(graph , nbr , visited);
		}
	}
}
void solve(vector<int>graph[] , vector<int>revGraph[] , int n) {
	bool *visited = new bool[n];
	memset(visited , false , n);

	vector<int>stack;
	// Step - 1 store the vertices according to the dfs finish time
	for (int i = 0 ; i < n ; i++) {
		if (!visited[i]) {
			dfs(graph , i , visited , stack);
		}
	}

	// Step - 2 reverse the graph
	// Step - 2 do dfs according to the ordering of the graph
	char componentName = 'A';
	memset(visited , false , n);
	for (int i = stack.size() - 1 ; i >= 0 ; i--) {
		int node = stack[i];
		if (!visited[node]) {
			cout << " component " << componentName << " ---> ";
			dfs2(revGraph , node , visited);
			cout << endl;
			componentName++;
		}
	}
}
int main() {
	int n;
	cin >> n;
	vector<int>graph[n];
	vector<int>revGraph[n];
	int m;
	cin >> m;
	while (m--) {
		int x , y;
		cin >> x >> y;
		graph[x].push_back(y);
		revGraph[y].push_back(x);
	}
	solve(graph , revGraph , n);
	return 0;
}