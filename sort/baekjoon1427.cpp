#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(char a,char b){
    return a>b;
};
int main(){
    string str;
    std::cin >> str;

    sort(str.begin(),str.end(),compare);
    
    std::cout <<str;


    return 0;
}