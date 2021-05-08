#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class poketmon{
private:
    vector<string> num_to_name;
    unordered_map<string,int> name_to_num;
    int N,M;
public:
    poketmon(){
        std::cin >> N >>M;
        num_to_name.resize(N+1);
        set_val();
    }
    void set_val(){
        string str;
        for(int i=1;i<=N;i++){
            std::cin >> str;
            name_to_num[str]=i;
            num_to_name[i]=str;
        } 
    }  
    void query(){
        string str;
        for(int i=0;i<M;i++){
            std::cin >>str;
            if(str[0]>'0' && str[0]<='9')
                std::cout << num_to_name[stoi(str)] << '\n';
            else
                std::cout << name_to_num[str] << '\n';
        }
    }
    
};
int main(){
    poketmon pk;
    pk.query();

    return 0;
}