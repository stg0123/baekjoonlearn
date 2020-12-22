#include <iostream>
#include <vector>

using namespace std;
class divisor{
private :
    vector<int> map;
    int N;
public:
    divisor(int n):N(n){
        map.resize(n+1,0);
        map[2]=1;
        map[3]=1;
        
    }
    int DP(int a){
        if(a<=1)
            return 0;
        else if(map[a]!=0)
            return map[a];
        
        if(a%3==0&&a%2==0)
            map[a]=min(DP(a/3)+1,DP(a/2)+1);
        else if(a%3==0)
            map[a]=min(DP(a/3)+1,DP(a-1)+1);
        else if(a%2==0)
            map[a]=min(DP(a/2)+1,DP(a-1)+1);
        else 
            map[a]=DP(a-1)+1;
        
        return map[a];
    }
    void print_val(int n){
        std::cout << map[n]<<'\n';
    }

};

int main(){
    int n;
    std::cin >> n;
    divisor dv(n);
    dv.DP(n);
    dv.print_val(n);
    return 0;
}