#include<bits/stdc++.h>
using namespace std;

int main() {
	int const n = 20;
	int ans = 1e9;
	for(int x = 0; x < (1 << n); ++x) {
		string s(n, 'a');
		for(int i = 0; i < n; ++i) {
			if(x&(1 << i)) s[n-1-i] = 'b';
		}
		int num_palindroms = 0;
		for(int i = 0; i < n; ++i) {
			for(int j = i; j < n; ++j) {
				bool palindrom = true;
				for(int k = 0; i+k < j-k and palindrom; ++k) {
					if(s[i+k] != s[j-k]) 
						palindrom = false;
				}
				if(palindrom) num_palindroms++;
			}
		}
		if(num_palindroms < ans) {
			ans = num_palindroms;
			cout << s << " : " << ans << endl;
		}
	}
}