#include<stdio.h>
#include<stdlib.h>

int main(){
    
    A:
    int A = 0;int B = 0;int C = 0;
    int sum1 = 0;int sum2 = 0;
    char max = '0';char min = '0';char cen = '0';
    int select = 0;
    
    printf("**==請輸入三個不相等的整數==**\n");
    printf("請輸入第一個數A:\n");
    scanf("%d",&A);
    printf("請輸入第二個數B:\n");
    scanf("%d",&B);
    printf("請輸入第三個數C:\n");
    scanf("%d",&C);
    printf("你輸入的三個數分別為:\tA:%d  B:%d  C:%d\n\n",A,B,C);
    
    sum1 = A+B+C;
    printf("第一題<<三數相加>>\n\tA+B+C=%d\n",sum1);
    
    sum2 = sum1/3;
    printf("第二題<<平均數>>\n\t平均數=%d\n",sum2);
    
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
    printf("第三題<<比大小>>\n\t %c<%c<%c\n\t %c>%c>%c\n",min,cen,max,max,cen,min);
    
    printf("◎重來請輸入1~離開請輸入2◎\n");
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
