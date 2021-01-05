#include <iostream>
#include <vector>
using namespace std;
class oil_val{
private:
    vector<long long> oil,dis;
    int N;
public:
    oil_val(int n):N(n){
        oil.resize(n);
        dis.resize(n);
    };
    void set_val(){
        for(int i=1;i<N;i++)
            std::cin >> dis[i];
        for(int i=0;i<N;i++)
            std::cin >> oil[i];
    }
    
    void Greedy(){
        long long sum=0,i=0,j=0;

        while(j<N){
            for(j=i+1;j<N;j++)
                if(oil[i]>=oil[j])
                    break;
            for(long long t=i+1;t<=j;t++)
                sum+=dis[t]*oil[i];

            if(j==N-1)
                break;
            
            i=j;
        }
        std::cout <<sum << '\n';
    };


};
int main(){
    int n;
    std::cin >>n;
    oil_val o(n);
    o.set_val();
    o.Greedy();



    return 0;
}