#include <stdio.h>
#include <stdlib.h>

void hanoi(int,int,int,int);
int t=1;

int main(){
    int j;
    printf("請輸入盤子數量: ");
    scanf("%d",&j);
    hanoi(j,1,2,3);
    
    printf("\n\n");
    system("pause");
    return 0;
}

void hanoi(int n,int p1,int p2,int p3){
    if(n==1){
      printf("第 %d 個盤子從 %d 移到 %d\t\t第 %d 次移動\n",n,p1,p3,t);
      t+=1;
    }else{
      hanoi(n-1,p1,p3,p2);
      printf("第 %d 個盤子從 %d 移到 %d\t\t第 %d 次移動\n",n,p1,p3,t);t+=1;
      hanoi(n-1,p2,p1,p3);
    }
}
