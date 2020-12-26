#include <iostream>
#include <vector>

using namespace std;
class factorial{
private:
    vector<int> chache;
    
public:
    factorial(int n){
        chache.resize(n+1,1);
        dp(n);
    };

    int dp(int n){
        if(n<=1)
            return 1;
        else if(chache[n]!=1)
            return chache[n];
        chache[n]=dp(n-1)*n;
        return chache[n];
    };
    int val(int n){
        return chache[n];
    }

};
int main(){
    int a,b;
    std::cin >> a>> b;
    factorial f(a);
    std::cout << f.val(a)/(f.val(a-b)*f.val(b));

    return 0;
}