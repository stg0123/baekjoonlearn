#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class knapsack{
private:
    vector<int> map,v1,v2;
    int N,BAG;
public:
    knapsack(int n,int m):N(n),BAG(m){
        map.resize(n);
    };
    void find(){
        set_val();
        leftcal(0,0);
        sort(v1.begin(),v1.end());
        rightcal(N/2,0);
        sort(v2.begin(),v2.end());
        int sol=0;
        for(int i=0;i<v1.size();i++){
            sol+=(upper_bound(v2.begin(),v2.end(),BAG-v1[i])-v2.begin()); 
        }
        std::cout << sol << '\n';

    }
    void print_vector(vector<int>& v){
        for(int i=0;i<v.size();i++)
            std::cout << v[i] << ' ';
        std::cout << '\n';
    }


    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> map[i];
    }

    void leftcal(int start,int sum){
        if(sum>BAG)
            return ;
        if(start == N/2)
            return v1.push_back(sum);
        leftcal(start+1,sum);
        leftcal(start+1,sum+map[start]);
    }

    void rightcal(int start,int sum){
        if(sum>BAG)
            return ;
        if(start == N)
            return v2.push_back(sum);
        rightcal(start+1,sum);
        rightcal(start+1,sum+map[start]);
    }

};
int main(){
    int n,b;
    std::cin >> n >> b;
    knapsack kn(n,b);
    kn.find();


    return 0;
}