#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int> repeticions(10, 3);
	repeticions[0] = 1;
	repeticions[1] = 0;
	repeticions[7] = repeticions[9] = 4;
	map<char,string> codifica;
	codifica['_'] = "0";
	int nombre = 1;
	int posicio = 1;
	for(char c = 'a'; c <= 'z'; ++c) {
		while(repeticions[nombre] < posicio) {
			posicio = 1;
			++nombre;
		}
		codifica[c] = string(posicio, '0' + nombre);
		++posicio;
	}


	string s;
	while(cin >> s) {
		for(char c : s) {
			cout << codifica[c];
		}
		cout << endl;
	}
}