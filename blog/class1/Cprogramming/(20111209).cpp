#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

int main(){
  int i,j;
  char a[10];
  
  for(i=1;i<10;i++){
    printf("\ninput a[%d]:",i);
    a[i] = getch();
    putch(a[i]);
  }
  
  puts("\n");
  
  for(i=1;i<10;i++){
    printf("%c",a[i]);
  }
  
  printf("\n\nEND\n");
  system("Pause");
  return 0;
}
