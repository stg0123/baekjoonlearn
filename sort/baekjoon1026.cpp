#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int& a,int& b){
    return a>b;
};
class treasure{
private:
    int N;
    vector<int> v1,v2;
public:
    treasure(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            v1.push_back(tmp);
        }
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            v2.push_back(tmp);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end(),compare);
    }
    void find_sol(){
        int sol=0;
        for(int i=0;i<N;i++){
            sol+=v1[i]*v2[i];
        }
        std::cout << sol;
    }


};
int main(){
    treasure tr;
    tr.find_sol();
    return 0;
}