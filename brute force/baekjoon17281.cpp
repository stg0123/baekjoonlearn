#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class baseball{
private:
    vector<vector<int>> ining;
    int N;
public:
    baseball(){
        std::cin >> N;
        ining.resize(N,vector<int>(9));
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            for(int j=0;j<9;j++)
                std::cin >> ining[i][j];
        
    };
    int run(vector<bool>& bb,int r){
        int point=0;
        for(int i=3;i>=1;i--){
            if(i+r<4)
                bb[i+r]=bb[i];
            else if(bb[i])
                point++;
            bb[i]=0;
        }
        if(r==4)
            point++;
        else
            bb[r]=true;
        return point;
    }
    int check(vector<int>& procedure){
        int out =0,i=0,cur;
        int sol=0;
        vector<bool> bb(4,false);
        while(out/3<N){
            if(i<3)
                cur = procedure[i];
            else if (i==3)
                cur = 0;
            else
                cur = procedure[i-1];
            if(ining[out/3][cur]==0){
                if((++out)%3==0)
                    bb[1]=bb[2]=bb[3]=false;
            }
            else
                sol+=run(bb,ining[out/3][cur]);
            i=(i+1)%9;
        }
        return sol;
    };

    void find_sol(){
        vector<int> procedure(8);
        int sol=0;
        for(int i=0;i<8;i++)
            procedure[i]=i+1;
        do{
            sol=max(sol,check(procedure));
            
        }while(next_permutation(procedure.begin(),procedure.end()));
        std::cout << sol << '\n';
    }

 
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    baseball bb;
    bb.find_sol();

    return 0;
}