#include<stdio.h>
#include<stdlib.h>

int main(){
    
    A:
    int A = 0;int B = 0;int C = 0;
    int sum1 = 0;int sum2 = 0;
    char max = '0';char min = '0';char cen = '0';
    int select = 0;
    
    printf("**==�п�J�T�Ӥ��۵������==**\n");
    printf("�п�J�Ĥ@�Ӽ�A:\n");
    scanf("%d",&A);
    printf("�п�J�ĤG�Ӽ�B:\n");
    scanf("%d",&B);
    printf("�п�J�ĤT�Ӽ�C:\n");
    scanf("%d",&C);
    printf("�A��J���T�ӼƤ��O��:\tA:%d  B:%d  C:%d\n\n",A,B,C);
    
    sum1 = A+B+C;
    printf("�Ĥ@�D<<�T�Ƭۥ[>>\n\tA+B+C=%d\n",sum1);
    
    sum2 = sum1/3;
    printf("�ĤG�D<<������>>\n\t������=%d\n",sum2);
    
    if(A>B && A>C){
            if(B>C){
                    max = 'A';
                    cen = 'B';
                    min = 'C';
                    }
            if(C>B){
                    max = 'A';
                    cen = 'C';
                    min = 'B';
                    }
            }
    if(B>A && B>C){
           if(A>C){
                   max = 'B';
                   cen = 'A';
                   min = 'C';
                   }
           if(C>A){
                   max = 'B';
                   cen = 'C';
                   min = 'A';
                   }
           }
    if(C>A && C>B){
           if(A>B){
                   max = 'C';
                   cen = 'A';
                   min = 'B';
                   }
           if(B>A){
                   max = 'C';
                   cen = 'B';
                   min = 'A';
                   }
           }
    printf("�ĤT�D<<��j�p>>\n\t %c<%c<%c\n\t %c>%c>%c\n",min,cen,max,max,cen,min);
    
    printf("�����ӽп�J1~���}�п�J2��\n");
    scanf("%d",&select);
    if(select==1){
                 goto A;
                 }
    if(select==2){
                  goto B;
                  }
    
    B:
    system("pause");
    return 0;
    }
