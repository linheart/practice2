#include "common.h"
#include <vector>

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

int gen_rand_num(int start, int end) {
  random_device rd;
  mt19937 gen(rd());
  uniform_int_distribution<> dis(start, end);
  return dis(gen);
}

int gen_prime_num() {
  vector<int> prime_nums = sieve(sieve_size);
  return prime_nums[gen_rand_num(0, prime_nums.size() - 1)];
}

int gcd(int a, int b) {
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int find_coprime_num(int n) {
	int num;
	do {
		num = gen_rand_num(1, n - 1);
	} while (gcd(n, num) != 1);

	return num;
}

int ex_euclid(int c, int m) {
  int x = 0, y = 1, lastx = 1, lasty = 0, temp;
  while (m != 0) {
    int q = c / m;
    int r = c % m;

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
