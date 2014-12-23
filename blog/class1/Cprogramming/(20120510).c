#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    int id;
    char name[10];
    int c_score;
    int e_score;
    int m_score;
    int s_score;
}myscore[20];

int main(){
    int i=0,j=0,k=0;
    int sel=0;
    int yesno=0;
    FILE* fptr;
    
    while(1){
      printf("=========================================================\n"); 
      printf("請選擇執行項目:   <<請注意!本程式預設學生數目為20人>>\n1.讀取檔案  2.新增資料  3.列印資料  4.存入檔案  5.離開\n");
      printf("=========================================================\n"); 
      scanf("%d",&sel);
      switch(sel){
        case 1:             
             fptr = fopen("myscore.txt","r");
             if(fptr != NULL){
               printf("檔案已開啟,資料讀取中...\n");
               while(!feof(fptr)){                 
                 fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\n",&myscore[j].id,
                                                        &myscore[j].name,
                                                        &myscore[j].c_score,
                                                        &myscore[j].e_score,
                                                        &myscore[j].m_score,
                                                        &myscore[j].s_score);
                 j++;
               }
             }
             k = j;
             printf("資料寫入完成,總共寫入 %d 筆學生資料!!\n\n",j);
             fclose(fptr);
             break;
        case 2:
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! 請先開啟檔案 !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             if(j==19){
               printf("學生資料已達最大數量!!!!!!\n\n");
               break;
             }
INPUT:       printf("請輸入學號:");
             scanf("%d",&myscore[k].id);
             for(i=0;i<k;i++){
               if(myscore[k].id == myscore[i].id){
                 printf("此學生已存在!!請重新輸入!!\n\n");
                 goto INPUT;
               }
             }
             printf("請輸入姓名:");
             scanf("%s",&myscore[k].name);
             printf("請輸入國文成績:");
             scanf("%d",&myscore[k].c_score);
             printf("請輸入英文成績:");
             scanf("%d",&myscore[k].e_score);
             printf("請輸入數學成績:");
             scanf("%d",&myscore[k].m_score);
             printf("請輸入自然成績:");
             scanf("%d",&myscore[k].s_score);
    
             printf("\t學號\t姓名\t國文\t英文\t數學\t自然\n");
    
             printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",myscore[k].id,
                                                 myscore[k].name,
                                                 myscore[k].c_score,
                                                 myscore[k].e_score,
                                                 myscore[k].m_score,
                                                 myscore[k].s_score);
             k++;
             printf("是否繼續新增學生資料?\n1.是  2.否");
             scanf("%d",&yesno);
             if(yesno == 1){
               goto INPUT;
             }
             printf("\n!!!!!!!!!!!!!!!!!!!!!!\n請注意~~\n新增的資料必須儲存進檔案\n!!!!!!!!!!!!!!!!!!!!!!\n\n");
             break;
        case 3:
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! 請先開啟檔案 !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             printf("\t學號\t姓名\t國文\t英文\t數學\t自然\n");
             for(i=0;i<k;i++)
               printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",myscore[i].id,
                                                   myscore[i].name,
                                                   myscore[i].c_score,
                                                   myscore[i].e_score,
                                                   myscore[i].m_score,
                                                   myscore[i].s_score); 
             printf("\n");
             break;
        case 4:
             fptr = fopen("myscore.txt","a");
             printf("檔案已開啟,資料準備寫入...\n");
             for(i=j;i<k;i++)
               fprintf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\n",myscore[i].id,
                                                       myscore[i].name,
                                                       myscore[i].c_score,
                                                       myscore[i].e_score,
                                                       myscore[i].m_score,
                                                       myscore[i].s_score);
    
             printf("資料寫入正確!!關閉檔案!!\n");
             fclose(fptr);
             i=0;j=0;k=0;
             printf("\n!!!!!!!!!!!!!!!!!!!!!!\n請注意~~\n檔案儲存完畢後請重新開啟檔案\n!!!!!!!!!!!!!!!!!!!!!!\n\n");
             break; 
        case 5:
             return 0;
      }
    }   
}
