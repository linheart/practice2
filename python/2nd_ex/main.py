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

    return c, lastx


if __name__ == '__main__':
    c = int(input())
    m = int(input())
    gcd, d = ex_euclid(c, m)

    if gcd == 1:
        print((d % m + m) % m)
    else:
        print("the numbers must be mutually inverse")

    
