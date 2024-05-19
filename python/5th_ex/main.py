import math

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

if __name__ == '__main__':
    a = int(input())
    b = int(input())
    c = int(input())

    exp = mod_pow(b, c, 4)
    if exp == 0:
        exp = 4
    print(mod_pow(a, exp, 10))
