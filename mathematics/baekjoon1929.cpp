#include <iostream>
#include <vector>

using namespace std;
class prime{
private :
    vector<int> map;
    int M,N;
public :
    prime(int m,int n):M(m),N(n){
        map.resize(N+1,1);
        map[0]=0;
        map[1]=0;
    };

    void find_prime(){
        for(int i=2;i<=N;i++)
            if(map[i]==1)
                for(int j=2;j<=N/i;j++)
                    map[i*j]=0;
    };

    void print_prime(){
        for(int i=M;i<=N;i++)
            if(map[i]==1)
                std::cout << i << '\n';
    };

};

int main(){
    int m,n;
    std::cin >> m >> n;
    prime sosu(m,n);
    sosu.find_prime();
    sosu.print_prime();
    return 0;
};