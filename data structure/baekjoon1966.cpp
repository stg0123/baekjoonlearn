#include <iostream>
#include <queue>
#include <vector>
//2:24
using namespace std;
class printer{
private:
    vector<pair<int,int>> paper;
    int N,front;
public:
    printer(int n):N(n){
        
    };
    void set_paper(){
        pair<int,int> tmp;
        int a;
        for(int i=0;i<N;i++){
            std::cin >>a;
            tmp.first=i;
            tmp.second=a;
            paper.push_back(tmp);
        }
        front=0;
    };
    void print_paper(){
        for(int i=0;i<paper.size();i++)
            std::cout << paper[i].first <<','<< paper[i].second << ' ';
        std::cout <<'\n';
    };
    void findk(int k){
        int a,count=0;
        bool flag =false;
        while(1){
            a=paper[front].second;
            flag=false;
            for(int i=front;i<paper.size();i++){
                if(paper[i].second>a){
                    paper.push_back(paper[front]);
                    front++;
                    flag=true;
                    break;
                }
            }
            if(flag==false){
                count++;
                if(paper[front].first==k)
                    break;
                front++;
            }
        }
        std::cout << count << '\n';
    };

};
int main(){
    int n,m,k;
    std::cin >> n;
    for(int i=0;i<n;i++){
        std::cin >> m>>k;
        printer p(m);
        p.set_paper();
        p.findk(k);
    }
    return 0;
}