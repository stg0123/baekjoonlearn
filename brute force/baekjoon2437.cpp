#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Weight{
private:
    vector<int> val;
    int N;
public:
    Weight(){
        std::cin >> N;
        set_val();      
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            val.push_back(tmp);
        }   
        sort(val.begin(),val.end());
    }
    void find_sol(){
        int sum=0;
        for(int i=0;i<val.size();i++){
            if(sum+1<val[i]){
                break;
            }
            sum+=val[i];
        }            
        std::cout << sum+1;
    }


};
int main(){
    Weight wg;
    wg.find_sol();

    return 0;
}