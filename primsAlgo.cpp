#include <bits/stdc++.h>
using namespace std;
class Graph {
	int V;
	vector<pair<int , int >>*l;
public:
	Graph(int V) {
		this->V = V;
		l = new vector<pair<int , int>>[V];
	}

	void addEdge(int x , int y , int wt) {
		l[x].push_back({wt , y});
		l[y].push_back({wt , x});
	}

	int primsAlgo() {
		// create a min heap
		priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq;
		// create a bollean visited array
		bool *visited = new bool[V] {0};
		int ans = 0;
		pq.push({0 , 0});
		while (!pq.empty()) {
			auto best = pq.top();
			pq.pop();

			int to = best.second;
			int wt = best.first;
			// if the vertex is visited then we don not add in the queue and
			// simply continue
			if (visited[to]) {
				continue;
			}

			ans += wt;
			visited[to] = true;
			for (auto x : l[to]) {
				if (!visited[x.second]) {
					pq.push({x.first , x.second});

				}
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
    
    cout << g.primsAlgo() << endl;

	return 0;
}