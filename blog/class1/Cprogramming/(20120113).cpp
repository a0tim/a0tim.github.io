#include <stdio.h>
#include <stdlib.h>

int main(){
    float list[2][5]={2.5,3,3.5,4,4.5,3,3.5,4,4.5,5};
Select:
    float list_edit=0,cal_x=0,cal_list=0,price=0;
    int select=0,e_f=0,e_r=0,cal_f=0;
    int i=0,j=0,k=0;

    printf("�z�w�w�w�w�w�w�w�w�w�{\n");
    printf("�x1.�d�߭p����      �x\n�x2.�ק�q�O�p��    �x\n�x3.�p��q�O        �x\n�x4.����            �x\n");
    printf("�|�w�w�w�w�w�w�w�w�w�}\n");
    printf("�п��:");
    scanf("%d",&select);
    
    switch(select){
      case 1:
           goto Print;
      case 2:
           goto Edit;
      case 3:
           goto Cal;
      case 4:
           goto End;
      default:
           printf("�L���ﶵ!!�Э��s���\n");
           goto Select;
    }

Print:
    printf("====�d�߭p����====\n"); 
    printf("\t 0~200\t200~300\t300~400\t400~500\t  500+  \n");
    printf("�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w�w\n"); 
    for(j=0;j<2;j++){
        if(j==0){
          printf("�V�u�q�O");
        }else{
          printf("�L�u�q�O");
        }
      for(i=0;i<5;i++){
        printf("  %.1f\t",list[j][i]);
        if(i==4){
          printf("\n");
        }
      }
    }
    printf("\n");
    
    goto Select;
Edit:
    printf("====�ק�q�O�p��====\n");
    printf("�п�J�A�n�ק諸�u�`:   1.�V�u  2.�L�u\n");
    scanf("%d",&e_f);e_f-=1;
    printf("�п�J�A�n�ק諸�q�O�d��:\n");
    printf("1. 0~200\n2. 200~300\n3. 300~400\n4. 400~500\n5. 500+\n");
    scanf("%d",&e_r);e_r-=1;
    printf("�ثe���欰: %.1f\n",list[e_f][e_r]); 
    printf("�п�J�n�諸����:");
    scanf("%f",&list_edit);
    list[e_f][e_r] = list_edit;
    printf("����w��אּ: %.1f\n\n",list[e_f][e_r]);
    
    goto Select;
Cal:
    printf("�п�J�A�n�p�⪺�u�`:   1.�V�u  2.�L�u\n");
    scanf("%d",&cal_f);
    printf("�п�J�A���q�O�׼�: ");
    scanf("%f",&cal_x);
    if(cal_x>=0 && cal_x<=200){
      price = cal_x * list[(cal_f-1)][0];
    }else if(cal_x>200 && cal_x<=300){
      price = 200 * list[(cal_f-1)][0];
      price += (cal_x-200) * list[(cal_f-1)][1];
    }else if(cal_x>300 && cal_x<=400){
      price = 200 * list[(cal_f-1)][0];
      price += 100 * list[(cal_f-1)][1];
      price += (cal_x-300) * list[(cal_f-1)][2];
    }else if(cal_x>400 && cal_x<=500){
      price = 200 * list[(cal_f-1)][0];
      price += 100 * list[(cal_f-1)][1];
      price += 100 * list[(cal_f-1)][2];
      price += (cal_x-400) * list[(cal_f-1)][3];
    }else if(cal_x>500){
      price = 200 * list[(cal_f-1)][0];
      price += 100 * list[(cal_f-1)][1];
      price += 100 * list[(cal_f-1)][2];
      price += 100 * list[(cal_f-1)][3];
      price += (cal_x-500) * list[(cal_f-1)][4];
    }else{
      printf("�A��J���׼Ƥ��X�z!!�Э��s��J!!\n");
      goto Cal;
    }
    
    printf("�g�L�p��,�A���q�O����:\t$ %.0f\n",price);
    printf("\n");
    
    goto Select;
End:
    printf("\n\nEND\n");
    system("Pause");
    return 0;
}
