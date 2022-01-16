#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[1000005] , freq[1000005];
vector<ll> primeSieve(ll *p , ll n) {
	for (ll i = 3; i <= n; i += 2) {
		p[i] = 1;
	}
	for (ll i = 3; i <= n; i++) {
		if (p[i] == 1) {
			for (ll j = i * i; j <= n; j += 2 * i) {
				p[i] = 0;
			}
		}
	}
	p[2] = 1;
	p[0] = p[1] = 0;
	vector<ll>primes;
	primes.push_back(2);
	for (ll i = 3; i <= n; i++) {
		primes.push_back(p[i]);
	}

	return primes;
}
int numberOfDivisor(ll n, vector<ll>&primes) {

	int i = 0;
	int p = primes[0];
	int ans = 1;
	while (p * p <= n) {
		if (n % p == 0) {
			int cnt = 0;
			while (n % p == 0) {
				cnt++;
				n = n / p;
			}
			ans = ans * (cnt + 1);
		}
		i++;
		p = primes[i];
	}
	if (n != 1) {
		ans *= 2;
	}
	return ans;


}
int main() {
	// ll N = 1000000;
	// ll p[N];
	// for(ll i=0;i<N;i++){
	//     p[i]=0;
	// }
	// vector<ll>primes = primeSieve(p,10000);
	// int n;
	// cin >>n;
	// cout << numberOfDivisor(n , primes) << endl;

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		memset(freq , 0 , sizeof(freq));
		freq[0] = 1;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
			sum %= n;
			sum = (sum + n) % n;
			freq[sum]++;

		}
		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int m = freq[i];
			ans += m * (m - 1) >> 1;
		}
		cout << ans << endl;
	}

	return 0;
}
