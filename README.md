# Tema 1 — Forme geometrice (OOP, C++)

Acest repository conține implementarea ta pentru recunoașterea de forme și aproximarea dimensiunii lor.
**Am păstrat integral codul tău original;** am adăugat doar comentarii explicative și acest `README.md`.

## Cerință (rezumat)

### Clase
- **Point**
  - Atribute private: `x`, `y` (double).
  - Constructori: fără parametri (x=y=0), respectiv cu 2 parametri.
  - `getX() const`, `getY() const`; `setX(...)`, `setY(...)`.
  - Operator `Point operator-(const Point&) const` care întoarce un punct ce conține **valori absolute** ale diferențelor coordonatelor (|x1 - x2|, |y1 - y2|).

- **Shape** (abstractă)
  - Atribute `protected`: `mFirst`, `mSecond` (Point), `mName` (std::string).
  - Constructori: default (puncte (0,0)), și cu doi `Point`.
  - `getFirst() const`, `getSecond() const`; `setFirst(...)`, `setSecond(...)`.
  - `getName() const`, `setName(...)`.
  - Metode **pure virtuale**: `getPerimeter() const`, `getArea() const` (double).

- **Quadrilateral** (derivată din `Shape`)
  - Constructor default: puncte (0,0), `mName = "Unknown"`.
  - Constructor cu 3 parametri: primele două puncte + nume.
  - `getLength() const` = distanța pe Ox între mFirst și mSecond; `getWidth() const` = distanța pe Oy.
  - Implementarea lui `getPerimeter()` și `getArea()`.
  - *Indicație:* folosește operatorul `-` din `Point` pentru a obține diferențele absolute.

- **Circle** (derivată din `Shape`)
  - Atribut privat: `mRadius` (double).
  - Constructor default: mFirst=(0,0), mSecond=(0,0), `mRadius=0`, `mName="Unknown"`.
  - Constructor `(Point center, double radius)`: `mFirst=center`, `mSecond` nefolosit, `mName="cerc"`.
  - Implementările pentru `getPerimeter()` și `getArea()`; `setRadius(...)`, `getRadius() const`.

### Funcționalitate
Se citește o listă de forme: cerc / pătrat / dreptunghi, cu mărimile de definiție:
- **cerc**: coordonatele centrului (x, y) și **raza**;
- **patrat**/**dreptunghi**: coordonatele colțului **stânga-sus** (x1, y1) și **dreapta-jos** (x2, y2).
Se sortează **crescător** după **arie**; dacă ariile sunt egale (vezi regula de egalitate), se sortează după **perimetru**.

Pe prima linie: `n min max` (n ∈ [1, 500], min/max > 0 și min ≤ max).Urmează `n` linii cu formele.

### Validări
- Dacă `n` iese din interval, ori vreo coordonată/rază e în afara domeniilor cerute, ori `min > max` → afișați **`Valoare de intrare invalida`** și terminați programul.
- **Egalitatea** între două numere floating point `f1` și `f2`: se consideră egale dacă `|1 - f1/f2| < 0.0001`.
- Calculați în **double** și afișați cu **exact 6 zecimale**.

### Ieșire
Formele ordonate crescător după arie: tip, arie, perimetru — fiecare pe linie, terminate cu `\n`.

## Exemplu IO

### Intrare
```
5 120.7 150.4
cerc 4.7 3.5 12
cerc 20 21 15
patrat 0 0 10 10
dreptunghi 40 23 45 30.5
cerc 10 21 17
```

### Ieșire
```
dreptunghi 37.500000 25.000000
patrat 100.000000 40.000000
cerc 452.389342 75.398224
cerc 706.858347 94.247780
cerc 907.920277 106.814150
```

## Compilare & rulare (exemplu, g++)
```bash
# proiect single-file:
g++ -std=c++17 -O2 -pipe -s -o forme main.cpp

# proiect multi-file:
g++ -std=c++17 -O2 -pipe -s -o forme *.cpp
./forme < input.txt
```

---

> ✍️ Comentarii au fost adăugate în fișierele sursă doar pentru claritate (headere + marcaje la clase/funcții), fără modificări de logică.  
> 📅 Data actualizării: 2025-10-16
