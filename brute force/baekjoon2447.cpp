#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class Star{
    private :
        char** star;
        int N;
    
    public :
        Star(int N){
            this->N =N;
            this->star = new char*[N];
            for(int i=0;i<N;i++){
                star[i]=new char[N];
                memset(star[i],' ',sizeof(char)*N);
            }
        }

        void set(int n,int x,int y){
            if(n==1){
                star[x][y]='*';
                return ;
            }
            int s=n/3;
            for(int i=0;i<3;i++)
                for(int j=0;j<3;j++){
                    if(i==1 &&j ==1)
                        continue;
                    else   
                        set(s,x+(i*s),y+(j*s));
                }
        }

        void print(){
            for(int i=0;i<N;i++){
                for(int j=0;j<N;j++)
                    std::cout << star[i][j];
            std::cout <<'\n';
            }
            return ;
        }        



};

int main(){
    int n;
    std::cin >> n;
    Star a(n);
    a.set(n,0,0);
    a.print();

    return 0;
}