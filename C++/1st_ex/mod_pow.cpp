#include "mod_pow.h"

int mod_pow(int a, int x, int p) {
	x = x % (p - 1);
  int res = 1;
  for (int i = 0; i < x; ++i)
    res = res * a % p;
  return res;
}
