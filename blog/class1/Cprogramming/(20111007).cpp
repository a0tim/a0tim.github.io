#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int num1 = 0;int num2 = 0;
    int sum1 = 0;int sum2 = 0;int sum3 = 0;int sum4 = 0;int sum5 = 0;
    int select = 0;
    
    printf("~~~~AM001871黃騰嶢--作業1~~~~\n\n");
    printf("請輸入第一個數A:\n");
    scanf("%d",&num1);
    printf("您輸入的第一個數A為:\t%d\n",num1);
    
    printf("請輸入第二個數B:\n");
    scanf("%d",&num2);
    printf("您輸入的第二個數B為:\t%d\n\n",num2);
    sum1 = num1+num2; sum2 = num1-num2; sum3 = num1*num2; sum4 = num1/num2; sum5 = num1%num2;
    
A:  printf("1.加法 2.減法 3.乘法 4.除法 5.全部顯示 6.離開\n");
    scanf("%d",&select);
    
    if(select==1){
    printf("A+B的值為:\t%d\n\n",sum1);
    }
    
    else if(select==2){    
    printf("A-B的值為:\t%d\n\n",sum2);
    }
    
    else if(select==3){    
    printf("A*B的值為:\t%d\n\n",sum3);
    }
    
    else if(select==4){    
    printf("A/B的值為:\t%d......%d\n\n",sum4,sum5);
    }
    
    else if(select==5){
    printf("A+B的值為:\t%d\nA-B的值為:\t%d\nA*B的值為:\t%d\nA/B的值為:\t%d......%d\n\n",sum1,sum2,sum3,sum4,sum5);
    }
    
    else if(select==6){
    goto B;
    }
    
    goto A;
B:  system("pause");
    return 0;
}
