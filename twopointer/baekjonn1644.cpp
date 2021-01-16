#include <iostream>
#include <vector>
using namespace std;
class prime_sum{
private:
    vector<int> prime;
    long long N,SUM;
public:
    prime_sum(int n):N(n){
        SUM=0;
        vector<bool> map(n+1,true);
        for(int i=2;i<=n;i++){
            if(map[i]==true){
                prime.push_back(i);
                if(i==n)
                    std::cout << n<<"!!\n";
                for(int j=2;j<=n/i;j++){
                    map[j*i]=false;
                }
                SUM+=i;
            }
        }
    }

    void print_prime(){
        for(int i=0;i<prime.size();i++)
            std::cout << prime[i]<< ' ';
        std::cout << '\n';
    }
    void two_pointer(){
        int start=0,end=prime.size()-1;
        int sol=0;
        while(start<=end){
            if(SUM==N){
                sol++;
                SUM-=prime[end];
                end--;
            }
            else if(SUM>N){
                SUM-=prime[end];
                end--;
            }
            else{
                SUM-=prime[start];
                start++;
                end++;
                if(end>=prime.size())
                    break;
                SUM+=prime[end];
            }
        }
        std::cout << sol << '\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    prime_sum pr(n);
    pr.two_pointer();

    
    return 0;
}