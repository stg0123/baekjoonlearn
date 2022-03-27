#include <iostream>
#include <string>
#include <vector>
using namespace std;
class test4{
private:
    int N;
    vector<int> sol;
public:
    test4(int n):N(n){
        for(int i=1;i<=N;i++)
            sol.push_back(i);
        suffle(0,N);
    }
    void suffle(int start,int end){
        if(end-start<=1)
            return ;
        int size=end-start;
        int p,len;
        for(int i=2;i<=size;i++){
            if(size%i==0){
                p=i; //2
                len=size/i; //6
                break;  
            }
        }
        vector<int> tmp = sol;
        int cur=start;
        for(int j=0;j<len;j++)
            for(int l=0;l<p;l++)
                sol[start+len*l+j]=tmp[cur++];

        for(int i=0;i<p;i++){
            suffle(i*len,(i+1)*len);
        }
    }
    vector<int> find_sol(){
        return sol;
    }


};

vector<int> solution(int n) {
    test4 t4(n);
    return t4.find_sol();
}
int main(){
    solution(18);

    return 0;
}