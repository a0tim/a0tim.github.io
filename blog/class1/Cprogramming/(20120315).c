#include <stdio.h>
#include <stdlib.h>

int add_v(int a,int b);
void add_a(int* a,int* b,int* c);
int add_v(int a,int b){
    int c = 0;
    c = a + b;
    a = a + b;
    b = b - a;
    return c;
}
void add_a(int* a,int* b,int* c){
    *c = *a + *b;
    *a = *a + *b;
    *b = *b - *a;
}

int main(){
    int x=0,y=0,z=0;
    
    x=10;y=20;
    z = add_v(x,y);
    printf("callbyvalue:\nx= %d\ty= %d\tz= %d\n",x,y,z);
    
    x=10;y=20;
    add_a(&x,&y,&z);
    printf("callbyadress:\nx= %d\ty= %d\tz= %d\n",x,y,z);

    printf("\n\n");
    system("pause");
    return 0;
}
