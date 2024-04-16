#include<bits/stdc++.h>
using namespace std;

bool IsPrime(int x) {
	for(int i = 2; i*i <= x; ++i) {
		if(x%i == 0) return false;
	}
	return true;
}

bool IsSuperprime(int x) {
	string s = to_string(x);
	int k = s.size();
	for(int i = 0; i < k; ++i) {
		for(int j = i; j < k; ++j) {
			if(not IsPrime(stoi(s.substr(i, j-i+1))))
				return false;
		}
	}
	return true;
}

int main() {
	int N = 1e6;
	for(int i = 1; i < N; ++i) {
		if(IsSuperprime(i)) cout << i << endl;
	}
}