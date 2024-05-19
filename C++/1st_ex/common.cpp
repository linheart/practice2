#include "common.h"

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

string to_binary(int num) {
  int t = log2(num);
  string bin = "";

  for (int i = 0; i <= t; i++, num /= 2)
    bin += num % 2 == 0 ? '0' : '1';

  return bin;
}
