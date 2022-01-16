#include <bits/stdc++.h>
using namespace std;
string extractStringAtKey(string str , int key) {
	char *s = strtok((char *)str.c_str() , " ");
	while (key > 1 ) {
		s = strtok(NULL , " ");
		key--;
	}
	return (string)s;
}
int stringToInt(string s) {
	int ans = 0;
	int p = 1;
	for (int i = s.length() - 1; i >= 0; i--) {
		ans += (s[i] - '0') * p;
		p *= 10;
	}
	return ans;
}
bool numericCompare(pair<string , string> p1 , pair<string , string> p2) {
	string s1 , s2;
	s1 = p1.second;
	s2 = p2.second;
	return stringToInt(s1) < stringToInt(s2);

}
bool lexographicCompare(pair<string , string>p1 , pair<string , string>p2) {
	return p1.second < p2.second;
}
int main() {
	int n;
	cin >> n;
	cin.get();
	string s[1000];
	for (int i = 0; i < n; i++) {
		getline(cin , s[i]);
	}
	int key;
	string reversal , ordering;
	cin >> key >> reversal >> ordering;
	pair<string , string>pr[1000];
	for (int i = 0; i < n; i++) {
		pr[i].first = s[i];
		pr[i].second = extractStringAtKey(s[i], key);
	}


	if (ordering == "numeric") {
		sort(pr , pr + n , numericCompare);
	}
	else {
		sort(pr , pr + n , lexographicCompare);
	}

	if (reversal == "true") {
		for (int i = 0; i < n / 2; i++) {
			swap(pr[i] , pr[n - i - 1]);
		}
	} else {
		for (int i = 0; i < n; i++) {
			cout << pr[i].first << endl;
		}
	}


	return 0;
}