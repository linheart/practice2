from random import randint
import math

sieve_size = 10000

def is_prime(num):
    if num <= 1 or num % 2 == 0 or num % 3 == 0:
        return False
    if num <= 3:
        return True

    for i in range(5, int(math.sqrt(num)), 6):
        if num % i == 0 or num % (i + 2) == 0:
            return False
    return True


def mod_pow(a, x, p):
    res = 1
    a = a % p
    if a == 0:
        return a

    if is_prime(p):
        x = x % (p - 1)

    while x > 0:
        if x & 1:
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
