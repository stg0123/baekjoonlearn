#include <iostream>

using namespace std;
typedef struct dunchi{
    int kg;
    int cm;
    int grade;

}dunchi;
int main(){
    int n;
    std::cin >> n;
    dunchi *a[n];
    for(int i=0;i<n;i++){
        a[i]=new dunchi;
        std::cin >>a[i]->kg >>a[i]->cm;
        a[i]->grade =1;
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i]->kg<a[j]->kg&&a[i]->cm<a[j]->cm)
                a[i]->grade++;
        
    for(int i=0;i<n;i++)
        std::cout << a[i]->grade << ' ';
    
    return 0;
}