#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,n1;
    int x;
    n=0;n1=0;x=0;
    
    printf("�п�J���@���:\n");
    scanf("%d",&n);
    n1 = n;
    
    printf("�ϦV��X�����G:");
        
    while(n!=0){
      x = x * 10 + (n%10);
      n /= 10;
      }
    
    printf("\n%d\n\n",x);  
    
    printf("%d - %d = %d\n",x,n1,x-n1);

system("pause");
return 0;
}
