#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int loc;
    int degree;

};
class hide_seek{
private:
    int START,END;

public:
    hide_seek(){
        std::cin >> START >> END;
    }
    void BFS(){
        if(START==END){
            std::cout << 0 << '\n' << 1<< '\n';
            return ;
        }
        vector<int> visit(200001,100000);
        queue<node> q;
        q.push({START,0});
        visit[START]=0;
        int cur,deg,sol_deg,sol=0;
        node tmp;
        bool flag=false;
        while(!q.empty()){
            cur = q.front().loc;
            deg = q.front().degree;
            q.pop();
            if(flag){
                if(deg>sol_deg)
                    break;
                else if(cur==END)
                    sol++;
            }
            else if(cur==END&&!flag){
                flag=true;
                sol++;
                sol_deg=deg;
            }

            if(cur+1<=END&&visit[cur+1]>=deg+1){
                visit[cur+1]=deg+1;
                tmp.loc=cur+1;
                tmp.degree=deg+1;
                q.push(tmp);
            }
            if(cur-1>=0&&visit[cur-1]>=deg+1){
                visit[cur-1]=deg+1;
                tmp.loc=cur-1;
                tmp.degree=deg+1;
                q.push(tmp);
            }
            if(cur*2<=END*2&&visit[cur*2]>=deg+1){
                visit[cur*2]=deg+1;
                tmp.loc=cur*2;
                tmp.degree=deg+1;
                q.push(tmp);
            }
        }
        std::cout << sol_deg << '\n';
        std::cout << sol << '\n';


    }

};

int main(){
    hide_seek hi;
    hi.BFS();

    return 0;
}