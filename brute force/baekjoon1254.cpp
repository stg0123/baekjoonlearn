#include <iostream>
#include <vector>
using namespace std;
class Palindrome{
private:
    string str;
public:
    Palindrome(){
        std::cin >> str;
    }

    void find_sol(){
        int sol=0;
        for(int i=0;i<str.size();i++){
            int start = i, end = str.size()-1;
            while(1){
                if(str[start]==str[end]){
                    start++;
                    end--;
                }
                else
                    break;
                if(start>=end){
                    std::cout << str.size()+i <<'\n';
                    return ;
                }
            }
        }
    }

};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    Palindrome pd;
    pd.find_sol();

    return 0;
}