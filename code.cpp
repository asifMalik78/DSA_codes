#include <bits/stdc++.h>
using namespace std;
void hashing(int *a , int n) {
	int m = a[n - 1];
	bool temp[m] = {false};
	for (int i = 0; i < n; ++i)
	{
		temp[a[i]] = true;
	}
	for (int i = 1 ; i < m; i++) {
		if (temp[i] == false) {
			cout << " The missing numbers are " << i << endl;
		}
	}
}
void iterative(int *a , int n) {
	int diff = a[0] - 0;
	for (int i = 0; i < n; ++i)
	{
		if ((a[i] - i) != diff)
		{
			while (diff < a[i] - i) {
				cout << " The missing numbers are " << diff + i << endl;
				diff++;
			}

		}
	}
}
void breakingSentence() {
	string s;
	cin >> s;
	string p;
	for (int i = 0; i < s.length(); i++) {
		p.push_back(s[i]);
		if (s[i + 1] >= 65 && s[i + 1] <= 90) {
			cout << p << endl;
			p.clear();
		}
	}
	cout << p;
}
int multiply(int x , int *result , int size) {
	int carry = 0;
	for (int i = 0; i < size; i++) {
		int prod = result[i] * x + carry;
		result[i] = prod % 10;
		carry = prod / 10;
	}
	while (carry) {
		result[size++] = carry % 10;
		carry /= 10;
	}
	return size;
}
void brokenCalculator(int n) {
	int result[1000];
	int result_size = 1;
	result[0] = 1;
	for (int i = 2; i <= n; i++) {
		result_size = multiply(i, result, result_size);
	}
	for (int i = result_size - 1; i >= 0; i--) {
		cout << result[i];
	}
}
int main() {
	// int n;
	// cin >> n;
	// int a[n];
	// for (int i = 0; i < n; ++i)
	// {
	// 	cin >> a[i];
	// }
	brokenCalculator(20);
	// breakingSentence();
	// sort(a , a + n);
	// cout << " i am using hashing" << endl;
	// hashing(a , n);
	// cout << " i am using iterative approach" << endl;
	// iterative(a , n);


}