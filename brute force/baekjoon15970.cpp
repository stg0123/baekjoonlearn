#include <iostream>
#include <vector>
#include <map>
using namespace std;
class ArrowDraw{
private:
    map<int,int> m;
    int N;
public:
    ArrowDraw(){
        std::cin >>N;
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a >> b;
            m[a+1]=b;
        }

    }
    void find_sol(){
        map<int,int> color,sol;
        int length;
        for(pair<int,int> i : m){
            if(color[i.second]){
                length = i.first-color[i.second];
                sol[i.first]=length;
                if(sol[color[i.second]])
                    sol[color[i.second]] = min(sol[color[i.second]],length);
                else
                    sol[color[i.second]] = length;
                color[i.second]=i.first;
            }
            else{
                color[i.second]=i.first;
            }
        }
        int solution =0;
        for(pair<int,int> i : sol){
            solution+=i.second;
        }
        std::cout << solution<<'\n';
        
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ArrowDraw AD;
    AD.find_sol();

    return 0;
}