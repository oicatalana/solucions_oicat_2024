#include<bits/stdc++.h>
using namespace std;

int main() {
	const int MOD = 1e8 + 7;
	vector<int> repeticions(10, 3);
	repeticions[0] = 1;
	repeticions[7] = repeticions[9] = 4;
	string s;
	while(cin >> s) {
		int n = s.size();
		vector<int> dp(n+1, 0);
		dp[0] = 1;
		for(int i = 1; i <= n; ++i) {
			int x = s[i-1] - '0';
			for(int j = 1; j <= repeticions[x]; ++j) {
				dp[i] += dp[i-j];
				dp[i] %= MOD;
				if(s[i-1] != s[i-j-1]) break;
			}
		}
		cout << dp[n] << endl;
	}
}