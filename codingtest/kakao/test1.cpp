#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
struct node{
    int num;
    int cnt;
    unordered_set<string> user; //신고한사람
};
class test1{
private:
    unordered_map<string,node> um;
    vector<int> sol;
    int K;
public:
    test1(vector<string>& id_list,int k):K(k){
        for(int i=0;i<id_list.size();i++){
            um[id_list[i]].num=i;
        }
        sol.resize(id_list.size());
    };
    vector<int> find_sol(vector<string>& report){
        string from,to;
        for(string str : report){
            for(int i=0;i<str.size();i++){
                if(str[i]==' '){
                    from = str.substr(0,i);
                    to =str.substr(i+1);   
                    break;
                }
            }
            if(um[to].user.insert(from).second){
                um[to].cnt++;
            }
        }
        for(auto n : um){
            if(n.second.cnt>=K){
                for(string str : n.second.user){
                    sol[um[str].num]++;
                }
            }
        }
        return sol;
    }

};
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    test1 t1(id_list,k);
    return t1.find_sol(report);
}
int main(){
    solution({"muzi", "frodo", "apeach", "neo"},{"muzi frodo","apeach frodo","frodo neo","muzi neo","apeach muzi"},2);

    return 0;
}