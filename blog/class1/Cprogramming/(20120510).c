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
      printf("�п�ܰ��涵��:   <<�Ъ`�N!���{���w�]�ǥͼƥج�20�H>>\n1.Ū���ɮ�  2.�s�W���  3.�C�L���  4.�s�J�ɮ�  5.���}\n");
      printf("=========================================================\n"); 
      scanf("%d",&sel);
      switch(sel){
        case 1:             
             fptr = fopen("myscore.txt","r");
             if(fptr != NULL){
               printf("�ɮפw�}��,���Ū����...\n");
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
             printf("��Ƽg�J����,�`�@�g�J %d ���ǥ͸��!!\n\n",j);
             fclose(fptr);
             break;
        case 2:
             if(k==0){
               printf("\n\t\t!!!!!!!!!!!!!!!!\n\t\t! �Х��}���ɮ� !\n\t\t!!!!!!!!!!!!!!!!\n\n");
               break;
             }
             if(j==19){
               printf("�ǥ͸�Ƥw�F�̤j�ƶq!!!!!!\n\n");
               break;
             }
INPUT:       printf("�п�J�Ǹ�:");
             scanf("%d",&myscore[k].id);
             for(i=0;i<k;i++){
               if(myscore[k].id == myscore[i].id){
                 printf("���ǥͤw�s�b!!�Э��s��J!!\n\n");
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
             printf("\n!!!!!!!!!!!!!!!!!!!!!!\n�Ъ`�N~~\n�s�W����ƥ����x�s�i�ɮ�\n!!!!!!!!!!!!!!!!!!!!!!\n\n");
             break;
        case 3:
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
             printf("\n");
             break;
        case 4:
             fptr = fopen("myscore.txt","a");
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
             printf("\n!!!!!!!!!!!!!!!!!!!!!!\n�Ъ`�N~~\n�ɮ��x�s������Э��s�}���ɮ�\n!!!!!!!!!!!!!!!!!!!!!!\n\n");
             break; 
        case 5:
             return 0;
      }
    }   
}
