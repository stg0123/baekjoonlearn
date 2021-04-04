#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class editor{
private:
    stack<char> left,right;
    int N;
public:
    editor(){
        string str;
        std::cin >> str;
        for(int i=0;i<str.size();i++)
            left.push(str[i]);    
        std::cin >> N;
    }
    void start_query(){
        char ch,a;
        for(int i=0;i<N;i++){
            std::cin >> ch;
            if(ch=='L'){
                if(left.empty())
                    continue; 
                right.push(left.top());
                left.pop();
            }
            else if(ch=='D'){
                if(right.empty())
                    continue;
                left.push(right.top());
                right.pop();
            }
            else if(ch=='B'){
                if(left.empty())
                    continue ;
                left.pop();
            }
            else if(ch=='P'){
                std::cin >> ch;
                left.push(ch);
            }
        }
        while(!left.empty()){
            right.push(left.top());
            left.pop();
        }
        while(!right.empty()){
            std::cout << right.top();
            right.pop();
        }
    }
};
int main(){
    editor ed;
    ed.start_query();
    return 0;    
}