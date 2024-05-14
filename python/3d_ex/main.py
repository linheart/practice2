def ex_euclid(c, m):
    steps = []
    x, y, lastx, lasty = 0, 1, 1, 0

    while m != 0:
        q = c // m
        r = c % m

        c, m = m, r

        temp = x
        x = lastx - q * x
        lastx = temp

        temp = y
        y = lasty - q * y
        lasty = temp

        steps.append({'r': c, 'x': lastx, 'y': lasty, 'q': q})

    steps.append({'r': m, 'x': x, 'y': y, 'q': 0})
    gcd = c
    return lastx, steps, gcd

def print_table(steps):
    print("r\t\tx\t\ty\t\tq")
    for step in steps:
        print(f"{step['r']}\t\t{step['x']}\t\t{step['y']}\t\t{step['q']}")

if __name__ == "__main__":
    c = int(input())
    m = int(input())

    d, steps, gcd = ex_euclid(c, m)
    print_table(steps)

    if gcd == 1:
        print((d % m + m) % m)
    else:
        print("the numbers must be mutually inverse")

