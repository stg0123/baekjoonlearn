#include <iostream>
#include <vector>
using namespace std;
class prime_pel{
private:
    vector<bool> table;
    int N,MAX_SOL=1003001;
    int size=1000000;
public:
    prime_pel(){
        std::cin >> N;
        table.resize(size+1,true);
        set_table();
    }
    void set_table(){
        table[0]=table[1]=0;
        for(int i=2;i<=size;i++){
            if(table[i]){
                for(int j=2;j<=size/i;j++)
                    table[i*j]=false;
                if(!check(to_string(i)))
                    table[i]=false;
            }
        }
    }
    bool check(string str){
        if(str.size()<=1)
            return true;
        if(str[0]!=str.back())
            return false;
        str.pop_back();
        return check(str.substr(1));
    }
    void find_sol(){
        for(int i=N;i<=size;i++){
            if(table[i]){
                std::cout << i << '\n';
                return ;
            }
        }
        std::cout << MAX_SOL << '\n';
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    prime_pel pp;
    pp.find_sol();

    return 0;
}