#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class clock_cal{
private:
    int N;
    vector<int> c1,c2;
    vector<int> d1,d2;
    vector<int> pi;
public:
    clock_cal(){
        std::cin >> N;
        c1.resize(N);
        c2.resize(N);
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >>c1[i];
        for(int i=0;i<N;i++)
            std::cin >>c2[i];
        sort(c1.begin(),c1.end());
        sort(c2.begin(),c2.end());
        for(int i=0;i<N-1;i++){
            d1.push_back(c1[i+1]-c1[i]);
            d2.push_back(c2[i+1]-c2[i]);
        }
        d1.push_back(360000-(c1[N-1]-c1[0]));
        d2.push_back(360000-(c2[N-1]-c2[0]));
        d1.insert(d1.end(),d1.begin(),d1.end());
    }
    void print(){
        for(int i=0;i<d1.size();i++)
            std::cout << d1[i] << ' ';
        std::cout << '\n';
        for(int i=0;i<d2.size();i++)
            std::cout << d2[i]<<' ';

    }
    void get_pi(){
        pi.resize(d2.size(),0);
        for(int i=1,j=0;i<d2.size();i++){
            while(j>0&&d2[i]!=d2[j])
                j=pi[j-1];
            if(d2[i]==d2[j])
                pi[i]=++j;
        }
    }
    void KMP(){
        vector<int> sol;
        for(int i=0,j=0;i<d1.size();i++){
            while(j>0&&d1[i]!=d2[j])
                j=pi[j-1];
            if(d1[i]==d2[j]){
                if(j==d2.size()-1){
                    sol.push_back(i-d2.size()+1);
                    j=pi[j];
                }
                else
                    j++;
            }
        }
        if(sol.empty())
            std::cout<<"impossible";
        else
            std::cout<<"possible";
    }

};
int main(){
    clock_cal cc;
    cc.get_pi();
    cc.KMP();
    return 0;
}