#include <iostream>
#include <vector>
using namespace std;
class LIS{
private:
    vector<int> map;
    vector<int> chache;
    int N;
public:
    LIS(int n):N(n){
        map.resize(n);
        chache.resize(n,0);
    };

    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >>map[i];
    }

    void print_chache(){
        for(int i=0;i<N;i++)
            std::cout << chache[i]<<' ';
        std::cout <<'\n';
    }
    void DP(){
        vector<int> lis;
        lis.push_back(map[0]);
        chache[0]=1;
        for(int i=1;i<N;i++){
            if(lis.back()<map[i]){
                lis.push_back(map[i]);
                chache[i]=lis.size();
            }
            else if(lis.back()>map[i]){
                chache[i]=lower_bound(lis.begin(),lis.end(),map[i])-lis.begin()+1;
                *(lis.begin()+chache[i]-1)=map[i];
            }
        }
        int tmp=lis.size();
        std::cout << tmp<<'\n';
        
        for(int i=N-1;i>=0;i--){
            if(chache[i]==tmp){
                lis[tmp-1]=map[i];
                tmp--;
            }
            if(tmp<=0)
                break;
        }
        for(int i=0;i<lis.size();i++)
            std::cout <<lis[i]<<' ';
            
    }
};

int main(){
    int n;
    std::cin >> n;
    LIS lis(n);
    lis.set_val();
    lis.DP();

    return 0;
}