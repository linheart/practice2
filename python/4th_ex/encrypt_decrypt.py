def XOR(m, c):
    return ''.join(chr(ord(k) ^ (c & 0xFF)) for k in m)
