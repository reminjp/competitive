from functools import reduce


def chinese_remainder_theorem(a, m):
    s = 0
    p = reduce(lambda a, b: a * b, m)
    for ai, mi in zip(a, m):
        pi = p // mi
        s += ai * modulo_inverse(pi, mi) * pi
    return s % p


def modulo_inverse(a, m):
    m0 = m
    x0, x1 = 0, 1
    if m == 1:
        return 1
    while a > 1:
        q = a // m
        a, m = m, a % m
        x0, x1 = x1 - q * x0, x0
    if x1 < 0:
        x1 += m0
    return x1


a = [32134, 193127]
m = [1584891, 3438478]
print(chinese_remainder_theorem(a, m))
# 35430270439
