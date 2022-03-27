val = list(map(int,input().split()))

def find_sol():
    for i in range(-999,1000):
        for j in range(-999,1000):
            if(val[0]*i+val[1]*j==val[2]) and (val[3]*i+val[4]*j==val[5]):
                print(i,j)
                return 0
    return 0

find_sol()