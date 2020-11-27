#include <iostream>

using namespace std;
int main(){
    int N,M;
    std::cin >> N >> M;
    int card[N];
    int good=300000,sum=0,tmp=0;
    for(int i=0;i<N;i++)
        std::cin >> card[i];
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            for(int k=0;k<N;k++){
                sum=card[i]+card[j]+card[k];
                if(i!=j&&j!=k&&k!=i&&good>M-sum&&M-sum>=0){
                    good=M-sum;
                    tmp=sum;
                }
            }    

    std::cout <<tmp;


    return 0;
}