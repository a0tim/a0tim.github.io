#include <stdio.h>
#include <stdlib.h>

int main(){
  int i=0,j=0;
  int a=0;
  
  printf("input~~~:");
  scanf("%d",&a);
  
  printf("\n\nANSWER IS:\n");
  
  for(j=1;j<10;j++){
    for(i=1;i<10;i++){
      if((j*i)==a-2 || (j*i)==a-1 || (j*i)==a || (j*i)==a+1 || (j*i)==a+2){
        printf("%d * %d = %d\n",j,i,(j*i));
      }
    }
  }

  system("pause");
  return 0;
}
