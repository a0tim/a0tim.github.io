#include <stdio.h>
#include <stdlib.h>

int main(){
  int a[5];
  int b[5]={0,10,20,30,40};
  int i = 0;
  
  printf("�}�Ca������:\n");
  for(i=0;i<5;i++){
    printf("a[%d] = %d\n",i,a[i]);
  }
  
  printf("\n�}�Cb������:\n");
  for(i=0;i<5;i++){
    printf("b[%d] = %d\n",i,b[i]);
  }

  printf("\n�бN�ƭȫ��w���}�Ca:\n");
  for(i=0;i<5;i++){
    printf("a[%d] = ",i);
    scanf("%d",&a[i]);
  }

  printf("\n�}�Ca������:\n");
  for(i=0;i<5;i++){
    printf("a[%d] = %d\n",i,a[i]);
  }
  
  printf("\n");
  system("pause");
  return 0;
}
