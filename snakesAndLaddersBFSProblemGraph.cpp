#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
	map<T , list<T>>l;
public:
	void addEdge(T x , T y) {
		l[x].push_back(y);
	}

	T bfs(T src , T dest) {
		unordered_map<T , int>dist;
		unordered_map<T , T>parent;
		for (auto i : l) {
			dist[i.first] = INT_MAX;
		}
		parent[src]=src;
		queue<T>q;
		dist[src] = 0;
		q.push(src);
		while (!q.empty()) {
			T current = q.front();
			// cout << current << " ";
			q.pop();
			for (auto nbr : l[current]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[current] + 1;
					parent[nbr]=current;
				}
			}
		}
        
        T temp=dest;
        while(temp != src){
        	cout << temp << " <-- " ;
        	temp=parent[temp]; 
        }
        cout << src << endl;
		return dist[dest];

	}
};
int main() {

	int board[50]={0};
	board[2]=13;
	board[5]=2;
	board[9]=18;
	board[18]=11;
	board[17]=-13;
	board[20]=-14;
	board[24]=-8;
	board[25]=10;
	board[32]=-2;
	board[34]=-22;

	Graph<int>g;
	for(int i=0 ; i<=36 ; i++){
		for(int dice=1 ; dice<=6 ; dice++){
			int j=i+dice;
			j+=board[j];
			if(j<=36){
				g.addEdge(i , j);
			}		
		}
	}
	g.addEdge(36 , 36);
	cout << g.bfs(0, 36) << endl;

	return 0;
}