#include<bits/stdc++.h>
using namespace std;

using ii = pair<int,int>;
using iii = pair<int,ii>;

int const INF = 1e9;
vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, 1, 0, -1};

int main() {
	int n, m;
	while(cin >> n >> m) {
		vector<string> v(n);
		for(string& s : v) 
			cin >> s;
		ii inicial;
		for(int r = 0; r < n; ++r) {
			for(int c = 0; c < m; ++c) {
				if(v[r][c] == 'I') {
					inicial = {r, c};
				}
			}
		}
		vector<vector<bool>> vist(n, vector<bool>(m, false));
		vist[inicial.first][inicial.second] = true;
		bool sortit = false;
		queue<ii> q;
		q.push(inicial);
		while(not q.empty()) {
			ii x = q.front();
			q.pop();
			int r = x.first;
			int c = x.second;
			if(r == 0 or c == 0 or r == n-1 or c == m-1) {
				sortit = true;
				break;
			}
			for(int k = 0; k < 4; ++k) {
				int rnou = r + dr[k];
				int cnou = c + dc[k];
				if(v[rnou][cnou] != 'X' and not vist[rnou][cnou]) {
					vist[rnou][cnou] = true;
					q.push({rnou, cnou});
				}
			}
		}
		cout << (sortit ? 0 : 1) << endl;
	}
}