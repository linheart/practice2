#include <cmath>
#include <iostream>

using namespace std;

bool is_prime(int num);
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

bool is_prime(int num) {
  if (num <= 1 || num % 2 == 0 || num % 3 == 0)
    return false;
  if (num <= 3)
    return true;

  for (int i = 5; i < sqrt(num); i += 6)
    if (num % i == 0 || num % (i + 2) == 0)
      return false;
  return true;
}

int mod_pow(int a, int x, int p) {
  a = a % p;
  if (a == 0)
    return a;

  if (is_prime(p))
    x = x % (p - 1);

  int res = 1;

  while (x > 0) {
    if (x & 1)
      res = res * a % p;
    a = a * a % p;
    x >>= 1;
  }
  return res;
}
