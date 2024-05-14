def mod_pow_log(a, x, p):
    bin_exp = bin(x)[2:]
    res = 1

    for i in bin_exp:
        if i == '1':
            res = res * a % p
        a = a * a % p
    return res
