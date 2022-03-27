#include <iostream>
#include <vector>
using namespace std;
class ureca{
private:
    vector<bool> triangle;
public:
    ureca(){
        triangle.resize(1001,false);
        set_val();
    }
    void set_val(){
        int tmp;
        for(int i=1;i<45;i++){
            for(int j=1;j<45;j++){
                for(int l=1;l<45;l++){
                    tmp = i*(i+1)/2+j*(j+1)/2+l*(l+1)/2;
                    if(tmp<=1000)
                        triangle[tmp]=true;    
                }
            }
        }
    }
    int find_ureca(int a){
        if(triangle[a])
            return 1;
        return 0;
    }
};
int main(){
    ureca uc;
    int n,a;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> a ;
        std::cout << uc.find_ureca(a)<< '\n';
    }

    return 0;
}