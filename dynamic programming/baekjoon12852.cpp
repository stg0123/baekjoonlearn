#include <iostream>
#include <vector>
using namespace std;
class make1{
private:
    vector<int> chache;
    vector<int> map;
    int N;
public:
    make1(int n):N(n){
        chache.resize(n+1,0);
        map.resize(n+1,0);
    };

    void start(){
        std::cout <<DP(N)<<'\n';
        print_sol(N);
    }
    void print_sol(int n){
        if(map[n]==3){
            std::cout << n<<' ';
            print_sol(n/3);
        }
        else if(map[n]==2){
            std::cout << n<<' ';
            print_sol(n/2);
        }
        else if(map[n]==1){
            std::cout << n<<' ';   
            print_sol(n-1);   
        }
        else
            std::cout<< n <<'\n';
        
    }

    int DP(int n){
        if(n==1)
            return 0;
        else if(chache[n]!=0)
            return chache[n];
        int tmp1,tmp2;
        if(n%3==0&&n%2==0){
            tmp1=DP(n/3)+1;
            tmp2=DP(n/2)+1;
            if(tmp1<tmp2){
               chache[n]=tmp1;
               map[n]=3;
            }
            else{
                chache[n]=tmp2;
                map[n]=2;
            }
        }
        else if(n%3==0){
            tmp1=DP(n/3)+1;
            tmp2=DP(n-1)+1;
            if(tmp1<tmp2){
               chache[n]=tmp1;
               map[n]=3;
            }
            else{
                chache[n]=tmp2;
                map[n]=1;
            }
        }
        else if(n%2==0){
            tmp1=DP(n/2)+1;
            tmp2=DP(n-1)+1;
            if(tmp1<tmp2){
               chache[n]=tmp1;
               map[n]=2;
            }
            else{
                chache[n]=tmp2;
                map[n]=1;
            }
        }
        else{
            chache[n]=DP(n-1)+1;
            map[n]=1;
        }
        return chache[n];

    };
};
int main(){
    int n;
    std::cin >> n;
    make1 ma(n);
    ma.start();

    return 0;
}