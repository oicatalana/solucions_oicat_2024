#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	while(cin >> s) {
		int n = s.size();
		bool valid = true;
		for(int i = 0; i < n; ++i) {
			if(s[i] == 'N' and s[(i+1)%n] == 'N') {
				valid = false;
				break;
			}
			if(n >= 4 and s[i] == 'B' and s[(i+1)%n] == 'B' and s[(i+2)%n] == 'B' and s[(i+3)%n] == 'B') {
				valid = false;
				break;
			}
		}
		cout << (valid ? "si" : "no") << endl;
	}
}