#include <stdio.h>
#include <stdlib.h>

int order[10] = {0,1,2,3,4,5,6,7,8,9};

void swap(int *i,int *j){
    int temp;
    temp = *i;
    *i = *j;
    *j = temp;
}
void bubble(int arr[10]){
    int i,j;
    for(i=0;i<10;i++){
      for(j=0;j<9;j++){
        if(arr[j] > arr[j+1]){
          swap(&arr[j],&arr[j+1]);
          swap(&order[j],&order[j+1]);
        }
      }
    }
}

int main(){
    struct student{
      int id; 
      char name[10];
      int chi;
      int eng;
      int mat;
      int sci;
      int com;
    };
    struct student class1[10];
    int sel_1 = 0,sel_2 = 0;
    char *str_1[7]={"學號","姓名","國文","英文","數學","自然","社會"};
    char *str_2[2]={"由大排到小","由小排到大"};
    int id[10],chi[10],eng[10],mat[10],sci[10],com[10];
    char sel_end = ' ';
    int i,j;
    char filename[15];
FN:    
    printf("◎請輸入你所要開啟的學生資料檔名稱(記得加上附檔名):\n");
    scanf("%s",&filename);
    
    FILE* fptr;
    fptr = fopen(filename,"r");
    if(fptr == NULL){
      printf("找不到你所輸入的檔案，請重新輸入檔案名稱!!!\n");
      goto FN;
    }
    for(i=0;i<10;i++){
      fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d",&class1[i].id,&class1[i].name,&class1[i].chi,&class1[i].eng,&class1[i].mat,&class1[i].sci,&class1[i].com);
    }
    
    printf("\t========================排序前成績=======================\n");
    printf("\t學號----姓名-----國文----英文----數學----自然----社會----\n");
    for(i=0;i<10;i++){
      printf("\t%d\t%s\t  %d\t  %d\t  %d\t  %d\t  %d\n",class1[i].id,class1[i].name,class1[i].chi,class1[i].eng,class1[i].mat,class1[i].sci,class1[i].com);
    }
    printf("\n");
    
SELECT:
SEL1:
    printf("※請選擇排序科目:  0.學號  1.國文  2.英文  3.數學  4.自然  5.社會\n");
    scanf("%d",&sel_1);
    if(sel_1>0 && sel_1<6){
      sel_1++;
    }
    if(sel_1<0 || sel_1>5){
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
           for(i=0;i<10;i++)
             id[i] = class1[i].id;
           bubble(id);
           break;
      case 2:
           for(i=0;i<10;i++)
             chi[i] = class1[i].chi;
           bubble(chi);
           break;
      case 3:
           for(i=0;i<10;i++)
             eng[i] = class1[i].eng;
           bubble(eng);
           break;
      case 4:
           for(i=0;i<10;i++)
             mat[i] = class1[i].mat;
           bubble(mat);
           break;
      case 5:
           for(i=0;i<10;i++)
             sci[i] = class1[i].sci;
           bubble(sci);
           break;
      case 6:
           for(i=0;i<10;i++)
             com[i] = class1[i].com;
           bubble(com);
           break;
    }
    
PRINT:    
    printf("\n");
    printf("你所選擇的排序方式是: 使用 <<%s>> 排序，",str_1[sel_1]);
    if(sel_2 == 1){
      printf(" <<%s>>\n",str_2[0]);
    }else{
      printf(" <<%s>>\n",str_2[1]);
    }
    
    printf("\t========================排序後成績=======================\n");
    printf("\t學號----姓名-----國文----英文----數學----自然----社會----\n");
    if(sel_2 == 1){
      for(i=9;i>=0;i--){
        printf("\t%d\t%s\t  %d\t  %d\t  %d\t  %d\t  %d\n",class1[order[i]].id,class1[order[i]].name,class1[order[i]].chi,class1[order[i]].eng,class1[order[i]].mat,class1[order[i]].sci,class1[order[i]].com);
      }
    }else{
      for(i=0;i<10;i++){
        printf("\t%d\t%s\t  %d\t  %d\t  %d\t  %d\t  %d\n",class1[order[i]].id,class1[order[i]].name,class1[order[i]].chi,class1[order[i]].eng,class1[order[i]].mat,class1[order[i]].sci,class1[order[i]].com);
      }
    }
    printf("\n");
    
END_SEL:    
    printf("\n\n重新排序請按<<1>> 離開請按<<2>>\n");
    sel_end = getch();
    if(sel_end == '1'){
      for(i=0;i<10;i++){
        order[i] = i;
      }
      goto SELECT; 
    }else if(sel_end == '2'){
      goto END;
    }else{
      printf("!!!!似乎按錯了,請再選擇一次!!!!");
      goto END_SEL;
    }
    
END:    
    printf("\n\nEND...");
    system("pause");
    return 0;
}
