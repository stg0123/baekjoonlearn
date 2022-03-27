#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define INF 10000
struct node{
    int prenum;
    char sol;
};
class regi_cal{
private:
    int START,END;
public:
    regi_cal(){
        std::cin >> START >> END;
    }
    void BFS(){
        vector<node> visit(INF+1,{-1,});
        queue<int> q;
        q.push(START);
        visit[START].prenum=0;
        int cur,tmp;
        while(!q.empty()){
            cur=q.front();
            q.pop();
            tmp=(cur*2)%INF;
            if(visit[tmp].prenum==-1){
                visit[tmp].prenum=cur;
                visit[tmp].sol='D';
                if(tmp==END)
                    break;
                q.push(tmp);
            }
            tmp=cur>0?cur-1:9999;
            if(visit[tmp].prenum==-1){
                visit[tmp].prenum=cur;
                visit[tmp].sol='S';
                if(tmp==END)
                    break;
                q.push(tmp);
            }
            tmp=(cur*10)%INF+(cur/1000);
            if(visit[tmp].prenum==-1){
                visit[tmp].prenum=cur;
                visit[tmp].sol='L';
                if(tmp==END)
                    break;
                q.push(tmp);
            }
            tmp=(cur%10)*1000+(cur/10);
            if(visit[tmp].prenum==-1){
                visit[tmp].prenum=cur;
                visit[tmp].sol='R';
                if(tmp==END)
                    break;
                q.push(tmp);
            }
        }
        stack<int> st;
        int i=END;
        while(1){
            st.push(i);
            i=visit[i].prenum;
            if(i==START){
                while(!st.empty()){
                    std::cout << visit[st.top()].sol;
                    st.pop();
                }
                std::cout << '\n';
                return ;
            }
        }

    }
  
};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        regi_cal r;
        r.BFS();
    }

    return 0;
}