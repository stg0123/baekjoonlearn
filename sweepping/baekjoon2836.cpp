#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
class texi{
private:
    vector<pair<int,int>> val;
    int N,M;
public:
    texi(){
        std::cin >> N >> M;    
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a >> b;
            if(a>b)
                val.push_back({b,a});
        }
        sort(val.begin(),val.end());
    }
    void cal_line(){
        ll sol=M;
        int left=0,right=0;
        for(int i=0;i<val.size();i++){
            if(right<val[i].first){
                sol+=(right-left)*2;

                left=val[i].first;
                right=val[i].second;
            }
            else
                right=max(right,val[i].second);
        }
        sol+=(right-left)*2;

        std::cout << sol;
    }

};
int main(){
    texi t;
    t.cal_line();
    return 0;
}