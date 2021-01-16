#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class two{
private:
    vector<int> map;
    int N;
public:
    two(int n):N(n){
        map.resize(n);
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> map[i];
        sort(map.begin(),map.end());
        print_map();
    }

    void print_map(){
        for(int i=0;i<N;i++)
            std::cout << map[i]<<' ';
        std::cout <<'\n';
    }
    void find_min(){
        int min=2000000000,start_sol,end_sol;
        int start=0,end=N-1;
        int tmp;
        while(start<end){
            tmp=map[start]+map[end];
            if(abs(tmp)<min){
                min=abs(tmp);
                start_sol=start;
                end_sol=end;
            }
            if(tmp==0){
                std::cout << map[start]<<' '<<map[end]<<'\n';
                return ;
            }
            else if(tmp>0)
                end--;
            else
                start++;
        }
        std::cout << map[start_sol]<<' '<<map[end_sol]<<'\n';
    }

};
int main(){
    int n;
    std::cin >> n;
    two t(n);
    t.set_val();
    t.find_min();
    return 0;
}