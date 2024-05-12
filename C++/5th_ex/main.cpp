#include <iostream>

using namespace std;

int mod_pow(int a, int x, int p);

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int exp = mod_pow(b, c, 4);
  if (exp == 0)
    exp = 4;

  cout << mod_pow(a, exp, 10);

  return 0;
}

int mod_pow(int a, int x, int p) {
  int res = 1;
  for (int i = 0; i < x; ++i)
    res = res * a % p;
  return res;
}
