#include<stdio.h>
#include<stdlib.h>

int main(){
    int s_chinese,s_english,s_math;
    int count,score;
    int check;
    char chr;
    char c_chinese,c_english,c_math;
    
CH:        
    printf("���п�J������\n");
    scanf("%d",&s_chinese);
    if(s_chinese>100 || s_chinese<0){
    printf("!!!�A��J�������Ʀ��~�A�ЦA��J�@��!!!\n");
    goto CH;
    }
EN: 
    printf("���п�J�^�����\n");
    scanf("%d",&s_english);
    if(s_english>100 || s_english<0){
    printf("!!!�A��J���^����Ʀ��~�A�ЦA��J�@��!!!\n");
    goto EN;
    }
MA: 
    printf("���п�J�ƾǤ���\n");
    scanf("%d",&s_math);
    if(s_math>100 || s_math<0){
    printf("!!!�A��J���ƾǤ��Ʀ��~�A�ЦA��J�@��!!!\n");
    goto MA;
    } 
CHECK:
    printf("�A��J���U����Ƭ�:\n\t���:\t%d\t�^��:\t%d\t�ƾ�:\t%d\n",s_chinese,s_english,s_math);
    printf("�������T�п�J1�A���~�п�J2����\n");
    scanf("%d",&check);
    if(check == 1){
             goto START;
    }else if(check == 2){
             goto CH;
    }
START:
    for(count = 0;count < 3;count++){
      if(count == 0){              /*������if�ΨӧP�w��بîM��score*/
       score = s_chinese;
      }else if(count == 1){
        score = s_english;
      }else if(count == 2){
        score = s_math;
      }
      
      if(score <= 100 && score >= 90){      /*������if�ΨӧP�wscore�����šA�ç⵲�G���w��chr*/
       chr = 'A';
      }else if(score < 90 && score >= 80){
        chr = 'B';
      }else if(score < 80 && score >= 70){
        chr = 'C';
      }else if(score < 70 && score >= 60){
        chr = 'D';
      }else if(score < 60 && score >= 0){
        chr = 'E';
      }
      
      if(count == 0){           /*������if�ΨӧP�w�ثe��بç�chr���ū��w���U���*/
       c_chinese = chr; 
      }else if(count == 1){
        c_english = chr;
      }else if(count == 2){
        c_math = chr;
      }
      chr = ' ';      /*�M��chr��������*/ 
    }
END:
    printf("���Z���Ť��O��:\n���>>>%c\n�^��>>>%c\n�ƾ�>>>%c\n",c_chinese,c_english,c_math);
    printf("�z--------�{\n�xA=100~90�x\n�xB= 89~80�x\n�xC= 79~70�x\n�xD= 69~60�x\n�xE= 59~ 0�x\n�|--------�}\n");
    
    system("pause");
    return 0;
    }
