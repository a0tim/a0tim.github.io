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
    int sel=0,edit=0,edit_B=0,edit_1=0,edit_2=0,edit_3=0,editscore=0;
    int yesno=0;
    FILE* fptr;
    
    while(1){
      printf("===================================================================\n"); 
      printf("請選擇執行項目:   <<請注意!本程式預設學生數目為20人>>\n1.讀取檔案 2.存入檔案 3.新增資料 4.修改/刪除資料 5.列印資料 6.離開\n");
      printf("===================================================================\n"); 
      scanf("%d",&sel);
      switch(sel){
        case 1://讀取檔案 
OPEN:        fptr = fopen("myscore.txt","r");
             if(fptr != NULL){
               printf("\t◎檔案已開啟,資料讀取中...\n");
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
             printf("\t◎資料寫入完成,總共寫入 %d 筆學生資料!!\n\n",j);
             fclose(fptr);
             break;
        case 2://寫入檔案 
SAVE:        fptr = fopen("myscore.txt","a");
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
             goto OPEN;
        case 3://新增資料 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! 請先開啟檔案 !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             if(j==19){
               printf("學生資料已達最大數量!!!!!!");
               break;
             }
INPUT:       printf("請輸入學號:");
             scanf("%d",&myscore[k].id);
             for(i=0;i<k;i++){
               if(myscore[k].id == myscore[i].id){
                 printf("\t◎此學生已存在!!請重新輸入!!\n");
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
             printf("\t◎自動儲存中......\n");
             goto SAVE;
        case 4:
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
EDIT:        printf("\n請輸入你要修改的學生學號: ");
             scanf("%d",&edit);
             for(i=0;i<k;i++){
               if(edit == myscore[i].id){
                 edit = i;
                 edit_B = 1;
               }
             }
             if(edit_B == 0){
               printf("\t◎找不到你所輸入的學號!!請重新輸入!!\n");
               goto EDIT;
             }
             printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",myscore[edit].id,
                                                 myscore[edit].name,
                                                 myscore[edit].c_score,
                                                 myscore[edit].e_score,
                                                 myscore[edit].m_score,
                                                 myscore[edit].s_score);
EDIT1:       printf("你要: 1.修改 2.刪除\n");
             scanf("%d",&edit_1);
             if(edit_1 == 1){
EDIT2:          printf("請輸入你要修改的成績: 1.國文 2.英文 3.數學 4.自然\n");
                scanf("%d",&edit_2);
                if(edit_2 == 1){
                  printf("你要修改%d %s的國文分數為: ",myscore[edit].id,myscore[edit].name);
                  scanf("%d",&editscore);
                  myscore[edit].c_score = editscore; 
                }else if(edit_2 == 2){
                  printf("你要修改%d %s的英文分數為: ",myscore[edit].id,myscore[edit].name);
                  scanf("%d",&editscore);
                  myscore[edit].e_score = editscore; 
                }else if(edit_2 == 3){
                  printf("你要修改%d %s的數學分數為: ",myscore[edit].id,myscore[edit].name);
                  scanf("%d",&editscore);
                  myscore[edit].m_score = editscore; 
                }else if(edit_2 == 4){
                  printf("你要修改%d %s的自然分數為: ",myscore[edit].id,myscore[edit].name);
                  scanf("%d",&editscore);
                  myscore[edit].s_score = editscore; 
                }else{
                  printf("\t◎輸入錯誤!!請重新選擇!!\n");
                  goto EDIT2;
                }
                printf("\t◎1.繼續修改 2.離開修改區\n");
                scanf("%d",&edit_3);
                if(edit_3 == 1){
                  goto EDIT2;
                }
             }else if(edit_1 == 2){
                printf("\t◎資料刪除中......\n");
                for(i=edit;i<19;i++){
                  myscore[i].id = myscore[i+1].id;
                  strcpy(myscore[i].name,myscore[i+1].name);
                  myscore[i].c_score = myscore[i+1].c_score;
                  myscore[i].e_score = myscore[i+1].e_score;
                  myscore[i].m_score = myscore[i+1].m_score;
                  myscore[i].s_score = myscore[i+1].s_score;
                }
                fptr = fopen("myscore.txt","w");
                for(i=0;i<k-1;i++)
                  fprintf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\n",myscore[i].id,
                                                          myscore[i].name,
                                                          myscore[i].c_score,
                                                          myscore[i].e_score,
                                                          myscore[i].m_score,
                                                          myscore[i].s_score);
                  fclose(fptr);
                printf("\t◎資料刪除完畢,並已自動寫入檔案!!!\n");
                i=0;j=0;k=0;
                goto OPEN;
             }else{
               printf("\t◎輸入錯誤!!請重新選擇!!\n");
               goto EDIT1;
             }
             edit = 0;edit_B = 0;edit_1 = 0;edit_2 = 0;edit_3 = 0;
             break;
        case 5://列印檔案 
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
             printf("\n\n");
             break;
        case 6:
             return 0;
      }
    }   
}
