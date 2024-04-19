#include<bits/stdc++.h>
using namespace std;

string s;

bool Valid() {
	int n = s.size();
	if(s[0] == 'N' and s[n-1] == 'N')
		return false; 
	if(n < 4) return true;
	for(int i = 0; i < 4; ++i) {
		int j = n-1-i;
		if(s[j] == 'B' and s[(j+1)%n] == 'B' and s[(j+2)%n] == 'B' and s[(j+3)%n] == 'B')
			return false;
	}
	return true;
}

int Resol(int actual, int n) {
	if(actual == n) {
		if(Valid()) return 1;
		return 0;
	}
	int resposta = 0;
	if(actual < 3 or s[actual-1] == 'N' or s[actual-2] == 'N' or s[actual-3] == 'N') {
		s[actual] = 'B';
		resposta += Resol(actual+1, n);
	}
	if(actual == 0 or s[actual-1] == 'B') {
		s[actual] = 'N';
		resposta += Resol(actual+1, n);
	}
	return resposta;
}

int main() {
	int n;
	while(cin >> n) {
		s = string(n, '?');
		cout << Resol(0, n) << endl;
	}
}