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
		vector<vector<int>> dist(n, vector<int>(m, INF));
		dist[inicial.first][inicial.second] = 0;
		priority_queue<iii, vector<iii>, greater<iii>> pq;
		pq.push({0, inicial});
		int ans = -1;
		while(not pq.empty()) {
			iii x = pq.top();
			pq.pop();
			int d = x.first;
			int r = x.second.first;
			int c = x.second.second;
			if(r == 0 or c == 0 or r == n-1 or c == m-1) {
				ans = d;
				break;
			}
			for(int k = 0; k < 4; ++k) {
				int rnou = r + dr[k];
				int cnou = c + dc[k];
				int increment = int(v[rnou][cnou] == 'X');
				if(dist[rnou][cnou] > dist[r][c] + increment) {
					dist[rnou][cnou] = dist[r][c] + increment;
					pq.push({dist[rnou][cnou], {rnou, cnou}});
				}
			}
		}
		cout << ans << endl;
	}
}