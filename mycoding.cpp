#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[100][100];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int sum = 0;
	int prefixArray[100][100];
	prefixArray[0][0] = a[0][0];
	for (int i = 1; i < n; i++) {
		prefixArray[0][i] = prefixArray[0][i - 1] + a[0][i];
	}
	for (int i = 1; i < n; i++) {
		prefixArray[i][0] = prefixArray[i - 1][0] + a[i][0];
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
			prefixArray[i][j] = prefixArray[i - 1][j] + prefixArray[i][j - 1] - prefixArray[i - 1][j - 1] + a[i][j];
	}
	for (int tli = 0 ; tli < n ; tli++) {
		for (int tlj = 0 ; tlj < n ; tlj++) {
			for (int bri = tli ; bri < n ; bri++) {
				for (int brj = tlj ; brj < n ; brj++) {
					sum += prefixArray[bri][brj] - prefixArray[tli - 1][brj] - prefixArray[bri][tlj - 1] + prefixArray[tli - 1][tlj - 1];
				}
			}
		}
	}
	cout << sum << endl;
	return 0;
}