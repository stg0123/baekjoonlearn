#include <iostream>

using namespace std;
void move(int a,int b,int n);
void move2(int a,int b);
int hanoi_c(int n);

void move(int a,int b,int n){
    int c=3;
    if((a+b)==4)
        c=2;
    else if((a+b)==5)
        c=1;
    if(n==1){
        std::cout<< a << ' '<< b << '\n';
        return ;
    }
    else if(n==2){
        move2(a,b);
        return ;
    }
    else if(n==3){
        move2(a,c);
        std::cout<< a << ' '<< b << '\n';
        move2(c,b);
        return ;
    }
    else{
        move(a,c,n-1);
        std::cout << a << ' '<< b << '\n';
        move(c,b,n-1);
        return ;
    } 
    

};
void move2(int a,int b){
    int c=3;
    if((a+b)==4)
        c=2;
    else if((a+b)==5)
        c=1;
    
    std::cout << a << ' ' << c << '\n';
    std::cout << a << ' ' << b << '\n';
    std::cout << c << ' ' << b << '\n';
    return ;
};
int hanoi_c(int n){
    if(n==3)
        return 7;
    else
        return hanoi_c(n-1)*2+1;


};


int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL); 
    int n;
    std::cin >> n;
    if(n==1)
        std::cout << "1\n";
    else if(n==2)
        std::cout << "3\n";
    else
        std::cout << hanoi_c(n)<< '\n';
    move(1,3,n);

    return 0;
}