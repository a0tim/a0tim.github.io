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
      printf("�п�ܰ��涵��:   <<�Ъ`�N!���{���w�]�ǥͼƥج�20�H>>\n1.Ū���ɮ� 2.�s�J�ɮ� 3.�s�W��� 4.�ק�/�R����� 5.�C�L��� 6.���}\n");
      printf("===================================================================\n"); 
      scanf("%d",&sel);
      switch(sel){
        case 1://Ū���ɮ� 
OPEN:        fptr = fopen("myscore.txt","r");
             if(fptr != NULL){
               printf("\t���ɮפw�}��,���Ū����...\n");
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
             printf("\t����Ƽg�J����,�`�@�g�J %d ���ǥ͸��!!\n\n",j);
             fclose(fptr);
             break;
        case 2://�g�J�ɮ� 
SAVE:        fptr = fopen("myscore.txt","a");
             printf("�ɮפw�}��,��ƷǳƼg�J...\n");
             for(i=j;i<k;i++)
               fprintf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\n",myscore[i].id,
                                                       myscore[i].name,
                                                       myscore[i].c_score,
                                                       myscore[i].e_score,
                                                       myscore[i].m_score,
                                                       myscore[i].s_score);
    
             printf("��Ƽg�J���T!!�����ɮ�!!\n");
             fclose(fptr);
             i=0;j=0;k=0;
             goto OPEN;
        case 3://�s�W��� 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! �Х��}���ɮ� !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             if(j==19){
               printf("�ǥ͸�Ƥw�F�̤j�ƶq!!!!!!");
               break;
             }
INPUT:       printf("�п�J�Ǹ�:");
             scanf("%d",&myscore[k].id);
             for(i=0;i<k;i++){
               if(myscore[k].id == myscore[i].id){
                 printf("\t�����ǥͤw�s�b!!�Э��s��J!!\n");
                 goto INPUT;
               }
             }
             printf("�п�J�m�W:");
             scanf("%s",&myscore[k].name);
             printf("�п�J��妨�Z:");
             scanf("%d",&myscore[k].c_score);
             printf("�п�J�^�妨�Z:");
             scanf("%d",&myscore[k].e_score);
             printf("�п�J�ƾǦ��Z:");
             scanf("%d",&myscore[k].m_score);
             printf("�п�J�۵M���Z:");
             scanf("%d",&myscore[k].s_score);
    
             printf("\t�Ǹ�\t�m�W\t���\t�^��\t�ƾ�\t�۵M\n");
    
             printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",myscore[k].id,
                                                 myscore[k].name,
                                                 myscore[k].c_score,
                                                 myscore[k].e_score,
                                                 myscore[k].m_score,
                                                 myscore[k].s_score);
             k++;
             printf("�O�_�~��s�W�ǥ͸��?\n1.�O  2.�_");
             scanf("%d",&yesno);
             if(yesno == 1){
               goto INPUT;
             }
             printf("\t���۰��x�s��......\n");
             goto SAVE;
        case 4:
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! �Х��}���ɮ� !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             printf("\t�Ǹ�\t�m�W\t���\t�^��\t�ƾ�\t�۵M\n");
             for(i=0;i<k;i++)
               printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",myscore[i].id,
                                                   myscore[i].name,
                                                   myscore[i].c_score,
                                                   myscore[i].e_score,
                                                   myscore[i].m_score,
                                                   myscore[i].s_score); 
EDIT:        printf("\n�п�J�A�n�ק諸�ǥ;Ǹ�: ");
             scanf("%d",&edit);
             for(i=0;i<k;i++){
               if(edit == myscore[i].id){
                 edit = i;
                 edit_B = 1;
               }
             }
             if(edit_B == 0){
               printf("\t���䤣��A�ҿ�J���Ǹ�!!�Э��s��J!!\n");
               goto EDIT;
             }
             printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",myscore[edit].id,
                                                 myscore[edit].name,
                                                 myscore[edit].c_score,
                                                 myscore[edit].e_score,
                                                 myscore[edit].m_score,
                                                 myscore[edit].s_score);
EDIT1:       printf("�A�n: 1.�ק� 2.�R��\n");
             scanf("%d",&edit_1);
             if(edit_1 == 1){
EDIT2:          printf("�п�J�A�n�ק諸���Z: 1.��� 2.�^�� 3.�ƾ� 4.�۵M\n");
                scanf("%d",&edit_2);
                if(edit_2 == 1){
                  printf("�A�n�ק�%d %s�������Ƭ�: ",myscore[edit].id,myscore[edit].name);
                  scanf("%d",&editscore);
                  myscore[edit].c_score = editscore; 
                }else if(edit_2 == 2){
                  printf("�A�n�ק�%d %s���^����Ƭ�: ",myscore[edit].id,myscore[edit].name);
                  scanf("%d",&editscore);
                  myscore[edit].e_score = editscore; 
                }else if(edit_2 == 3){
                  printf("�A�n�ק�%d %s���ƾǤ��Ƭ�: ",myscore[edit].id,myscore[edit].name);
                  scanf("%d",&editscore);
                  myscore[edit].m_score = editscore; 
                }else if(edit_2 == 4){
                  printf("�A�n�ק�%d %s���۵M���Ƭ�: ",myscore[edit].id,myscore[edit].name);
                  scanf("%d",&editscore);
                  myscore[edit].s_score = editscore; 
                }else{
                  printf("\t����J���~!!�Э��s���!!\n");
                  goto EDIT2;
                }
                printf("\t��1.�~��ק� 2.���}�ק��\n");
                scanf("%d",&edit_3);
                if(edit_3 == 1){
                  goto EDIT2;
                }
             }else if(edit_1 == 2){
                printf("\t����ƧR����......\n");
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
                printf("\t����ƧR������,�äw�۰ʼg�J�ɮ�!!!\n");
                i=0;j=0;k=0;
                goto OPEN;
             }else{
               printf("\t����J���~!!�Э��s���!!\n");
               goto EDIT1;
             }
             edit = 0;edit_B = 0;edit_1 = 0;edit_2 = 0;edit_3 = 0;
             break;
        case 5://�C�L�ɮ� 
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! �Х��}���ɮ� !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             printf("\t�Ǹ�\t�m�W\t���\t�^��\t�ƾ�\t�۵M\n");
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
