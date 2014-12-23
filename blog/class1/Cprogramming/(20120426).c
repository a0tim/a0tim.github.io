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
    char *str_1[7]={"�Ǹ�","�m�W","���","�^��","�ƾ�","�۵M","���|"};
    char *str_2[2]={"�Ѥj�ƨ�p","�Ѥp�ƨ�j"};
    int id[10],chi[10],eng[10],mat[10],sci[10],com[10];
    char sel_end = ' ';
    int i,j;
    char filename[15];
FN:    
    printf("���п�J�A�ҭn�}�Ҫ��ǥ͸���ɦW��(�O�o�[�W���ɦW):\n");
    scanf("%s",&filename);
    
    FILE* fptr;
    fptr = fopen(filename,"r");
    if(fptr == NULL){
      printf("�䤣��A�ҿ�J���ɮסA�Э��s��J�ɮצW��!!!\n");
      goto FN;
    }
    for(i=0;i<10;i++){
      fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\t%d",&class1[i].id,&class1[i].name,&class1[i].chi,&class1[i].eng,&class1[i].mat,&class1[i].sci,&class1[i].com);
    }
    
    printf("\t========================�Ƨǫe���Z=======================\n");
    printf("\t�Ǹ�----�m�W-----���----�^��----�ƾ�----�۵M----���|----\n");
    for(i=0;i<10;i++){
      printf("\t%d\t%s\t  %d\t  %d\t  %d\t  %d\t  %d\n",class1[i].id,class1[i].name,class1[i].chi,class1[i].eng,class1[i].mat,class1[i].sci,class1[i].com);
    }
    printf("\n");
    
SELECT:
SEL1:
    printf("���п�ܱƧǬ��:  0.�Ǹ�  1.���  2.�^��  3.�ƾ�  4.�۵M  5.���|\n");
    scanf("%d",&sel_1);
    if(sel_1>0 && sel_1<6){
      sel_1++;
    }
    if(sel_1<0 || sel_1>5){
      printf("!!!!��ؿ�ܦ��~,�Э��s���!!!!\n");
      goto SEL1;
    }
SEL2:    
    printf("���п�ܱƦC�覡:  1.�Ѥj�ƨ�p  2.�Ѥp�ƨ�j\n");
    scanf("%d",&sel_2);
    if(sel_2<1||sel_2>2){
      printf("!!!!�ƦC�覡��ܦ��~,�Э��s���!!!!\n");
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
    printf("�A�ҿ�ܪ��ƧǤ覡�O: �ϥ� <<%s>> �ƧǡA",str_1[sel_1]);
    if(sel_2 == 1){
      printf(" <<%s>>\n",str_2[0]);
    }else{
      printf(" <<%s>>\n",str_2[1]);
    }
    
    printf("\t========================�Ƨǫᦨ�Z=======================\n");
    printf("\t�Ǹ�----�m�W-----���----�^��----�ƾ�----�۵M----���|----\n");
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
    printf("\n\n���s�ƧǽЫ�<<1>> ���}�Ы�<<2>>\n");
    sel_end = getch();
    if(sel_end == '1'){
      for(i=0;i<10;i++){
        order[i] = i;
      }
      goto SELECT; 
    }else if(sel_end == '2'){
      goto END;
    }else{
      printf("!!!!���G�����F,�ЦA��ܤ@��!!!!");
      goto END_SEL;
    }
    
END:    
    printf("\n\nEND...");
    system("pause");
    return 0;
}
