#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    std::cin >>n;
    if(n==1)
        return 0;
    vector<bool> map(n+1,1);
    map[0]=map[1]=false;
    for(int i=2;i<=n;i++){
        if(map[i]==true)
            for(int j=2;j<=n/i;j++)
                map[i*j]=false;
    }
    while(1){
        if(n==1)
            break;
        for(int i=2;i<=n;i++)
            if(map[i]==true&&n%i==0){
                n/=i;
                std::cout << i <<'\n';
                break;
            }
    }

    return 0;
}