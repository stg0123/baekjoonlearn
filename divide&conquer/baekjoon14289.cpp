#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000007
typedef long long l;
typedef vector<vector<l>> metrix;
class path_num{
private:
    metrix node;
    int SIZE;
public:
    path_num(){
        std::cin >> SIZE;
        node.resize(SIZE,vector<l>(SIZE,0));
        set_connect();
    }
    void set_connect(){
        int n;
        std::cin >> n;
        int a,b;
        for(int i=0;i<n;i++){
            std::cin >> a>> b;
            node[a-1][b-1]=1;
            node[b-1][a-1]=1;
        }
    }

    metrix m_mul(metrix A,metrix B){
        metrix sol(A.size(),vector<l>(B[0].size()));
        l sum;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B[0].size();j++){
                sum=0;
                for(int l=0;l<B.size();l++){
                    sum=(sum+A[i][l]*B[l][j])%INF;
                }
                sol[i][j]=sum%INF;
            }
        }
        return sol;
    }
    metrix pow(metrix A,long long idx){
        if(idx ==1)
            return A;
        if(idx%2==0){
            metrix tmp=pow(A,idx/2);
            return m_mul(tmp,tmp);
        }
        return m_mul(pow(A,idx-1),A);
    }

    void find_num(){
        long long COST;
        std::cin >>COST;
        if(COST==0){
            std::cout << 1<<'\n';
            return ;
        }
        std::cout << pow(node,COST)[0][0]%INF<<'\n';

    }

};
int main(){
    path_num pa;
    pa.find_num();

    return 0;
}