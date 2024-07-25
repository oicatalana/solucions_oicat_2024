# Solucions Final OIcat 2024

## Taula de continguts
* [Problema C1. Localitat més llunyana](#C1)
* [Problema C2. Quadrilàters](#C2)
* [Problema Q1. Suma de cubs (1)](#Q1)
* [Problema G1. Llonganisses](#G1)
* [Problema C3. Collaret de perles (1)](#C3)
* [Problema G2. Vestits](#G2)
* [Problema Q2. Superprimers](#Q2)
* [Problema C4. Més o menys?](#C4)
* [Problema Q3. Pocs palíndroms](#Q3)
* [Problema G3. Pinball](#G3)
* [Problema C5. Quadradets](#C5)
* [Problema Q4. Suma de cubs (2)](#Q4)
* [Problema C6. Laberint](#C6)
* [Problema C7. Collaret de perles (2)](#C7)
* [Problema C8. Arbres Red-Black](#C8)


## [Problema C1. Localitat més llunyana](https://jutge.org/problems/P37104_ca) <a name="C1"></a>

En aquest problema es donaven dues ciutats, amb la seva distància en milles o quilòmetres, i s'havia de dir quina de les dues era la més llunyana (suposant que una milla equival exactament a 1609 metres). Conceptualment, aquest problema era molt senzill, però alguns participants van tenir errors per manipular malament els nombres amb decimals. Per evitar-ho, la solució més senzilla consistia en passar totes les quantitats a metres. Així, les quantitats en quilòmetres s'havien de multiplicar per 1000 i les quantitats en milles s'havien de multiplicar per 1609, i no feia falta utilitzar nombres amb decimals en cap moment.  

<details>
  <summary><b>Codi (C++)</b></summary>

```cpp
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
```
</details>

<details>
  <summary><b>Codi (Python 3)</b></summary>

```py
from easyinput import read

def Convert(a):
  if a[2] == "milles":
    a[1] *= 1609
  else:
    a[1] *= 1000


a = read(str, int, str)
b = read(str, int, str)
Convert(a)
Convert(b)
if a[1] > b[1]:
  print(a[0])
else:
  print(b[0])
```
</details>

## [Problema C2. Quadrilàters](https://jutge.org/problems/P67380_ca) <a name="C2"/>

En aquest problema, donades les longituds de 4 segments, ens demanaven si podíem construir un quadrilàter amb ells. La clau del problema era adonar-se'n que es pot construir un quadrilàter si, i només si, el segment més llarg és més curt que la suma de la resta.

En el cas d'un triangle, la mateixa condició continua sent vàlida, i es coneix amb el nom de [desigualtat triangular](https://ca.wikipedia.org/wiki/Desigualtat_triangular). Així doncs, podrem construir un triangle amb costats $a \leq b \leq c$ sempre que es compleixi que $c < a + b$. 
<details>
  <summary><b>Demostració del cas del triangle (no del tot rigurosa)</b></summary>
Per veure-ho, observem que si $c \geq a + b$, amb els segments de longituds $a$ i $b$ no podem arribar a "tancar" el de longitud $c$ (en el cas $c = a + b$ sí que podríem, però la figura resultant tindria àrea zero, i no considerem que sigui un triangle). En canvi, si $c < a + b$, col·loquem el segment $c$ horitzontal amb els segments $a$ i $b$ verticals un a cada extrem, i anem rotant els segments $a$ i $b$ de manera que la part superior dels dos segments estigui a la mateixa altura. No és difícil convèncer-se que la condició $c < a + b$ implica que els extrems lliures dels dos segments s'acabaran trobant, tancant el triangle.
</details>

Un cop ho hem resolt pel triangle, podem utilitzar aquesta mateixa idea pel cas del quadrilàter:
<details>
  <summary><b>Demostració del cas del quadrilàter (no del tot rigurosa)</b></summary>
  Suposem que tenim quatre segments amb longituds $a \leq b \leq c \leq d$. Si $d \geq a + b + c$, igual que en el cas del triangle és fàcil veure que no es pot aconseguir un quadrilàter d'àrea no zero. Suposem doncs que $d < a + b + c$. Si $a = b = c = d$, podem construir un quadrat. Així doncs, podem assumir que no tots els segments són igual de llargs. Això implica que podem ajuntar els dos segments més petits i construir un triangle amb costats de longitud $d$, $c$ i $a + b$ (en efecte, es continua complint que $d < c + a + b$, i també que $a + b < c + d$, ja que $a \leq c$ i $b \leq d$, i la igualtat només es podria donar si els quatre costats fossin iguals). Un cop construït el triangle amb un costat de longitud $a + b$, podem ajuntar lleugerament els dos extrems del costat $a + b$, i subdividir-lo en dos costats de longitud $a$ i $b$, que ja no seran paral·lels. 

  Òbviament, aquesta no és una demostració totalment rigurosa, però esperem que serveixi per donar una idea intuïtiva de perquè la observació és certa.
</details>

La implementació és senzilla, ja sigui trobant el costat màxim i la suma, i comprovant que `suma - maxim > maxim`, o ordenant els quatre costats de petit a gran i comprovant la condició directament.

<details>
  <summary><b>Codi (C++)</b></summary>
  
```cpp
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
```
</details>

<details>
  <summary><b>Codi (Python 3)</b></summary>

```py
from easyinput import read

n = read(int)
for _ in range(n):
  a = [read(int) for _ in range(4)]
  a.sort()
  if a[0] + a[1] + a[2] > a[3]:
    print("si")
  else:
    print("no")
```
</details>

## [Problema Q1. Suma de cubs (1)](https://jutge.org/problems/P43901_ca) <a name="Q1"/>

En aquest problema hem de trobar el nombre més petit que sigui la suma de 8 cubs consecutius i que sigui divisible per 2024 (a part del 2024 mateix). Per resoldre-ho, calculem totes les possibles sumes de cubs consecutius i comprovem per cadascuna si és divisible per 2024. 

<details>
  <summary><b>Codi (C++)</b></summary>
  
```cpp
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
```
</details>

<details>
  <summary><b>Codi (Python 3)</b></summary>

```py
for n in range(100):
  suma_cubs = 0
  for i in range(8):
    suma_cubs += (n + i)**3
  if suma_cubs % 2024 == 0:
    print(suma_cubs)
```
</details>


## [Problema G1. Llonganisses](https://jutge.org/problems/P55377_ca) <a name="G1"/>

En aquest problema s'havia de crear una imatge representant una fusta de la qual pengen una sèrie de llonganisses de les mides donades. La única dificultat de la solució era implementar les instruccions donades sense equivocar-se.

Recordeu que podeu trobar una xuleta pels problemes gràfics a [](https://lliçons.jutge.org/python/grafics/pil.html), amb exemples d'ús de les funcions més habituals.

<details>
  <summary><b>Codi (Python 3)</b></summary>

```py
from PIL import Image, ImageDraw
from easyinput import read

# Dibuixa un rectangle:
#    nw = cantonada superior esquerra
#    se = cantonada inferior dreta
def DibuixaRectangle(nw, se, color):
  dib.polygon([nw, (nw[0], se[1]), se, (se[0], nw[1])], color)

n = read(int)
a = [read(int) for _ in range(n)]

alcada = 10 + 40 + max(a) + 20
llargada = 20 + 20*n + 10*(n-1) + 20
img = Image.new('RGB', (llargada, alcada), 'MidnightBlue')
dib = ImageDraw.Draw(img)

DibuixaRectangle((0,0), (llargada-1, 10 - 1), "Sienna")
x = 20
for i in range(n):
  DibuixaRectangle((x + 9, 10), (x + 10, 49), "White")
  dib.ellipse([(x, 50), (x + 19, 69)], "Grey")
  DibuixaRectangle((x, 60), (x + 19, a[i] + 39), "Grey")
  dib.ellipse([(x, a[i] + 30), (x + 19, a[i] + 49)], "Firebrick")
  x += 30

img.save('output.png')
```
</details>

## [Problema C3. Collaret de perles (1)](https://jutge.org/problems/P38607_ca) <a name="C3"/>

<details>
  <summary><b>Codi (C++)</b></summary>
  
```cpp

```
</details>

<details>
  <summary><b>Codi (Python 3)</b></summary>

```py

```
</details>

## [Problema G2. Vestits](https://jutge.org/problems/P15490_ca) <a name="G2"/>

## [Problema Q2. Superprimers](https://jutge.org/problems/P99345_ca) <a name="Q2"/>

## [Problema C4. Més o menys?](https://jutge.org/problems/P17499_ca) <a name="C4"/>

## [Problema Q3. Pocs palíndroms](https://jutge.org/problems/P97623_ca) <a name="Q3"/>

## [Problema G3. Pinball](https://jutge.org/problems/P94446_ca) <a name="G3"/>

## [Problema C5. Quadradets](https://jutge.org/problems/P76718_ca) <a name="C5"/>

## [Problema Q4. Suma de cubs (2)](https://jutge.org/problems/P52098_ca) <a name="Q4"/>

## [Problema C6. Laberint](https://jutge.org/problems/P34055_ca) <a name="C6"/>

## [Problema C7. Collaret de perles (2)](https://jutge.org/problems/P89236_ca) <a name="C7"/>

## [Problema C8. Arbres Red-Black](https://jutge.org/problems/P13747_ca) <a name="C8"/>



