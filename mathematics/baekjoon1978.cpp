#include <iostream>
#include <vector>

using namespace std;
class sosu{
private :
    vector<int> num;
    int N,Max;
public :
    sosu(int n):N(n){
        Max=0;
    };

    void set_num(){
        for(int i=0;i<N;i++){
            int a;
            std::cin >> a;
            num.push_back(a);
            if(a>Max)
                Max=a;
        }
    };
    
    void find(){
        vector<int> n;
        n.resize(Max+1,1);
        n[0]=0;
        n[1]=0;
        for(int i=2;i<=Max;i++)
            if(n[i]==1)
                for(int j=2;j<=Max/i;j++){
                    n[i*j]=0;           
                }
        int count=0;
        for(int i=0;i<N;i++)
            if(n[num[i]]==1)
                count++;
        std::cout <<count << '\n';
    };

    void print(){
        std::cout <<Max <<"\n";
        for(int i=0;i<N;i++)
            std::cout << num[i]<<',';
        std::cout << '\n';

    };

};

int main(){
    int n;
    std::cin >> n;
    sosu so(n);    
    so.set_num();
    so.find();

    return 0;
}