#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class conversion{
private:
    int A,B;
public:
    conversion(){
        std::cin >> A >> B;
    }
    void find_sol(){
        int N,tmp;
        stack<int> st;
        std::cin >>N;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            st.push(tmp);
        }
        N=0,tmp=1;
        while(!st.empty()){
            N+=st.top()*tmp;
            st.pop();
            tmp*=A;
        }
        while(N){
            st.push(N%B);
            N/=B;
        }
        while(!st.empty()){
            std::cout << st.top() <<' ';
            st.pop();
        }
    }
    
};
int main(){
    conversion cs;
    cs.find_sol();
    return 0;
}