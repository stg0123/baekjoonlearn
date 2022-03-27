#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class queen{
    private: 
        int x,y;
    public:
        queen(int X,int Y):x(X),y(Y){
            return ;
        };
        int getx(){
            return x;
        };
        int gety(){
            return y;
        };
};

bool check(int x,int y,vector<queen>& visit);

void dfs(int& count,int n,int x,int y,vector<queen>& visit){
    if(check(x,y,visit)==true)
        return ;
    //std::cout<<"x= "<< x<< " y= "<< y<<'\n';    
    if(x==n-1){
        //std::cout <<"\n**\n";
        count++;
        return ;
    }
    queen tmp(x,y);
    visit.push_back(tmp);
    for(int i=0;i<n;i++)
        dfs(count,n,x+1,i,visit);
    visit.pop_back();
};

bool check(int x,int y ,vector<queen>& visit){
    for(int i=0;i<visit.size();i++){
        if(visit[i].getx()==x||visit[i].gety()==y)
            return true;
        if(visit[i].getx()+visit[i].gety()==x+y)
            return true;
        if(visit[i].getx()-visit[i].gety()==x-y)
            return true;
    }
    return false;
};

int main(){
    int n;
    std::cin >> n;
    vector<queen> visit;
    int count=0;
    for(int i=0;i<n;i++)
        dfs(count,n,0,i,visit);
    std::cout << count;

    return 0;
}