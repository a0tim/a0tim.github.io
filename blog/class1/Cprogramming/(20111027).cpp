#include<stdio.h>
#include<stdlib.h>

int main(){
    int s_chinese,s_english,s_math;
    int count,score;
    int check;
    char chr;
    char c_chinese,c_english,c_math;
    
CH:        
    printf("§請輸入國文分數\n");
    scanf("%d",&s_chinese);
    if(s_chinese>100 || s_chinese<0){
    printf("!!!你輸入的國文分數有誤，請再輸入一次!!!\n");
    goto CH;
    }
EN: 
    printf("§請輸入英文分數\n");
    scanf("%d",&s_english);
    if(s_english>100 || s_english<0){
    printf("!!!你輸入的英文分數有誤，請再輸入一次!!!\n");
    goto EN;
    }
MA: 
    printf("§請輸入數學分數\n");
    scanf("%d",&s_math);
    if(s_math>100 || s_math<0){
    printf("!!!你輸入的數學分數有誤，請再輸入一次!!!\n");
    goto MA;
    } 
CHECK:
    printf("你輸入的各科分數為:\n\t國文:\t%d\t英文:\t%d\t數學:\t%d\n",s_chinese,s_english,s_math);
    printf("◎◎正確請輸入1，錯誤請輸入2◎◎\n");
    scanf("%d",&check);
    if(check == 1){
             goto START;
    }else if(check == 2){
             goto CH;
    }
START:
    for(count = 0;count < 3;count++){
      if(count == 0){              /*此部分if用來判定科目並套換score*/
       score = s_chinese;
      }else if(count == 1){
        score = s_english;
      }else if(count == 2){
        score = s_math;
      }
      
      if(score <= 100 && score >= 90){      /*此部分if用來判定score的等級，並把結果指定給chr*/
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
      
      if(count == 0){           /*此部分if用來判定目前科目並把chr等級指定給各科目*/
       c_chinese = chr; 
      }else if(count == 1){
        c_english = chr;
      }else if(count == 2){
        c_math = chr;
      }
      chr = ' ';      /*清空chr內的等級*/ 
    }
END:
    printf("成績等級分別為:\n國文>>>%c\n英文>>>%c\n數學>>>%c\n",c_chinese,c_english,c_math);
    printf("┌--------┐\n│A=100~90│\n│B= 89~80│\n│C= 79~70│\n│D= 69~60│\n│E= 59~ 0│\n└--------┘\n");
    
    system("pause");
    return 0;
    }
