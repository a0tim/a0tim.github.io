#include<stdio.h>
#include<stdlib.h>

int main(){
    int s1,s2,s3,sel;
    char a1,a2,a3;
A:
Ch:
printf("§請輸入國文成績\n");
scanf("%d",&s1);
if(s1<0 || s1>100){
        printf("!!!你的國文分數不正確，請再輸入一次!!!\n");
        goto Ch;
        }
En:
printf("§請輸入英文成績\n");
scanf("%d",&s2);
if(s2<0 || s2>100){
        printf("!!!你的英文分數不正確，請再輸入一次!!!\n");
        goto En;
        }
Ma:
printf("§請輸入數學成績\n");
scanf("%d",&s3);
if(s3<0 || s3>100){
        printf("!!!你的數學分數不正確，請再輸入一次!!!\n");
        goto Ma;
        }

printf("你輸入的成績分別是=>國文:%d 英文:%d 數學:%d\n",s1,s2,s3);
printf("◎◎正確請輸入1，錯誤請輸入2◎◎\n");
scanf("%d",&sel);
if(sel==1){
               goto B;
               }
if(sel==2){
               goto A;
               }

B:
if(s1<=100 && s1>=90){
           a1='A';
           }
if(s1<90 && s1>=80){
         a1='B';
         }
if(s1<80 && s1>=70){
         a1='C';
         }
if(s1<70 && s1>=60){
         a1='D';
         }
if(s1<60 && s1>=0){
         a1='E';
         }


if(s2<=100 && s2>=90){
           a2='A';
           }
if(s2<90 && s2>=80){
         a2='B';
         }
if(s2<80 && s2>=70){
         a2='C';
         }
if(s2<70 && s2>=60){
         a2='D';
         }
if(s2<60 && s2>=0){
         a2='E';
         }


if(s3<=100 && s3>=90){
           a3='A';
           }
if(s3<90 && s3>=80){
         a3='B';
         }
if(s3<80 && s3>=70){
         a3='C';
         }
if(s3<70 && s3>=60){
         a3='D';
         }
if(s3<60 && s3>=0){
         a3='E';
         }
         
printf("你的\n國文分數為:%c\n英文分數為:%c\n數學分數為:%c\n\n",a1,a2,a3);
printf("┌--------┐\n│A=100~90│\n│B= 89~80│\n│C= 79~70│\n│D= 69~60│\n│E= 59~0 │\n└--------┘\n");

system("pause");
return 0;
}
