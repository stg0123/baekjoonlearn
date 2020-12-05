#include <iostream>
#include <vector>

using namespace std;
class prime{
private :
    vector<int> map;
    int N;
public :
    prime(int n):N(n){
        map.resize(2*n+1,1);
        map[0]=0;
        map[1]=0;

    };

    void find_prime(){
        for(int i=2;i<=2*N;i++)
            if(map[i]==1)
                for(int j=2;j<=(2*N)/i;j++)
                    map[j*i]=0;
    };
    
    void print_cnt(){
        int count=0;
        for(int i=N+1;i<=2*N;i++)
            if(map[i]==1)
                count++;
        std::cout << count << '\n';
    };
    

};

int main(){
    int a;
    while(1){
        std::cin >> a;
        if(a==0)
            break;
        prime p(a);
        p.find_prime();
        p.print_cnt();

    }

    return 0;
}