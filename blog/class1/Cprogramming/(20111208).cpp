#include <stdio.h>
#include <stdlib.h>

int main(void){
  int i,j;
  
  printf("倒過來的期中考= =\n\n");
  
  for(i=9;i>=3;i-=3){
    printf("%d\t%d\t%d\n",i,i-1,i-2);
    printf("------\t------\t------\n");
    for(j=9;j>=1;j--){
      printf("%d*%d=%d\t%d*%d=%d\t%d*%d=%d\n",i,j,i*j,i-1,j,(i-1)*j,i-2,j,(i-2)*j);
    }
    printf("\n");
  }

  printf("\n程式END\n");
  system("pause");
  return 0;
}
