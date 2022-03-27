#include <iostream>
#include <vector>
/*
operation : [0] + [1] - [2] * [3] /
*/

using namespace std;
class calculator{
    private :
        vector<int> formula_num;
        vector<char> operate;
        int operation[4];
        int N,MAX,MIN;
    public :
        calculator(int n):N(n){
            formula_num.resize(n);
            operate.resize(n-1);
            MAX=-1000000000;
            MIN=1000000000;
        };

        void set_(){
            for(int i=0;i<N;i++)
                std::cin >> formula_num[i];
            for(int i=0;i<4;i++)
                std::cin >> operation[i];
        };

        void input_op(int op,int degree){
            if(op==0)
                operate[degree-1]='+';
            else if(op==1)
                operate[degree-1]='-';
            else if(op==2)
                operate[degree-1]='*';
            else if(op==3)
                operate[degree-1]='/'; 
        };
        
        void operating(){
            int tmp=formula_num[0];
            int a;
            char oper;
            for(int i=1;i<N;i++){
                oper=operate[i-1];
                a=formula_num[i];
                if(oper=='+')
                    tmp +=a;
                else if(oper=='-')
                    tmp -=a;
                else if(oper=='*')
                    tmp *=a;
                else if(oper=='/')
                    tmp /=a;
            }
            if(tmp<MIN)
                MIN=tmp;
            if(tmp>MAX)
                MAX=tmp;

        };
        void dfs(int op,int degree){
            if(operation[op]==0)
                return;
            input_op(op,degree);
            if(degree ==N-1){
                operating();
                return;
            }
            operation[op]-=1;
            for(int i=0;i<4;i++)
                dfs(i,degree+1);
            
            operation[op]+=1;

        };
        void min_max(){
            std::cout << MAX<<'\n' << MIN;

        };
        void print_formula(){
                std::cout << formula_num[0];
            for(int i=0;i<N-1;i++){
                std::cout << operate[i];
                std::cout << formula_num[i+1];
            }
            std::cout <<'\n';
            
        };

};



int main(){
    int n;
    std::cin >> n;
    calculator cal(n);
    cal.set_();
    for(int i=0;i<4;i++)
        cal.dfs(i,1);
    cal.min_max();   

    return 0;
}