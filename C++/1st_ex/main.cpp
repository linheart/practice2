#include "common.h"
#include "mod_pow.h"
#include "mod_pow_log.h"
#include <iostream>

using namespace std;

int main() {
  int a, x, p;
  cin >> a >> x >> p;

  if (!is_prime(p)) {
    cout << "p must be a prime number" << endl;
    return 1;
  }

  a = a % p;

  if (a == 0)
    cout << 0 << endl;
  else {
    x = x % (p - 1);
    cout << mod_pow(a, x, p) << endl;
    cout << mod_pow_log(a, x, p) << endl;
  }
  return 0;
}
