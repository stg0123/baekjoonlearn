#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class loc{
private:
    vector<int> val,s_val;
    unordered_map<int,int> m;
    int N;
public:
    loc(){
        std::cin >> N;
        set_val();

    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            val.push_back(tmp);
        }
        s_val=val;
        sort(s_val.begin(),s_val.end()); 
    }
    void find_sol(){
        int idx=0;
        for(int i=0;i<s_val.size();i++){
            m[s_val[i]]=idx;
            while(s_val[i]==s_val[i+1]){
                i++;
                m[s_val[i]]=idx;
            }
            idx++;
        }
        for(int i=0;i<val.size();i++){
            std::cout << m[val[i]] << ' ';
        }
    }

};
int main(){
    loc l;
    l.find_sol();
    return 0;
}