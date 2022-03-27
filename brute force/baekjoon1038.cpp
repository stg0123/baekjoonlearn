#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class decreasing{
private:
    int N;
    int sol=0;
    string number;
public:
    decreasing(){
        std::cin >> N;
    }
    bool dfs(int cur,int depth){
        if(cur ==depth){
            if(sol++==N){
                std::cout << number<<'\n';
                return true;
            }
            return false;
        }
        int k;
        if(number.empty())
            k=10;
        else
            k=number.back()-48;
        for(int i=0;i<k;i++){
            number.push_back(i+48);
            if(dfs(cur+1,depth))
                return true;
            number.pop_back();
        }
        return false;
    }
    void find_sol(){
        for(int i=1;i<=10;i++){
            if(dfs(0,i))
                return ;
        }
        std::cout << -1 << '\n';
    }



    
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    decreasing dc;
    dc.find_sol();
    return 0;
}