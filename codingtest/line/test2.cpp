#include <iostream>
#include <string>
#include <vector>

using namespace std;
struct node{
    int check=0;
    int cnt=0;
};
class test2{
private:
    vector<vector<node>> day;
    int N,K;
public:
    test2(int n,int k):N(n),K(k){
        
    }
    string find_sol(vector<string>& rs){
        vector<int> ch(26,0);
        pair<char,int> sol={'N',0};
        day.resize(rs.size(),vector<node>(26));
        for(int i=0;i<rs.size();i++){
            for(char c : rs[i]){
                day[i][c-97].cnt++;
                if(day[i][c-97].cnt==K){
                    if(i==0)
                        day[i][c-97].check++;
                    else
                        day[i][c-97].check=day[i-1][c-97].check+1;
                }
            }
        }
        int ck = 2*N*K;
        int cnt=0;
        for(int i=0;i<day.size();i++){
            for(int j=0;j<26;j++){
                if(day[i][j].check>=N){
                    cnt=0;
                    for(int l=0;l<N;l++)
                        cnt+=day[i-l][j].cnt;
                    if(cnt>=ck){
                        ch[j]++;
                        if(sol.second<ch[j] || (sol.second==ch[j] && sol.first>'a'+j)){
                            sol.first='a'+j;
                            sol.second=ch[j];
                        }
                    }
                }
            }
        }
        if(sol.first=='N')
            return "None";
        string str;
        str.push_back(sol.first);
        return str;

    }
};
string solution(vector<string> research, int n, int k) {
    test2 t2(n,k);
    return t2.find_sol(research);
};

int main(){
    std::cout << solution({"xy", "xy"}, 1, 1)<<'\n';
    return 0;
}