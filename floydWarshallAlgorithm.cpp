#include <bits/stdc++.h>
#define INF 10000
using namespace std;
vector<vector<int>> floydWarshellAlgo(vector<vector<int>>&graph) {
	vector<vector<int>>dist(graph);
	int V = graph.size();
	// phases in kth phases we included vertices (1 , 2 , k) as intermediate veritces
	for (int k = 0 ; k < V ; k++) {
		// iterate over the entire 2d matrix
		for (int i = 0 ; i < V ; i++) {
			for (int j = 0 ; j < V ; j++) {
				// k is included  and we can minimise the distance

				dist[i][j] = min(dist[i][j] , dist[i][k] + dist[k][j]);
				// if (dist[i][j] > dist[i][k] + dist[k][j]) {
				// 	dist[i][j] = dist[i][k] + dist[k][j];
				// }
			}
		}
	}

	return dist;
}
int main() {
	vector<vector<int>> graph{
		{0 , INF , -2 , INF},
		{4 , 0 , 3 , INF},
		{INF , INF , 0 , 2},
		{INF , -1 , INF , 0}

	};


	vector<vector<int>> res = floydWarshellAlgo(graph);


	for (int i = 0 ; i < res.size() ; i++) {
		for (int j = 0 ; j < res[0].size() ; j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}