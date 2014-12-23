#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i=0,j=0,k=0,l=0;
int sel=0,select=0,editid=0,edit_B=0,edit_1=0,edit_2=0,edit_3=0,editscore=0;
int add_id=0,check=0,yesno=0;
char *classname[4]={"國文","英文","數學","自然"};
FILE* fptr;
struct student *start, *end, *temp, *deluse, newadd, edit;

struct student{
    int id;
    char name[10];
    int c_score;
    int e_score;
    int m_score;
    int s_score;
    struct stdunt *next;
};

void load(void){
     temp = (struct student*) malloc (sizeof(struct student));
     start = end = temp;
     
     fptr = fopen("myscore.txt","r");
     if(fptr != NULL){
       printf("\t\t◎檔案已開啟,資料讀取中...\n");
       while(!feof(fptr)){
         temp = (struct student*) malloc (sizeof(struct student));
         fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\n",&temp->id,
                                                &temp->name,
                                                &temp->c_score,
                                                &temp->e_score,
                                                &temp->m_score,
                                                &temp->s_score);
         temp -> next = NULL;
         end -> next = temp;
         end = temp;
         j++;
       }
     }
     temp = start;
     k = j;
     printf("\t\t◎檔案讀取完成,總共寫入 %d 筆學生資料!!\n\n",j);
     fclose(fptr);
}

void saveall(void){
     temp = start;
     fptr = fopen("myscore.txt","w");
     if(fptr!=NULL){
       printf("\t\t●檔案已開啟,資料準備寫入...\n");
       do{
         temp = temp->next;
         fprintf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\n",temp->id,
                                                 temp->name,
                                                 temp->c_score,
                                                 temp->e_score,
                                                 temp->m_score,
                                                 temp->s_score);         
       }while(temp->next!=NULL);
       printf("\t\t●資料寫入正確!!關閉檔案!!\n");
       fclose(fptr);
       i=0;j=0;k=0;
     }else{
       printf("\t\t●檔案無法正確開啟,請檢查\"myscore.txt\"是否存在!!!\n");
     }
}

void save(void){
     temp = start;
     fptr = fopen("myscore.txt","a");
     if(fptr!=NULL){
       printf("\t\t●檔案已開啟,資料準備寫入...\n");
       do{
         temp = temp->next;
         if(l>=j){
           fprintf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\n",temp->id,
                                                   temp->name,
                                                   temp->c_score,
                                                   temp->e_score,
                                                   temp->m_score,
                                                   temp->s_score);
         }         
         l++;
       }while(temp->next!=NULL);
       printf("\t\t●資料寫入正確!!關閉檔案!!\n");
       fclose(fptr);
       i=0;j=0;k=0;l=0;
     }else{
       printf("\t\t●檔案無法正確開啟,請檢查\"myscore.txt\"是否存在!!!\n");
     }
}

void checkid(void){
     check = 0;
     temp = start;
     do{
       temp = temp->next;
       if(newadd.id == temp->id){
         check = 1;
         break;
       }
     }while(temp->next!=NULL);
}

void findid(void){
     l=0;
     temp = start;
     do{
       temp = temp->next;
       if(editid == temp->id){
         edit.id = temp->id;
         strcpy(edit.name,temp->name);
         edit.c_score = temp->c_score;
         edit.e_score = temp->e_score;
         edit.m_score = temp->m_score;
         edit.s_score = temp->s_score;
         edit.next = temp->next;
         editid = l;
       }
       l++;
     }while(temp->next!=NULL);
}

void change(void){
     temp = (struct student*) malloc (sizeof(struct student));
     temp->id = newadd.id;
     strcpy(temp->name,newadd.name);
     temp->c_score = newadd.c_score;
     temp->e_score = newadd.e_score;
     temp->m_score = newadd.m_score;
     temp->s_score = newadd.s_score;
     temp->next = NULL;
     end -> next = temp;
     end = temp;
}

void editchange(void){
     l=0;
     temp = start;
     do{
       temp = temp->next;
       if(l == editid){
         temp->id = edit.id;
         strcpy(temp->name,edit.name);
         temp->c_score = edit.c_score;
         temp->e_score = edit.e_score;
         temp->m_score = edit.m_score;
         temp->s_score = edit.s_score;
         temp->next = edit.next;
       }
       l++;
     }while(temp->next!=NULL);
}

void add(void){
     while(1){
       while(1){
         printf("請輸入學號:");
         scanf("%d",&newadd.id);
         checkid();
         if(check==1){
           printf("\t◎此學生已存在!!請重新輸入!!\n");
         }else if(check==0){
           break;
         }
       }
       printf("請輸入姓名:");
       scanf("%s",&newadd.name);
       printf("請輸入國文成績:");
       scanf("%d",&newadd.c_score);
       printf("請輸入英文成績:");
       scanf("%d",&newadd.e_score);
       printf("請輸入數學成績:");
       scanf("%d",&newadd.m_score);
       printf("請輸入自然成績:");
       scanf("%d",&newadd.s_score);
       printf("\t學號\t姓名\t國文\t英文\t數學\t自然\n");
       printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",newadd.id,
                                           newadd.name,
                                           newadd.c_score,
                                           newadd.e_score,
                                           newadd.m_score,
                                           newadd.s_score);
       change();
       k++;
       printf("是否繼續新增學生資料?\n1.是  2.否\n");
       scanf("%d",&yesno);
       if(yesno != 1)break;
     }
}

void print(void){
     temp = start;
     printf("\t學號\t姓名\t國文\t英文\t數學\t自然\n");
     do{
       temp = temp->next;
       printf ("\t%d\t%s\t%d\t%d\t%d\t%d\n",temp->id,
                                            temp->name,
                                            temp->c_score,
                                            temp->e_score,
                                            temp->m_score,
                                            temp->s_score);
     }while(temp->next!=NULL);
     printf("\n\n");
}

void del(void){
     l=0;
     temp = start;
     do{
       temp = temp->next;
       if(l==editid-1){
         deluse = temp;
         if(temp->next == end){
           temp->next = NULL;
           end = temp;
         }
       }
       if(l==editid+1){
         deluse->next = temp;
       }
       l++;
     }while(temp->next!=NULL);
}

void editdel(void){
     do{
       while(1){
         printf("→請輸入你要修改的學生學號: ");
         scanf("%d",&editid);
         edit_B = editid;
         findid();
         if(edit_B != editid)break;
         printf("\t◎找不到你所輸入的學號!!請重新輸入!!\n");
       }
       printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",edit.id,
                                           edit.name,
                                           edit.c_score,
                                           edit.e_score,
                                           edit.m_score,
                                           edit.s_score);
       do{
         printf("你要: 1.修改 2.刪除\n");
         scanf("%d",&edit_1);
         switch(edit_1){
           case 1:
             do{
               printf("請輸入你要修改的成績: 1.國文 2.英文 3.數學 4.自然\n");
               scanf("%d",&edit_2);
               switch(edit_2){
                 case 1:
                   printf("你要修改%d %s的國文分數為: ",edit.id,edit.name);
                   scanf("%d",&editscore);
                   edit.c_score = editscore;
                   break;
                 case 2:
                   printf("你要修改%d %s的英文分數為: ",edit.id,edit.name);
                   scanf("%d",&editscore);
                   edit.e_score = editscore;
                   break;
                 case 3:
                   printf("你要修改%d %s的數學分數為: ",edit.id,edit.name);
                   scanf("%d",&editscore);
                   edit.m_score = editscore;
                   break;
                 case 4:
                   printf("你要修改%d %s的自然分數為: ",edit.id,edit.name);
                   scanf("%d",&editscore);
                   edit.s_score = editscore;
                   break;
               }
             }while(edit_2<1 || edit_2>4);
             editchange();
             break;
           case 2:
             printf("\t◎資料刪除中......\n");
             del();
             k--;
             break;
           }
       }while(edit_1<1 || edit_1>2);
       printf("\t◎1.繼續修改 2.離開修改區\n");
       scanf("%d",&edit_3);
     }while(edit_3!=2);
     saveall();
     printf("\t◎資料刪除完畢,並已自動寫入檔案!!!\n");
     i=0;j=0;k=0;
     editid = 0;edit_B = 0;edit_1 = 0;edit_2 = 0;edit_3 = 0;
}

int main(){   
    while(1){
      printf("===================================================================\n"); 
      printf("請選擇執行項目:\n1.讀取檔案 2.存入檔案 3.新增資料 4.修改/刪除資料 5.列印資料 6.離開\n");
      printf("===================================================================\n"); 
      scanf("%d",&sel);
      switch(sel){
        case 1://讀取檔案 
             load();
             break;
        case 2://寫入檔案 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! 請先開啟檔案 !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             printf("\t◎請注意!此處為覆蓋原有檔案儲存!!\n");
             printf("\t◎繼續請按１\n");
             select = getch();
             if(select != 1)break;
             saveall();
             load();
             break;
        case 3://新增資料 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! 請先開啟檔案 !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             add();
             printf("\t◎自動儲存中......\n");
             save();
             i=0;j=0;k=0;
             printf("\t◎自動重新讀取中......\n");
             load();
             break;
        case 4://修改.刪除資料 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! 請先開啟檔案 !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             print();
             editdel();
             printf("\t◎自動重新讀取中......\n");
             load();
             break;
        case 5://列印檔案 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! 請先開啟檔案 !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             print();
             break;
        case 6://離開 
             return 0;
      }
    }   
}
