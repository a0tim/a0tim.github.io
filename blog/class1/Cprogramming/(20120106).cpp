#include <stdio.h>
#include <stdlib.h>

int main(){
    int num[5][7]={0};    //�ŧi�H��5�H�A����:�Ǹ�.���.�^��.�ƾ�.�۵M.���|.�`��(7��)
    char name[5][10];     //�ŧi�H�W�}�C 
Head://======================================================================================================
    float verage[7]={0};  //�ŧi�U�쥭���}�C
    float totalverage[5]={0};  //�ŧi�ӤH�`�������}�C
    int chi=0,eng=0,mat=0,sci=0,com=0,tot=0;  //�ŧi�ܼƥΨ��x�s�U��̰����̪��Ǹ� 
    int select=0,edit=0,number=0,edi=0,sco=0;
    int x=0,y=0;
    float i=0,j=0;

Sel://=======================================================================================================
    printf("����������������������\n");
    printf("��  1.��J���Z      ��\n��  2.�C�L���Z��    ��\n��  3.�ק令�Z      ��\n��  4.�d�߭ӤH���Z  ��\n��  5.���}          ��\n");
    printf("����������������������\t");
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
           goto Score;
      case 5:
           goto End;
      default :
           goto Sel;
    }
    
Input://=====================================================================================================
    printf("�p�G�̰��������ƬۦP�̶ȷ|��ܤ@�H!!!\n");
    printf("=================�п�J���Z=================\n");
    for(x=0;x<5;x++){
      printf("�ǥ;Ǹ�:\t");
      scanf("%d",&num[x][0]);
      printf("�ǥͩm�W:\t");
      scanf("%s",name[x]);
      reinputscore: 
      printf("���-�^��-�ƾ�-�۵M-���|\n");
      scanf("%d %d %d %d %d",&num[x][1],&num[x][2],&num[x][3],&num[x][4],&num[x][5]);
      for(y=1;y<6;y++){
        if(num[x][y]<0 || num[x][y]>100){
          printf("�z�ҿ�J�����Z���~!!!�Э��s��J!!!\n");
          goto reinputscore;
        }
      }      
    }
    printf("\n");
    
    goto Sel;
    
Edit://======================================================================================================
    printf("�п�J�A�n�ק諸�Ǹ�:\t");
    scanf("%d",&edit);
    printf("\n");
    for(x=0;x<5;x++){
      if(edit == num[x][0]){
        edi = 1;
        printf("=================�п�J���Z=================\n");
        reinputedit:
        printf("���-�^��-�ƾ�-�۵M-���|\n");
        scanf("%d %d %d %d %d",&num[x][1],&num[x][2],&num[x][3],&num[x][4],&num[x][5]);
        for(y=1;y<6;y++){
          if(num[x][y]<0 || num[x][y]>100){
            printf("�z�ҿ�J�����Z���~!!!�Э��s��J!!!\n");
            goto reinputedit;
          }
        } 
      }
    }
    if(edi == 0){
      printf("�d�ߤ���z�ҿ�J���Ǹ�!!!�Э��s��J�@��!!!\n");
      goto Edit;
    }
    printf("\n");
     
    goto Head;    

Print://=====================================================================================================
    for(x=0;x<5;x++){
      num[x][6] = num[x][1]+num[x][2]+num[x][3]+num[x][4]+num[x][5];  //����ΨӲ֥[�ӤH���Ʀ��`�� 
      totalverage[x] = num[x][6]/5;  //����Ψӭp��ӤH�������� 
    } 
    for(x=0;x<5;x++){           //�������ΨӲ֥[�U�쪺���� 
      for(y=0;y<5;y++){
        verage[y] = verage[y] + num[x][y+1];
      } 
      i += num[x][6];           //����ΨӲ֥[�C�H�`�� 
      j += totalverage[x];      //����ΨӲ֥[�C�H����
    }
    
    for(x=0;x<5;x++){           //�������ΨӱN�֥[�᪺�U���`������ 
      verage[x] = verage[x]/5;
    }
    verage[5] = i/5;            //����N�֥[�᪺�C�H�`������ 
    verage[6] = j/5;            //����N�֥[�᪺�C�H�������� 
                   
    for(x=0;x<5;x++){           //�������Ψӧ�X�C��̰����P�� 
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
    printf("==================================���Z��=================================\n");
    printf("�Ǹ�\t�m�W\t���\t�^��\t�ƾ�\t�۵M\t���|\t�`��\t����\n");
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
    printf("����\t\t");
    for(x=0;x<7;x++){
      printf("%.2f\t",verage[x]);
    }
    printf("\n\n");
    printf("�����Ƴ̰����O:\t%d\t%s\n",num[chi][0],name[chi]);
    printf("�^����Ƴ̰����O:\t%d\t%s\n",num[eng][0],name[eng]);
    printf("�ƾǤ��Ƴ̰����O:\t%d\t%s\n",num[mat][0],name[mat]);
    printf("�۵M���Ƴ̰����O:\t%d\t%s\n",num[sci][0],name[sci]);
    printf("���|���Ƴ̰����O:\t%d\t%s\n",num[com][0],name[com]);
    printf("�`�����Ƴ̰����O:\t%d\t%s\n",num[tot][0],name[tot]);
    printf("�������Ƴ̰����O:\t%d\t%s\n",num[tot][0],name[tot]);
    printf("\n");
    
    goto Head;

Score://============================================================================================
    printf("�п�J�n�d�ߪ��ǥ;Ǹ�:");
    scanf("%d",&number);
    for(x=0;x<5;x++){
       if(number == num[x][0]){
         sco = 1;
         printf("�z�Ҭd�ߪ��O:\n\n");
         printf("�Ǹ�: %d\t�ǥͩm�W: %s\n",num[x][0],name[x]);
         printf("=================���Z=================\n");
         printf("���\t�^��\t�ƾ�\t�۵M\t���|\n");
         printf("%d\t%d\t%d\t%d\t%d\n",num[x][1],num[x][2],num[x][3],num[x][4],num[x][5]);
       }
     }
    if(sco == 0){
      printf("�d�ߤ���z�ҿ�J���Ǹ�!!!�Э��s��J�@��!!!\n");
      goto Score;
    }
    printf("\n");
    
    goto Sel;
    
End://==============================================================================================
    printf("\n\nEND\n");
    system("pause");
    return 0;
}
