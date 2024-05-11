#include <iostream>

using namespace std;

int ex_gcd(int, int, int &, int &);
int mod_inverse(int, int);

int main() {
  int c, m;
  cin >> c >> m;
  cout << mod_inverse(c, m);

  return 0;
}

int mod_inverse(int c, int m) {
  int x, y;
  if (ex_gcd(c, m, x, y) == 1)
    return (x % m + m) % m;
  return -1;
}

int ex_gcd(int c, int m, int &x, int &y) {
  if (m == 0) {
    x = 1;
    y = 0;
    return c;
  }
  int x1, y1;
  int d = ex_gcd(m, c % m, x1, y1);
  x = y1;
  y = x1 - (c / m) * y1;
  return d;
}
