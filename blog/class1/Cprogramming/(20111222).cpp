#include <stdio.h>
#include <stdlib.h>

void swap(float *i,float *j){
     float temp = 0;     
     temp = *i;
     *i = *j;
     *j = temp;
}

void bubble(float arr[],int length){
     int i=0,j=0;     
     for(i=0;i<length;i++){
       for(j=0;j<length;j++){
         if(arr[j]>arr[j+1]){
           swap(&arr[j],&arr[j+1]);
         }
       }
     }
}

int main(){
    
    int numscore[5][6]={0};
Head:     
    float chinese[6]={0},english[6]={0},math[6]={0},science[6]={0},community[6]={0},total[6]={0},totalverage[6]={0};
    float chi=0,eng=0,mat=0,sci=0,com=0,tot=0,tove=0;
    float Bchi[6]={0},Beng[6]={0},Bmat[6]={0},Bsci[6]={0},Bcom[6]={0},Btot[6]={0},Btov[6]={0};
    int Hchi=0,Heng=0,Hmat=0,Hsci=0,Hcom=0,Htot=0,Htov=0;
    int a=0,b=0,x=0,y=0,z=0;
    int select=0,edit=0;

Sel:
    printf("\n��������������������\n");
    printf("��  1.��J���Z    ��\n��  2.�C�L���Z��  ��\n��  3.�ק令�Z    ��\n��  4.���}        ��\n");
    printf("��������������������\t");
    printf("�п��:");
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
           goto End;
    }
    
Input:
    printf("�p�G�̰��������ƬۦP�̶ȷ|��ܤ@�H!!!\n");
    printf("=================�п�J���Z=================\n");
    printf("�Ǹ�\t���\t�^��\t�ƾ�\t�۵M\t���|\n");
    for(x=0;x<5;x++){
      scanf("%d %d %d %d %d %d",&numscore[x][0],&numscore[x][1],&numscore[x][2],&numscore[x][3],&numscore[x][4],&numscore[x][5]);
    }    
    
    goto Sel;
    
Edit:
     printf("�п�J�A�n�ק諸�Ǹ�:\t");
     scanf("%d",&edit);
     printf("\n");
     for(x=0;x<5;x++){
       if(edit == numscore[x][0]){
         printf("=================�п�J���Z=================\n");
         printf("���\t�^��\t�ƾ�\t�۵M\t���|\n");
         scanf("%d %d %d %d %d",&numscore[x][1],&numscore[x][2],&numscore[x][3],&numscore[x][4],&numscore[x][5]);
       }
     }
     printf("\n");
     
    goto Head;
     
Print:    
    for(x=0;x<5;x++){
      for(z=1;z<6;z++){
        total[x] += numscore[x][z];
      }
      tot += total[x];
    }
    
    for(x=0;x<5;x++){
      chinese[x] = numscore[x][1];
      english[x] = numscore[x][2];
      math[x] = numscore[x][3];
      science[x] = numscore[x][4];
      community[x] = numscore[x][5];
    }
    
    for(x=0;x<5;x++){
      chi += chinese[x];
      eng += english[x];
      mat += math[x];
      sci += science[x];
      com += community[x];
    }
    
    chinese[5] = (chi/5);
    english[5] = (eng/5);
    math[5] = (mat/5);
    science[5] = (sci/5);
    community[5] = (com/5);
       
    total[5] = (tot/5);
    
    for(x=0;x<5;x++){
      totalverage[x] = (total[x]/5);
      tove += totalverage[x];
    }
    
    totalverage[5] = (tove/5);
    
    for(x=0;x<5;x++){
      Bchi[x] = chinese[x];
      Beng[x] = english[x];
      Bmat[x] = math[x];
      Bsci[x] = science[x];
      Bcom[x] = community[x];
      Btot[x] = total[x];
      Btov[x] = totalverage[x];
    }
    
    bubble(Bchi,4);
    bubble(Beng,4);
    bubble(Bmat,4);
    bubble(Bsci,4);
    bubble(Bcom,4);
    bubble(Btot,4);
    bubble(Btov,4);
       
    for(x=0;x<5;x++){
      if(Bchi[4] == numscore[x][1]){
        Hchi = x;
      }
      if(Beng[4] == numscore[x][2]){
        Heng = x;
      }
      if(Bmat[4] == numscore[x][3]){
        Hmat = x;
      }
      if(Bsci[4] == numscore[x][4]){
        Hsci = x;
      }
      if(Bcom[4] == numscore[x][5]){
        Hcom = x;
      }
      if(Btot[4] == total[x]){
        Htot = x;
      }
      if(Btov[4] == totalverage[x]){
        Htov = x;
      }
    }
        
    printf("\n");
    printf("=============================���Z��=================================\n");
    printf("�Ǹ�\t���\t�^��\t�ƾ�\t�۵M\t���|\t�`��\t����\n");
    for(a=0;a<5;a++){
      for(b=0;b<6;b++){
        printf("%d\t",numscore[a][b]);        
      }
      if(a<5){
        printf("%.0f\t",total[a]);
        printf("%2.2f\t",totalverage[a]);
      }
      printf("\n");
    }
    printf("====================================================================\n");
    printf("����\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\t%3.2f\n",chinese[5],english[5],math[5],science[5],community[5],total[5],totalverage[5]);
    printf("\n");
    printf("�����Ƴ̰����O:\t%d\n",numscore[Hchi][0]);
    printf("�^����Ƴ̰����O:\t%d\n",numscore[Heng][0]);
    printf("�ƾǤ��Ƴ̰����O:\t%d\n",numscore[Hmat][0]);
    printf("�۵M���Ƴ̰����O:\t%d\n",numscore[Hsci][0]);
    printf("���|���Ƴ̰����O:\t%d\n",numscore[Hcom][0]);
    printf("�`�����Ƴ̰����O:\t%d\n",numscore[Htot][0]);
    printf("�������Ƴ̰����O:\t%d\n",numscore[Htov][0]);
    
    goto Sel;
    
End:
    printf("\n\nEND\n");
    system("Pause");
    return 0;
}
