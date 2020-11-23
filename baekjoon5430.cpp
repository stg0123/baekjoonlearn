#include <iostream>
#include <deque>
#include <cstdio>

using namespace std;
class AC{
private :
    deque<int> map;
    string command;
    int start,end;
    int N;
public:
    AC(int n,string str):N(n),command(str){
        start=0;
        end=n;
    };

    void set_map(){
        int a;
        char d;
        std::cin >> d;
        for(int i=0;i<N;i++){
            scanf("%d%*c",&a);
            map.push_back(a);
        }
        if(N==0)
            getchar();
    };

    void print_map(bool flag){
        std::cout << '[';
        if(start<end){
            if(flag){
                std::cout << map[end-1];
                for(int i=end-2;i>=start;i--)
                    std::cout << ','<<map[i];
            }
            else{
                std::cout << map[start];
                for(int i=start+1;i<end;i++)
                    std::cout <<','<< map[i];
            }
        }
        std::cout << "]\n";
    };
    
    void operation(){
        bool flag=false;
        for(int i=0;i<command.length();i++){
            //std::cout << "end,start,flag,N,command= "<<end <<' '<<start <<' '<<flag <<' '<<N << ' '<<command<<'\n';
            if(command[i]=='R')
                flag=!flag;
            else if(command[i]=='D'){
                if(flag)
                    end--;
                else
                    start++;

                if(end<start){
                    std::cout << "error\n";
                    return ;
                }
            }

        }
        print_map(flag);

    }
};

int main(){
    int T,n;
    string str;
    std::cin >>T;
    for(int i=0;i<T;i++){
        std::cin >> str;
        std::cin >> n;
        AC ac(n,str);
        ac.set_map();
        ac.operation();
    }

    return 0;
}