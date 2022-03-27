#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
using namespace std;

typedef struct meeting{
    long long start,end;
}meeting;

bool compare1(meeting a,meeting b){
    if(a.start==b.start)
        return a.end<b.end;
    else
        return a.start<b.start;
};

int min_cal(meeting* m,int idx,int n){
       // std::cout <<" sol = "<< m[i].start << " ," << m[i].end << '\n';
    long long tmp = 0xffffffff,next=-1;
    if(idx==-1){
        for(int i=0;i<n;i++){
            if(tmp>m[i].end){
                tmp=m[i].end;
                next=i;
            }
            if(m[i].start>tmp)
                break;
        }
        return next;     
    }
    long long started=m[idx].end;
    for(int i=idx+1;i<n;i++){
        if(started<=m[i].start&&m[i].end-m[idx].end<tmp){
            tmp=m[i].end-m[idx].end;
            next=i;
        }
        if(tmp<m[i].start-m[idx].end)
            break;
    }
    return next;
};
int main(){
    int n,start=0,sol=1;
    std::cin >> n;
    meeting mt[n];

    for(int i=0;i<n;i++){
        std::cin >>mt[i].start >> mt[i].end;
    }
    std::sort(mt,&mt[n],compare1);
    start=min_cal(mt,-1,n);
    for(int i=0;i<n;i++){
        start=min_cal(mt,start,n);
        if(start==-1)
            break;
        sol++;
    }
    std::cout << sol;     
    return 0;
}