#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node{
    string nick;
    string email;
    int parent;
};
class test5{
private:
    vector<node> User;
    int sol;
public:
    test5(vector<string>& nick,vector<string>& emails){
        User.resize(nick.size());
        for(int i=0;i<nick.size();i++){
            User[i].nick=nick[i];
            User[i].email=emails[i];
            User[i].parent=i;
        }
    }
    void find_sol(){
        vector<vector<bool>> simiar_nick;
    }

    int find(int n){
        if(User[n].parent==n)
            return n;
        return User[n].parent=find(n);
    }
    void merge(int a,int b){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return ;
        User[p_b].parent=p_a;
        sol++;
    }
};

int solution(vector<string> nicks, vector<string> emails) {
    int answer = -1;
    return 3;
}