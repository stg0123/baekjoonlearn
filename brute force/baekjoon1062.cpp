#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class teach{
private:
    vector<int> words;
    int N,K;
public:
    teach(){
        std::cin >> N >> K;
        set_val();
    }
    void set_val(){
        string str;
        for(int i=0;i<N;i++){ // a c i n t  제외
            std::cin >> str;
            int w=0;
            for(int j=0;j<str.size();j++){
                if(str[j]>'t')
                    w|=(1<<(str[j]-97-5));
                else if(str[j]>'n' && str[j]<'t')
                    w|=(1<<(str[j]-97-4));
                else if(str[j]>'i' && str[j]<'n')
                    w|=(1<<(str[j]-97-3));
                else if(str[j]>'c' && str[j]<'i')
                    w|=(1<<(str[j]-97-2));
                else if(str[j]>'a' && str[j]<'c')
                    w|=(1<<(str[j]-97-1));
                else
                    continue ;              
            }
            words.push_back(w);
        }
    }
    int check(int learn){
        int sol=0;
        for(int i=0;i<N;i++){
            if((words[i]&learn)==words[i])
                sol++;
        }
        return sol;

    }
    void find_sol(){
        vector<bool> teaching(21,false);
        if(K<5){
            std::cout << 0 << '\n';
            return ;
        }
        for(int i=0;i<K-5;i++)
            teaching[i]=true;
        int sol=0;
        do{
            int learn=0;
            for(int i=0;i<21;i++){
                if(teaching[i])
                    learn |=(1<<i);
            }
            sol=max(sol,check(learn));

        }while(prev_permutation(teaching.begin(),teaching.end()));
        std::cout << sol << '\n';
    }
    

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    teach t;
    t.find_sol();   
    return 0;
}