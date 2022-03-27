#include <iostream>
#include <vector>
#include <string>
using namespace std;
class inequality{
private:
    vector<bool> map;
    string str;
    string minimum="99999999999",maximum="0";
    int N;
public:
    inequality(){
        std::cin >> N;
        map.resize(N,0);
        set_val();
    }
    void set_val(){
        char ch;
        for(int i=0;i<N;i++){
            std::cin >>ch;
            if(ch=='<')
                map[i]=1;
        }
    }
    void dfs(int bitmask){
        if(str.size()==N+1){
            if(str>maximum)
                maximum=str;
            if(str<minimum)
                minimum=str;
            return ;
        }
        for(int i=0;i<=9;i++){
            if(!str.empty()){
                if((str.back()-48<i)!=map[str.size()-1])
                    continue ;
            }
            if(!(bitmask&(1<<i))){
                str.push_back(i+48);
                dfs(bitmask|(1<<i));
                str.pop_back();
            }
        }
    }
    void find_sol(){
        dfs(0);
        std::cout << maximum << '\n';
        std::cout << minimum << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    inequality in;
    in.find_sol();
    return 0;
}