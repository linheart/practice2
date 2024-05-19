#include <iostream>

using namespace std;

int ex_euclid(int, int, int &);

int main() {
  int c, m;
  cin >> c >> m;

  int gcd;
  int d = ex_euclid(c, m, gcd);

  if (gcd == 1)
    cout << (d % m + m) % m << endl;
  else
    cout << "the numbers must be mutually inverse" << endl;

  return 0;
}

int ex_euclid(int c, int m, int &gcd) {
  int x = 0, y = 1, lastx = 1, lasty = 0, temp;
  while (m != 0) {
    int q = c / m;
    int r = c % m;

    c = m;
    m = r;

    temp = x;
    x = lastx - q * x;
    lastx = temp;

    temp = y;
    y = lasty - q * y;
    lasty = temp;
  }
  gcd = c;
  return lastx;
}
