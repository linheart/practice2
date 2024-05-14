from random import randint

sieve_size = 10000

def mod_pow(a, x, p):
    res = 1
    while x > 0:
        if x % 2 == 1:
            res = res * a % p
        a = a * a % p
        x >>= 1
    return res

def ex_euclid(c, m):
    x, y, lastx, lasty = 0, 1, 1, 0
    while m != 0:
        q = c // m
        r = c % m

        c = m
        m = r

        temp = x
        x = lastx - q * x
        lastx = temp

        temp = y
        y = lasty - q * y
        lasty = temp

    return lastx

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)

def find_coprime_num(n):
    while True:
        num = randint(1, n - 1)
        if (gcd(n, num) == 1):
            break
    return num
        

def gen_prime_num():
    prime_nums = sieve(sieve_size)
    return prime_nums[randint(0, len(prime_nums) -1)]


def sieve(num):
    nums = [i for i in range(2, num + 1)]

    max_num = nums[-1]

    i = 2
    while i ** 2 < max_num:
        if i in nums:
            j = i ** 2 - 2
            while j < len(nums):
                nums[j] = 0
                j += i
        i += 1

    nums = [i for i in nums if i != 0]
    return nums
