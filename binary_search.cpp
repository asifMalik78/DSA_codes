#include <bits/stdc++.h>
using namespace std;
int first_occurance(int *a , int n , int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			ans = mid;
			e = mid - 1;
		} else if (a[mid] < key) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	return ans;
}
int last_occurance(int *a , int n , int key) {
	int s = 0;
	int e = n - 1;
	int ans = -1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			ans = mid;
			s = mid + 1;
		} else if (a[mid] < key) {
			s = mid + 1;
		} else {
			e = mid - 1;
		}
	}
	return ans;
}

//Binary search in unsorted array withourt using sort() functon
int find(int *a , int n , int key) {
	int s = 0;
	int e = n - 1;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (a[mid] == key) {
			return mid;
		}
		else if (a[s] <= a[mid]) {
			if (key >= a[s] && key <= a[mid]) {
				e = mid - 1;
			} else {
				s = mid + 1;
			}
		} else {
			if (key >= a[mid] && key <= a[e]) {
				s = mid + 1;

			}
			else {
				e = mid - 1;
			}
		}
	}
	return -1;
}

//Square root of a number of a number using binary search
float square_Root(int n , int p) {
	int s = 0;
	int e = n;
	float ans = -1;
	while (s <= e) {
		int mid = (s + e) >> 1;
		if (mid * mid == n) {
			return mid;
		} else if (mid * mid > n) {
			e = mid - 1;
		} else {
			ans = mid;
			s = mid + 1;
		}
	}
	//float part
	float inc = 0.1;
	for (int i = 0; i < p; i++) {
		while (ans * ans <= n) {
			ans += inc;
		}
		ans -= inc;
		inc /= 10;
	}
	return ans;
}


bool cowsArePlaced(int *a , int n , int c , int min_dist) {

	int last_cow = a[0];
	int count = 1;
	for (int i = 1; i < n; i++) {
		if (a[i] - last_cow >= min_dist) {
			last_cow = a[i];
			count++;
			if (count == c) {
				return true;
			}
		}
	}
	return false;
}
//Agressive Cows
void aggrsssiveCows() {
	int t;
	cin >> t;
	while (t--) {
		int n , cows;
		cin >> n >> cows;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		sort(a , a + n);
		int s = 0;
		int e = a[n - 1] - a[0];
		int placed = INT_MIN;
		while (s <= e) {

			int mid = (s + e) >> 1 ;
			bool cowsPlaced = cowsArePlaced(a , n , cows , mid);
			if (cowsPlaced) {
				placed = max(placed , mid);
				s = mid + 1;
			} else {
				e = mid - 1;
			}

		}
		cout << placed << endl;
	}

}


bool isPossible(int *arr , int n , int stud , int max_pages) {

	int studentUsed = 1;
	int pagesRead = 0;
	for (int i = 0; i < n; i++) {
		if (pagesRead + arr[i] > max_pages) {
			studentUsed++;
			pagesRead = arr[i];
			if (studentUsed > stud) {
				return false;
			}
		} else {
			pagesRead += arr[i];

		}
	}

	return true;
}
//Book Allocation Problem
int bookAllocation(int *arr , int n , int stud) {
	if (n < stud) {
		return -1;
	}
	int s = arr[n - 1];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
	}
	int e = sum;
	int ans = INT_MAX;
	while (s <= e) {
		int mid = (s + e) >> 1;
		if (isPossible(arr , n , stud , mid)) {
			ans = min(ans , mid);
			e = mid - 1;
		} else {
			s = mid + 1;
		}

	}
	return ans;

}

bool minimumTime(int *arr , int n , int noOfParata , int min_time) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		int j = 1;
		int sum = 0;
		while (sum + arr[i]*j <= min_time) {
			sum += arr[i] * j;
			count++;
			j++;
			if (count >= noOfParata) {
				return true;
			}

		}
	}
	return false;
}
//Parata (spoj problem)
int parata(int *arr , int n , int p) {
	int s = 0;
	int e = p * (p + 1) / 2;
	int ans = INT_MAX;
	while (s <= e) {
		int mid = (s + e) >> 1;
		if (minimumTime(arr , n , p , mid)) {
			ans = min(ans , mid);
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return ans;
}
bool isPossible1(int *a , int n , int k , int min_time){
	int painterUsed=1;
	int sum=0;
	for(int i=0;i<n;i++){
		if(sum+a[i] > min_time){
			painterUsed++;
			sum=a[i];
			if(painterUsed > k){
				return false;
			}
		}else{
			sum+=a[i];
		}
	}
	return true;
}

//painter's problem
int painter(int *a , int n , int k) {
	int s = a[0];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	int e = sum;
	int ans = INT_MAX;
	while (s <= e) {
		int mid = (s + e) >> 1;
		if (isPossible1(a , n , k  , mid)) {
			ans = min(ans , mid);
			e = mid - 1;
		} else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {
	// int n;
	// cin >> n;
	// int a[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }
	// int key;
	// cin >> key;


	// cout << first_occurance(a , n , key) << endl;


	// cout << last_occurance(a , n , key) << endl;


	// cout << find(a , n , key) << endl;


	//cout << square_Root(10 , 3) << endl;


	aggrsssiveCows();


	// bookAllocation();


	// int n , m;
	// cin >> n >> m;
	// int a[n];
	// for(int i=0;i<n;i++)
	// 	cin >> a[i];
	// cout << bookAllocation(a , n , m);

	// int paratha;
	// cin >> paratha;
	// int chief;
	// cin >> chief;
	// int rating[chief];
	// for(int i=0;i<chief;i++){
	// 	cin >> rating[i];
	// }
	// cout << parata(rating , chief , paratha) << endl;

	// int n , k , t;
	// cin >> n >> k >> t;
	// int a[n];
	// for (int i = 0; i < n; i++) {
	// 	cin >> a[i];
	// }
	// cout << painter(a , n , k ) << endl;
	return 0;
}