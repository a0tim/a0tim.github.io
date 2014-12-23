#include <stdio.h>
#include <stdlib.h>

int main(){
  int a[5];
  int b[5]={0,10,20,30,40};
  int i = 0;
  
  printf("陣列a內的值:\n");
  for(i=0;i<5;i++){
    printf("a[%d] = %d\n",i,a[i]);
  }
  
  printf("\n陣列b內的值:\n");
  for(i=0;i<5;i++){
    printf("b[%d] = %d\n",i,b[i]);
  }

  printf("\n請將數值指定給陣列a:\n");
  for(i=0;i<5;i++){
    printf("a[%d] = ",i);
    scanf("%d",&a[i]);
  }

  printf("\n陣列a內的值:\n");
  for(i=0;i<5;i++){
    printf("a[%d] = %d\n",i,a[i]);
  }
  
  printf("\n");
  system("pause");
  return 0;
}
