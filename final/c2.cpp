#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int suma = a + b + c + d;
		int maxim = max(a, max(b, max(c, d)));
		if (suma - maxim > maxim)
			cout << "si" << endl;
		else
			cout << "no" << endl;
	}
}