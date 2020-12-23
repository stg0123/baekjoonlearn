#include <iostream>
#include <vector>
using namespace std;
class sub_sqeuence{
private:
    vector<int> up_chache;
    vector<int> dw_chache;
    vector<int> map;
    int N;
public:
    sub_sqeuence(int n):N(n){
        map.resize(n+1,0);
        dw_chache.resize(n+1,0);
    }
    void set_val(){
        for(int i=1;i<=N;i++)
            std::cin >> map[i];
        up_chache.push_back(map[1]);
        dw_chache[N]=1;
    }
    void DP(){
        if(N==1){
            std::cout <<1<<'\n';
            return ;
        }
        int tmp,max=0;
        for(int i=2;i<=N;i++){
            tmp=up_sq(i)+dw_sq(i)-1;
            if(tmp>max)
                max=tmp;
        }
       std::cout << max<<'\n';
        return ;
    };
    int up_sq(int n){
        if(n==1)
            return 1;
        if(map[n]>up_chache[up_chache.size()-1])
            up_chache.push_back(map[n]);
        else{
            for(int i=0;i<up_chache.size();i++)
                if(up_chache[i]>=map[n]){
                    up_chache[i]=map[n];
                    break;
                }
        }
        return up_chache.size();
    };
    int dw_sq(int n){
        if(n==N)
           return 1;
        else if(dw_chache[n]!=0)
            return dw_chache[n];
        
        vector<int> temp;
        temp.push_back(map[N]);
        for(int i=N-1;i>=n;i--){
            if(map[i]>temp[temp.size()-1]){
                temp.push_back(map[i]);
                dw_chache[i]=temp.size();
            }
            else{
                for(int j=0;j<temp.size();j++){
                    if(temp[j]>=map[i]){
                        temp[j]=map[i];
                        break;
                    }
                }
                dw_chache[i]=temp.size();
            }
        }
        return temp.size();  
    
    };

    void print_chache(){
        for(int i=0;i<dw_chache.size();i++)
            std::cout << dw_chache[i]<<' ';
        std::cout <<'\n';
    } 
};
int main(){
    int n;
    std::cin >> n;
    sub_sqeuence sq(n);
    sq.set_val();
    sq.DP();

    return 0;
}