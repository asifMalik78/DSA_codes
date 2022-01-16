#include <bits/stdc++.h>
using namespace std;

// DFS search on graph

// template<typename T>
// class Graph{
// 	unordered_map<T , list<T>>l;
// public:
// 	void addEdge(T x , T y){
// 		l[x].push_back(y);
// 		l[y].push_back(x);
// 	}

// 	void dfs_Helper(T src , unordered_map<T , bool> &visited){
//         // recursive function that will traverse the graph
// 		cout << src << " ";
// 		visited[src]=true;
// 		for(auto nbr : l[src]){
// 			// go to all the neibhour that is not visited
// 			if(!visited[nbr]){
// 				dfs_Helper(nbr , visited);
// 			}
// 		}
// 	}

// 	void dfs(T src){
// 		unordered_map<T , bool>visited;
// 		for(auto it : l){
// 			// mark all the vertices is initially false
// 			T node=it.first;
// 			visited[node]=false;
// 		}

// 		dfs_Helper(src , visited);
// 	}
// };


// connected components  using DFS graph


// template<typename T>
// class Graph {
// 	     map<T , list<T>>l;
// public:
// 	void addEdge(T x , T y) {
// 		l[x].push_back(y);
// 		l[y].push_back(x);
// 	}

// 	void dfs_Helper(T src , unordered_map<T , bool> &visited) {
// 		// recursive function that will traverse the graph
// 		cout << src << " ";
// 		visited[src] = true;
// 		for (auto nbr : l[src]) {
// 			// go to all the neibhour that is not visited
// 			if (!visited[nbr]) {
// 				dfs_Helper(nbr , visited);
// 			}
// 		}
// 	}

// 	void dfs() {
// 		unordered_map<T , bool>visited;
// 		for (auto it : l) {
// 			// mark all the vertices is initially false
// 			T node = it.first;
// 			visited[node] = false;
// 		}
// 		int cnt = 1;
// 		for (auto p : l) {
// 			if (!visited[p.first]) {
// 				cout << "components" << " " << cnt << " --> ";
// 				dfs_Helper(p.first , visited);
// 				cout << endl;
// 				cnt++;
// 			}
// 		}
// 	}
// };


// topological sorting using dfs

// template<typename T>
// class Graph {
// 	map<T , list<T>>l;
// public:
// 	void addEdge(T x , T y) {
// 		l[x].push_back(y);
// 		// l[y].push_back(x);
// 	}

// 	void dfs_Helper(T src , unordered_map<T , bool> &visited , list<T>&ordering) {
// 		// recursive function that will traverse the graph
// 		visited[src] = true;
// 		for (auto nbr : l[src]) {
// 			// go to all the neibhour that is not visited
// 			if (!visited[nbr]) {
// 				dfs_Helper(nbr , visited , ordering);
// 			}
// 		}

// 		ordering.push_front(src);
// 		return;
// 	}

// 	void dfs() {
// 		unordered_map<T , bool>visited;
// 		for (auto it : l) {
// 			// mark all the vertices is initially false
// 			T node = it.first;
// 			visited[node] = false;
// 		}
// 		list<T>ordering;
// 		for (auto p : l) {
// 			if (!visited[p.first]) {
// 				dfs_Helper(p.first , visited , ordering);
// 			}
// 		}

// 		for (auto node : ordering) {
// 			cout << node << endl;
// 		}
// 		cout << endl;
// 	}
// };


// topological sort using bfs
template<typename T>
class Graph {
	map<T , list<T>>l;
public:
	void addEdge(T x , T y) {
		l[x].push_back(y);
		// l[y].push_back(x);
	}

	void topological_sort() {

		for(auto i : l){
			cout << i.first << " --> ";
			for(auto j : i.second){
				cout << j << endl;
			}
		}
		T *indegree = new T[100]();// addded(); this will initialise all enteries to 0

        // setting all the indegrees to zero 
		// for (auto nodes : l) {
		// 	indegree[nodes.first] = 0;
		// }
        // setting all indegrees with their values
		for (auto p : l) {
			for (auto y : p.second) {
				indegree[y]++;
			}
		}

		queue<T>q;
		// pushging those vertices whose indegrees is 0
		for (auto nodes : l) {
			if (indegree[nodes.first] == 0) {
				q.push(nodes.first);
			}
		}

		while (!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbr : l[node]) {
				indegree[nbr]--;
				if (indegree[nbr] == 0) {
					q.push(nbr);
				}
			}
		}

	}


};
int main() {
	// Graph<int> g;
	// g.addEdge(1 , 2);
	// g.addEdge(2,  3);
	// g.addEdge(1 , 0);
	// g.addEdge(0 , 3);
	// g.addEdge(3 , 4);
	// g.addEdge(4 , 5);
	// g.dfs(0);



	// Graph<int> g;
	// g.addEdge(0 , 1);
	// g.addEdge(1,  2);
	// g.addEdge(2 , 3);
	// g.addEdge(0 , 3);
	// g.addEdge(0 , 4);

	// g.addEdge(5 , 6);
	// g.addEdge(6 , 7);

	// g.addEdge(8 , 8);

	// g.dfs();

	// Graph<string>g;
	// g.addEdge("Python" , "Data Preprocessing");
	// g.addEdge("Python" , "PyTorch");
	// g.addEdge("Python" , "ML");
	// g.addEdge("Data Preprocessing" , "ML");
	// g.addEdge("ML" , "DL");
	// g.addEdge("DL" , "Face Recognition");
	// g.addEdge("Data Set" , "Face Recognition");
	// g.dfs();

	Graph<int>g;
	g.addEdge(0, 2);
	g.addEdge(2, 3);
	g.addEdge(2, 5);
	g.addEdge(1, 2);
	g.addEdge(1, 4);
	g.addEdge(3, 5);
	
	g.topological_sort();

	return 0;
}