#include "common.h"
#include "mod_pow.h"
#include "mod_pow_log.h"
#include <iostream>

using namespace std;

int main() {
  int a, x, p;
  cin >> a >> x >> p;
	if (ferma(a, x, p))
		cout << 1 << endl;
	else {
		cout << mod_pow(a, x, p) << endl;
		cout << mod_pow_log(a, x, p) << endl;
	}
  return 0;
}
