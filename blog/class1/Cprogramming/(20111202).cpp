#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

int main(){
    int x=0;
    int h=0,m=0,s=0;
    int hs=0,ms=0,ss=0;
    
    printf("�п�J�z�Q�]�w���x���ɶ�(HH MM SS)(24�p�ɮ榡)\n");
    scanf("%d%d%d",&hs,&ms,&ss);
    printf("�z��J���x���ɶ���>>%02d:%02d:%02d\n\n",hs,ms,ss);
    
    time_t t = time(NULL);
    struct tm *tPtr = localtime(&t);
    h = tPtr->tm_mon;
    
    for(;h<24;h++){
      m = 0;
      if(x==0){
        m = tPtr->tm_min;
      }
      for(;m<60;m++){
        s = 0;
        if(x==0){
          s = tPtr->tm_sec;
        }
        for(;s<60;s++){
          if(h==hs && m==ms && s==ss){
            printf("\n\n\t====================================\n");
            printf("\t��������!!�x���]�w�ɶ���F!!��������");
            printf("\n\t====================================\n\n");
          }
          x++;
          printf("\r�m�t�ήɶ�-->%02d:%02d:%02d�n",h,m,s);
          Sleep(1000);
        }
      }
    }

    printf("\n");

    system("pause");
    return 0;
}
