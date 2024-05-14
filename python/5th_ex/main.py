def mod_pow(a, x, p):
    res = 1
    for _ in range(x):
        res = res * a % p
    return res

if __name__ == '__main__':
    a = int(input())
    b = int(input())
    c = int(input())

    exp = mod_pow(b, c, 4)
    if exp == 0:
        exp = 4
    print(mod_pow(a, exp, 10))
