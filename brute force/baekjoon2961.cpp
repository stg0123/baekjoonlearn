#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INF =1000000000;
class chief{
private:
    vector<pair<int,int>> material;
    int N;
public:
    chief(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a >> b;
            material.push_back({a,b});
        }
    }

    void find_sol(){
        int sol=INF;
        for(int i=1;i<=N;i++){
            vector<bool> select(N,false);
            for(int j=0;j<i;j++)
                select[j]=true;
            do{
                int sour=1,bitter=0;
                for(int j=0;j<N;j++){
                    if(select[j]){
                        sour *=material[j].first;
                        bitter +=material[j].second;
                    }
                }
                sol=min(sol,abs(sour-bitter));
            }while(prev_permutation(select.begin(),select.end()));
        }
        std::cout << sol << '\n';
        
    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    chief ch;
    ch.find_sol();

    return 0;
}