#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n;
    string str;
    std::cin >>n;
    std::cin >>str;
    int sol=0;
    for(int i=0;i<n;i++){
        if(str[i]=='L')
            i++;
        sol++;
    }
    std::cout << min(sol+1,n);
    return 0;
}