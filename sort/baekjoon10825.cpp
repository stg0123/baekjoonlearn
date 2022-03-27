#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct student{
    string name;
    int A,B,C;
};
bool compare(student& a,student& b){
    if(a.A!=b.A)
        return a.A>b.A;
    else if(a.B!=b.B)
        return a.B<b.B;
    else if(a.C!=b.C)
        return a.C>b.C;
    else
        return a.name<b.name;
};
class sorting{
private:
    vector<student> st;
    int N;
public:
    sorting(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int a,b,c;
        string name;
        for(int i=0;i<N;i++){
            std::cin >> name >> a >> b >> c;
            st.push_back({name,a,b,c});
        }
    }
    void find_sol(){
        sort(st.begin(),st.end(),compare);
        for(int i=0;i<st.size();i++)
            std::cout << st[i].name << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    sorting st;
    st.find_sol();

    return 0;
}