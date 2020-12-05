#include <iostream>
#include <vector>

using namespace std;
class golden{
private :
    vector<int> map;
    int N;
public :
    golden(int n):N(n){
        map.resize(n+1,1);
        map[0]=0;
        map[1]=0;
    };

    void find_prime(){
        for(int i=2;i<=N;i++)
            if(map[i]==1)
                for(int j=2;j<=N/i;j++)
                    map[i*j]=0;
    };

    void find(){
        int a=N/2;
        for(int i=a;i>1;i--)
            if(map[i]==1&&map[N-i]==1){
                std::cout << i << ' '<<N-i << '\n';
                break;
            }
    };


};

int main(){
    int n,a;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> a;
        golden go(a);
        go.find_prime();
        go.find();
        
    }
    
    return 0;
}