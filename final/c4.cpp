#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(cin >> n) {
		int minim = 1;
		int maxim = n;
		int x;
		while(cin >> x and x != 0) {
			string s;
			cin >> s;
			if(s == "mes")
				minim = max(minim, x + 1);
			else if(s == "menys")
				maxim = min(maxim, x - 1);
			else {
				minim = max(minim, x);
				maxim = min(maxim, x);
			}
		}
		if(minim > maxim) 
			cout << "trampa!" << endl;
		else if(minim == maxim) 
			cout << minim << endl;
		else 
			cout << "ok" << endl;
	}
}