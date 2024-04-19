#include<bits/stdc++.h>
using namespace std;
 
int const MOD = 1e8 + 7; 
int const N = 1e5;
vector<int> dp;

int Resol(int n) {
	int ans = 0;
	for(int esq = 0; esq <= 3; ++esq) {
		for(int dre = 0; dre <= 3; ++dre) {
			if(esq + dre >= 4) continue;
			if(esq + dre == 0) continue;
			if(esq + dre >= n) continue;
			ans += dp[n-esq-dre];
		}
	}
	if(n <= 3) ans++; // tot B's
	return ans%MOD;
}

int main(){
	// dp[i] := nombre de paraules vàlides de llargada 'i' que 
	//          comencen i acaben amb N (sense comprovar extrems).
	dp = vector<int>(N, 0); 
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	dp[4] = 1;
	int max_n = 4;

	int n;
	while(cin >> n) {
		for(int i = max_n + 1; i <= n; ++i) {
			dp[i] = (dp[i-2] + dp[i-3] + dp[i-4]) % MOD;
		}
		max_n = max(max_n, n);
		cout << Resol(n) << endl;
	}	
}