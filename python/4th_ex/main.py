from random import randint
import common
import encrypt_decrypt

if __name__ == '__main__':
    q = common.gen_prime_num()
    p = common.gen_prime_num()
    n = p * q
    phi = (p - 1) * (q - 1)
    e = common.find_coprime_num(phi)
    d = (common.ex_euclid(e, phi) % phi) + phi % phi

    print(f"public keys: {e} {n}")
    print(f"privat keys: {d} {n}")
    
    m = input()
    session_key = randint(1, n - 1)
    enc_key = common.mod_pow(session_key, e, n)
    enc_message = encrypt_decrypt.XOR(m, session_key)
    print(enc_message)

    dec_key = common.mod_pow(enc_key, d, n)
    dec_message = encrypt_decrypt.XOR(enc_message, dec_key)
    print(dec_message)


