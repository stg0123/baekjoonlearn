#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INF=1000000000;
struct node{
    int r,c,s;  
};
class round_arr{
private:
    vector<vector<int>> map;
    vector<node> round;
    int N,M,K;
public:
    round_arr(){
        std::cin >> N >>M >>K;
        map.resize(N,vector<int>(M));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<M;j++)
                std::cin >> map[i][j];
        int r,c,s;
        for(int i=0;i<K;i++){
            std::cin >> r >> c >> s;
            round.push_back({r,c,s});
        }    
    }
    void rounding(vector<vector<int>>& tmp_map,node& set){
        int x=set.r-1,y=set.c-1;

        for(int d=1;d<=set.s;d++){
            int save1=tmp_map[x+d][y-d];
            int save2=tmp_map[x-d][y-d];
            int save3=tmp_map[x-d][y+d];
            int save4=tmp_map[x+d][y+d];
            for(int j=y-d+1;j<=y+d;j++)
                tmp_map[x+d][j-1]=tmp_map[x+d][j];
            for(int i=x-d+1;i<=x+d;i++)
                tmp_map[i-1][y-d]=tmp_map[i][y-d];
            for(int j=y+d-1;j>=y-d;j--)
                tmp_map[x-d][j+1]=tmp_map[x-d][j];
            for(int i=x+d-1;i>=x-d;i--)
                tmp_map[i+1][y+d]=tmp_map[i][y+d];
            tmp_map[x+d-1][y-d]=save1;
            tmp_map[x-d][y-d+1]=save2;
            tmp_map[x-d+1][y+d]=save3;
            tmp_map[x+d][y+d-1]=save4;
        }


    };
    int check(vector<int>& order){
        int sol=INF;
        vector<vector<int>> tmp_map=map;
        for(int i=0;i<K;i++){
            rounding(tmp_map,round[order[i]]);
        }
        for(int i=0;i<N;i++){
            int sum=0;
            for(int j=0;j<M;j++)
                sum+=tmp_map[i][j];
            sol=min(sol,sum);
        }
        return sol;
    }

    void find_sol(){
        int sol=INF;
        vector<int> order(K);
        for(int i=0;i<K;i++)
            order[i]=i;
        do{
            sol=min(sol,check(order));
        }while(next_permutation(order.begin(),order.end()));
        std::cout << sol << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    round_arr ra;
    ra.find_sol();
    return 0;
}
