#include<bits/stdc++.h>
using namespace std;
 
using ll = long long;
int const MOD = 1e8 + 7; 
int const N = 1e5;
vector<vector<ll>> A;

vector<ll> Producte(vector<vector<ll>> const& A, vector<ll> const& v) {
	int r = A.size();
	int c = A[0].size();
	assert(int(v.size()) == c);
	vector<ll> ans(r, 0);
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			ans[i] += (A[i][j] * v[j]) % MOD;
		}
		ans[i] %= MOD;
	}
	return ans;
}

vector<vector<ll>> Producte(vector<vector<ll>> const& A, vector<vector<ll>> const& B) {
	int r = A.size();
	int c = B[0].size();
	int m = B.size();
	vector<vector<ll>> ans(r, vector<ll>(c, 0));
	for(int i = 0; i < r; ++i) {
		for(int j = 0; j < c; ++j) {
			for(int k = 0; k < m; ++k) {
				ans[i][j] += (A[i][k] * B[k][j]) % MOD;
			}
			ans[i][j] %= MOD;
		}
	}
	return ans;
}

vector<vector<ll>> Exp(vector<vector<ll>> const& A, ll k) {
	int n = A.size();
	vector<vector<ll>> ans(n, vector<ll>(n, 0));
	if(k == 0) {
		for(int i = 0; i < n; ++i)
			ans[i][i] = 1;
		return ans;
	}
	ans = Exp(A, k/2);
	ans = Producte(ans, ans);
	if(k&1) ans = Producte(ans, A);
	return ans;
}

// Torna un vector amb {dp[n], dp[n-1], dp[n-2], dp[n-3]}.
// Pre: n >= 4
vector<ll> GetDP(ll n) {
	vector<ll> v = {1, 1, 0, 1}; // {dp[4], dp[3], dp[2], dp[1]}
	return Producte(Exp(A, n-4), v);
}

int Resol(ll n) {
	if(n == 1) return 2;
	if(n == 2) return 3;
	if(n == 3) return 4;
	vector<ll> dp = GetDP(n);
	int ans = 0;
	for(int esq = 0; esq <= 3; ++esq) {
		for(int dre = max(1, esq); dre + esq < min(4ll, n); ++dre) {
			if(esq == dre) ans += dp[esq+dre];
			else ans += 2 * dp[esq+dre];
		}
	}
	return ans%MOD;
}

int main(){
	A = vector<vector<ll>>(4, vector<ll>(4, 0));
	A[0][1] = A[0][2] = A[0][3] = A[1][0] = A[2][1] = A[3][2] = 1;

	ll n;
	while(cin >> n) {
		cout << Resol(n) << endl;
	}	
}