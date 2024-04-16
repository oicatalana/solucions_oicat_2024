#include<bits/stdc++.h>
using namespace std;

bool IsPrime(int x) {
	for(int i = 2; i*i <= x; ++i) {
		if(x%i == 0) return false;
	}
	return true;
}

int main() {
	vector<int> v = {1, 2, 3, 5, 7};
	set<int> superprimers;
	queue<int> q;
	for(int x : v) {
		superprimers.insert(x);
		q.push(x);
	}
	while(not q.empty()) {
		int x = q.front();
		q.pop();
		for(int i : v) {
			int y = 10*x + i;
			string s = to_string(y);
			reverse(s.begin(), s.end());
			s.pop_back();
			reverse(s.begin(), s.end());
			if(IsPrime(y) and superprimers.count(stoi(s))) {
				q.push(y);
				superprimers.insert(y);
			}
		}
	}
	for(int x : superprimers) {
		cout << x << endl;
	}
}