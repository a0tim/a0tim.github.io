#include <stdio.h>
#include <stdlib.h>

void hanoi(int,int,int,int);
int t=1;

int main(){
    int j;
    printf("�п�J�L�l�ƶq: ");
    scanf("%d",&j);
    hanoi(j,1,2,3);
    
    printf("\n\n");
    system("pause");
    return 0;
}

void hanoi(int n,int p1,int p2,int p3){
    if(n==1){
      printf("�� %d �ӽL�l�q %d ���� %d\t\t�� %d ������\n",n,p1,p3,t);
      t+=1;
    }else{
      hanoi(n-1,p1,p3,p2);
      printf("�� %d �ӽL�l�q %d ���� %d\t\t�� %d ������\n",n,p1,p3,t);t+=1;
      hanoi(n-1,p2,p1,p3);
    }
}
