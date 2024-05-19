import common
import mod_pow
import mod_pow_log
import sys

if __name__ == '__main__':
    a = int(input())
    x = int(input())
    p = int(input())

    if not common.is_prime(p):
        print("p must be a prime number")
        sys.exit(1)

    a = a % p 

    if a == 0:
        print(0)
    else:
        x = x % (p - 1)
        print(mod_pow.mod_pow(a, x, p))
        print(mod_pow_log.mod_pow_log(a, x, p))
