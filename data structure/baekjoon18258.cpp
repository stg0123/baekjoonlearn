#include <iostream>
#include <queue>
#include <string>

using namespace std;
class qtraining{
private:
    queue<int> q;
    int N;
public :    
    qtraining(int n):N(n){
    };
    void command(){
        string str;
        int a;
        std::cin >> str;
        if(str=="push"){
            std::cin >> a;
            q.push(a);
        }
        else if(str=="front"){
            if(!q.empty())
                std::cout << q.front() << '\n';
            else
                std::cout << -1 << '\n';
        }
        else if(str=="back"){
            if(!q.empty())
                std::cout << q.back() << '\n';
            else
                std::cout << -1 << '\n';
        }
        else if(str=="size")
            std::cout << q.size() << '\n';
        else if(str=="pop")
            if(!q.empty()){
                a=q.front();
                std::cout << a<<'\n';
                q.pop();
            }
            else
                std::cout << -1<<'\n';
        else if(str=="empty")
            std::cout << q.empty()<<'\n';
    }
};
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    qtraining tr(n);
    for(int i=0;i<n;i++)
        tr.command();


    return 0;
}