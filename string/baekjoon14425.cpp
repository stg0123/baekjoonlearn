#include <iostream>
#include <vector>
using namespace std;
struct _node{
    bool live;
    _node* edge[26];
};
class TRIE{
private:
    _node* root;
    int N,M;
public:
    TRIE(){
        root=new _node;
        std::cin >> N>>M;
        set_val();
    }
    void set_val(){
        string str;
        for(int i=0;i<N;i++){
            std::cin >> str;
            insert_trie(str);
        }
    }
    void insert_trie(string& s){
        _node* tmp=root;
        for(int i=0;i<s.length();i++){
            if(!(tmp->edge[s[i]-97]))
                tmp->edge[s[i]-97]=new _node({false,});
            tmp=tmp->edge[s[i]-97];
        }
        tmp->live=true;
    }
    void start_check(){
        string str;
        int sol=0;
        for(int i=0;i<M;i++){
            std::cin >>str;
            if(check(str))
                sol++;
        }
        std::cout << sol;

    }

    bool check(string& s){
        _node* tmp=root;
        for(int i=0;i<s.length();i++){
            if(!(tmp->edge[s[i]-97]))
                return false;
            tmp=tmp->edge[s[i]-97];
        }
        if(tmp->live)
            return true;
        else
            return false;
    }

};
int main(){
    TRIE tr;
    tr.start_check();
    return 0;
}