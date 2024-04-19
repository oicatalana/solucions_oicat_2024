#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ii = pair<int,int>;

vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
vector<int> dy = {0, -1, -1, -1, 0, 1, 1, 1};

int main()  {
	int n, m;
	while(cin >> n >> m) {
		vector<ii> v(m);
		map<ii, int> id;
		for(int i = 0; i < m; ++i) {
			cin >> v[i].first >> v[i].second;
			id[v[i]] = i;
		}
		vector<bool> vist(m, false);
		int quadrats = 0;
		int quasi = 0;

		function<void(int, vector<int>&)> dfs = [&](int i, vector<int>& comp) {
			ii pos = v[i];
			comp.push_back(i);
			for(int j = 0; j < 8; ++j) {
				ii newpos = pos;
				newpos.first += dx[j];
				newpos.second += dy[j];
				if(id.count(newpos)) {
					int newi = id[newpos];
					if(not vist[newi]) {
						vist[newi] = true;
						dfs(newi, comp);
					}
				}
			}
		};

		auto EsQuadrat = [&](vector<int> const& comp) {
			int xmin = n;
			int xmax = 1;
			int ymin = n;
			int ymax = 1;
			for(int i : comp) {
				xmin = min(xmin, v[i].first);
				xmax = max(xmax, v[i].first);
				ymin = min(ymin, v[i].second);
				ymax = max(ymax, v[i].second);
			}
			return xmax <= xmin + 1 and ymax <= ymin + 1;
		};

		auto EsQuasiQuadrat = [&](vector<int> const& comp) {
			if(not EsQuadrat(comp)) return false;
			ll sumx = 0, sumy = 0;
			for(int i : comp) {
				sumx += v[i].first;
				sumy += v[i].second;
			}
			int xmissing = sumx/3 + int(sumx%3 == 1);
			int ymissing = sumy/3 + int(sumy%3 == 1);

			vector<ii> oposats;
			for(int i : comp) {
				ii p = {xmissing + (xmissing-v[i].first), ymissing + (ymissing - v[i].second)};
				oposats.push_back(p);
			}
			for(ii const& p : oposats) {
				if(id.count(p)) return false;
			}
			return true;
		};

		for(int i = 0; i < m; ++i) {
			if(not vist[i]) {
				vector<int> comp;
				vist[i] = true;
				dfs(i, comp);
				if(comp.size() == 4 and EsQuadrat(comp)) 
					++quadrats;
				if(comp.size() == 3 and EsQuasiQuadrat(comp))
					++quasi;
			}
		}
		cout << quadrats << " " << quasi << endl;
	}
}