#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class val_bracket{
private:
    string str;
public:
    val_bracket(){
        std::cin >> str;
    }    
    // (1 [2
    void find_sol(){
        int sol=0;
        stack<int> st;
        for(int i=0;i<str.size();i++){
            if(str[i]=='('){
                st.push(-1);
            }
            else if(str[i]==')'){
                int tmp=0;
                while(1){
                    if(st.empty()){
                        std::cout << 0 << '\n';
                        return ;
                    }
                    if(st.top()==-1){
                        if(tmp==0)
                            tmp=2;
                        else
                            tmp*=2;
                        st.pop();
                        st.push(tmp);
                        break;
                    }
                    else if(st.top()>0){
                        tmp+=st.top();
                        st.pop();
                    }
                    else{
                        std::cout << 0 << '\n';
                        return ;
                    }   
                }
            }
            else if(str[i]=='['){
                st.push(-2);
            }
            else if(str[i]==']'){
                int tmp=0;
                while(1){
                    if(st.empty()){
                        std::cout << 0 << '\n';
                        return ;
                    }
                    if(st.top()==-2){
                        if(tmp==0)
                            tmp=3;
                        else
                            tmp*=3;
                        st.pop();
                        st.push(tmp);
                        break;
                    }
                    else if(st.top()>0){
                        tmp+=st.top();
                        st.pop();
                    }
                    else{
                        std::cout << 0 << '\n';
                        return ;
                    }   
                }
            }
        }
        while(!st.empty()){
            if(st.top()<0){
                std::cout << 0 << '\n';
                return ;
            }
            sol+=st.top();
            st.pop();
        }
        std::cout << sol<<'\n';

    }


};
int main(){
    val_bracket vb;
    vb.find_sol();
    return 0;
}