#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1000000000 
using namespace std;

class draw_line{
private:
    vector<pair<int,int>> val;
    int N;
public:
    draw_line(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin>> a >>b;
            val.push_back({a,b});
        }
        sort(val.begin(),val.end());
    }
    void find_length(){
        int sol=0,left=-INF,right=-INF;
        for(int i=0;i<N;i++){
            if(right<val[i].first){
                sol+=right-left;
                left=val[i].first;
                right=val[i].second;
            }
            else
                right=max(right,val[i].second);

        }
        sol+=right-left;
        std::cout << sol;
    }


};
int main(){
    draw_line dl;
    dl.find_length();

    return 0;
}