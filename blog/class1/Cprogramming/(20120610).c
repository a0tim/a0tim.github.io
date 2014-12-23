#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i=0,j=0,k=0,l=0;
int sel=0,select=0,editid=0,edit_B=0,edit_1=0,edit_2=0,edit_3=0,editscore=0;
int add_id=0,check=0,yesno=0;
char *classname[4]={"���","�^��","�ƾ�","�۵M"};
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
       printf("\t\t���ɮפw�}��,���Ū����...\n");
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
     printf("\t\t���ɮ�Ū������,�`�@�g�J %d ���ǥ͸��!!\n\n",j);
     fclose(fptr);
}

void saveall(void){
     temp = start;
     fptr = fopen("myscore.txt","w");
     if(fptr!=NULL){
       printf("\t\t���ɮפw�}��,��ƷǳƼg�J...\n");
       do{
         temp = temp->next;
         fprintf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\n",temp->id,
                                                 temp->name,
                                                 temp->c_score,
                                                 temp->e_score,
                                                 temp->m_score,
                                                 temp->s_score);         
       }while(temp->next!=NULL);
       printf("\t\t����Ƽg�J���T!!�����ɮ�!!\n");
       fclose(fptr);
       i=0;j=0;k=0;
     }else{
       printf("\t\t���ɮ׵L�k���T�}��,���ˬd\"myscore.txt\"�O�_�s�b!!!\n");
     }
}

void save(void){
     temp = start;
     fptr = fopen("myscore.txt","a");
     if(fptr!=NULL){
       printf("\t\t���ɮפw�}��,��ƷǳƼg�J...\n");
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
       printf("\t\t����Ƽg�J���T!!�����ɮ�!!\n");
       fclose(fptr);
       i=0;j=0;k=0;l=0;
     }else{
       printf("\t\t���ɮ׵L�k���T�}��,���ˬd\"myscore.txt\"�O�_�s�b!!!\n");
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
         printf("�п�J�Ǹ�:");
         scanf("%d",&newadd.id);
         checkid();
         if(check==1){
           printf("\t�����ǥͤw�s�b!!�Э��s��J!!\n");
         }else if(check==0){
           break;
         }
       }
       printf("�п�J�m�W:");
       scanf("%s",&newadd.name);
       printf("�п�J��妨�Z:");
       scanf("%d",&newadd.c_score);
       printf("�п�J�^�妨�Z:");
       scanf("%d",&newadd.e_score);
       printf("�п�J�ƾǦ��Z:");
       scanf("%d",&newadd.m_score);
       printf("�п�J�۵M���Z:");
       scanf("%d",&newadd.s_score);
       printf("\t�Ǹ�\t�m�W\t���\t�^��\t�ƾ�\t�۵M\n");
       printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",newadd.id,
                                           newadd.name,
                                           newadd.c_score,
                                           newadd.e_score,
                                           newadd.m_score,
                                           newadd.s_score);
       change();
       k++;
       printf("�O�_�~��s�W�ǥ͸��?\n1.�O  2.�_\n");
       scanf("%d",&yesno);
       if(yesno != 1)break;
     }
}

void print(void){
     temp = start;
     printf("\t�Ǹ�\t�m�W\t���\t�^��\t�ƾ�\t�۵M\n");
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
         printf("���п�J�A�n�ק諸�ǥ;Ǹ�: ");
         scanf("%d",&editid);
         edit_B = editid;
         findid();
         if(edit_B != editid)break;
         printf("\t���䤣��A�ҿ�J���Ǹ�!!�Э��s��J!!\n");
       }
       printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",edit.id,
                                           edit.name,
                                           edit.c_score,
                                           edit.e_score,
                                           edit.m_score,
                                           edit.s_score);
       do{
         printf("�A�n: 1.�ק� 2.�R��\n");
         scanf("%d",&edit_1);
         switch(edit_1){
           case 1:
             do{
               printf("�п�J�A�n�ק諸���Z: 1.��� 2.�^�� 3.�ƾ� 4.�۵M\n");
               scanf("%d",&edit_2);
               switch(edit_2){
                 case 1:
                   printf("�A�n�ק�%d %s�������Ƭ�: ",edit.id,edit.name);
                   scanf("%d",&editscore);
                   edit.c_score = editscore;
                   break;
                 case 2:
                   printf("�A�n�ק�%d %s���^����Ƭ�: ",edit.id,edit.name);
                   scanf("%d",&editscore);
                   edit.e_score = editscore;
                   break;
                 case 3:
                   printf("�A�n�ק�%d %s���ƾǤ��Ƭ�: ",edit.id,edit.name);
                   scanf("%d",&editscore);
                   edit.m_score = editscore;
                   break;
                 case 4:
                   printf("�A�n�ק�%d %s���۵M���Ƭ�: ",edit.id,edit.name);
                   scanf("%d",&editscore);
                   edit.s_score = editscore;
                   break;
               }
             }while(edit_2<1 || edit_2>4);
             editchange();
             break;
           case 2:
             printf("\t����ƧR����......\n");
             del();
             k--;
             break;
           }
       }while(edit_1<1 || edit_1>2);
       printf("\t��1.�~��ק� 2.���}�ק��\n");
       scanf("%d",&edit_3);
     }while(edit_3!=2);
     saveall();
     printf("\t����ƧR������,�äw�۰ʼg�J�ɮ�!!!\n");
     i=0;j=0;k=0;
     editid = 0;edit_B = 0;edit_1 = 0;edit_2 = 0;edit_3 = 0;
}

int main(){   
    while(1){
      printf("===================================================================\n"); 
      printf("�п�ܰ��涵��:\n1.Ū���ɮ� 2.�s�J�ɮ� 3.�s�W��� 4.�ק�/�R����� 5.�C�L��� 6.���}\n");
      printf("===================================================================\n"); 
      scanf("%d",&sel);
      switch(sel){
        case 1://Ū���ɮ� 
             load();
             break;
        case 2://�g�J�ɮ� 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! �Х��}���ɮ� !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             printf("\t���Ъ`�N!���B���л\�즳�ɮ��x�s!!\n");
             printf("\t���~��Ы���\n");
             select = getch();
             if(select != 1)break;
             saveall();
             load();
             break;
        case 3://�s�W��� 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! �Х��}���ɮ� !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             add();
             printf("\t���۰��x�s��......\n");
             save();
             i=0;j=0;k=0;
             printf("\t���۰ʭ��sŪ����......\n");
             load();
             break;
        case 4://�ק�.�R����� 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! �Х��}���ɮ� !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             print();
             editdel();
             printf("\t���۰ʭ��sŪ����......\n");
             load();
             break;
        case 5://�C�L�ɮ� 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! �Х��}���ɮ� !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             print();
             break;
        case 6://���} 
             return 0;
      }
    }   
}
