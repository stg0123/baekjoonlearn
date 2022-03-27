#include <iostream>
#include <vector>
#include <map>
using namespace std;
struct _node{
    string parent;
    int size_of_set;
};
class set_size{
private:
    map<string,_node> graph; 
    int M;
public:
    set_size(){
        std::cin >> M;
    }
    void start(){
        string str1,str2;
        for(int i=0;i<M;i++){
            std::cin >> str1 >> str2;
            merge(str1,str2);
        }

    }
    string find(const string& str){
        if(graph[str].parent=="root")
            return str;
        return graph[str].parent=find(graph[str].parent);
    }
    void merge(const string& str1,const string& str2){
        if(graph[str1].parent.size()==0)
            graph[str1]={"root",1};
        if(graph[str2].parent.size()==0)
            graph[str2]={"root",1};
        string p_str1=find(str1);
        string p_str2=find(str2);
        if(p_str1==p_str2){
            std::cout << graph[p_str1].size_of_set<<'\n';
            return ;
        }
        graph[p_str2].parent=p_str1;
        graph[p_str1].size_of_set+=graph[p_str2].size_of_set;
        std::cout << graph[p_str1].size_of_set<<'\n';
        
    }


};
int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++){
        set_size set;
        set.start();

    }

    return 0;
}