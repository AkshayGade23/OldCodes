#include<stdio.h>
int i=1;
void TowerOfHonoi(int n,char from,char to,char via)
{
    if(n==1)
    printf("%d.  < %c to %c >\n",i++,from,to);

    else {
        TowerOfHonoi(n-1,from,via,to);
        printf("%d.  < %c to %c >\n",i++,from,to);
        TowerOfHonoi(n-1,via,to,from);
    }
}
void main(){
int n = 20;
char from='A',to='B',via='C';

printf("steps are\n");
TowerOfHonoi(n,from,to,via);

}