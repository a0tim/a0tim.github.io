#include<stdio.h>
#include<stdlib.h>

int main(){
    int count;
        
    for(count=1;count<=20;count++){
       printf("%d",count);
       if((count%2)==1){
         printf("���_��\n");
       }else{
         printf("������\n");                             
       }
    }
    
    system("pause");
    return 0;
    }
