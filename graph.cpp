#include <bits/stdc++.h>
using namespace std;
// implementation of adjacency list


// class Graph{
// 	int V;
// 	list<int>*l;
// public:
// 	Graph(int V){
// 		this->V=V;
// 		l=new list<int>[V];
// 	}

// 	void addEdge(int x , int y){
// 		l[x].push_back(y);
// 		l[y].push_back(x);
// 	}

// 	void print(){
// 		for(int i=0 ; i<V ; i++){
// 			cout <<"Vertex -> " << i << "-> ";
// 			for(auto nbh : l[i]){
// 				cout << nbh << " ";
// 			}
// 			cout << endl;
// 		}
// 	}
// };

// implementation of generic data of adjacency list of a graph

// class Graph{
// 	unordered_map<string , list<pair<string , int>>>l;
// public:
// 	void addEdge(string x , string y , bool bDir , int wt){
// 		l[x].push_back(make_pair(y , wt));
// 		if(bDir){
// 			l[y].push_back({x , wt});
// 		}
// 	}

// 	void print(){
// 		for(auto i : l){
// 			cout << "city : " << i.first;
// 			for(auto j : i.second){
// 				cout << "( "<< j.first << " " << j.second  << " ) -> ";
// 			}
// 			cout << endl;
// 		}
// 	}
// };


// implementation of BFS


// template<typename T>
// class Graph{
// 	unordered_map<T , list<T>>l;
// public:
// 	void addEdge(T x , T y){
// 		l[x].push_back(y);
// 		l[y].push_back(x);
// 	}

// 	void bfs(T src){
// 		queue<T>q;
// 		unordered_map<T , bool>visited;
// 		visited[src]=true;
// 		q.push(src);
// 		while(!q.empty()){
// 			T current=q.front();
// 			cout << current << " ";
// 			q.pop();
// 			for(auto nbr : l[current]){
// 				if(!visited[nbr]){
// 					q.push(nbr);
// 					visited[nbr]=true;
// 				}
// 			}
// 		}

// 	}


// 	void print(){
// 		for(auto i : l){
// 			cout << "city : " << i.first;
// 			for(auto j : i.second){
// 				cout << "( "<< j.first << " " << j.second  << " ) -> ";
// 			}
// 			cout << endl;
// 		}
// 	}
// };


// shortest using bfs algorithm

// template<typename T>
// class Graph{
// 	map<T , list<T>>l;
// public:
// 	void addEdge(T x , T y){
// 		l[x].push_back(y);
// 		l[y].push_back(x);
// 	}

// 	void bfs(T src){
// 		unordered_map<T , int>dist;
// 		for(auto i : l){
// 			dist[i.first]=INT_MAX;
// 		}
// 		queue<T>q;
// 		dist[src]=0;
// 		q.push(src);
// 		while(!q.empty()){
// 			T current=q.front();
// 			// cout << current << " ";
// 			q.pop();
// 			for(auto nbr : l[current]){
// 				if(dist[nbr]==INT_MAX){
// 					q.push(nbr);
// 					dist[nbr]=dist[current]+1;
// 				}
// 			}
// 		}

// 		for(auto nodePair : l){
// 			T node=nodePair.first;
// 			int d=dist[node];

// 			cout << "node " << node << " -> distance from source " << d << endl;

// 		}

// 	}


// 	void print(){
// 		for(auto i : l){
// 			cout << "city : " << i.first;
// 			for(auto j : i.second){
// 				cout << "( "<< j.first << " " << j.second  << " ) -> ";
// 			}
// 			cout << endl;
// 		}
// 	}
// };


// undirected graph is a tree or not
// class Graph {
// 	list<int>*l;
// 	int v;
// public:
// 	Graph(int v) {
// 		this->v = v;
// 		l = new list<int>[v];
// 	}

// 	void addEdge(int x , int y) {
// 		l[x].push_back(y);
// 		l[y].push_back(x);
// 	}

// 	bool is_Tree() {
// 		bool *visited = new bool[v]();
// 		int *parent = new int[v]();
// 		for (int i = 0 ; i < v ; i++) {
// 			visited[i] = false;
// 			parent[i] = i;
// 		}

// 		queue<int>q;
// 		int src = 0;
// 		q.push(src);
// 		visited[src] = true;

// 		while (!q.empty()) {
// 			int node = q.front();
// 			q.pop();
// 			for (auto nbr : l[node]) {
// 				if (visited[nbr] == true and parent[node] != nbr) {
// 					return false;
// 				}
// 				else if (!visited[nbr]) {
// 					visited[nbr] = true;
// 					parent[node] = nbr;
// 					q.push(nbr);
// 				}
// 			}
// 		}

// 		return true;
// 	}
// };



// cycle detection in directed graph using bfs


// class Graph {
// 	list<int>*l;
// 	int v;
// public:
// 	Graph(int v) {
// 		this->v = v;
// 		l = new list<int>[v];
// 	}

// 	void addEdge(int x , int y) {
// 		l[x].push_back(y);
// 	}

// 	bool cycleHelper(int node , bool *visited , bool *stack){
// 		// visit a node
// 		visited[node]=true;
// 		stack[node]=true;
// 		for(auto nbr : l[node]){
// 			if(stack[nbr]==true){
// 				return true;
// 			}
// 			else if(visited[nbr]==false){
// 				bool cycleHai=cycleHelper(nbr , visited , stack);
// 				if(cycleHai){
// 					return true;
// 				}
// 			}
// 		}

// 		stack[node]=false;

// 		return false;
// 	}

// 	bool cycleDetection(){
// 		bool *visited=new bool[v]();
// 		bool *stack=new bool[v]();
// 		int src=0;
// 		return cycleHelper(src ,visited , stack);
// 	}
// };


// cycle detection in a directed graph using bfs
class Graph {
	list<int>*l;
	int v;
public:
	Graph(int v) {
		this->v = v;
		l = new list<int>[v];
	}

	void addEdge(int x , int y) {
		l[x].push_back(y);
	}

	bool cycleHelper(int node , bool *visited , int parent) {
		visited[node] = true;

		for (auto nbr : l[node]) {
			// two cases
			if (visited[nbr] and parent != nbr) {
				return true;
			}
			else if (!visited[nbr]) {
				bool cycleHai = cycleHelper(nbr , visited , node);
				if (cycleHai) {
					return true;
				}
			}
		}

		return false;
	}

	bool cycleDetection() {
		bool *visited = new bool[v]();
		int src = 0;
		return cycleHelper(src , visited , -1);
	}
};
int main() {
	// Graph g(4);
	// g.addEdge(0 , 1);
	// g.addEdge(0 , 2);
	// g.addEdge(2 , 3);
	// g.addEdge(1 , 2);
	// g.print();

	// Graph g;
	// g.addEdge("A" , "B" , true , 20);
	// g.addEdge("A" , "C" , true , 10);
	// g.addEdge("C" , "D" , true , 40);
	// g.addEdge("B" , "D" , true , 30);
	// g.addEdge("A" , "D" , false , 30);
	// g.print();


	// Graph<int> g;
	// g.addEdge(1 , 2);
	// g.addEdge(2,  3);
	// g.addEdge(1 , 0);
	// g.addEdge(0 , 3);
	// g.addEdge(3 , 4);
	// g.addEdge(4 , 5);
	// g.bfs(0);

	// Graph g(4);
	// g.addEdge(0 , 2);
	// g.addEdge(2 , 0);
	// g.addEdge(2 , 3);
	// g.addEdge(3 , 2);
	// g.addEdge(1 , 3);
	// g.addEdge(3 , 1);
	// cout << g.is_Tree() << endl;



	// Graph g(7);
	// g.addEdge(0 , 1);
	// g.addEdge(1 , 2);
	// g.addEdge(2 , 3);
	// g.addEdge(3 , 4);
	// g.addEdge(4 , 5);
	// g.addEdge(1 , 5);
	// g.addEdge(5 , 6);
	// g.addEdge(4 , 2);//back edge
	// cout << g.cycleDetection() << endl;


	Graph g(5);
	g.addEdge(0 , 1);
	g.addEdge(1 , 2);
	g.addEdge(2 , 3);
	g.addEdge(3 , 4);
	//g.addEdge(4 , 8);
	cout << g.cycleDetection() << endl;
	return 0;
}