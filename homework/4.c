#include <stdio.h>
#include <stdlib.h>

int lower_bound(int* tail,int len,int x) {
    int left=0,right=len;
    while (left<right) {
        int mid=left+(right-left)/2;
        if (tail[mid]<x){
            left=mid+1;
        } else{
            right=mid;
        }
    }
    return left;
}

int main(){
    int nums[2505],tail[2505];
    int n=0;
    
    while(scanf("%d", &nums[n]) == 1) {
        n++;
    }
    int len=0;
    for(int i=0;i<n;i++) {
        int pos=lower_bound(tail,len,nums[i]);
        tail[pos] = nums[i];
        if (pos==len) {
            len++;
        }
    }
    printf("%d\n",len);
    return 0;
}