#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n) {
		vector<string> v(n);
		for(string& fila : v)
			cin >> fila;
		
		int ans = 0;

		vector<int> usat(n, false);
		map<string,int> m;
		string cami = "";

		function<void(int,int,bool,vector<int>const&)> genera = [&](int last, int num, bool segona_iteracio, vector<int> const& s) {
			if(num == (n+1)/2) {
				if(not segona_iteracio) m[cami]++;
				else {
					ans += m[cami];
				}
				return;
			}
			for(int x : s) {
				if(not usat[x]) {
					usat[x] = true;
					if(segona_iteracio) cami.push_back(v[last][x]);
					else cami.push_back(v[x][last]);
					genera(x, num+1, segona_iteracio, s);
					cami.pop_back();
					usat[x] = false;
				}
			}
		};

		
		for(int i = 0; i < (1<<n); ++i) {
			if(__builtin_popcount(i) != n/2) continue;
			cami.clear();
			fill(usat.begin(), usat.end(), false);
			vector<int> a;
			vector<int> b;
			for(int j = 0; j < n; ++j) {
				if(i&(1<<j)) a.push_back(j);
				else b.push_back(j);
			}

			if(n&1) {
				for(int x : b) {
					usat[x] = true;
					m.clear();
					genera(x, 1, false, a);
					genera(x, 1, true, b);
					usat[x] = false;
				}
			}
			else {
				m.clear();
				for(int x : a) {
					usat[x] = true;
					genera(x, 1, false, a);
					usat[x] = false;
				}
				for(int x : b) {
					usat[x] = true;
					genera(x, 1, true, b);
					usat[x] = false;
				}
			}
		}
		cout << ans << endl;
	}
}