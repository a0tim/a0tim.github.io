#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    int id;
    char name[10];
    int c_score;
    int e_score;
    int m_score;
    int s_score;
}myscore[5];

int main(){
    int i;
    FILE* fptr;
    fptr = fopen("score.txt","r");
    for(i=0;i<5;i++){
      fscanf(fptr,"%d\t%s\t%d\t%d\t%d\t%d\n",&myscore[i].id,
                                             &myscore[i].name,
                                             &myscore[i].c_score,
                                             &myscore[i].e_score,
                                             &myscore[i].m_score,
                                             &myscore[i].s_score);
    }
    fclose(fptr);
    
    printf("\t學號\t姓名\t國文\t英文\t數學\t自然\n");
    for(i=0;i<5;i++)
    printf("\t%d\t%s\t%d\t%d\t%d\t%d\n",myscore[i].id,
                                        myscore[i].name,
                                        myscore[i].c_score,
                                        myscore[i].e_score,
                                        myscore[i].m_score,
                                        myscore[i].s_score);
    
    system("pause");
    return 0;
}
