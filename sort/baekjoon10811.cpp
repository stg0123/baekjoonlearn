#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class reversed{
private:
    vector<int> val;
    int N,M;
public:
    reversed(){
        std::cin >> N >> M;
        val.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            val[i]=i+1;
    }
    void find_sol(){
        int start,end;
        for(int i=0;i<M;i++){
            std::cin >> start >> end;
            reverse(val.begin()+start-1,val.begin()+end);
        }
        for(int i : val)
            std::cout << i << ' ';
        std::cout << '\n';
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    reversed rsd;
    rsd.find_sol();
    return 0;
}