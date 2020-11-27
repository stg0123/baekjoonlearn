#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(string a,string b){
    if(a.length()==b.length())
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i])
                return a[i]<b[i]; 
        } 
    return a.length()<b.length();
    
};

class wordorder{
private:
    vector<string> word;
    int N;
public :
    wordorder(int n):N(n){
        word.resize(n);
    };
    void set_word(){
        for(int i=0;i<N;i++)
            std::cin >> word[i];
    };
    void sorting(){
        int d=1;
        std::sort(word.begin(),word.end(),compare);
        std::cout << word[0]<<'\n';
        for(int i=1;i<N;i++){
            if(word[i-d]==word[i])
                d++;
            else{   
                std::cout << word[i] <<'\n';
                d=1;
            }
        }
    };

};


int main(){
    int n;
    std::cin >> n;
    wordorder wd(n);
    wd.set_word();
    wd.sorting();

    return 0;
}