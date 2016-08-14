# -*- coding: utf-8 -*-
#
#  https://codeiq.jp/challenge/2934
#
######################################

def func(p):
    p *= 2
	
    res = 0
    a = 0
    while a*(a+1) <= p:
        if p % (a + 1) == 0:
            b = p / (a + 1) - a
            if b != 0 and b % 2 == 0:
	             res += 1
        a += 1
	
    return res


n = int(input())

res = 0
for p in range(1,n+1):
    if n % p == 0:
        q = n / p
        res += func(p) * func(q)

print(res)

