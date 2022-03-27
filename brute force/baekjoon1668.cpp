#include <iostream>
#include <vector>
using namespace std;
class tropi{
private:
    vector<int> val;
    int N;
public:
    tropi(){
        std::cin >> N;
        val.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> val[i];
    }
    void find_sol(){
        int left=0,right=0;
        int maxleft=0,maxright=0;
        for(int i=0;i<N;i++){
            if(maxleft<val[i]){
                maxleft=val[i];
                left++;
            }
            if(maxright<val[N-1-i]){
                maxright=val[N-1-i];
                right++;
            }
        }
        
        
        std::cout << left << '\n';
        std::cout << right << '\n';
    }



};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    tropi tp;
    tp.find_sol();
    return 0;
}