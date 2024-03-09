#include<bits/stdc++.h>
using namespace std;

vector<int> dr = {1, 0, -1, 0};
vector<int> dc = {0, 1, 0, -1};
int n, m;
vector<string> graella;
vector<vector<bool>> vist;

// Retorna el nombre de caselles visitades a partir de la posició (i,j)
int dfs(int i, int j) {
	if(i >= n or i < 0 or j >= m or j < 0 or graella[i][j] != '.') 
		return 0; // Casella invàlida.
	if(vist[i][j]) 
		return 0; // Casella ja visitada.

	vist[i][j] = true;
	int ans = 1;
	for(int k = 0; k < 4; ++k) {
		int in = i + dr[k];
		int jn = j + dc[k];
		ans += dfs(in, jn);
	}
	return ans;
}

// Marca totes les caselles del component connex al qual pertany (i,j) amb el caràcter c.
void pinta(int i, int j, char c) {
	if(i >= n or i < 0 or j >= m or j < 0 or graella[i][j] != '.') 
		return; // Casella invàlida.
	graella[i][j] = c;
	for(int k = 0; k < 4; ++k) {
		int in = i + dr[k];
		int jn = j + dc[k];
		pinta(in, jn, c);
	}
}

int main() {
	char c;
	while(cin >> n >> m >> c) {
		graella = vector<string>(n);
		for(string& s : graella)
			cin >> s;

		// Troba màxim component connex:
		int maxmida = 0; // Màxima mida d'un component connex.
		int i0 = -1, j0 = -1; // Casella dins del màxim component connex.
		// vist[i][j] := 1 si ja hem visitat la casella (i,j)
		vist = vector<vector<bool>>(n, vector<bool>(m, false)); 
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if(graella[i][j] == '.') {
					int mida = dfs(i, j);
					if(mida > maxmida) {
						maxmida = mida;
						i0 = i;
						j0 = j;
					}
				}
			}
		}

		// Marca màxim component connex:
		pinta(i0, j0, c);

		// Output:
		for(string const& s : graella)
			cout << s << endl;
		cout << string(10, '-') << endl;
	}
}
