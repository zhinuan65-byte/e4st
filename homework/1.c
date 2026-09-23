#include <stdio.h>

int prime(int num){
    if (num <= 1)
    return 0;
    for (int i=2;i*i<=num;i++){
        if (num%i==0)
        return 0; 
    }
    return 1;
}

int main(){
    int n=0;
    scanf("%d",&n);
    for(int i=1;1;i++){
        if(i>n&&prime(i)){
            printf("%d",i);
            break;
        }
    }
    return 0;
}