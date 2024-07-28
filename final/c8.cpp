#include <iostream>
#include <vector>
using namespace std;


const int H = 6 + 1;
const int PW = (1<<(H+1));


using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using VI = vector<int>;


const vector<char> car = { '.', 'R', 'B' };


VVL R(H, VL(H));  // R[h][b] = arbres amb arrel R, d'alcada h, amb b negres als camins
VVL AR(H, VL(H)); // acumulat per h
VVL B(H, VL(H));  // B[h][b] = arbres amb arrel B, d'alcada h, amb b negres als camins
VVL AB(H, VL(H)); // acumulat per h

VI prof(PW); // profunditat dels nodes de l'arbre binari (guardat com un heap)

VI qb(PW);  // nombre de bs amb que arribem a cada posicio del heap
VI res(PW); // 0: fulla; 1: red; 2: black;


int h;          // alcada objectiu
ll num;         // numero que encara falta
bool ok;        // indica si ja s'ha aconseguit alcada h
int bmin, bmax; // rang per a les bs possibles


ll quad(ll x) {
  return x*x;
}


void calcula_profs(int pos, int p) {
  if (pos >= PW) return;
  prof[pos] = p;
  calcula_profs(2*pos, p + 1);
  calcula_profs(2*pos + 1, p + 1);
}


void calcula(int pos, int fill, int b, ll& bons, ll& sobren) {
  if (pos == 0) return;

  if (fill == 2*pos) { // venim del fill esquerra
    if (res[pos] == 1) {
      bons *= AB[h-prof[pos]][b-qb[pos]];
      sobren *= AB[h-prof[pos]-1][b-qb[pos]];
    }
    else {
      bons *= AR[h-prof[pos]][b-qb[pos]] + AB[h-prof[pos]][b-qb[pos]];
      sobren *= AR[h-prof[pos]-1][b-qb[pos]] + AB[h-prof[pos]-1][b-qb[pos]];
    }
  }

  calcula(pos/2, pos, b, bons, sobren);
}


void solu(int pos) {
  if (prof[pos] > h) {
    res[pos] = 0;
    cout << car[0];
    return;
  }

  int bs = qb[pos] = qb[pos/2];
  if (bs == bmin) {
    ll bons = 1;
    ll sobren = 1;
    calcula(pos/2, pos, bmin, bons, sobren);
    if (not ok) bons -= sobren;

    if (bons > num) {
      res[pos] = 0;
      cout << car[0];
      bmax = bmin;
      return;
    }
    num -= bons;
  }

  if (res[pos/2] == 2) {
    ll quants = 0;
    for (int b = bmin; b <= bmax; ++b) {
      ll bons = AR[h-prof[pos]+1][b-bs];
      ll sobren = AR[h-prof[pos]][b-bs];
      calcula(pos/2, pos, b, bons, sobren);
      if (not ok) bons -= sobren;
      quants += bons;
    }

    if (quants > num) {
      res[pos] = 1;
      cout << car[1];
      if (prof[pos] == h) ok = true;
      bmax = min(bmax, bs + (h - prof[pos]));
      solu(2*pos);
      solu(2*pos + 1);
      return;
    }

    num -= quants;
  }

  ++qb[pos];
  res[pos] = 2;
  cout << car[2];
  if (prof[pos] == h) ok = true;
  bmin = max(bmin, bs + 1);
  solu(pos*2);
  solu(pos*2 + 1);
}


int main() {
  B[0][0] = AB[0][0] = 1;
  R[1][0] = AR[1][0] = 1;
  AB[1][0] = 1;
  B[1][1] = AB[1][1] = 1;

  for (h = 2; h < H; ++h) {
    for (int b = 0; b <= h; ++b) {
      R[h][b] = quad(AB[h-1][b]) - quad(AB[h-2][b]);
      AR[h][b] = AR[h-1][b] + R[h][b];
    }
    for (int b = 0; b <= h; ++b) {
      if (b) B[h][b] = quad(AR[h-1][b-1] + AB[h-1][b-1]) - quad(AR[h-2][b-1] + AB[h-2][b-1]);
      AB[h][b] = AB[h-1][b] + B[h][b];
    }
  }

  calcula_profs(1, 1);

  qb[0] = 0;
  res[0] = 2;

  while (cin >> h >> num) {
    --num;
    ok = false;
    bmin = h/2;
    bmax = h;
    solu(1);
    cout << endl;
    if (num != 0) cerr << "PIFIA!!! " << num << endl;
  }
}