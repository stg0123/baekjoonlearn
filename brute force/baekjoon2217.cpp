#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class max_val{
private:
    vector<int> loop;
    int N;
public:
    max_val(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            loop.push_back(tmp);
        }
        sort(loop.begin(),loop.end());
            
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<N;i++){
            sol = max(loop[i]*(N-i),sol);
        }
        std::cout << sol;
    }

};
int main(){
    max_val mv;
    mv.find_sol();
    return 0;
}