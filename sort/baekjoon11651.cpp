#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
    if(a.second==b.second)
        return a.first<b.first;
    else 
        return a.second<b.second;
}; 
class sorting{
private:
    vector<pair<int,int>> map;
    int N;
public:
    sorting(int n):N(n){
    };
    
    void set_map(){
        pair<int,int> tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp.first;
            std::cin >> tmp.second;
            map.push_back(tmp);
        }
    };

    void sorted(){
        std::sort(map.begin(),map.end(),compare);
        
        for(int i=0;i<map.size();i++)
            std::cout << map[i].first << " "<< map[i].second << '\n';

    };
    
};
int main(){
    int n;
    std::cin >> n;
    sorting st(n);
    st.set_map();
    st.sorted();
    
    return 0;
}