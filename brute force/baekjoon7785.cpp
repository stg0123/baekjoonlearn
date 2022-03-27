#include <iostream>
#include <set>
using namespace std;
class set_tutorial{
private:
    set<string> Sets;
    int N;
public:
    set_tutorial(){
        std::cin >> N;
    }
    void find_sol(){
        string tmp,status;
        for(int i=0;i<N;i++){
            std::cin >> tmp >> status;
            if(status=="enter")
                Sets.insert(tmp);
            else
                Sets.erase(tmp);
        }
        for(set<string>::reverse_iterator it=Sets.crbegin();it !=Sets.crend();++it)
            std::cout << *it<<'\n';
    }
};
int main(){
    set_tutorial st;
    st.find_sol();

    return 0;
}