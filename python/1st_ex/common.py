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
