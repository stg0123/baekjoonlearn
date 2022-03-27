#include <iostream>
#include <vector>
using namespace std;
int INF=1000000000;
class str{
private:
    string A,B;
public:
    str(){
        std::cin >> A >> B;
    }
    void find_sol(){
        int m=INF,tmp;
        for(int i=0;i<=B.size()-A.size();i++){
            tmp=0;
            for(int j=0;j<A.size();j++){
                if(B[i+j]!=A[j])
                    tmp++;
            }
            m=min(tmp,m);
        }
        std::cout << m  << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    str s;
    s.find_sol();

    return 0;
}