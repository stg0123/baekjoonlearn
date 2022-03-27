#include <iostream>
#include <vector>
using namespace std;
struct node{
    int value;
    int next;
};

class dice{
private:
    vector<int> val,loc;
    vector<node> map;
public:
    dice(){
        loc.resize(4,0);
        val.resize(10);
        set_val();

    }
    void set_val(){
        for(int i=0;i<10;i++)
            std::cin >> val[i];
        map.resize(35);
        for(int i=0;i<=20;i++){
            map[i].value=i*2;
            map[i].next=i+1;
        }
        // if 5 10 15 일경우 21 24 26으로 감
        map[20].next=32;
        map[21]={13,22};
        map[22]={16,23};
        map[23]={19,29};
        map[24]={22,25};
        map[25]={24,29};
        map[26]={28,27};
        map[27]={27,28};
        map[28]={26,29};
        map[29]={25,30};
        map[30]={30,31};
        map[31]={35,20};
        map[32]={0,32};
    }
    int dfs(int depth){
        if(depth==10)
            return 0;
        int sol=0;
        for(int i=0;i<4;i++){
            int cur = loc[i];
            if(cur ==32)
                continue;
            bool flag =true;
            for(int j=0;j<val[depth];j++){
                if(j==0){
                    if(loc[i]==5)
                        loc[i]=21;
                    else if (loc[i]==10)
                        loc[i]=24;
                    else if(loc[i]==15)
                        loc[i]=26;
                    else
                        loc[i]=map[loc[i]].next;
                }
                else 
                    loc[i] = map[loc[i]].next;
            }
            for(int j=0;j<4;j++)
                if(i!=j &&loc[i] ==loc[j])
                    flag= false;
            if(loc[i]==32 || flag)
                sol=max(sol,dfs(depth+1)+map[loc[i]].value);
            loc[i]=cur;
        }
        return sol;
    }
    void find_sol(){
        std::cout << dfs(0)<<'\n';

    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    dice dc;
    dc.find_sol();


    return 0;
}