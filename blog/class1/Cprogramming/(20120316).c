#include <stdio.h>
#include <stdlib.h>

int cal_1(int,int);
int cal_2(int,int,int);

int cal_1(int x,int y){
    if(x == 1){
      printf("%d = %d\n\n",x,y);
    }else{
      printf("%d*",x);
      y *= x;
      x -= 1;
      cal_1(x,y);
    }
}
int cal_2(int i,int j,int k){
    if(i == 1){
      printf("%d = %d\n\n",j,k);
    }else{
      printf("%d*",j);
      k *= j;
      i -= 1;
      cal_2(i,j,k);
    }
}

int main(){
    int num_1 = 0,Acal_1 = 1;
    int num_2 = 0,Acal_2 = 1;
    
    printf("STEP 1:(����)\n");
    printf("�п�J 1 ~ 10 ���Ʀr: ");
    scanf("%d",&num_1);
    printf("Ans :  ");
    cal_1(num_1,Acal_1);
    
    printf("STEP 2:(����)\n");
    printf("�п�J����: ");
    scanf("%d",&num_2);
    printf("Ans :  ");
    cal_2(num_2,num_2,(num_2 * Acal_2));
    
    printf("\n\n");
    system("pause");
    return 0;
}
