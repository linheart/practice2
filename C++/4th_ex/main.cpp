#include "common.h"
#include "encypt_decrypt.h"
#include <iostream>

using namespace std;

int main() {
  int64_t p = gen_prime_num();
  int64_t q = gen_prime_num();
  int64_t n = p * q;
  int64_t phi = (p - 1) * (q - 1);
  int64_t e = find_coprime_num(phi);
  int64_t d = (ex_euclid(e, phi) % phi + phi) % phi;

  cout << "public keys: " << e << ' ' << n << endl;
  cout << "closed keys: " << d << ' ' << n << endl;

  string m;
  getline(cin, m);

  int64_t session_key = gen_rand_num(1, n - 1);
  int64_t enc_key = mod_pow(session_key, e, n);

  string enc_message = XOR(m, session_key);
  cout << enc_message << endl;

  int64_t dec_key = mod_pow(enc_key, d, n);
  string dec_message = XOR(enc_message, dec_key);
  cout << dec_message << endl;

  return 0;
}
