#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n) {
		vector<vector<int>> G(n);
		for(int i = 0; i < n-1; ++i) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		vector<int> pare(n, -1);
		vector<int> dist(n, -1);
		queue<int> q;
		dist[0] = 0;
		q.push(0);
		while(not q.empty()) {
			int x = q.front();
			q.pop();
			for(int y : G[x]) {
				if(dist[y] == -1) {
					dist[y] = dist[x] + 1;
					pare[y] = x;
					q.push(y);
				}
			}
		}

		vector<int> vertexos(n);
		iota(vertexos.begin(), vertexos.end(), 0);
		sort(vertexos.begin(), vertexos.end(), [&](int u, int v) {
			return dist[u] > dist[v];
		});

		vector<int> grup(n, 0);
		int seguent_grup = 1;
		bool impossible = false;
		for(int v : vertexos) {
			if(grup[v] == 0) {
				vector<int> fills_no_marcats;
				for(int u : G[v]) {
					if(u != pare[v] and grup[u] == 0)
						fills_no_marcats.push_back(u);
				}
				int num_fills = fills_no_marcats.size();
				if(num_fills >= 3) {
					impossible = true;
				}
				else if(num_fills == 2) {
					grup[v] = seguent_grup;
					for(int fill : fills_no_marcats)
						grup[fill] = seguent_grup;
					++seguent_grup;
				}
				else if(num_fills == 1){
					if(pare[v] == -1 or grup[pare[v]] != 0) {
						impossible = true;
					}
					else {
						grup[v] = grup[pare[v]] = seguent_grup;
						grup[fills_no_marcats[0]] = seguent_grup;
						++seguent_grup;
					}
				}
			}
		}
		for(int v : vertexos) {
			if(grup[v] == 0) impossible = true;
		}

		if(impossible) {
			cout << "NO" << endl;
		}
		else {
			cout << "SI" << endl;
			vector<pair<int,int>> arestes_elim;
			for(int v = 1; v < n; ++v) {
				if(grup[v] != grup[pare[v]]) {
					arestes_elim.push_back({pare[v], v});
				}
			}
			for(pair<int,int>& e : arestes_elim) {
				if(e.first > e.second) 
					swap(e.first, e.second);
			}
			sort(arestes_elim.begin(), arestes_elim.end());
			for(pair<int,int> e : arestes_elim) {
				cout << e.first << " " << e.second << endl;
			}
		}
	}
}
