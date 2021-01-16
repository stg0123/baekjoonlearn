#include <iostream>
#include <vector>
using namespace std;
class medicine{
private:
    vector<int> map;
    int N;
public:
    medicine(int n):N(n){
        map.resize(101,-1);
    };
    void set_val(){
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> a>> b;
            map[a]=b;
        }
    }
    
    void find(){
        int n,a;
        vector<int> sol;
        std::cin >> n;
        bool flag =false;
        for(int i=0;i<n;i++){
            std::cin >>a;
            if(map[a]==-1||a>100||a<0){
                flag =true;
                continue;
            }
            sol.push_back(map[a]);
        }
        if(flag)
            std::cout << "YOU DIED\n";
        else{ 
            for(int i=0;i<sol.size();i++)
                std::cout << sol[i]<<' ';
            std::cout <<'\n';
        }
    }

    
};
int main(){
    int n;
    std::cin >> n;
    medicine me(n);
    me.set_val();
    std::cin >> n;
    for(int i=0;i<n;i++)
        me.find();

    return 0;
}