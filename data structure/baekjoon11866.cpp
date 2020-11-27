#include <iostream>
#include <queue>

using namespace std;
class yo{
private:
    vector<int> arr;
    int N;
public:
    yo(int n):N(n){
        arr.resize(n);
        for(int i=0;i<n;i++)
            arr[i]=i+1; 
    };
    void print_k(int k){
        int a=-1,count=0;
        std::cout << '<';
        while(1){
            for(int i=0;i<k;i++){
                while(1){
                    a++;
                    a%=N;
                    if(arr[a]!=0)
                        break;
                }   
            }
            std::cout << arr[a];
            arr[a]=0;
            count++;
            if(count==N)
                break;
            std::cout <<", ";
        }
        std::cout<<'>';
    }
};
int main(){
    int n,k;
    std::cin >> n >> k;
    yo y(n);
    y.print_k(k);  

}