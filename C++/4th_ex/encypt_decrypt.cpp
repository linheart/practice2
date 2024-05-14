#include "encypt_decrypt.h"

string XOR(string m, int64_t c) {
  string enc_text = m;
  for (char &k : enc_text)
    k ^= c;
  return enc_text;
}
