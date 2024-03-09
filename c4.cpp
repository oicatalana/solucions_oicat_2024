#include<bits/stdc++.h>
using namespace std;

int main() {
	int k;
	string s;
	while(cin >> k >> s) {
		int n = s.size();
		map<string,int> ocurr;
		for(int i = 0; i + k <= n; ++i) {
			ocurr[s.substr(i, k)]++;
		}
		int num_max = 0;
		for(pair<string,int> x : ocurr) {
			num_max = max(num_max, x.second);
		}
		vector<string> resposta;
		for(pair<string,int> x : ocurr) {
			if(x.second == num_max)
				resposta.push_back(x.first);
		}
		int m = resposta.size();
		for(int i = 0; i < m; ++i) {
			cout << resposta[i] << (i == m-1? '\n' : ' ');
		} 
	}
}
