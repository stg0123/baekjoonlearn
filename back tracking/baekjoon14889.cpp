#include <iostream>
#include <vector>

using namespace std;
class maps{
    private:
        vector<vector<int>> map;
        vector<bool> team;
        int N,min;
    public:
        maps(int n):N(n){
            map.resize(n+1);
            for(int i=0;i<=n;i++)
                map[i].resize(n+1,0);
            team.resize(n+1,false);
        };
        void set_map(){
            for(int i=1;i<=N;i++)
                for(int j=1;j<=N;j++)
                    std::cin >> map[i][j];
        };
        
        void print_map(){
            std::cout<<'\n';
            for(int i=1;i<=N;i++){
                for(int j=1;j<=N;j++)
                    std::cout << map[i][j] << ' ';
                std::cout <<'\n';

            }
        };
        void operation(){
            int team1=0,team2=0;
            for(int i=1;i<=N;i++){
                if(team[i]==true){
                    for(int j=i;j<=N;j++)
                        if(team[j]==true)
                            team1+=map[i][j]+map[j][i];
                }
                else{
                    for(int j=i;j<=N;j++)
                        if(team[j]==false)
                            team2+=map[i][j]+map[j][i];
                }
            }
            if(team1>team2){
                if(team1-team2<min)
                    min=team1-team2;
            }
            else
                if(team2-team1<min)
                    min=team2-team1;
        };

        void print_min(){
            std::cout << min;
        };

        void dfs(int person,int degree){
            if(team[person]==true)
                return ;
            team[person]=true;
            if(degree==N/2){
                operation();
                team[person]=false;
                return ;
            }

            for(int i=person;i<=N;i++)
                dfs(i,degree+1);
            
            team[person]=false;

            
        };
};

int main(){
    int n;
    std::cin >>n;
    maps soccer(n);
    soccer.set_map();
    for(int i=1;i<=n/2+1;i++)
        soccer.dfs(i,1);
    soccer.print_min();   
    

    return 0;
}