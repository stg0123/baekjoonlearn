#include <iostream>
#include <deque>

using namespace std;
class dqtr{
private :
    deque<int> dq;
    int N;
public:
    dqtr(int n):N(n){};

    void tr(){
        string str;
        int a;
        std::cin >>str;
        if(str=="push_front"){
            std::cin >> a;
            dq.push_front(a);
        }
        else if(str=="push_back"){
            std::cin >> a;
            dq.push_back(a);
        }
        else if(str=="pop_front"){
            if(dq.empty())
                std::cout << -1 <<'\n';
            else{
                std::cout << dq.front()<< '\n';
                dq.pop_front();
            }
        }
        else if(str=="pop_back"){
            if(dq.empty())
                std::cout << -1 <<'\n';
            else{
                std::cout << dq.back()<< '\n';
                dq.pop_back();
            }
        }
        else if(str=="size")
            std::cout << dq.size()<<'\n';
        else if(str=="empty")
            std::cout << dq.empty()<<'\n';
        else if(str=="front"){
            if(dq.empty())
                std::cout << -1 <<'\n';
            else{
                std::cout << dq.front()<< '\n';
            }
        }
        else if(str=="back"){
            if(dq.empty())
                std::cout << -1 <<'\n';
            else{
                std::cout << dq.back()<< '\n';
            }
        }
    };
};

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    dqtr dq(n);
    for(int i=0;i<n;i++)
        dq.tr();

    

    return 0;
}