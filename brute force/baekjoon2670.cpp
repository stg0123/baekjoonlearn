#include <iostream>
#include <vector>
using namespace std;
class contSubMaxMul{
private:
    vector<double> arr;
    int N;
    double MaxVal=0;
public:
    contSubMaxMul(){
        std::cin >> N;
        arr.resize(N);
        setVal();
    }
    void setVal(){
        for(int i=0;i<N;i++){
            std::cin >> arr[i];
            MaxVal = max(MaxVal, arr[i]);
        }
    }
    void findSol(){
        for(int i=1;i<N;i++ ){
            arr[i] = max(arr[i], arr[i]*arr[i-1]);
            MaxVal = max(MaxVal, arr[i]);
        }

        std::cout << fixed;
        cout.precision(3);
        std::cout << MaxVal <<'\n';
    }  
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    contSubMaxMul cSMM;
    cSMM.findSol();
    return 0;
}