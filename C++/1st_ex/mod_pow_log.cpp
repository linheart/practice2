#include "mod_pow_log.h"
#include "common.h"

int mod_pow_log(int a, int x, int p) {
  string bin_exp = to_binary(x);
  int res = 1;

  for (size_t i = 0; i < bin_exp.size(); i++) {
    if (bin_exp[i] == '1')
      res = res * a % p;
    a = a * a % p;
  }
  return res;
}
