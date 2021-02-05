#include <iostream>
#include <vector>
using namespace std;
struct _node{
    int edge_num;
    bool live;
    _node* edge[26];
};
class phone_dic{
private:
    _node* root;
    vector<string> str;
    int N;
public:
    phone_dic(int n):N(n){
        root=new _node({0,false,});
        str.resize(N);
        set_val();
    }
    ~phone_dic(){
        free_all(root);
    }
    void free_all(_node* cur){
        if(!cur)
            return ;
        for(int i=0;i<26;i++){
            free_all(cur->edge[i]);
        }
        delete(cur);
    }
    void set_val(){
        for(int i=0;i<N;i++){
            std::cin >> str[i];
            insert_trie(str[i]);
        }
    }
    void insert_trie(string& s){
        _node* tmp=root;
        for(int i=0;i<s.length();i++){
            if(!(tmp->edge[s[i]-97])){
                tmp->edge_num++;
                tmp->edge[s[i]-97]=new _node({0,false,});
            }
            tmp=tmp->edge[s[i]-97];
        }
        tmp->live=true;
    }
    void start_find(){
        root->edge_num=0;
        double sol=0;
        for(int i=0;i<str.size();i++){
            sol+=find_trie(str[i]);
        }
        cout<<fixed;
        cout.precision(2);
        std::cout << (double)sol/str.size()<<'\n';
    }
    int find_trie(string s){
        _node* tmp=root;
        int sol=s.length();
        for(int i=0;i<s.length();i++){
            if(tmp->edge_num==1){
                if(!(tmp->live))
                    sol--;
            }
            tmp=tmp->edge[s[i]-97];
        }
        return sol;
    }

};
int main(){
    int n;
    while(1){
        std::cin >> n;
        if(cin.eof()==true)
            break;
        phone_dic pd(n);
        pd.start_find();
        
    }
    return 0;
}