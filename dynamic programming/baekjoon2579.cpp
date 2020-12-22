#include <iostream>
#include <vector>

using namespace std;
class stair{
private:
    vector<int> map;
    vector<int> chache;
    int N;
public:
    stair(int n):N(n){
        map.resize(n+1,0);
        chache.resize(n+1,-1);
        chache[0]=0;
    };
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> map[i];
    };
    void cal(){
        if(N>2){
            chache[1]=map[1];
            chache[2]=map[1]+map[2];
        }
        else
        {
            if(N==0)
                std::cout << 0<<'\n';
            else if(N==1)
                std::cout<<map[1]<<'\n';
            else if(N==2)
                std::cout<<map[1]+map[2]<<'\n';
            
            return ;
        }
        for(int i=3;i<=N;i++){
            chache[i] = max(chache[i-3]+map[i-1]+map[i],chache[i-2]+map[i]);    
        }
        print_val(N);
    }
    void print_val(int n){
        std::cout << chache[n]<<'\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    stair s(n);
    s.set_val();
    s.cal();

    return 0;
}