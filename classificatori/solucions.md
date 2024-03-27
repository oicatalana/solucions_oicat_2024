# Solucions Classificatori OICat 2024

## Taula de continguts
* [Problema C1. Carrers i avingudes](#C1)
* [Problema C2. Pedra, paper, tisores, llangardaix, Spock](#C2)
* [Problema G1. Codi de barres](#G1)
* [Problema Q1. Caramels](#Q1)
* [Problema C3. SMS (1)](#C3)
* [Problema G2. Triler](#G2)
* [Problema C4. Subparaules més freqüents](#C4)
* [Problema Q2. Factors petits](#Q2)
* [Problema C5. Territori més gran](#C5)
* [Problema C6. SMS (2)](#C6)
* [Problema C7. Arbre en grups de tres](#C7)
* [Problema C8. Camins hamiltonians palindròmics](#C8)


## [Problema C1. Carrers i avingudes](https://jutge.org/problems/P11225_ca) <a name="C1"></a>

Cal calcular el que precisament es coneix com a <a href="https://ca.wikipedia.org/wiki/Geometria_del_taxista">distància Manhattan</a>. Com que primer ens podem moure en una dimensió, i després en l'altra, la resposta és senzillament $\left\vert c_1 - c_2 \right\vert + \left \vert a_1 - a_2 \right\vert$.

<details>
  <summary><b>Codi</b></summary>

```cpp
#include<bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << abs(a-c) + abs(b-d) << endl;
}
```
</details>

## [Problema C2.  Pedra, paper, tisores, llangardaix, Spock](https://jutge.org/problems/P78607_ca) <a name="C2"/>

Hi ha moltes solucions possibles, algunes massa complicades. Podem programar-ho de forma còmoda si a cada paraula li assignem un número:
```cpp
int num(string s) {
  if (s == "pedra") return 0;
  if (s == "paper") return 1;
  if (s == "tisores") return 2;
  if (s == "Spock") return 3;
  if (s == "llangardaix") return 4;
  return -1; // no hauria de passar
}
```
i creem una matriu que guardi els resultats de cada enfrontament:
```cpp
using VI = vector<int>;
using VVI = vector<VI>;

const VVI M = {
  { 2, 0, 1, 0, 1 },
  { 1, 2, 0, 1, 0 },
  { 0, 1, 2, 0, 1 },
  { 1, 0, 1, 2, 0 },
  { 0, 1, 0, 1, 2 }
};
```

El programa principal ara pot ser
```cpp
int main() {
  VI R(3, 0);
  string s, t;
  while (cin >> s >> t) ++R[M[num(s)][num(t)]];
  cout << R[1] << ' ' << R[0] << endl;
}
```


## [Problema G1. Codi de barres](https://jutge.org/problems/P60369_ca) <a name="G1"/>

Aquesta n'és una possible solució:
```py
from PIL import Image, ImageDraw

# Extrem esquerre superior (x, y), altura h, amplada w, color col.
def rect(x, y, w, h, col):
    dib.polygon([(x, y), (x + w - 1, y), (x + w - 1, y + h - 1), (x, y + h - 1)], col)

marge_vores = 5
alcada = 100
marge_entre_barres = 10
amplada_barra = 5

a = [int(x) for x in input()]
n = len(a)

W = 2*marge_vores + sum(a)*amplada_barra + (n-1)*marge_entre_barres
H = alcada + 2*marge_vores

img = Image.new('RGB', (W, H), 'Red')
dib = ImageDraw.Draw(img)

x = marge_vores
for d in a:
    rect(x, marge_vores, amplada_barra*d, alcada, 'Black')
    x += amplada_barra*d + marge_entre_barres

img.save("output.png")
```

Per aquest i altres problemes gràfics, recordeu que les imatges de la llibreria `PIL` es representen com graelles amb $n$ files i $m$ columnes, on la casella superior esquerra té les coordenades $(0,0)$ i la casella inferior dreta té les coordenades $(m-1,n-1)$. Per meś dubtes, podeu consultar la xuleta per a problemes gràfics a <a>https://lliçons.jutge.org/python/grafics/pil.html</a>.


## [Problema Q1. Caramels](https://jutge.org/problems/P22580_ca) <a name="Q1"/>

Cal saber que hi ha $\binom{n}{k}$ ("$n$ sobre $k$") maneres d'escollir $k$ objectes d'entre $n$. El nombre de maneres es pot calcular amb la fórmula $\binom{n}{k} = \frac{n!}{k!(n-k)!}$.

Les nenes poden rebre un caramel especial o dos. El nombre de maneres que una nena rebi un caramel especial és $\binom{6}{1} \cdot \binom{4}{2} = 6 \cdot 6 = 36$. El nombre de maneres que dues nenes reben un caramel especial és $\binom{6}{2} \cdot \binom{4}{1}  = 15 \cdot 4 = 60$. En total, hi ha 96 possibilitats.

El problema també es pot resoldre de forma no-matemàtica, calculant per exemple les 1024 cadenes de 10 bits, interpretant els bits a 1 com "la persona $i$-èsima té un caramel especial", i comptant quantes combinacions tenen exactament 3 bits a 1, almenys 1 bit a 1 en les primeres 6 posicions, i almenys 1 bit a 1 en les últimes 4 posicions.

## [Problema C3. SMS (1)](https://jutge.org/problems/P41768_ca) <a name="C3"/>

Potser la manera més senzilla de resoldre aquest problema consisteix a
guardar la codificació de cada lletra en un map:

```cpp
  map<char, string> M;
  M['a'] = "2";
  M['b'] = "22";
  M['c'] = "222";
  M['d'] = "3";
  ...
```

Amb això, el bucle principal és trivial:
```cpp
  string s;
  while (cin >> s) {
    for (char c : s) cout << M[c];
    cout << endl;
  }
```

En lloc d'omplir el map a mà, també es podria fer així:
```cpp
vector<int> repeticions(10, 3);
repeticions[0] = 1;
repeticions[1] = 0;
repeticions[7] = repeticions[9] = 4;
map<char,string> M;
M['_'] = "0";
int nombre = 1;
int acumulat = 1;
for(char c = 'a'; c <= 'z'; ++c) {
  while(repeticions[nombre] < acumulat) {
    acumulat = 1;
    ++nombre;
  }
  M[c] = string(acumulat, '0' + nombre);
  ++acumulat;
}
```

## [Problema G2. Triler](https://jutge.org/problems/P97253_ca) <a name="G2"/>

Aquesta és la part principal d'una possible solució:

```cpp
estat = [0, 1, 2]

s = read(str)
while s is not None:
    a = int(s[0]) - 1
    b = int(s[4]) - 1
    estat[a], estat[b] = estat[b], estat[a]
    s = read(str)
```

## [Problema C4. Subparaules més freqüents](https://jutge.org/problems/P76844_ca) <a name="C4"/>

Com que la $k$ és molt petita, no cal fer cap optimització especial. Una manera relativament directa de resoldre el problema consisteix a comptar el nombre d'aparicions de cada subparaula, trobar el nombre màxim, i després escriure el resultat:

```cpp
int main() {
  int k;
  string s;
  while (cin >> k >> s) {
    int n = s.size();
    map<string, int> M; // per a cada subparaula, quantes vegades apareix
    for (int i = 0; i <= n - k; ++i) ++M[s.substr(i, k)];

    int mx = 0; // comptador maxim
    for (auto& p : M) mx = max(mx, p.second);

    bool primer = true; // per evitar el primer espai
    for (auto& p : M)
      if (p.second == mx) {
        if (primer) primer = false;
        else cout << ' ';
        cout << p.first;
      }
    cout << endl;
  }
}
```

<details><summary><b>Repte</b></summary>
    Com resoldríeu el problema en temps $\mathcal{O}(\vert s \vert)$ si la $k$ pogués anar de 1 fins a $\vert s \vert$?
</details>

## [Problema Q2. Factors petits](https://jutge.org/problems/P94100_ca) <a name="Q2"/>

Podem fer un programa que calculi tots els nombres mes petits que $10^8$ amb la propietat demanada, i escriure'n el més gran:

```cpp
const vector<int> V = { 2, 3, 5, 7 };

int main() {
  set<int> S; // amb tots els nombres trobats
  queue<int> Q; // amb els nombres encara per tractar
  S.insert(1);
  Q.push(1);
  while (not Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y : V) {
      int z = y*x;
      if (z < 1e8 and S.find(z) == S.end()) { // si es un nombre prou petit i nou
        S.insert(z);
        Q.push(z);
     }
   }
  }
  cout << *(--S.end()) << endl; // màxim element del conjunt
}
```

<details><summary><b>Solució alternativa</b></summary>

```cpp
  set<int> s;
  s.insert(1);
  int res = 0;
  while(*s.begin() < 1e8) {
    int x = *s.begin();
    resposta = max(res, x);
    s.erase(x);
    s.insert(2*x);
    s.insert(3*x);
    s.insert(5*x);
    s.insert(7*x);
  }
  cout << res << endl;
```
</details>

## [Problema C5. Territori més gran](https://jutge.org/problems/P63631_ca) <a name="C5"/>

La solució més natural fa dos recorreguts pel graf (en profunditat, que són més
simples):
```cpp
using VC = vector<char>;
using VVC = vector<VC>;
using VI = vector<int>;
using VVI = vector<VI>;


// Per comoditat, podem fer servir variables globals.
char c;   // caràcter a pintar
int n, m; // dimensions
VVC M;    // mapa
VVI vist; // caselles ja vistes


// Retorna el nombre de caselles noves del component connex de (i, j).
int dfs1(int i, int j) {
  if (i < 0 or i >= n or j < 0 or j >= m or M[i][j] == 'X' or vist[i][j]) return 0;
  vist[i][j] = true;
  return 1 + dfs1(i + 1, j) + dfs1(i - 1, j) + dfs1(i, j + 1) + dfs1(i, j - 1);
}


// Pinta amb el caràcter c el component connex de (i, j).
void dfs2(int i, int j) {
  if (i < 0 or i >= n or j < 0 or j >= m or M[i][j] == 'X' or M[i][j] == c) return;
  M[i][j] = c;
  dfs2(i + 1, j);
  dfs2(i - 1, j);
  dfs2(i, j + 1);
  dfs2(i, j - 1);
}


int main() {
  while (cin >> n >> m >> c) {
    M = VVC(n, VC(m));
    for (int i = 0; i < n; ++i)
      for (char& d : M[i]) cin >> d;

    vist = VVI(n, VI(m, false));
    int mx = 0;
    int x = -1;
    int y = -1;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (not vist[i][j]) {
          int q = dfs1(i, j);
          if (q > mx) {
            mx = q;
            x = i;
            y = j;
          }
        }

    dfs2(x, y);

    for (int i = 0; i < n; ++i) {
      for (char d : M[i]) cout << d;
      cout << endl;
    }
    cout << string(10, '-') << endl;
  }
}
```


## [Problema C6. SMS (2)](https://jutge.org/problems/P35938_ca) <a name="C6"/>

La solució esperada usa la tècnica anomenada "programació dinàmica". Bàsicament, consisteix a trobar una recurrència que resolgui el problema, i evitar repetir càlculs. Sigui $f(i)$ la resposta corresponent als $i$ primers dígits. Com a cas base, tenim que $f(0) = 1$ (la seqüència buida). En general, tenim per exemple $f(i) = f(i - 1) + (f - 2) + f(i - 3)$ si els últims tres dígits del prefix són iguals (i no són 0, 7 ni 9):

```cpp
using VI = vector<int>;
string s;
VI V;

// Hi ha moltes maneres similars d'escriure això mateix.
int f(int i) {
  int& res = V[i];
  if (res != -1) return res; // si ja havíem calculat f(i)
  if (i == 0) return res = 1; // cas base
  char c = s[i-1];
  if (c == '0') return res = f(i - 1); // no hi ha opcions: és un espai
  int mx = (c == '7' or c == '9' ? 4 : 3); // en general, 3 caràcters màxim, però 4 per al 7 i el 9
  int j = i - 1;
  while (--j >= 0 and s[j] == c and i - j <= mx) ; // mirem quants dígits seguits iguals hi ha (màxim mx)
  res = 0;
  for (int k = i - 1; k > j; --k) res = (res + f(k))%MOD; // sumem totes les opcions
  return res;
}


int main() {
  while (cin >> s) {
    int n = s.size();
    V = VI(n + 1, -1);
    cout << f(n) << endl;
  }
}
```
El codi anterior serà eficient gràcies a la línia `if (res != -1) return res;` que evita tornar a calcular `f(i)` si ja l'hem calculat anteriorment per a aquell valor de `i`. Observeu també que quan fem `int& res = V[i]`, el signe '&' indica que no estem copiant el valor de `V[i]` a una nova variable `res`, sinó que la variable `res` apunta directament a la direcció de memòria on tenim guardat `V[i]`. Així doncs, quan modifiquem `res`, també estarem modificant `V[i]`. Així garantim que els nous valors que calculem es guarden al vector `V` per a evitar tornar-los a calcular en les futures crides a `f`.


## [Problema C7. Arbre en grups de tres](https://jutge.org/problems/P81908_ca) <a name="C7"/>

Es pot recórrer l'arbre en <a href="https://en.wikipedia.org/wiki/Tree_traversal">post-ordre</a>, i mantenir un booleà que indica si tot ha anat bé. Per a cada fill, mirem quants nodes sobren (pot ser 0, 1 o 2). Per a que tot vagi bé, podem tenir un fill amb un excedent de 2 i cap altre excedent, o com a màxim dos fills amb un excedent de 1 i cap altre excedent. L'excedent del subarbre actual es calcula fàcilment en funció de l'excedent dels fills. Per exemple, si cap fill té excedents, al subarbre actual li sobra un node (l'arrel). Mentre es comprova que la solució és possible, és fàcil saber quines arestes cal esborrar, perquè la solució és única (si existeix): són les arestes que connecten cada node amb els seus fills sense excedents.

## [Problema C8. Camins hamiltonians palindròmics ](https://jutge.org/problems/P31373_ca) <a name="C8"/>

La solució directa, que només obté puntuació parcial, calcula els 12! camins, i per a cadascun comprova que sigui un palíndrom. Tenint en compte que hi ha prop de 500 milions de camins, això és massa lent.

La solució esperada primer reparteix els vèrtexs en dos conjunts de (quasi) la mateixa mida, de totes les maneres possibles. Després, calcula tots els camins per força bruta en el graf original amb els vèrtexs d'un dels subconjunts, guardant els prefixos trobats i de quantes maneres s'han obtingut en un map. Després, es fa una altra força bruta en el graf invers amb l'altre subconjunt de vèrtexs. Per a cada sufix trobat, sumem al resultat total la quantitat de vegades que el mateix prefix ha aparegut en la força bruta anterior. Aquesta tècnica s'anomena <a href="https://usaco.guide/gold/meet-in-the-middle?lang=cpp">meet in the middle</a>.

Si calculem què costa, tenim $\binom{12}{6} = 924$ maneres de repartir els vèrtexs en dues meitats. Cada meitat costa $6! = 720$ permutacions, que s'ha de multiplicar pel cost de guardar-la o buscar-la a un map. Això dóna $924*2*6!$ accessos a un map, nombre
més petit que un milió i mig.
