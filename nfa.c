#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n,m,f,s,q;
int hash[128];
char sym[1000];
int trans[101][101][101];
int fin[101];
char str[1001];
int i,j,k;
char c;
int num;
int backtrack(int id,int curr)
{
        //printf("%d",id);
        int i,j,k;
        if(id==num)
        return fin[curr];
        if(curr==0)
        return 0;
        k=-1;
        for(k=1;k<=s;k++)
        if(str[id]==sym[k])
        break;
        if(k==-1)
        return 0;
        int l=0;
        while(1)
        {
                if(trans[curr][0][l]==0)
                break;
                if(backtrack(id,trans[curr][0][l]))
                return 1;
                l++;
        }
        l=0;
        while(1)
        {
                if(trans[curr][k][l]==0)
                break;
                if(backtrack(id+1,trans[curr][k][l]))
                return 1;
                l++;
        }
        return 0;
}
int main()
{
        printf("Enter the number of states, final states, initial state,number of symbols\n");
        scanf("%d %d %d %d",&n,&f,&q,&s);
        printf("Enter the final states\n");
        for(i=0;i<f;i++)
        {
                int t;
                scanf("%d",&t);
                fin[t]=1;
        }
        printf("Enter the symbols\n");
        for(i=1;i<=s;i++)
        {
                while(c=getchar(),c!=10 && c!=48);
                
                        scanf("%c",&sym[i]);
                
        }
        sym[0]='$';
        printf("Enter the transition table\n");
        for(int i=1;i<=n;i++)
        {
                printf("%d  \n",i);
                for(j=0;j<=s;j++)
                {
                        printf("%c:: ",sym[j]);
                        k=0;
                        while(1)
                        {
                                int t;
                                scanf("%d",&t);
                                if(t==-1)
                                break;
                                trans[i][j][k++]=t;
                        }
                }
        }
        volatile int t=1;
        while(t)
        {
                printf("Enter the string \n");
                scanf("%s",str);
                //printf("%s",str);
                ///return 0;
                num = strlen(str);
                
                if(backtrack(0,q))
                printf("Accepted\n");
                else
                printf("Not Accepted\n");
                fflush(stdout);
                
                
        }
}
