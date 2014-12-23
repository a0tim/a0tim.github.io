#include <stdio.h>
#include <stdlib.h>
//此程式來自...黃騰嶢... 
void cal_1(int,int);
void cal_2(int,int);
int B = 0;

void cal_1(int x,int y){
    if(x==0){
      B = y;
      printf("%d\n",y);
    }else if(y==0){
      B = x;
      printf("%d\n",x);
    }else{
      if(x>y){
        x = x % y;
      }else{
        y = y % x;
      }
      cal_1(x,y);
    }
}
void cal_2(int x,int y){
    int temp = 0;
    temp = x * y / B;
    printf("%d\n",temp);
}

int main(){
    int a = 0,b = 0;
    int B = 0;
    
    printf("請輸入兩數 A , B :");
    scanf("%d %d",&a,&b);
    printf("兩數最大公因數為: ");
    cal_1(a,b);
    printf("兩數最小公倍數為: ");
    cal_2(a,b);
    
    printf("\n\n");
    printf("\n\n....程式設計→黃騰嶢--請勿轉烤！！！");
    system("pause");
    return 0;
}
