#include <stdio.h>
#include <stdlib.h>

void cal(int* a,int* b,int* i,int* j,float* k,float* l);
void cal(int* a,int* b,int* i,int* j,float* k,float* l){
     *i = *a + *b;
     *j = *a - *b;
     *k = *a * *b;
     *l = (float)*a / (float)*b;
}

int main(){
    int x=0,y=0;
    int a_1 = 0,a_2 = 0;
    float a_3 = 0,a_4 = 0;
    
    printf("請輸入第一個數:");
    scanf("%d",&x);
    printf("請輸入第二個數:");
    scanf("%d",&y);
    printf("你輸入的為: x = %d  y = %d\n\n",x,y);
    
    cal(&x,&y,&a_1,&a_2,&a_3,&a_4);
    printf("經過計算:(x = %d  y = %d)\nx + y = %d\nx - y = %d\nx * y = %.2f\nx / y = %.2f\n",x,y,a_1,a_2,a_3,a_4);
    
    printf("\n\n");
    system("pause");
    return 0;
}
