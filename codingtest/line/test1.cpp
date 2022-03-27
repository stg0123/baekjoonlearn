#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct node{
    int left=0,right=0;
};
class test1{
private:
    vector<node> student;
    vector<int> sinior;
    int K;
public:
    test1(vector<int>& s,int k):K(k){
        student.resize(s.size());
        int n=0;
        int last =0;
        for(int i=0;i<s.size();i++){
            if(s[i]){
                student[last].right=n;
                student[i].left=n;
                sinior.push_back(i);
                n=0;
                last=i;
            }
            else 
                n++;
        }
        student[last].right=n;

        for(int i=0;i<student.size();i++)
            std::cout << student[i].left << ','<<student[i].right <<'\n';
        for(int i : sinior)
            std::cout << i << ' ';
        std::cout << '\n';

    }
    int find_sol(){
        int sol=0;
        if(K>sinior.size())
            return 0;
        for(int i=0;i<=sinior.size()-K;i++)
            sol +=(student[sinior[i]].left+1)*(student[sinior[i+K-1]].right+1);
        return sol;
    }
};

int solution(vector<int> student, int k) {
    test1 t1(student,k);
    return t1.find_sol();
}
int main(){
    std::cout << solution({0,1,0,0},1)<<'\n';

    return 0;
}