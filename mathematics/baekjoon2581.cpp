#include <iostream>
#include <vector>

using namespace std;
class sosu{
private :
    int M,N;
public :
    sosu(int m,int n):M(m),N(n){
    };

    void find(){
        vector<int> n;
        n.resize(N+1,1);
        n[0]=0;
        n[1]=0;
        for(int i=2;i<=N;i++)
            if(n[i]==1)
                for(int j=2;j<=N/i;j++){
                    n[i*j]=0;           
                }
        int sum=0,min=0;
        bool flag=false;
        for(int i=M;i<=N;i++){
            if(n[i]==1){
                sum+=i;
                if(flag==false){
                    min=i;
                    flag=true;
                }
            }
        }
        if(flag ==false)
            std::cout << -1;
        else
            std::cout << sum<<'\n'<<min << '\n';
    };

};

int main(){
    int M,N;
    std::cin >>M >> N;
    sosu so(M,N);
    so.find();
    return 0;
}