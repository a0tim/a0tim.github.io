#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
  int input = 0,count = 1;
  int A = 0,B = 0;
  int Q[4]={0},Ans[4]={0};
  int i = 0,j = 0,k = 0,l = 0,m =0,n = 0;
  int end = 0;

Question:  
  srand(time(NULL));

  for(l=0;l<=3;l++){
    Q[l] = rand() % 10;
  }
  for(m=0;m<=3;m++){
    for(n=0;n<=3;n++){
      if(m!=n){
        if(Q[m]==Q[n]){
          printf("�X�D��......\r");
          goto Question;
        }
      }
    }
  }
    
  printf("�п�J4��Ʀr,���o����!!\n\n");
  
Answer:
  printf("�q��%d��:\n",count);
  scanf("%d",&input);
  for(k=3;k>=0;k--){
    Ans[k] = input % 10;
    input /= 10;
  }
  
  for(i=0;i<=3;i++){
    for(j=0;j<=3;j++){
      if(Ans[i] == Q[j]){
        if(i == j){
          A++;
        }else{
          B++;
        }
      }
    }
  }
  
  if(A == 4){
    printf("\t%dA %dB\n",A,B);
    printf("\n~~~!!!BINGO!!!~~~\n");
    printf("�A�`�@�q�F%d��",count);
  }else{
    printf("\t%dA %dB\n",A,B);
    count++;
    A = 0;B = 0;
    goto Answer;
  }
  
  printf("\n\n==�A���@���п�J1 ; ���}�п�J2==\n");
  scanf("%d",&end);
  if(end == 1){
    count = 1;
    A = 0;B = 0;
    goto Question;
  }
    
  printf("\n\nEND\n");  
  system("Pause");
  return 0;
}
