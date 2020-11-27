#include <stdio.h>

int main(){
    int a=0,b=0;
    scanf("%d %d",&a,&b);
    if(b>=45){
        b=b-45;
    }
    else if(a==0){
        a=23;
        b=b+15;
    }
    else{
        --a;
        b=b+15;
    }
    printf("%d %d",a,b);
    
    return 0;
}