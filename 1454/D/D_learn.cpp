/**
 * https://codeforces.com/contest/1454/submission/99423587
 */
#include<bits/stdc++.h>
#define all(x) begin(x), end(x)
using namespace std;
using ll = long long;
const int maxn = 1<<20;
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;cin >> t;
	while(t--) {
        // cout << "SSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS"<<endl;
		ll n;cin >> n;
		ll ans = 1;
		vector<array<ll, 2>> f;
		for(ll d = 2; d*d <= n; d++) if(n%d == 0) {
			ll p = 0;
			while(n%d == 0) n/=d, p++;
			ans = max(ans, p);//最大个数
			f.push_back({d, p});
		}
		if(n > 1)
			f.push_back({n, 1});
        // for(auto &[x, y] : f)
        // {
        //     cout << "[" << x << "]" << y << endl; 
        // }
		cout << ans << '\n';
        //最多的因式打底,作为最开始的项;然后减小循环
		// for(int i = ans; i; i--) {
		// 	ll cur = 1;
		// 	for(auto &[x, y] : f) if(y == i) y--, cur *= x;//y--的操作
		// 	cout << cur << " ";
		// }

        for(int i = 0; i < ans; ++i)
        {
            ll cur = 1;
            for(int pos = 0; pos < f.size(); ++pos)
            {
                if(f[pos][1] + i >= ans)
                    cur *= f[pos][0];
            }
            cout << cur << " ";
        }

		cout << '\n';
	}
}
