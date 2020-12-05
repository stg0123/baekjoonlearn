#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> pita;
    pita.resize(3,0);
    while(1){
        std::cin >> pita[0]>>pita[1]>>pita[2];
        if(pita[0]==0)
            break;
        std::sort(pita.begin(),pita.end());
        if(pita[0]*pita[0]+pita[1]*pita[1]==pita[2]*pita[2])
            std::cout << "right\n";
        else
            std::cout << "wrong\n";
    }


    return 0;
}