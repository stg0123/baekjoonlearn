#include <iostream>
#include <vector>
using namespace std;
struct node{
    string ware;
    string type;
};
class sub_num{
private:
    vector<vector<node>> map;
    int N;
public:
    sub_num(int n):N(n){

    };
    void set_val(){
        node tmp_n;
        bool flag =false;
        for(int i=0;i<N;i++){
            std::cin >>tmp_n.ware >> tmp_n.type;
            flag=false;
            for(int j=0;j<map.size();j++){
                if(map[j][0].type==tmp_n.type){
                    map[j].push_back(tmp_n);
                    flag=true;
                    break;
                }
            }
            if(!flag){
                vector<node> tmp_v;
                tmp_v.push_back(tmp_n);
                map.push_back(tmp_v);
            }
        }

    };
    void sol(){
        int sum=1; 
        for(int i=0;i<map.size();i++)
            sum*=map[i].size()+1;
        std::cout << sum -1<< '\n';
    }

};
int main(){
    int n,num;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> num;
        sub_num sub(num);
        sub.set_val();
        sub.sol();
    }

    return 0;
}