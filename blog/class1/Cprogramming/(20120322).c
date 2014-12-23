#include <stdio.h>
#include <stdlib.h>

#define str_2_1 "由大排到小"
#define str_2_2 "由小排到大" 

void swap(int *i,int *j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
void bubble(int arr[][6],int s){
    int i,j,k;
    for(i=0;i<10;i++){
      for(j=0;j<9;j++){
        if(arr[j][s] > arr[j+1][s]){
          for(k=0;k<6;k++){
            swap(&arr[j][k],&arr[j+1][k]);
          }
        }
      }
    }
}

int main(){
    int num[10][6]={1001,85,65,44,87,88,1002,73,58,72,97,66,1003,88,75,77,64,89,1004,66,58,69,77,84,1005,85,81,72,88,56,1006,68,75,65,74,82,1007,58,84,65,42,89,1008,96,57,71,88,84,1009,68,87,75,63,72,1010,99,76,84,75,68};
    int sel_1 = 0,sel_2 = 0;
    char sel_end = ' ';
    char str_1[6][5]={"學號","國文","英文","數學","自然","社會"};
    int i,j;

    printf("\t===================排序前成績==================\n");
    printf("\t學號---國文----英文----數學----自然----社會----\n");
    for(i=0;i<10;i++){
      for(j=0;j<6;j++){
        printf("\t%d",num[i][j]);
      }
      printf("\n");
    }
    printf("\n");
    
SELECT:
SEL1:
    printf("※請選擇排序科目:  0.學號  1.國文  2.英文  3.數學  4.自然  5.社會\n");
    scanf("%d",&sel_1);
    if(sel_1<0||sel_1>5){
      printf("!!!!科目選擇有誤,請重新選擇!!!!\n");
      goto SEL1;
    }
SEL2:    
    printf("※請選擇排列方式:  1.由大排到小  2.由小排到大\n");
    scanf("%d",&sel_2);
    if(sel_2<1||sel_2>2){
      printf("!!!!排列方式選擇有誤,請重新選擇!!!!\n");
      goto SEL2;
    }
    
    switch(sel_1){
      case 0:
           bubble(num,0);
           break;
      case 1:
           bubble(num,1);
           break;
      case 2:
           bubble(num,2);
           break;
      case 3:
           bubble(num,3);
           break;
      case 4:
           bubble(num,4);
           break;
      case 5:
           bubble(num,5);
           break;
    }

PRINT:    
    printf("\n\n");
    printf("你所選擇的排序方式是: 使用 <<%s>> 排序，",str_1[sel_1]);
    if(sel_2 == 1){
      printf(" <<%s>>\n",str_2_1);
    }else{
      printf(" <<%s>>\n",str_2_2);
    }
    
    printf("\t===================排序後成績==================\n");
    printf("\t學號---國文----英文----數學----自然----社會----\n");
    if(sel_2 == 1){
      for(i=9;i>=0;i--){
        for(j=0;j<6;j++){
          printf("\t%d",num[i][j]);
        }
        printf("\n");
      }
    }else{
      for(i=0;i<10;i++){
        for(j=0;j<6;j++){
          printf("\t%d",num[i][j]);
        }
        printf("\n");
      }
    }
    printf("\n");
    
END_SEL:    
    printf("\n\n重新排序請按<<1>> 離開請按<<2>>\n");
    sel_end = getch();
    if(sel_end == '1'){
      goto SELECT; 
    }else if(sel_end == '2'){
      goto END;
    }else{
      printf("!!!!似乎按錯了,請再選擇一次!!!!");
      goto END_SEL;
    }
    
END:    
    printf("\n\n");
    system("pause");
    return 0;
}
