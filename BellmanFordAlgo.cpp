#include <bits/stdc++.h>
using namespace std;
vector<int> bellmanFord(int V , int src , vector<vector<int>>&edgeList) {
	// create a distance vector
	vector<int>dist(V + 1 , INT_MAX);
	dist[src] = 0;
	// traverse all edges in v-1 times
	for (int i = 1 ; i < V - 1 ; i++) {
		for (auto edge : edgeList) {
			int x = edge[0];
			int y = edge[1];
			int wt = edge[2];
			if (dist[x] != INT_MAX and dist[x] + wt < dist[y]) {
				dist[y] = dist[x] + wt;
			}
		}
	}
	//if negative cycle is present
	for (auto edge : edgeList) {
		int x = edge[0];
		int y = edge[1];
		int wt = edge[2];
		if (dist[x] != INT_MAX and dist[x] + wt < dist[y]) {
			cout << "negative wt cycle is found" << endl;
			exit(0);
		}
	}

	return dist;
}
int main() {
	int n , m;
	cin >> n >> m;
	vector<vector<int>>edgeList;
	while (m--) {
		int x , y , wt;
		cin >> x >> y >> wt;
		edgeList.push_back({x , y , wt});
	}

	vector<int>dist = bellmanFord(n , 1 , edgeList);

	for (int i = 1 ; i <= n ; i++) {
		cout << "Node " << i << " is at a distance " << dist[i] << endl;
	}
	return 0;
}