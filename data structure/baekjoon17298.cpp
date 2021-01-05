#include <iostream>
#include <stack>
#include <vector>
using namespace std;
struct node{
    int data,idx;
};
class rbn{
private:
    vector<int> map;
    int N;
public:
    rbn(int n):N(n){
        map.resize(n,-1);
    };

    void find_rbn(){
        stack<node> st;
        int data;
        node tmp;
        for(int i=0;i<N;i++){
            std::cin>> data;
            while(!st.empty()){
                if(st.top().data<data){
                    map[st.top().idx]=data;
                    st.pop();
                }
                else
                    break;
            }
            tmp.data=data;
            tmp.idx=i;
            st.push(tmp);
        }

        print_map();

    }

    void print_map(){
        for(int i=0;i<N;i++)
            std::cout << map[i]<<' ';
        std::cout <<'\n';
    }
};
int main(){
    int n;
    std::cin >> n;
    rbn r(n);
    r.find_rbn();

    return 0;
}