#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int,int> a,pair<int,int> b){
    return a.first == b.first ? a.second < b.second : a.first < b.first;
};

class arrSort{
private:
    int N;
    vector<int> arrA;
public:
    arrSort(){
        std::cin >> N;
        arrA.resize(N);
        setVal();
    }
    void setVal(){
        for(int i=0;i<N;i++)
            std::cin >> arrA[i];
    }
    void findSol(){
        vector<pair<int,int>> sortedArr(N);
        for(int i=0;i<N;i++){
            sortedArr[i].first=arrA[i];
            sortedArr[i].second=i;
        }
        sort(sortedArr.begin(),sortedArr.end(),compare);
        vector<int> P(N);
        for(int i=0;i<N;i++)
            P[sortedArr[i].second] = i;
        for(int i : P)
            std::cout << i << ' ';
    }
};


int main(){
    cin.tie(NULL);cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    arrSort as;
    as.findSol();

    return 0;
}