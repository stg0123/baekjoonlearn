#include <iostream>
#include <vector>

using namespace std;
class counting{
private :
    vector<int> map;
    int N,Max;
public: 
    counting(int n):N(n){
        map.resize(10001,0);                
        Max=0;
    }
    
    void set_map(){
        for(int i=0;i<N;i++){
            int temp;
            std::cin >> temp;
            map[temp]++;
            if(temp>Max)
                Max=temp;
        }
        
    }
    void counting_sort(){
        for(int i=1;i<=Max;i++){
            while(1){
                if(map[i]==0)
                    break;
                std::cout << i <<'\n';
                map[i]--;

            }
        }
    }

};
int main(){
    std::cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    counting cs(n);
    cs.set_map();
    cs.counting_sort();


    return 0;
}