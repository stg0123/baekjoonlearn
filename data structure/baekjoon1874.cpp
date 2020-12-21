#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class stack_sqeuence{
private:
    stack<int> st;
    vector<char> map;
    int N;
public:
    stack_sqeuence(int n):N(n){

    };
    void input(){
        int a;
        int cur=0;
        for(int i=0;i<N;i++){
            std::cin >> a;
            if(!st.empty()&&st.top()==a){
                st.pop();
                map.push_back('-');
            }
            else if(cur<a){
                for(int j=cur+1;j<=a;j++){
                    st.push(j);
                    map.push_back('+');
                }
                cur=a;
                st.pop();
                map.push_back('-');
            }
            else{
                std::cout <<"NO\n";
                return ;
            }
        }
        print_map();
    };
    void print_map(){
        for(int i=0;i<map.size();i++)
            std::cout << map[i]<<'\n';
    };

};

int main(){
    int n;
    std::cin >>n;
    stack_sqeuence sq(n);
    sq.input();

    return 0;
}