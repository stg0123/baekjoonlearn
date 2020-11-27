#include <iostream>
#include <queue>

using namespace std;
int main(){
    int n,a;
    std::cin >> n;
    queue<int> card;
    for(int i=0;i<n;i++)
        card.push(i+1);
    
    while(1){
        if(card.size()==1)
            break;
        card.pop();
        a=card.front();
        card.pop();
        card.push(a);
    }
    std::cout << card.front()<<'\n';
    
    return 0;
}