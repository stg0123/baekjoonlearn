#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
class carddrop{
private:
    vector<string> val;
    int N,K;
public:
    carddrop(){
        std::cin >> N >> K;
        val.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> val[i];

    }
    void find_sol(){
        sort(val.begin(),val.end());
        unordered_set<string> sol;
        do{
            string str;
            for(int i=0;i<K;i++)
                str+=val[i];
            sol.insert(str);
            reverse(val.begin()+K,val.end());
        }while(next_permutation(val.begin(),val.end()));
        std::cout << sol.size() << '\n';
    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    carddrop cd;
    cd.find_sol();

    return 0;
}