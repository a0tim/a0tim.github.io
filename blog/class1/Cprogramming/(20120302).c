#include <stdio.h>
#include <stdlib.h>

void swap(int *i,int *j){
   int temp;
   temp = *i;
   *i = *j;
   *j = temp;
}

int main(){
   int num[5]={0};
   int a=0,b=0;
   printf("請輸入5個數: ");
   for(a=0;a<5;a++){
      scanf("%d",&num[a]);
   }
   for(a=0;a<5;a++){
     for(b=0;b<5;b++){
       if(num[b] > num[b+1]){
         swap(&num[b],&num[b+1]);
       }
     }
   }
   printf("\n");
   for(a=0;a<5;a++){
     printf("%d ,",num[a]);
   }
   printf("\n\n");
   system("pause");
   return 0;
}
