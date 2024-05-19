def mod_pow(a, x, p):
   	x = x % (p - 1);
    res = 1
    for _ in range(x):
        res = res * a % p
    return res

