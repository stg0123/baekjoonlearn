#include <iostream>
#include <stack>
#include <vector>
typedef long long l;
using namespace std;
class max_area{
private:
    vector<l> map;
    int N;
public:
    max_area(int n):N(n){
        map.resize(n);

    };
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> map[i];
    }

    void cal(){
        l max=0,tmp,sol;
        stack<int> st;
        for(int i=0;i<N;i++){
            if(st.empty())
                st.push(i);
            else{
                while(map[st.top()]>map[i]){
                    tmp=st.top();
                    st.pop();
                    if(st.empty()){
                        sol=i*map[tmp];
                        if(max<sol)
                            max=sol;
                        break;
                    }
                    else{
                        sol=(i-(st.top()+1))*map[tmp];
                        if(max<sol)
                            max=sol;
                    }                                    
                }
                st.push(i);
            }
        }
        while(!st.empty()){
            tmp=st.top();
            st.pop();
            if(st.empty()){
                sol=N*map[tmp];
            }
            else{
                sol=(N-(st.top()+1))*map[tmp];
            }                 
            if(max<sol)
                max=sol;
        }
        std::cout << max<<'\n';
    }
};
int main(){
    int n;
    std::cin >> n;
    max_area m(n);
    m.set_val();
    m.cal();
    return 0;
}