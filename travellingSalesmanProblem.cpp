#include <bits/stdc++.h>
using namespace std;
int n = 4;
// create a 2d array of 2^n * n
int dp[16][4];
// adj matrix which defines the graph
int dist[10][10] = {
	{0 , 20 , 42 , 25},
	{20 , 0 , 30 , 34},
	{42 , 30 , 0 , 10},
	{25 , 34 , 10 , 0}
};
// if all cities are visited
int Visited_All = (1 << n) - 1;
int tsp(int mask , int pos) {
	if (mask == Visited_All) {
		return dist[pos][0];
	}

	if(dp[mask][pos]!=-1){
		return dp[mask][pos];
	}
	int finalAns = INT_MAX;
	for (int city = 0 ; city < n ; city++) {
		if ((mask & (1 << city)) == 0) {
			int ans = dist[pos][city] +  tsp((mask | (1 << city)) , city);
			finalAns = min(finalAns , ans);
		}
	}

	return dp[mask][pos]=finalAns;
}
int main() {
	memset(dp , -1 , sizeof(dp));
	cout << "min wt hamiltonion path cost "<< tsp(1 , 0) << endl;
	return 0;
}