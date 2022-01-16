#include <bits/stdc++.h>
using namespace std;
template<typename T>
class Graph {
	unordered_map<T , list<pair<T , int>>>mp;
public:
	void addEdge(T x , T y , int dist , bool bidr = true) {
		mp[x].push_back({y , dist});
		if (bidr) {
			mp[y].push_back({x , dist});
		}
	}

	void printAdjacencyList() {
		for (auto p : mp) {
			cout << p.first << " --> ";
			for (auto sp : p.second) {
				cout << "( " << sp.first  << " , " << sp.second << " )";
			}
			cout << endl;
		}
	}

	void dijkstrasAlgortihm(T src) {
		unordered_map<T , int>dist;
		// set all the distance to infinity
		for (auto p : mp) {
			dist[p.first] = INT_MAX;
		}
		// make a set to find out a node with minimum distance
		dist[src] = 0;
		set<pair<int , T>>s;
		s.insert({0 , src});
		while (!s.empty()) {
			// find the pair at the front
			auto p = *s.begin();
			T node = p.second;
			int nodeDist = p.first;

			// deleting the node from the set
			s.erase(s.begin());
			for (auto childPair : mp[node]) {
				if (nodeDist + childPair.second < dist[childPair.first]) {
					// in set updation is not possible so we have to remove the old pair and replace it with a new pair
					auto f = s.find({dist[childPair.first] , childPair.first});
					if (f != s.end()) {
						s.erase(f);
					}

					// insert the new pair
					dist[childPair.first] = nodeDist + childPair.second;
					s.insert({dist[childPair.first] , childPair.first});
				}
				else{
					continue;
				}
			}
		}

		// printing the node
		for (auto d : dist) {
			cout << d.first << " is located at a distance of " << d.second << endl;
		}
	}
};
int main() {
	Graph<int>g;
	g.addEdge(1 , 2 , 1);
	g.addEdge(1 , 3 , 4);
	g.addEdge(2 , 3 , 1);
	g.addEdge(3 , 4 , 2);
	g.addEdge(1 , 4 , 7);
	g.dijkstrasAlgortihm(1);
	// Graph<string>india;
	// india.addEdge("Amritsar" , "Delhi" , 1);
	// india.addEdge("Amritsar" , "Jaipur" , 4);
	// india.addEdge("Jaipur" , "Delhi" , 2);
	// india.addEdge("Jaipur" , "Mumbai" , 8);
	// india.addEdge("Bhopal" , "Agra" , 2);
	// india.addEdge("Mumbai" , "Bhopal" , 3);
	// india.addEdge("Agra" , "Delhi" , 1);
	// india.printAdjacencyList();
	// cout << endl << endl << endl;
	// india.dijkstrasAlgortihm("Amritsar");

	return 0;
}