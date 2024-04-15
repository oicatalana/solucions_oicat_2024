#include<bits/stdc++.h>
using namespace std;

int main() {
	for(int n = 1; n <= 100; ++n) {
		int suma_cubs = 0;
		for(int i = 0; i < 8; ++i) {
			suma_cubs += (n+i) * (n+i) * (n+i);
		}
		if(suma_cubs % 2024 == 0) {
			cout << suma_cubs << endl;
		}
	}
}