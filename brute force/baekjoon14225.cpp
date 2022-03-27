#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int& a,int& b){
    return a<b;

};
class subsquence{
private:
    vector<int> val;
    int N;
public:
    subsquence(){
        std::cin >> N;
        val.resize(N);
        set_val();
        
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> val[i];
        sort(val.begin(),val.end(),compare);

    }
    void find_sol(){
        int sol=1;
        for(int i=0;i<N;i++){
            if(val[i]>sol)
                break;
            sol+=val[i];
        }
        std::cout << sol << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    subsquence ss;
    ss.find_sol();

    return 0;
}