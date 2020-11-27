#include <iostream>
#include <vector>

using namespace std;
class CP{
private:
    vector<vector<int>> paper;
    int N,zero_num,one_num;
public:
    CP(int n):N(n){
        paper.resize(n);
        for(int i=0;i<n;i++)
            paper[i].resize(n,0);
        zero_num=0;
        one_num=0;
    };
    void set_paper(){
        for(int i=0;i<N;i++)
            for(int j=0;j<N;j++)
                std::cin >> paper[i][j];
    };
    void print_paper(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++)
                std::cout << paper[i][j]<<' ';
        std::cout << '\n';
        } 
    };

    void dp(int x,int y,int l){
        int sum=0;
        for(int i=0;i<l;i++)
            for(int j=0;j<l;j++)
                sum+=paper[x+i][y+j];
        if(sum==0)
            zero_num+=1;
        else if(sum==l*l)
            one_num+=1;
        else{
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                    dp(x+i*(l/2),y+j*(l/2),l/2);
        }
    }
    void print(){
        std::cout << zero_num <<'\n';
        std::cout << one_num << '\n';
    };


};

int main(){
    int n;
    std::cin >> n;
    CP C(n);
    C.set_paper();
    C.dp(0,0,n);
    C.print();


    return 0;
}