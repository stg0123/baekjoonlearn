#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef struct node{
    int data;
    string str;
}node;

bool compare(node a,node b){
    return a.data< b.data;
};

class sortbaekjoon{
private: 
    vector<node> map;
    int N;
public :
    sortbaekjoon(int n):N(n){
    };

    void set_map(){
        node tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp.data;
            std::cin >> tmp.str;
            map.push_back(tmp);
        }
    };
    void print_map(){
        for(int i=0;i<map.size();i++)
            std::cout << map[i].data << ' '<< map[i].str << '\n';
    }
    void sorting(){
        std::stable_sort(map.begin(),map.end(),compare);
        print_map();
    };
};


int main(){
    int n;
    std::cin >> n;
    sortbaekjoon st(n);
    st.set_map();
    st.sorting();

    return 0;
}