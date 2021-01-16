#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class subsum{
private:
    vector<int> map;
    int N,VAL,SUM;
public:
    subsum(int n,int s):N(n),VAL(s){
        map.resize(n);
        SUM=0;
    }
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >> map[i];
            SUM+=map[i];
        }
    }
    void find_min(){
        int start=0,end=N-1;
        int tmp;
        if(SUM<VAL){
            std::cout <<0 <<'\n';
            return ;
        }
        else{
            SUM-=map[end];
            end--;
        }

        while(start<=end){
            if(SUM>=VAL){
                SUM-=map[end];
                end--;
            }
            else{
                SUM-=map[start];
                start++;
                end++;
                if(end>=N)
                    break;
                SUM+=map[end];
            }
        }
        std::cout << end-start+2<<'\n';

    }
};
int main(){
    int n,s;
    std::cin>> n >> s;
    subsum sub(n,s);
    sub.set_val();
    sub.find_min();
    return 0;
}
