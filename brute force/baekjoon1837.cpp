#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
class Cryption{
private:
    string crypt;
    int K;
    vector<bool> primeTable;
public:
    Cryption(){
        std::cin >> crypt  >> K ;
        primeTable.resize(K,true);
    }
    void findSol(){
        for(int i=2;i<K;i++){
            if(!primeTable[i])
                continue;
            if(isModuler(i)){
                std::cout << "BAD "<< i << '\n';
                return ;
            }
            for(int j=i*2; j<K; j+=i)
                primeTable[j]=false;
        }
        std::cout << "GOOD\n";
    }
    bool isModuler(int n){
        int sum =0;
        for(int i=0;i<crypt.size();i++)
            sum = (sum*10+(crypt[i]-'0'))%n;
        if(sum)
            return false;
        return true;

    }
};
int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    Cryption cp;
    cp.findSol();

    return 0;
}