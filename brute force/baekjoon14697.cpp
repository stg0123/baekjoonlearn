#include <iostream>
#include <vector>
using namespace std;
class room{
private:
    vector<int> val;
    int N;
public:
    room(){
        val.resize(3);
        for(int i=0;i<3;i++)
            std::cin >> val[i];
        std::cin >> N;
    }
    bool dfs(int cur,int remain){
        if(cur>2)
            return false;
        int tmp=0;
        bool flag=false;
        while(1){
            if(tmp==remain)
                return true;
            else if(tmp<remain)
                flag|=dfs(cur+1,remain-tmp);
            else
                break;
            tmp+=val[cur];
        }
        return flag;
    }
    void find_sol(){
        std::cout << dfs(0,N)<<'\n';
    }


};
int main(){
    room rm;
    rm.find_sol();
    return 0;
}