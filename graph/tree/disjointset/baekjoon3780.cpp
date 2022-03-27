#include <iostream>
#include <vector>
using namespace std;
int mod=1000;
struct _node{
    int parent=-1;
    int dis=0;
};
class network{
private:
    vector<_node> Set;
    int N;
public:
    network(){
        std::cin >> N;
        Set.resize(N+1);
    }
    int find(int a){
        if(Set[a].parent==-1)
            return a;
        int tmp=find(Set[a].parent);
        Set[a].dis+=Set[Set[a].parent].dis;
        return Set[a].parent=tmp;
    };
    void merge(int a,int b){
        Set[a].dis = abs(a-b)%mod;
        Set[a].parent=b;
    };
    void query(){
        char q;
        int a,b;
        while(1){
            std::cin >> q;
            if(q == 'E'){
                std::cin >> a;
                find(a);
                std::cout << Set[a].dis << '\n';
            }
            else if(q == 'I'){
                std::cin >> a >> b;
                merge(a,b);
            }
            else
                break;
        }
    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        network nt;
        nt.query();
    }
    return 0;
}