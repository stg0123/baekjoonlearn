#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct _node{
    int data;
    int x,y,z;
};
bool compare_x(_node& a,_node& b){
    return a.x<b.x;
};
bool compare_y(_node& a,_node& b){
    return a.y<b.y;
};
bool compare_z(_node& a,_node& b){
    return a.z<b.z;
};
struct point_info{
    int a,b;
    int dis;
};
bool compare_info(point_info& a,point_info& b){
    return a.dis<b.dis;
};
class ternel{
private:
    vector<_node> node;
    vector<int> parent;
    vector<point_info> info;  
    int N;
    long long sol;
public:
    ternel(){
        std::cin >> N;
        parent.resize(N,-1);
        sol=0;
        set_val();
    }
    int find(int n){
        if(parent[n]<0)
            return n;
        return parent[n]=find(parent[n]);
    }
    void merge(int a,int b,int dis){
        int p_a=find(a);
        int p_b=find(b);
        if(p_a==p_b)
            return ;
        parent[p_b]=p_a;
        sol+=dis;
    }
    int distance(_node& a,_node& b){
        int dis=min(abs(a.x-b.x),abs(a.y-b.y));
        dis=min(dis,abs(a.z-b.z));
        return dis;
    }
    void set_val(){
        int x,y,z;
        for(int i=0;i<N;i++){
            std::cin >> x >> y >> z;
            node.push_back({i,x,y,z});
        }
        sort(node.begin(),node.end(),compare_x);
        for(int i=0;i<N-1;i++)
            info.push_back({node[i].data,node[i+1].data,distance(node[i],node[i+1])});
        
        sort(node.begin(),node.end(),compare_y);
        for(int i=0;i<N-1;i++)
            info.push_back({node[i].data,node[i+1].data,distance(node[i],node[i+1])});

        sort(node.begin(),node.end(),compare_z);
        for(int i=0;i<N-1;i++)
            info.push_back({node[i].data,node[i+1].data,distance(node[i],node[i+1])});
        
        sort(info.begin(),info.end(),compare_info);
    }

    void cruscal(){
        for(int i=0;i<info.size();i++){
            merge(info[i].a,info[i].b,info[i].dis);
        }
        std::cout << sol << '\n';
    }


};
int main(){

    ternel tr;
    tr.cruscal();

    return 0;
}