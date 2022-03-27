import sys
import math
from decimal import *
fastinput = lambda: sys.stdin.readline().rstrip()
N, K = map(int, fastinput().split())
val = list(map(int, fastinput().split()))
def find_sol():
    sol = list()
    for i in range(N-K+1):
        for j in range(N-K-i+2):
            tmp_list = val[i:i+K+j]
            m = sum(tmp_list)/len(tmp_list)
            tmp = 0
            for v in tmp_list:
                tmp+=(v-m)**2
            tmp = tmp/len(tmp_list)
            sol.append(tmp)
    return sol
print(math.sqrt(min(find_sol())))