#include <iostream>
#include <vector>

using namespace std;
class stoku
{
private:
    vector<vector<int>> map;
    vector<pair<int, int>> problem;
    bool flag;

public:
    stoku(){
        map.resize(9);
        for (int i = 0; i < 9; i++)
            map[i].resize(9);
        flag=false;
    };

    void set_map(){
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++){
                std::cin >> map[i][j];
                if(map[i][j]==0){
                    pushpair(i,j);
                }
            }
    };
    void pushpair(int x,int y){
        pair<int,int> tmp;
        tmp.first=x;
        tmp.second=y;
        problem.push_back(tmp);
    };
    
    void print_map(){
        //std::cout <<'\n';
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++)
                std::cout << map[i][j] << ' ';
        std::cout <<'\n';
        }
    };

    void problem_print(){
        std::cout << " pairsize ="<<problem.size() << '\n';
        for(int i=0;i<problem.size();i++)
            std::cout << " x=" << problem[i].first << " y=" <<problem[i].second <<' ';    
    };

    bool check(int x,int y){
        int count_x=0,count_y=0;
        for(int i=0;i<9;i++){
            if(map[x][i]==map[x][y]){
                count_x++;
                if(count_x==2)
                    return false;
            }
            if(map[i][y]==map[x][y]){
                count_y++;
                if(count_y==2)
                    return false;
            }
        }
        int count =0;
        int dx=(x/3)*3,dy=(y/3)*3;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                if(map[dx+i][dy+j]==map[x][y]){
                    count++; 
                    if(count==2)
                        return false;
                }
        return true;
    };

    void dfs(int n,int val){
        if(flag)
            return;
        int x,y;
        x=problem[n].first;
        y=problem[n].second;
        map[x][y]=val;
        if(check(x,y)==false){
            map[x][y]=0;
            return ;
        }
        if(n==problem.size()-1){
            print_map();
            flag=true;
            map[x][y]=0;
            return ;
        }
        
        for(int i=1;i<=9;i++)
            dfs(n+1,i);

        map[x][y]=0;
    }

};

int main()
{ 
    stoku stk;
    stk.set_map();
    //stk.print_map();   
    //stk.problem_print();
    for(int i=1;i<=9;i++)
        stk.dfs(0,i);
    return 0;
}