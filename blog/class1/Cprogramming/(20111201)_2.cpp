#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>

int main(void){
  int h,m,s,x,y=1;

  for(h=0;h<24;h++){
    for(m=0;m<60;m++){
      for(s=0;s<60;s++){
        for(x=0;x<100;x++){
          Sleep(10);
          printf("時間:%02d:%02d:%02d'%02d\r",h,m,s,x);
          if(kbhit()!=0){
            printf("第%d次時間:%02d:%02d:%02d'%02d\r\n",y,h,m,s,x);
            y+=1;
            getch();
          }
        }
      }
    }
  }
  
  system("pause");
  return 0;
}
