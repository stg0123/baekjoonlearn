#include <iostream>
#include <vector>
using namespace std;
class star{
private:
    int N;
public:
    star(){
        std::cin >> N;
    }
    void makestar(){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(i==0 || i==N-1 || j==0 || j==N-1 || j==i || j== (N-1-i))
                    std::cout << '*';
                else
                    std::cout << ' ';
            }
            std::cout << '\n';
        }
    }
};
int main(){
    star st;
    st.makestar();
    return 0;
}