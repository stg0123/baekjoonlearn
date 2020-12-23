#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class sub_sqeuence{
private:
    vector<int> chache;
    vector<int> map;
    int N;
public :
    sub_sqeuence(int n):N(n){
        map.resize(n+1,0);
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> map[i];
        chache.push_back(map[1]);
    }   
    void DP(){
        if(N==1){
            std::cout << 1<<'\n';
            return ;
        }
        int j;
        for(int i=2;i<=N;i++){
            if(map[i]>chache[chache.size()-1])
                chache.push_back(map[i]);
            else if(map[i]<chache[chache.size()-1]){
                for(j=0;j<chache.size();j++){
                    if(chache[j]>=map[i]){
                        chache[j]=map[i];
                        break;
                    }
                }
            }
        }
        std::cout << chache.size()<<'\n';
            
        return ;
    };
};
int main(){
    int n;
    std::cin >> n;
    sub_sqeuence sq(n);
    sq.set_val();
    sq.DP();
    return 0;
}