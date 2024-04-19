#include<bits/stdc++.h>
using namespace std;

string s;

bool Valid() {
	int n = s.size();
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'N' and s[(i+1)%n] == 'N') 
			return false;
		if(n >= 4 and s[i] == 'B' and s[(i+1)%n] == 'B' and s[(i+2)%n] == 'B' and s[(i+3)%n] == 'B')
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
	s[actual] = 'B';
	resposta += Resol(actual+1, n);
	s[actual] = 'N';
	resposta += Resol(actual+1, n);
	return resposta;
}

int main() {
	int n;
	while(cin >> n) {
		s = string(n, '?');
		cout << Resol(0, n) << endl;
	}
}
