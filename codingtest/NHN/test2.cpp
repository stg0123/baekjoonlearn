#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class test2{
private:
    unordered_map<int,int> frequencyCount;
    int N,K;
public:
    test2(int n,int k,int * numOfFrequenciesInRegion,int ** frequencies):N(n),K(k){
        for(int i=0;i<n;i++){
            for(int j=0;j<numOfFrequenciesInRegion[i];j++){
                frequencyCount[frequencies[i][j]]++;
            }
        }
    }
    
    void find_sol(){
        vector<bool> attack(20,false);
        for(int i=0;i<K;i++)
            attack[i]=true;
        int sol=0;
        do{
            int sum=0;
            for(int i=0;i<20;i++){
                if(attack[i])
                    sum+=frequencyCount[i+1];
            }
            sol=max(sol,sum);
        }while(prev_permutation(attack.begin(),attack.end()));

        std::cout << sol;
    }


};
