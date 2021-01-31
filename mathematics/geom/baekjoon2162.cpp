#include <iostream>
#include <vector>
using namespace std;
struct _node{
    int parent;
    int group_sum;
    pair<int,int> p1,p2;
};
class line_group{
private:
    vector<_node> line;
    int N,group_num;
    int sol_max;
public:
    line_group(){
        std::cin >> N;
        group_num=N;
        line.resize(N,{-1,1});
        sol_max=1;
        set_val();
    }
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >> line[i].p1.first >> line[i].p1.second;
            std::cin >> line[i].p2.first >> line[i].p2.second;
        }
    }
    int find(int n){
        if(line[n].parent<0)
            return n;
        return line[n].parent=find(line[n].parent);
    }
    void merge(int a,int b){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return ;
        
        line[p_b].parent=p_a;
        line[p_a].group_sum+=line[p_b].group_sum;
        if(line[p_a].group_sum>sol_max)
            sol_max=line[p_a].group_sum;
        group_num--;
    }

    int CCW(pair<int,int>& a,pair<int,int>& b,pair<int,int>& c){
        int tmp =(a.first*b.second-a.second*b.first)+(b.first*c.second-b.second*c.first)+(c.first*a.second-c.second*a.first);
        if(tmp>0)
            return 1;
        else if(tmp<0)
            return -1;
        else if(tmp==0)
            return 0;
    }

    bool line_cross(_node& a,_node& b){
        int s1=CCW(a.p1,a.p2,b.p1)*CCW(a.p1,a.p2,b.p2);
        int s2=CCW(b.p1,b.p2,a.p1)*CCW(b.p1,b.p2,a.p2);
        if(s1==0 && s2==0){
            if(a.p1>a.p2)
                swap(a.p1,a.p2);
            if(b.p1>b.p2)
                swap(b.p1,b.p2);
            
            if(b.p1<=a.p2 && a.p1<=b.p2)
                return true;
            else
                return false;
        }
        else if(s1<=0&&s2<=0)
            return true;
        else
            return false;
    
    }
    void find_cross(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(line_cross(line[i],line[j]))
                    merge(i,j);
            }
        }
        std::cout << group_num << '\n' << sol_max;
    }

};
int main(){
    line_group lg;
    lg.find_cross();
    return 0;
}