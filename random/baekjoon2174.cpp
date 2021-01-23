#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct robot{
    char state;
    int x,y;
};
class robot_simul{
private:
    vector<robot> bot;
    vector<vector<int>> map;
    int A,B;
    int N,M;
    string sol;
public:
    robot_simul(){
        std::cin >>A>>B;
        map.resize(A+1);
        for(int i=1;i<=A;i++)
            map[i].resize(B+1,0);
        std::cin >> N >> M;
        bot.resize(N+1);
        sol="OK";
        set_val();
    }
    void set_val(){
        for(int i=1;i<=N;i++){
            std::cin >> bot[i].x >> bot[i].y >> bot[i].state;
            map[bot[i].x][bot[i].y]=i;
        }
    }
    void print_map(){
        std::cout << '\n';
        for(int i=1;i<=A;i++){
            for(int j=1;j<=B;j++)
                std::cout<<map[i][j]<<' ';
            std::cout <<'\n';
        }
    }
    void simulation(){
        int bot_num,repeat;
        char oper;
        for(int i=0;i<M;i++){
            std::cin >> bot_num >> oper >> repeat;
            if(sol!="OK")
                continue;         
            if(oper=='L')
                for(int j=0;j<repeat;j++)
                    Left(bot_num);
            else if(oper=='R')
                for(int j=0;j<repeat;j++)
                    Right(bot_num);
            else if(oper=='F')
                for(int j=0;j<repeat;j++){
                    if(!Fist(bot_num))
                        break;
                }
        }
        std::cout << sol;

    }
    void Left(int n){
        if(bot[n].state=='E')
            bot[n].state='N';
        else if(bot[n].state=='N')
            bot[n].state='W';
        else if(bot[n].state=='W')
            bot[n].state='S';
        else if(bot[n].state=='S')
            bot[n].state='E';
    }
    void Right(int n){
        if(bot[n].state=='E')
            bot[n].state='S';
        else if(bot[n].state=='S')
            bot[n].state='W';
        else if(bot[n].state=='W')
            bot[n].state='N';
        else if(bot[n].state=='N')
            bot[n].state='E';
    }
    bool Fist(int n){
        map[bot[n].x][bot[n].y]=0;
        if(bot[n].state=='E')
            bot[n].x++;
        else if(bot[n].state=='N')
            bot[n].y++;
        else if(bot[n].state=='W')
            bot[n].x--;
        else if(bot[n].state=='S')
            bot[n].y--;
        
        if(bot[n].x<=0||bot[n].x>A||bot[n].y<=0||bot[n].y>B){
            sol="Robot ";
            sol.append(to_string(n));
            sol.append(" crashes into the wall");
            return false;
        }
        else if(map[bot[n].x][bot[n].y]!=0){
            sol="Robot ";
            sol.append(to_string(n));
            sol.append(" crashes into robot ");
            sol.append(to_string(map[bot[n].x][bot[n].y]));
            return false;
        }
        else
            map[bot[n].x][bot[n].y]=n;
        
        return true;
    }

};
int main(){
    robot_simul rsimul;
    rsimul.simulation();
    
    return 0;
}