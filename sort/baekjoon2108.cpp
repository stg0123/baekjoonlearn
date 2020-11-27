#include <iostream>
#include <vector>
#include <math.h>

using namespace std;
class statistic{
private :
    vector<int> map;
    vector<int> sorting;
    int N,MAX,MIN,MAXCOUNT;
    int AllSum;
public :
    statistic(int n):N(n){
        map.resize(8001,0);
        sorting.resize(n+1,0);
        MAX=-4000;
        MIN=4000;
        AllSum=0;
        MAXCOUNT=0;
    }

    void set_map(){
        int tmp,maxnum;
        bool flag=false;
        for(int i=0;i<N;i++){
            std::cin >> tmp;
            map[tmp+4000]++;
            AllSum+=tmp;
            if(tmp>MAX)
                MAX=tmp;
            if(tmp<MIN)
                MIN=tmp;
        }            
        for(int i=MIN+4000;i<=MAX+4000;i++){
            if(map[i]>MAXCOUNT){
                MAXCOUNT=map[i];
                maxnum=i-4000;
                flag=false;
            }
            else if(map[i]==MAXCOUNT&&flag==false){
                maxnum=i-4000;
                flag=true;
            }
        }
        MAXCOUNT=maxnum;

        //std::cout <<"allsum= "<< AllSum << '\n';
    }

    void avg(){
        std::cout << round((float)AllSum/N) << '\n';
    }
    void middle(){
        int tmp=0;
        for(int i=1;i<=N;i++){//counting sort 배열에 저장된 수만큼 그숫자가있다
            while(1){
                if(map[tmp]==0)
                    tmp++;
                else{
                    sorting[i]=tmp-4000;
                    map[tmp]--;
                    break;
                }
            }
        }
        std::cout << sorting[(N+1)/2]<<'\n';
    }
    void choibin(){
        std::cout<< MAXCOUNT<<'\n';
    }
    void range(){
        std::cout <<MAX-MIN<<'\n';

    }
    

};
int main(){
    int n;
    std::cin >>n;

    statistic st(n);
    st.set_map();
    st.avg();
    st.middle();
    st.choibin();
    st.range();

    return 0;
}