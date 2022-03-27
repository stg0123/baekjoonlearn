#include <iostream>
#include <vector>
using namespace std;
class LDS{
private:
    vector<int> lds;
    int N;
public:
    LDS(){
        std::cin >> N;
    }
    void find_sol(){
        int a;
        for(int i=0;i<N;i++){
            std::cin >> a;
            if(lds.empty())
                lds.push_back(a);
            else if(lds.back()>a)
                lds.push_back(a);
            else if(lds.back()<a){
                for(int l=0;l<lds.size();l++){
                    if(lds[l]<=a){
                        lds[l]=a;
                        break;
                    }
                }
            }
        }
        std::cout << lds.size()<<'\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    LDS lds;
    lds.find_sol();

    return 0;
}