#include <stdio.h>
#include <stdlib.h>
//���{���Ӧ�...�����f... 
void cal_1(int,int);
void cal_2(int,int);
int B = 0;

void cal_1(int x,int y){
    if(x==0){
      B = y;
      printf("%d\n",y);
    }else if(y==0){
      B = x;
      printf("%d\n",x);
    }else{
      if(x>y){
        x = x % y;
      }else{
        y = y % x;
      }
      cal_1(x,y);
    }
}
void cal_2(int x,int y){
    int temp = 0;
    temp = x * y / B;
    printf("%d\n",temp);
}

int main(){
    int a = 0,b = 0;
    int B = 0;
    
    printf("�п�J��� A , B :");
    scanf("%d %d",&a,&b);
    printf("��Ƴ̤j���]�Ƭ�: ");
    cal_1(a,b);
    printf("��Ƴ̤p�����Ƭ�: ");
    cal_2(a,b);
    
    printf("\n\n");
    printf("\n\n....�{���]�p�������f--�Ф���N�I�I�I");
    system("pause");
    return 0;
}
