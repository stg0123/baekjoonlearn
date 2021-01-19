#include <iostream>
#include <vector>
using namespace std;
#define INF 1000000007
typedef long long l;
typedef vector<vector<l>> metrix;
class path_num{
private:
    metrix node;
    long long COST;
public:
    path_num(){
        std::cin >> COST;
        node.resize(8,vector<l>(8,0));
        set_connect();
        
    }
    void set_connect(){
        node[0][1]=1;
        node[0][2]=1;
        
        node[1][0]=1;
        node[1][2]=1;
        node[1][3]=1;

        node[2][0]=1;
        node[2][1]=1;
        node[2][3]=1;
        node[2][4]=1;

        node[3][1]=1;
        node[3][2]=1;
        node[3][4]=1;
        node[3][5]=1;

        node[4][2]=1;
        node[4][3]=1;
        node[4][5]=1;
        node[4][6]=1;

        node[5][3]=1;
        node[5][4]=1;
        node[5][7]=1;

        node[6][4]=1;
        node[6][7]=1;

        node[7][5]=1;
        node[7][6]=1;
    }
    
    metrix m_mul(metrix A,metrix B){
        long long sum;
        metrix sol(A.size(),vector<l>(B[0].size()));
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

    metrix pow(metrix A,l idx){
        if(idx==1)
            return A;
        
        if(idx%2==0){
            metrix tmp=pow(A,idx/2);
            return m_mul(tmp,tmp);
        }
        return m_mul(pow(A,idx-1),A);   
    }
    void find_num(){
        if(COST==0){
            std::cout << 1<<'\n';
            return ;   
        }
        std::cout << pow(node,COST)[0][0] << '\n';

    }


};
int main(){
    path_num pa;
    pa.find_num();

    return 0;
}