#include<stdio.h>
#include<stdlib.h>

int main(){
    int s1,s2,s3,sel;
    char a1,a2,a3;
A:
Ch:
printf("���п�J��妨�Z\n");
scanf("%d",&s1);
if(s1<0 || s1>100){
        printf("!!!�A�������Ƥ����T�A�ЦA��J�@��!!!\n");
        goto Ch;
        }
En:
printf("���п�J�^�妨�Z\n");
scanf("%d",&s2);
if(s2<0 || s2>100){
        printf("!!!�A���^����Ƥ����T�A�ЦA��J�@��!!!\n");
        goto En;
        }
Ma:
printf("���п�J�ƾǦ��Z\n");
scanf("%d",&s3);
if(s3<0 || s3>100){
        printf("!!!�A���ƾǤ��Ƥ����T�A�ЦA��J�@��!!!\n");
        goto Ma;
        }

printf("�A��J�����Z���O�O=>���:%d �^��:%d �ƾ�:%d\n",s1,s2,s3);
printf("�������T�п�J1�A���~�п�J2����\n");
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
         
printf("�A��\n�����Ƭ�:%c\n�^����Ƭ�:%c\n�ƾǤ��Ƭ�:%c\n\n",a1,a2,a3);
printf("�z--------�{\n�xA=100~90�x\n�xB= 89~80�x\n�xC= 79~70�x\n�xD= 69~60�x\n�xE= 59~0 �x\n�|--------�}\n");

system("pause");
return 0;
}
