#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
vector<int> solution(vector<string> &S) {
    for(int j=0;j<S[0].size();j++){
        unordered_map<char,int> um;
        for(int i=0;i<S.size();i++){
            if(um.find(S[i][j])!=um.end())
                return {um[S[i][j]],i,j};
            else
                um[S[i][j]]=i;
        }
    }
    return {};

}
