#include <iostream>
#include <stack>

using namespace std;
int main(){
    int n,a,sum;
    sum=0;
    std::cin >> n;
    stack<int> st;
    for(int i=0;i<n;i++){
        std::cin >> a;
        if(a==0){
            sum-=st.top();
            st.pop();
        }
        else{
            sum+=a;
            st.push(a);            
        }
    }
    std::cout <<sum <<'\n';

    return 0;
}