#include <stdio.h>
#include <stdlib.h>

int main(){
  int a = 20;
  int b = 0;
  int c = 1;
  
  for(c;c<=10;c++){
    printf("請輸入數值:\n");
    scanf("%d",&b);
    if(b == a){
      printf("\n!!!!!!!!!!!!!!\n!!!!猜中嚕!!!!\n!!!!!!!!!!!!!!\n\n"); 
      break;
    }
  }
  
  if(c == 11){
    printf("\n~~~~~~失敗~~~~~~\n\n");
  }
  
  system("pause");
  return 0;
}
