#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
class doubles{
private:
    vector<int> val;
    unordered_set<int> S;
public:
    doubles(int n){
        int a;
        val.push_back(n);
        S.insert(n);
        while(1){
            std::cin >> a;
            if(!a)
                break;
            val.push_back(a);
            S.insert(a);
        }
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<val.size();i++){
            if(S.find(val[i]*2)!=S.end())
                sol++;
        }
        std::cout << sol << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    while(1){
        std::cin >> t;
        if(t==-1)
            break;
        doubles db(t);
        db.find_sol();
    }
    return 0;
}