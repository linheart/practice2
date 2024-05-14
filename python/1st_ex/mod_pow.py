def mod_pow(a, x, p):
    res = 1
    for _ in range(x):
        res = res * a % p
    return res

