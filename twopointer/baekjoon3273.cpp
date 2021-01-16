#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n,tmp,sol=0;
    vector<int> map;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >>tmp;
        map.push_back(tmp);
    }
    sort(map.begin(),map.end());
    int start=0,end=n-1,x;
    std::cin>>x;
    while(start<end){
        if(start<0||end>=n)
            break;
        tmp=map[start]+map[end];
        if(tmp==x){
            sol++;
            start++;
            end--;
        }
        else if(tmp>x)
            end--;
        else
            start++;
    }
    std::cout << sol<<'\n';
        


    return 0;
}