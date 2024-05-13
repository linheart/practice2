#include "common.h"
#include <iostream>
#include <string>

using namespace std;

int gen_prime_num();

int main() {
  int p = gen_prime_num();
  int q = gen_prime_num();
	int n = p * q;
	int phi = (p - 1) * (q - 1);
	int e = find_coprime_num(phi);
	int d = (ex_euclid(e, phi) % phi + phi) % phi;

	cout << "public keys: " << e << ' ' << n << endl;
	cout << "closed keys: " << d << ' ' << n << endl;

	string m;
	getline(cin, m);
  return 0;
}
