#include <iostream>
#include <stack>
using namespace std;
class top{
private:
    stack<pair<int,int>> st;
    int N;
public:
    top(){
        std::cin >> N;
    }
    void find_top(){
        int tmp;
        for(int i=1;i<=N;i++){
            std::cin >> tmp;
            while(1){
                if(st.empty()){
                    std::cout << 0 <<' ';
                    st.push({i,tmp});
                    break;
                }
                else if(st.top().second>=tmp){
                    std::cout << st.top().first << ' ';
                    st.push({i,tmp});
                    break;
                }
                else{
                    st.pop();
                }
            }

        }
    }
};
int main(){
    top t;
    t.find_top();

    return 0;
}