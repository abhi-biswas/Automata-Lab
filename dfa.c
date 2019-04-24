#include<stdio.h>
#include<stdlib.h>
int trans[1001][1001];
int fin[1001];
char s[1001];
int n,f,sym,q;
int i,j,k;
int main()
{
        printf("Enter the number of states , final states, symbols ,initial state\n");
        scanf("%d %d %d %d",&n,&f,&sym,&q);
        printf("Enter the final states\n");
        for(i=0;i<f;i++)
        {
                scanf("%d",&fin[i]);
        }
        printf("Enter the symbols\n");
        for(i=0;i<sym;i++)
        {
                while(getchar()!=10);
                scanf("%c",&s[i]);
        }
        printf("Enter the transitions\n");
        for(i=1;i<=n;i++)
        {
                printf("For state %d \n",i);
                for(int j=0;j<sym;j++)
                {
                        scanf("%d",&trans[i][j]);
                }
        }
        while(1)
        {
                //while(getchar()!=10);
                char str[100];
                printf("Enter the string\n");
                scanf("%s",str);
                printf("%s",str);
                int curr=q;
                i=0;
                while(str[i])
                {
                        j=-1;
                        for(j=0;j<sym;j++)
                        {
                                if(s[i]==str[j])
                                break;
                        }
                        if(j==-1)
                        {
                                printf("Not Accepted\n");
                                continue;
                        }
                        curr=trans[curr][j];
                        i++;
                        
                }
                int f=1;
                for(j=0;j<f;j++)
                {
                        if(fin[j]==curr)
                        {
                                printf("Accepted\n");
                                f=0;
                                break;
                        }
                }
                if(f)
                {
                        printf("Not Accepted\n");
                }
        }
}
