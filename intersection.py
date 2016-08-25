# -*- coding: utf-8 -*-
#
# https://codeiq.jp/challenge/2944
#
#############################
import numpy as np

def sign(a): # necessary to prevent overflow
   if a > 0:
      return 1;
   elif a < 0:
      return -1;
   return 0

def isDoubled(p,q):
   return -1 if (p==q).all() else 0

def Contains(p,a):
   f = sign(np.cross(p-a[0], a[1]-a[0]))
   g = sign(np.cross(p-a[1], a[2]-a[1]))
   h = sign(np.cross(p-a[2], a[0]-a[2]))
   
   return 1 if f*g >= 0 and g*h >= 0 and h*f >= 0 else 0

def isCrossed(a,b,c,d):
   return 1 if sign(np.cross(c-a, b-a)) * sign(np.cross(d-a, b-a)) < 0 and sign(np.cross(a-c, d-c)) * sign(np.cross(b-c, d-c)) < 0 else 0

query = raw_input().split(" ")
query = [q.split("/") for q in query]
query = [[tri[1:-1].split(")(") for tri in q] for q in query]
query = [[[p.split(",") for p in tri] for tri in q] for q in query]
query = [[[list(map(long,p)) for p in tri] for tri in q] for q in query]
query = np.array(query)

output = ""
for q in query:
   a = q[0]
   b = q[1]
   
   inA = [Contains(p,b) for p in a]
   inB = [Contains(p,a) for p in b]
   doubled = [isDoubled(s,t) for s in a for t in b]
   cross = [isCrossed(a[i], a[(i+1)%3], b[j], b[(j+1)%3]) for i in range(3) for j in range(3)]
   res = sum(inA + inB + cross + doubled)
   res = '-' if res<=2 else str(res)
   output += res

print output
