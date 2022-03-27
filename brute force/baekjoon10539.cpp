#include <iostream>
using namespace std;
class subin{
private:
    int N;
public:
    subin(){
        std::cin >> N;
    }
    void find_sol(){
        int tmp,least=0;
        for(int i=1;i<=N;i++){
            std::cin >> tmp;
            std::cout << tmp*i-least<< ' ';
            least=tmp*i;
        }
    }


};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    subin sb;
    sb.find_sol();    


    return 0;
}