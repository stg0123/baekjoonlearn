#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class knight{
private:
    vector<vector<bool>> visit;
public:
    knight(){
        visit.resize(7,vector<bool>(7,false));
    }
    pair<int,int> loc(string str){
        return {str[0]-64,str[1]-48};
    }
    bool check(pair<int,int>& last,pair<int,int>& cur){
        if(cur.first<=0||cur.first>6||cur.second<=0||cur.second>6)
            return false;        
        else if(abs(last.first-cur.first)==1&&abs(last.second-cur.second)==2&&!visit[cur.first][cur.second])
            return true;
        else if(abs(last.first-cur.first)==2&&abs(last.second-cur.second)==1&&!visit[cur.first][cur.second])
            return true;
        else 
            return false;
    }

    void dfs(){
        string str;
        std::cin >> str;
        pair<int,int> last = loc(str);
        pair<int,int> first=last;
        pair<int,int> tmp;
        bool flag=false;
        visit[last.first][last.second]=true;
        for(int i=0;i<35;i++){
            std::cin >> str;
            tmp=loc(str);
            if(check(last,tmp)){
                if(i==34){
                    if(!check(first,tmp))
                        flag=true;
                }
                visit[tmp.first][tmp.second]=true;
                last=tmp;
            }
            else{
                flag=true;
            }
        }    
        if(flag)
            std::cout <<"Invalid";
        else
            std::cout << "Valid";
    }
};
int main(){
    knight k;
    k.dfs();

    return 0;
}