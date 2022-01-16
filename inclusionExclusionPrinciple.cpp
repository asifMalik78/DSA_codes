#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main() {
	ll primes[] = {2, 3, 5, 7, 11, 13, 17, 19};
	ll t;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		int subsets = (1 << 8) - 1;
		ll ans = 0;
		for (ll i = 1; i <= subsets; i++)
		{
			ll denm = 1ll;
			int setBits = __builtin_popcount(i);
			for (ll j = 0; j <= 7; j++) {
				if (i & (1 << j)) {
					denm *= primes[j];
				}
			}
			if ((setBits & 1))
			{
				ans += n / denm;
			} 
			else
			{
				ans -= n / denm;
			}
			
		}
		cout << ans << endl;
	}

	return 0;
}