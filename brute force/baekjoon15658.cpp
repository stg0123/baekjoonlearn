#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INF = 1000000000;
class oper{
private:
    vector<int> order;
    vector<int> val;
    int N;
public:
    oper(){
        std::cin >> N;
        val.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> val[i];
        int n;
        for(int i=0;i<4;i++){
            std::cin >> n;
            for(int j=0;j<n;j++)
                order.push_back(i);
        }
    }
    int check(vector<int>& order){
        int sol=val[0];
        for(int i=0;i<N-1;i++){
            if(order[i]==0)
                sol+=val[i+1];
            else if(order[i]==1)
                sol-=val[i+1];
            else if(order[i]==2)
                sol*=val[i+1];
            else
                sol/=val[i+1];
        }
        return sol;
    }

    void find_sol(){
        int MAX=-INF,MIN=INF;
        int tmp;
        do{
            tmp=check(order);
            MAX=max(tmp,MAX);
            MIN=min(tmp,MIN);
            reverse(order.begin()+N-1,order.end());
        }while(next_permutation(order.begin(),order.end()));
        std::cout << MAX << '\n';
        std::cout << MIN << '\n';

    }


};
int main(){
    oper op;
    op.find_sol();   

    return 0;
}