#include <bits/stdc++.h>
using namespace std;
class maxHeap {
	vector<int>v;
	void heapify(int idx) {
		int last = v.size() - 1;
		int max_idx = idx;
		int left = 2 * idx;
		int right = 2 * idx + 1;
		if (left <= last and v[left] > v[max_idx]) {
			max_idx = left;
		}

		if (right <= last and v[right] > v[max_idx]) {
			max_idx = right;
		}

		if (max_idx != idx) {
			swap(v[idx] , v[max_idx]);
			heapify(max_idx);
		}
	}
public:
	maxHeap() {
		v.push_back(-1);
	}

	void push(int d) {
		v.push_back(d);
		int idx = v.size() - 1;
		int parent = idx / 2;
		while (idx > 1  and v[idx] > v[parent]) {
			swap(v[idx] , v[parent]);
			idx = parent;
			parent = idx / 2;
		}
	}

	bool empty() {
		return v.size() == 1;
	}

	int getMax() {
		return v[1];
	}

	void pop() {
		swap(v[1] , v[v.size() - 1]);
		v.pop_back();
		heapify(1);
	}

};


class minHeap {
	vector<int>v;
	void heapify(int idx) {
		int last = v.size() - 1;
		int min_idx = idx;
		int left = 2 * idx;
		int right = 2 * idx + 1;
		if (left <= last and v[left] < v[min_idx]) {
			min_idx = left;
		}

		if (right <= last and v[right] < v[min_idx]) {
			min_idx = right;
		}

		if (min_idx != idx) {
			swap(v[idx] , v[min_idx]);
			heapify(min_idx);
		}
	}
public:
	minHeap() {
		v.push_back(-1);
	}

	void push(int d) {
		v.push_back(d);
		int idx = v.size() - 1;
		int parent = idx / 2;
		while (idx > 1  and v[idx] < v[parent]) {
			swap(v[idx] , v[parent]);
			idx = parent;
			parent = idx / 2;
		}
	}

	bool empty() {
		return v.size() == 1;
	}

	int getMin() {
		return v[1];
	}

	void pop() {
		swap(v[1] , v[v.size() - 1]);
		v.pop_back();
		heapify(1);
	}
};

void heapify(vector<int>&v , int idx) {
	int last = v.size() - 1;
	int max_idx = idx;
	int left = 2 * idx;
	int right = 2 * idx + 1;
	if (left <= last and v[left] > v[max_idx]) {
		max_idx = left;
	}

	if (right <= last and v[right] > v[max_idx]) {
		max_idx = right;
	}

	if (max_idx != idx) {
		swap(v[idx] , v[max_idx]);
		heapify(v , max_idx);
	}
}


// building a heap in an array in O(nlogn) complexity
void createHeap(vector<int>&v) {
	for (int i = 2 ; i < v.size() ; i++) {
		int idx = i;
		int parent = i / 2;
		while (idx > 1 and v[idx] > v[parent]) {
			swap(v[idx] , v[parent]);
			idx = parent;
			parent = parent / 2;
		}
	}
}

// building a heap in an array in O(n) complexity
void createHeapOptimized(vector<int>&v) {
	for (int i = v.size() - 1 / 2 ; i >= 1 ; i--) {
		heapify(v , i);
	}
}

// heap sort inplace

void heapifyH(vector<int>&v , int idx , int size) {
	int last = size - 1;
	int max_idx = idx;
	int left = 2 * idx;
	int right = 2 * idx + 1;
	if (left <= last and v[left] > v[max_idx]) {
		max_idx = left;
	}

	if (right <= last and v[right] > v[max_idx]) {
		max_idx = right;
	}

	if (max_idx != idx) {
		swap(v[idx] , v[max_idx]);
		heapifyH(v , max_idx , size);
	}
}

void heapSort(vector<int>&v) {
	createHeapOptimized(v);
	int n = v.size();
	while (n > 1) {
		swap(v[1] , v[n - 1]);
		n--;
		heapifyH(v , 1 , n);
	}
}
void print(vector<int>&v) {
	for (int i = 1 ; i < v.size() ; i++)
		cout << v[i] << " ";

	cout << endl;
}

// heaps or priority queue using stl
// push()->o(logn) , pop()->o(logn) , top()->o(1)
void priorityQueue() {
	priority_queue<int> pq_max; // by default it is max heap
	priority_queue<int , vector<int> , greater<int>> pq_min; // to make min heap we have to include two argument that is vector<int> and greater<int>
	int n;
	cin >> n;
	for (int i = 0 ; i < n ; i++) {
		int no;
		cin >> no;
		pq_max.push(no);
		pq_min.push(no);
	}

	while (!pq_max.empty()) {
		cout << pq_max.top() << " ";
		pq_max.pop();
	}

	cout << endl;

	while (!pq_min.empty()) {
		cout << pq_min.top() << " ";
		pq_min.pop();
	}
}

// priority queue for custom class
class persons {
public:
	string name;
	int age;
	persons(string s, int a) {
		name = s;
		age = a;
	}
};

class comparePersons {
public:
	bool operator()(persons A , persons B) {
		return A.age > B.age;
	}
};


// running medium of integer stream
void stream() {
	priority_queue<int>leftHeap; // max heap
	priority_queue<int , vector<int> , greater<int>>rightHeap; // min heap
	int d;
	cin >> d;
	float med = d;
	leftHeap.push(d);
	cout << "median is " << med << endl;
	cin >> d;
	while (d != -1) {
		if (leftHeap.size() > rightHeap.size()) {
			if (d < med) {
				rightHeap.push(leftHeap.top());
				leftHeap.pop();
				leftHeap.push(d);
			}
			else {
				rightHeap.push(d);
			}
			med = (leftHeap.top() + rightHeap.top()) / 2.0;
		}
		else if (leftHeap.size() == rightHeap.size()) {
			if (d < med) {
				leftHeap.push(d);
				med = leftHeap.top();
			}
			else {
				rightHeap.push(d);
				med=rightHeap.top();
			}
		}
		else {
			if (d < med) {
				leftHeap.push(d);
			}
			else {
				leftHeap.push(rightHeap.top());
				rightHeap.pop();
				rightHeap.push(d);
			}
			med = (leftHeap.top() + rightHeap.top()) / 2.0;
		}

		cout << "median is " << med << endl;

		cin >> d;

	}


}

// merge k sorted arrays
typedef pair<int , pair<int , int>> node;
vector<int> mergeKArrays(vector<vector<int>>&v){
	vector<int>res;
	// we create a min heap
	priority_queue<node , vector<node> , greater<node>>pq;
    // we push first element of all array 
	for(int i=0 ; i<v.size() ; i++){
		pq.push({v[i][0] , {i , 0}});
	}
    // while pq is not empty we will continously pop pq top and push next element of an array
	while(!pq.empty()){
		node current=pq.top();
		pq.pop();
		// here we are putting out minimum element present at top of the heap
		res.push_back(current.first);
        // we are getting the coordinates of vector of vector
		int x=current.second.first;
		int y=current.second.second;
        // here we will check whether col does not exceed size 
		if(y+1 < v[x].size()){
			// if true then we push the element
			pq.push({v[x][y+1] , {x , y+1}});
		}
	}

	return res;
}
int main() {
	// minHeap h;
	// maxHeap m;
	// int n;
	// cin >> n;
	// for (int i = 0 ; i < n ; i++) {
	// 	int no;
	// 	cin >> no;
	// 	h.push(no);
	// 	m.push(no);
	// }

	// while (!h.empty()) {
	// 	cout << h.getMin() << " ";
	// 	h.pop();
	// }

	// cout << endl;
	// while (!m.empty()) {
	// 	cout << m.getMax() << " ";
	// 	m.pop();
	// }
	// int n;
	// cin >> n;
	// vector<int>v;
	// v.push_back(-1);
	// for (int i = 0 ; i < n ; i++) {
	// 	int a;
	// 	cin >> a;
	// 	v.push_back(a);
	// }
	// print(v);
	// // createHeapOptimized(v);
	// // print(v);
	// heapSort(v);
	// print(v);
	// priorityQueue();


	// int n;
	// cin >> n;
	// priority_queue<persons , vector<persons> , comparePersons> pq;
	// for(int i=0 ; i<n ; i++){
	// 	string str;
	// 	int age;
	// 	cin >> str >> age;
	// 	persons p(str , age);
	// 	pq.push(p);
	// }

	// int k=3;
	// for(int i=0 ; i<k ; i++){
	// 	persons p=pq.top();
	// 	cout << p.name << " " << p.age << endl;
	// 	pq.pop();
	// }



	stream();


	// vector<vector<int>>v{{2 , 6 , 12 , 15} , {1 , 3 , 14 , 20} , {3 , 5 , 8 , 10}};
	// vector<int>ans=mergeKArrays(v);
	// for(int i : ans){
	// 	cout << i << " ";
	// }
	// cout << endl;
	return 0;
}





// --> priorityQueue questions
// -> Given N ropes of different sizes , we have join the ropes together, The cost of joining two ropes of different sizes a and b is a+b . find the minimum cost to join all the ropes together
// eg-> 4 3 2 6 -> min cost is 29

// #include <iostream>
// #include <bits/stdc++.h>
// using namespace std;
// int joinRopes(int *arr , int n){
//     priority_queue<int , vector<int> , greater<int>>pq;
//     for(int i=0 ; i<n ; i++){
//         pq.push(arr[i]);
//     }
//     int sum;
//     int cost=0;
//     while(pq.size() > 1){
//     	sum=0;
//         int n1=pq.top();
//         cout << n1 << endl;
//         pq.pop();
//         int n2=pq.top();
//         cout << n2 << endl;
//         pq.pop();
//         sum=n1+n2;
//         cost+=sum;
//         cout << "i am sum" << " " << sum << endl;
//         pq.push(sum);
//     }

//     return cost;
// }
// int main() {
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i=0 ; i<n ; i++){
//         cin >> arr[i];
//     }

//     cout << joinRopes(arr , n) << endl;
// }
