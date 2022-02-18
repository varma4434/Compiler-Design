#include<stdio.h>
#include<string.h>
#include<ctype.h>
char gram[10][10],res[10];
int k=0;
void first(char g,int n)
{
    if(!(isupper(g)))
        res[k++]=g;
    else
    {
        for(int i=0;i<n;i++)
        {
            if(gram[i][0]==g)
            {
                if(islower(gram[i][3]))
                    res[k++]=gram[i][3];
                else
                    first(gram[i][3],n);
            }
        }
    }
}
void follow(char c,int n)
{
    if(gram[0][0]==c)
        res[k++]='$';
    for(int i=0;i<n;i++)
    {
        for(int j=3;j<strlen(gram[i]);j++)
        {
            if(gram[i][j]==c)
            {
                if(gram[i][j+1]!='\0')
                    first(gram[i][j+1],n);
                if(gram[i][j+1]=='\0' && c!=gram[i][0])
                    follow(gram[i][0],n);
            }
        }
    }
}
int main()
{
     char nt;
     int n;
     printf("Enter No of Productions ");
    scanf("%d",&n);
    printf("Enter the Productions");
    for(int i=0;i<n;i++)
    {
        scanf("%s",gram[i]);
    }
    for(int i=0;i<n;i++)
    {
      k=0;
     follow(gram[i][0],n);
    printf("Follow of of %c is {",gram[i][0]);
    for(int i=0;i<k;i++)
    {
        printf(" %c ",res[i]);
    }
    printf("}");
    printf("\n");
    }
   return 0;
}
