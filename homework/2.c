#include <stdio.h>
int main() {
    int n,m,a,b;
    scanf("%d %d %d %d",&n,&m,&a,&b);
    int min=n*a;
    for(int i=0;i<=n/m; i++){
        int remain=n-i*m;
        if(remain<0)remain=0;
        int judge=i*b+remain*a;
        if(judge<min){
            min=judge;
        }
    }
    int k=n/m+1;
    int judge=k*b;
    if(judge<min){
        min=judge;
    
    printf("%d",min);
    return 0;
}