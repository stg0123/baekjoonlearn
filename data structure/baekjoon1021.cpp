#include <iostream>
#include <deque>

using namespace std;


void shift_L(deque<int>& dq,int& count){
    int tmp;
    tmp=dq.front();
    dq.pop_front();
    dq.push_back(tmp);
    count+=1;
};
void shift_R(deque<int>&dq,int& count){
    int tmp;
    tmp=dq.back();
    dq.pop_back();
    dq.push_front(tmp);
    count+=1;
};
bool compare(deque<int> dq,int k){//true면 왼쪽이빠르고 false면 오른쪽이빠르다
    int count=0;
    
    while(1){
        if(dq.front()==k)
           break;
        count++;
        dq.pop_front();
    }
    return dq.size()>count;
};



int main(){
    int n,m,count=0;
    std::cin >> n>>m;
    deque<int> dq;
    int drop[m];
    for(int i=0;i<n;i++)
        dq.push_back(i+1);

    for(int i=0;i<m;i++)
        std:: cin>>drop[i];
    
    for(int i=0;i<m;i++){
        if(drop[i]==dq.front()){
            dq.pop_front();
            continue;
        }
        if(compare(dq,drop[i])){
            for(int j=0;j<n;j++){
                shift_L(dq,count);
                if(dq.front()==drop[i]){
                    dq.pop_front();
                    break;
                }
            }
        }
        else{
            for(int j=0;j<n;j++){
                shift_R(dq,count);
                if(dq.front()==drop[i]){
                    dq.pop_front();
                    break;
                }
            }    
        }
    }
    std::cout << count;
    return 0;
}