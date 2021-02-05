#include <iostream>
#include <vector>
using namespace std;
class ad_min{
private:
    int L;
    string str;
    vector<int> pi;
public:
    ad_min(){
        std::cin >> L >> str;
        pi.resize(L,0);
    }
    void getpi(){
        for(int i=1,j=0;i<L;i++){
            while(j>0 && str[i]!=str[j])
                j=pi[j-1];
            if(str[i]==str[j])
                pi[i]=++j;
        }
        std::cout << L-pi[L-1];
    }

};
int main(){
    ad_min ad;
    ad.getpi();

    return 0;
}