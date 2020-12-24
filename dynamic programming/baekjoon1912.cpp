#include <iostream>
#include <vector>
using namespace std;
class con_sq{
private:
    vector<int> map;
    vector<int> chache;
    int N;
public:
    con_sq(int n):N(n){
        map.resize(n+1,0);
        chache.resize(n+1,0);
    };
    void set_val(){
        for(int i=1;i<=N;i++){
            std::cin >> map[i];
            chache[i]=map[i];
        }
    };
    void dp(){
        int max=-2000;
        for(int i=1;i<=N;i++){
            if(chache[i]<chache[i-1]+map[i])
                chache[i]=chache[i-1]+map[i];
                
            if(chache[i]>max)
                max=chache[i];

        }
        std::cout << max<<'\n';
    };

};
int main(){
    int n;
    std::cin >>n;
    con_sq sq(n);
    sq.set_val();
    sq.dp();

    return 0;
}