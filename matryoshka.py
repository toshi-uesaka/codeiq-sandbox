# -*- coding: utf-8 -*-
#
# https://codeiq.jp/challenge/2950
# Python3
#
#############################

n = int(input())
hoge = [(n-i)**i for i in range(n)]
print(max(hoge))
