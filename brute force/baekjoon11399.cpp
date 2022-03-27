#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;
int main(){
    int n,sol=0;
    std::cin >> n;
    int p[n];
    for(int i=0;i<n;i++)
        std::cin >>p[i];
    std::sort(p,&p[n]);
    
    for(int i=0;i<n;i++)
        sol+=p[i]*(n-i);

    std::cout << sol;
    
    return 0;
}