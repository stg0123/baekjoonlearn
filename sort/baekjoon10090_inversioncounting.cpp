#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class merge_sort{
private:
    vector<int> val;
    vector<int> sol;
    int N;
    ll result;
public:
    merge_sort(){
        std::cin >> N;
        val.resize(N);
        set_val();
        sol=val;
        result=0;
    }
    void set_val(){
        for(int i=0;i<N;i++)
            std::cin >> val[i];
    }

    void merge(int start,int end){
        if(end<=start)
            return ;
        
        int mid= (start+end)/2;
        
        merge(start,mid);
        merge(mid+1,end);
        
        // 머지 소트 부분
        int part1 = start;
        int part2 = mid+1;
        int index = start;
        while(part1<=mid && part2 <=end){
            if(val[part1]<=val[part2]){
                sol[index]=val[part1++];
            }
            else{
                sol[index]=val[part2++];
                result+=(mid-part1+1);
            }
            index++;
        }
        while(part1<=mid)
            sol[index++]=val[part1++];
        while(part2<=end)
            sol[index++]=val[part2++];
        for(int i=start;i<=end;i++){
            val[i]=sol[i];
        }
    }
    void start_sort(){
        merge(0,N-1);
        std::cout << result ;
    }

};
int main(){
    merge_sort ms;
    ms.start_sort();

    return 0;
}