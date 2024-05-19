#include "common.h"

bool is_prime(int64_t num) {
  if (num <= 1 || num % 2 == 0 || num % 3 == 0)
    return false;
  if (num <= 3)
    return true;

  for (int i = 5; i < sqrt(num); i += 6)
    if (num % i == 0 || num % (i + 2) == 0)
      return false;
  return true;
}

int64_t mod_pow(int64_t a, int64_t x, int64_t p) {
  int64_t res = 1;
  a = a % p;
  if (a == 0)
    return a;

  if (is_prime(p))
    x = x % (p - 1);

	while (x > 0) {
    if (x & 1)
      res = res * a % p;
    a = a * a % p;
    x >>= 1;
  }

  return res;
}

vector<int> sieve(int num) {
  vector<int> nums;

  for (int i = 2; i <= num; i++)
    nums.push_back(i);

  int max_num = nums.back();

  for (int i = 2; pow(i, 2) < max_num; i++)
    if (find(nums.begin(), nums.end(), i) != nums.end())
      for (size_t j = pow(i, 2) - 2; j <= nums.size(); j += i)
        nums[j] = 0;

  nums.erase(remove_if(nums.begin(), nums.end(), [](int i) { return i == 0; }),
             nums.end());
  return nums;
}

int64_t gen_rand_num(int64_t start, int64_t end) {
  random_device rd;
  mt19937_64 gen(rd());
  uniform_int_distribution<int64_t> dis(start, end);
  return dis(gen);
}

int64_t gen_prime_num() {
  vector<int> prime_nums = sieve(sieve_size);
  return prime_nums[gen_rand_num(0, prime_nums.size() - 1)];
}

int64_t gcd(int64_t a, int64_t b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int64_t find_coprime_num(int64_t n) {
  int64_t num;
  do {
    num = gen_rand_num(1, n - 1);
  } while (gcd(n, num) != 1);

  return num;
}

int64_t ex_euclid(int64_t c, int64_t m) {
  int64_t x = 0, y = 1, lastx = 1, lasty = 0, temp;
  while (m != 0) {
    int64_t q = c / m;
    int64_t r = c % m;

    c = m;
    m = r;

    temp = x;
    x = lastx - q * x;
    lastx = temp;

    temp = y;
    y = lasty - q * y;
    lasty = temp;
  }
  return lastx;
}
