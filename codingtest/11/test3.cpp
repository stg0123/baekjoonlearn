#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int solution(int n){
    string str = to_string(n);
    map<char,int> m;
    if(str.size()>=9)
        return -1;
    
    for(int i=0;i<str.size();i++)
        m[str[i]]++;
    str = "";
    for(pair<char,int> p : m ){
        for(int i=0;i<p.second;i++)
            str+=p.first;
    }
    reverse(str.begin(),str.end());
    return stoi(str);

}