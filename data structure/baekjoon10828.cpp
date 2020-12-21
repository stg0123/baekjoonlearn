#include <iostream>
#include <stack>

using namespace std;
class my_stack{
private :
    stack<int> st;
public :
    my_stack(){
    };

    void input(){
        string str;
        std::cin >>str;
        if(str == "push"){
            int a;
            std::cin >>a;
            st.push(a);
        }
        else if(str == "pop"){
            if(st.empty())
                std::cout << -1<<'\n';
            else{
                std::cout << st.top() << '\n';
                st.pop();
            }
        }
        else if(str == "size"){
            std::cout << st.size()<<'\n';
        }
        else if(str == "empty"){
            std::cout << st.empty()<<'\n';
        }
        else if(str == "top"){
            if(st.empty())
                std::cout << -1<<'\n';
            else
                std::cout << st.top()<<'\n';            
        }
    }
};

int main(){
    int n;
    std::cin >> n;
    my_stack st;
    for(int i=0;i<n;i++){
        st.input();
    }    

    return 0;
}