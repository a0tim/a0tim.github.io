#include <stdio.h>
#include <stdlib.h>

int main(){
    float list[2][5]={2.5,3,3.5,4,4.5,3,3.5,4,4.5,5};
Select:
    float list_edit=0,cal_x=0,cal_list=0,price=0;
    int select=0,e_f=0,e_r=0,cal_f=0;
    int i=0,j=0,k=0;

    printf("┌─────────┐\n");
    printf("│1.查詢計價表      │\n│2.修改電費計價    │\n│3.計算電費        │\n│4.結束            │\n");
    printf("└─────────┘\n");
    printf("請選擇:");
    scanf("%d",&select);
    
    switch(select){
      case 1:
           goto Print;
      case 2:
           goto Edit;
      case 3:
           goto Cal;
      case 4:
           goto End;
      default:
           printf("無此選項!!請重新選擇\n");
           goto Select;
    }

Print:
    printf("====查詢計價表====\n"); 
    printf("\t 0~200\t200~300\t300~400\t400~500\t  500+  \n");
    printf("───────────────────────\n"); 
    for(j=0;j<2;j++){
        if(j==0){
          printf("冬季電費");
        }else{
          printf("夏季電費");
        }
      for(i=0;i<5;i++){
        printf("  %.1f\t",list[j][i]);
        if(i==4){
          printf("\n");
        }
      }
    }
    printf("\n");
    
    goto Select;
Edit:
    printf("====修改電費計價====\n");
    printf("請輸入你要修改的季節:   1.冬季  2.夏季\n");
    scanf("%d",&e_f);e_f-=1;
    printf("請輸入你要修改的電費範圍:\n");
    printf("1. 0~200\n2. 200~300\n3. 300~400\n4. 400~500\n5. 500+\n");
    scanf("%d",&e_r);e_r-=1;
    printf("目前價格為: %.1f\n",list[e_f][e_r]); 
    printf("請輸入要改的價格:");
    scanf("%f",&list_edit);
    list[e_f][e_r] = list_edit;
    printf("價格已更改為: %.1f\n\n",list[e_f][e_r]);
    
    goto Select;
Cal:
    printf("請輸入你要計算的季節:   1.冬季  2.夏季\n");
    scanf("%d",&cal_f);
    printf("請輸入你的電費度數: ");
    scanf("%f",&cal_x);
    if(cal_x>=0 && cal_x<=200){
      price = cal_x * list[(cal_f-1)][0];
    }else if(cal_x>200 && cal_x<=300){
      price = 200 * list[(cal_f-1)][0];
      price += (cal_x-200) * list[(cal_f-1)][1];
    }else if(cal_x>300 && cal_x<=400){
      price = 200 * list[(cal_f-1)][0];
      price += 100 * list[(cal_f-1)][1];
      price += (cal_x-300) * list[(cal_f-1)][2];
    }else if(cal_x>400 && cal_x<=500){
      price = 200 * list[(cal_f-1)][0];
      price += 100 * list[(cal_f-1)][1];
      price += 100 * list[(cal_f-1)][2];
      price += (cal_x-400) * list[(cal_f-1)][3];
    }else if(cal_x>500){
      price = 200 * list[(cal_f-1)][0];
      price += 100 * list[(cal_f-1)][1];
      price += 100 * list[(cal_f-1)][2];
      price += 100 * list[(cal_f-1)][3];
      price += (cal_x-500) * list[(cal_f-1)][4];
    }else{
      printf("你輸入的度數不合理!!請重新輸入!!\n");
      goto Cal;
    }
    
    printf("經過計算,你的電費應為:\t$ %.0f\n",price);
    printf("\n");
    
    goto Select;
End:
    printf("\n\nEND\n");
    system("Pause");
    return 0;
}
