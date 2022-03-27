#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct node{
    string number;
    int strike,ball;
};
class baseball{
private:
    vector<node> info;
    int N;
public:
    baseball(){
        std::cin >> N;
        set_val();
    }
    void set_val(){
        string str;
        int a,b;
        for(int i=0;i<N;i++){
            std::cin >> str >> a >> b;
            info.push_back({str,a,b});
        }
    }
    bool check(string& num){
        for(auto n : info){
            int strike=0,ball=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(i==j && n.number[i]==num[j])
                        strike++;
                    else if(n.number[i]==num[j])
                        ball++;
                }
            }
            if(n.strike != strike || n.ball!=ball)
                return false;
        }
        return true;
    }
    void find_sol(){
        string num;
        for(int i=1;i<=9;i++){
            num.push_back(i+48);
        }
        int sol=0;
        do{
            sol+=check(num);
            reverse(num.begin()+3,num.end());
        }while(next_permutation(num.begin(),num.end()));
        std::cout << sol << '\n';

    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    baseball bb;
    bb.find_sol();
    return 0;
}