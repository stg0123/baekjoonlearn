#include <iostream>
#include <vector>


using namespace std;
class map{
private:
    vector<pair<int,int>> zero_one;
    int N;
public:
    map(int n):N(n){
        pair<int,int> tmp;
        tmp.first=1;
        tmp.second=0;
        zero_one.push_back(tmp);
        tmp.first=0;
        tmp.second=1;
        zero_one.push_back(tmp);

    };
    pair<int,int> fibonachi(int n){
        pair<int,int> tmp;
        if(zero_one.size()>n){
            tmp.first=zero_one[n].first;
            tmp.second=zero_one[n].second;
            return tmp;
        }
        else{
            tmp.first=fibonachi(n-2).first+fibonachi(n-1).first;
            tmp.second=fibonachi(n-2).second+fibonachi(n-1).second;
            zero_one.push_back(tmp);
            return tmp;
        }
    };

    void print_(){  
        for(int i=0;i<zero_one.size();i++)
            std::cout << zero_one[i].first<<','<<zero_one[i].second<< ' ';
        std::cout << '\n';    
        
    };

    
};
int main(){
    int n,m;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> m;
        map fi(m);
        pair<int,int> tmp;
        tmp=fi.fibonachi(m);
        std::cout<< tmp.first << ' '<<tmp.second<<'\n';
    }

}