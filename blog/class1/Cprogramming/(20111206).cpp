#include <stdio.h>
#include <stdlib.h>

int main(){
  int a = 20;
  int b = 0;
  int c = 1;
  
  for(c;c<=10;c++){
    printf("�п�J�ƭ�:\n");
    scanf("%d",&b);
    if(b == a){
      printf("\n!!!!!!!!!!!!!!\n!!!!�q���P!!!!\n!!!!!!!!!!!!!!\n\n"); 
      break;
    }
  }
  
  if(c == 11){
    printf("\n~~~~~~����~~~~~~\n\n");
  }
  
  system("pause");
  return 0;
}
