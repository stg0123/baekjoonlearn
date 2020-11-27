#include <iostream>

using namespace std;
void room(){
    int H,W,N;
    cin >> H>>W>>N;
    int tmp_h,tmp_r;
    if(N%H==0){
        tmp_h=H;
        tmp_r=N/H;
    }
    else{
        tmp_h=N%H;
        tmp_r=N/H+1;
    }

    if(tmp_r<10)
        cout<< tmp_h <<'0'<<tmp_r<<'\n';
    else
        cout<< tmp_h <<tmp_r<<'\n';
};




int main(){
    int n;
    std::cin >> n;
    for(int i=0;i<n;i++)
        room();

    return 0;
}