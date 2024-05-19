#ifndef COMMON_H // COMMON_H
#define COMMON_H

#include <cstdint>
#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

#define sieve_size 10000

bool is_prime(int64_t num);
int64_t mod_pow(int64_t a, int64_t x, int64_t p);
vector<int> sieve(int num);
int64_t gen_rand_num(int64_t start, int64_t end);
int64_t gen_prime_num();
int64_t find_coprime_num(int64_t n);
int64_t gcd(int64_t a, int64_t b);
int64_t ex_euclid(int64_t c, int64_t m);

#endif // COMMON_H
