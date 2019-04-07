# -*- coding: utf-8 -*-
def gcd(a, b):
  return a if b == 0 else gcd(b, a % b)


def solve():
  n, l = map(int, input().split())
  a = list(map(int, input().split()))
  for i in range(len(a) - 1):
    if a[i] != a[i + 1]:
      p = i + 1
      break
  r = [0] * (l + 1)
  r[p] = gcd(a[p - 1], a[p])
  for i in reversed(range(p)):
    r[i] = a[i] // r[i + 1]
  for i in range(p + 1, l + 1):
    r[i] = a[i - 1] // r[i - 1]
  p = list(set(r))
  p.sort()
  assert len(p) == 26
  print("".join(map(lambda e: chr(ord("A") + p.index(e)), r)))


for i in range(1, int(input()) + 1):
  print("Case #{}: ".format(i), end="")
  solve()
