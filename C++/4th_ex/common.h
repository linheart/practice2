#ifndef COMMON_H // COMMON_H
#define COMMON_H

#include <vector>
#include <cmath>
#include <algorithm>
#include <random>

using namespace std;

#define sieve_size 10000

vector<int> sieve(int num);
int gen_rand_num(int start, int end);
int gen_prime_num();
int find_coprime_num(int n);
int gcd(int a, int b);
int ex_euclid(int c, int m);

#endif // COMMON_H
