#include <stdio.h>
#include <stdlib.h>

int main(){
    int num[5][7]={0};    //宣告人數5人，項目:學號.國文.英文.數學.自然.社會.總分(7個)
    char name[5][10];     //宣告人名陣列 
Head://======================================================================================================
    float verage[7]={0};  //宣告各科平均陣列
    float totalverage[5]={0};  //宣告個人總分平均陣列
    int chi=0,eng=0,mat=0,sci=0,com=0,tot=0;  //宣告變數用來儲存各科最高分者的學號 
    int select=0,edit=0,number=0,edi=0,sco=0;
    int x=0,y=0;
    float i=0,j=0;

Sel://=======================================================================================================
    printf("◎◎◎◎◎◎◎◎◎◎◎\n");
    printf("◎  1.輸入成績      ◎\n◎  2.列印成績單    ◎\n◎  3.修改成績      ◎\n◎  4.查詢個人成績  ◎\n◎  5.離開          ◎\n");
    printf("◎◎◎◎◎◎◎◎◎◎◎\t");
    printf("請選擇:");
    scanf("%d",&select);
    printf("\n");
    
    switch(select){
      case 1:      
           goto Input;  
      case 2:
           goto Print;
      case 3:
           goto Edit;
      case 4:
           goto Score;
      case 5:
           goto End;
      default :
           goto Sel;
    }
    
Input://=====================================================================================================
    printf("如果最高分有分數相同者僅會顯示一人!!!\n");
    printf("=================請輸入成績=================\n");
    for(x=0;x<5;x++){
      printf("學生學號:\t");
      scanf("%d",&num[x][0]);
      printf("學生姓名:\t");
      scanf("%s",name[x]);
      reinputscore: 
      printf("國文-英文-數學-自然-社會\n");
      scanf("%d %d %d %d %d",&num[x][1],&num[x][2],&num[x][3],&num[x][4],&num[x][5]);
      for(y=1;y<6;y++){
        if(num[x][y]<0 || num[x][y]>100){
          printf("您所輸入的成績有誤!!!請重新輸入!!!\n");
          goto reinputscore;
        }
      }      
    }
    printf("\n");
    
    goto Sel;
    
Edit://======================================================================================================
    printf("請輸入你要修改的學號:\t");
    scanf("%d",&edit);
    printf("\n");
    for(x=0;x<5;x++){
      if(edit == num[x][0]){
        edi = 1;
        printf("=================請輸入成績=================\n");
        reinputedit:
        printf("國文-英文-數學-自然-社會\n");
        scanf("%d %d %d %d %d",&num[x][1],&num[x][2],&num[x][3],&num[x][4],&num[x][5]);
        for(y=1;y<6;y++){
          if(num[x][y]<0 || num[x][y]>100){
            printf("您所輸入的成績有誤!!!請重新輸入!!!\n");
            goto reinputedit;
          }
        } 
      }
    }
    if(edi == 0){
      printf("查詢不到您所輸入的學號!!!請重新輸入一次!!!\n");
      goto Edit;
    }
    printf("\n");
     
    goto Head;    

Print://=====================================================================================================
    for(x=0;x<5;x++){
      num[x][6] = num[x][1]+num[x][2]+num[x][3]+num[x][4]+num[x][5];  //此行用來累加個人分數成總分 
      totalverage[x] = num[x][6]/5;  //此行用來計算個人平均分數 
    } 
    for(x=0;x<5;x++){           //此部分用來累加各科的分數 
      for(y=0;y<5;y++){
        verage[y] = verage[y] + num[x][y+1];
      } 
      i += num[x][6];           //此行用來累加每人總分 
      j += totalverage[x];      //此行用來累加每人平均
    }
    
    for(x=0;x<5;x++){           //此部分用來將累加後的各科總分平均 
      verage[x] = verage[x]/5;
    }
    verage[5] = i/5;            //此行將累加後的每人總分平均 
    verage[6] = j/5;            //此行將累加後的每人平均平均 
                   
    for(x=0;x<5;x++){           //此部分用來找出每科最高分同學 
      for(y=0;y<5;y++){
        if(num[chi][1]<num[y][1]){
          chi = y;
        }
        if(num[eng][2]<num[y][2]){
          eng = y;
        }
        if(num[mat][3]<num[y][3]){
          mat = y;
        }
        if(num[sci][4]<num[y][4]){
          sci = y;
        }
        if(num[com][5]<num[y][5]){
          com = y;
        }
        if(num[tot][6]<num[y][6]){
          tot = y;
        }
      } 
    } 
    
    printf("\n");
    printf("==================================成績單=================================\n");
    printf("學號\t姓名\t國文\t英文\t數學\t自然\t社會\t總分\t平均\n");
    for(x=0;x<5;x++){
      for(y=0;y<7;y++){
        printf("%d\t",num[x][y]);
        if(y==0){
          printf("%s\t",name[x]);
        }
      }      
      printf("%.2f\n",totalverage[x]);
    }
    printf("=========================================================================\n");
    printf("平均\t\t");
    for(x=0;x<7;x++){
      printf("%.2f\t",verage[x]);
    }
    printf("\n\n");
    printf("國文分數最高的是:\t%d\t%s\n",num[chi][0],name[chi]);
    printf("英文分數最高的是:\t%d\t%s\n",num[eng][0],name[eng]);
    printf("數學分數最高的是:\t%d\t%s\n",num[mat][0],name[mat]);
    printf("自然分數最高的是:\t%d\t%s\n",num[sci][0],name[sci]);
    printf("社會分數最高的是:\t%d\t%s\n",num[com][0],name[com]);
    printf("總分分數最高的是:\t%d\t%s\n",num[tot][0],name[tot]);
    printf("平均分數最高的是:\t%d\t%s\n",num[tot][0],name[tot]);
    printf("\n");
    
    goto Head;

Score://============================================================================================
    printf("請輸入要查詢的學生學號:");
    scanf("%d",&number);
    for(x=0;x<5;x++){
       if(number == num[x][0]){
         sco = 1;
         printf("您所查詢的是:\n\n");
         printf("學號: %d\t學生姓名: %s\n",num[x][0],name[x]);
         printf("=================成績=================\n");
         printf("國文\t英文\t數學\t自然\t社會\n");
         printf("%d\t%d\t%d\t%d\t%d\n",num[x][1],num[x][2],num[x][3],num[x][4],num[x][5]);
       }
     }
    if(sco == 0){
      printf("查詢不到您所輸入的學號!!!請重新輸入一次!!!\n");
      goto Score;
    }
    printf("\n");
    
    goto Sel;
    
End://==============================================================================================
    printf("\n\nEND\n");
    system("pause");
    return 0;
}
