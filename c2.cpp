#include<bits/stdc++.h>
using namespace std;

int main() {
	map<string,int> index;
	vector<string> v = {"pedra", "paper", "tisores", "llangardaix", "Spock"};
	for(int i = 0; i < 5; ++i) {
		index[v[i]] = i;
	}
	vector<vector<bool>> guanya(5, vector<bool>(5, false));
	guanya[2][1] = true;
	guanya[1][0] = true;
	guanya[0][3] = true;
	guanya[3][4] = true;
	guanya[4][2] = true;
	guanya[2][3] = true;
	guanya[3][1] = true;
	guanya[1][4] = true;
	guanya[4][0] = true;
	guanya[0][2] = true;

	string a, b;
	int punts_a = 0, punts_b = 0;
	while(cin >> a >> b) {
		int i = index[a];
		int j = index[b];
		if(i == j) continue;
		if(guanya[i][j]) punts_a++;
		else punts_b++;
	}

	cout << punts_a << " " << punts_b << endl;
}