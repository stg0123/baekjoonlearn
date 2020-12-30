#include <iostream>
#include <vector>
using namespace std;
long long DQ(int a,int b,int c){
    if(b==1){
        return a%c;
    }
    long long tmp=DQ(a,b/2,c);
    if(b%2==1)
        return ((tmp*tmp)%c*a)%c;
    else
        return (tmp*tmp)%c;  
};
int main(){
    int a,b,c;
    std::cin >>a >> b>> c;
    std::cout << DQ(a,b,c);
    return 0;
}