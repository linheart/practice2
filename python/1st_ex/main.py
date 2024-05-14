import common
import mod_pow
import mod_pow_log

if __name__ == '__main__':
    a = int(input())
    b = int(input())
    c = int(input())

    if common.ferma(a, b, c):
        print(1)
    else:
        print(mod_pow.mod_pow(a, b, c))
        print(mod_pow_log.mod_pow_log(a, b, c))
    


