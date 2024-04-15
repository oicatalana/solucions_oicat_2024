#include<bits/stdc++.h>
using namespace std;

int main() {
	string nom1, nom2;
	int dist1, dist2;
	string unitat1, unitat2;
	cin >> nom1 >> dist1 >> unitat1;
	cin >> nom2 >> dist2 >> unitat2;
	
	if(unitat1 == "milles") 
		dist1 *= 1609;
	else 
		dist1 *= 1000;

	if(unitat2 == "milles") 
		dist2 *= 1609;
	else 
		dist2 *= 1000;

	if(dist1 > dist2) 
		cout << nom1 << endl;
	else 
		cout << nom2 << endl;
}