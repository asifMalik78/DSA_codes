#include <iostream>
#include <algorithm>
using namespace std;
bool compare(int a , int b) {
	if (a < b) {
		return b > a;
	}
	return 0;
}

void purmutation1() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		next_permutation(a , a + n , compare);
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}
bool compare1(pair<int , int>a  , pair<int , int>b) {
	return a.second < b.second;
}
void activitySelectionProblem() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a , b;
		pair <int , int>p[n];
		for (int i = 0; i < n; i++) {
			cin >> a >> b;
			p[i] = make_pair(a , b);
		}
		sort(p , p + n , compare1);
		int ans = 1;
		int count = 0;
		for (int i = 1; i < n; i++) {
			if (p[i].first >= p[count].second) {
				ans++;
				count = i;
			}
		}
		cout << ans << endl;

	}
}
void stringCompression() {
	string s;
	cin >> s;
	char ch=s[0];
	int count=1;
	for (int i = 1; i < s.length(); i++) {
		if(ch==s[i]){
           count++;
		}else{
			cout << ch << count;
			count=1;
			ch=s[i];
		}
	}
	cout <<  ch  << count;
}
int main() {


	// purmutation1();
	//activitySelectionProblem();
	// stringCompression();
    
	return 0;
}