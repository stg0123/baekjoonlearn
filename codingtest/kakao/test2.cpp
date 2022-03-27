#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
class test2{
private:    
    vector<bool> prime_table;
    int N,K;
public:
    test2(int n,int k):N(n),K(k){
        prime_table.resize(1000001,true);
        prime_table[0]=false;
        prime_table[1]=false;
        for(int i=2;i<=1000000;i++)
            if(prime_table[i])
                for(int j=2;j<1000000/i;j++)
                    prime_table[j*i]=false;
    }
    int find_sol(){
        int sol =0;
        stack<int> st;
        while(N){
            st.push(N%K);
            N/=K;
        }
        string str ="";
        while(!st.empty()){
            if(st.top()==0){
                if(!str.empty()&& str.size()<7){
                    int i =stoi(str);
                    if(prime_table[i])
                        sol++;
                }
                str = "";
            }       
            else
                str.push_back(char(st.top()+48));
            st.pop();
        }
            // str.size가 7보다큰게2개있었음 
        if(!str.empty() && str.size()<7)
            if(prime_table[stoi(str)])
                sol++;
        std::cout << sol <<'\n';
        return sol;
    }

};
int solution(int n, int k) {
    test2 t2(n,k);
    return t2.find_sol();
}
int main(){
    solution(89894,7);

    return 0;
}