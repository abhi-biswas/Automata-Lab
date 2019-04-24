#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char regex[100],input[100];
int len,len1,i,j,k,l;
char copy[200];
int check=0,ans=0;

int strcmpp(char copy1[],char copy2[])
{
     //printf("herestrcmmp\n");
        int len1=strlen(copy1);
        int len2=strlen(copy2);
        if(len1!=len2)
                return -1;
        for(i=0;i<len1;i++)
        if(copy1[i]!=copy2[i]&&copy1[i]!='.'&&copy2[i]!='.')
                return -1;

        return 0;
}

void fun(int id,int pointer)
{
        //printf("%s %d %d\n",copy,id,pointer);
        if(ans==1)
        return ;
        if(id==len && pointer==len1)
        if(strcmpp(input,copy)==0)
        {
                ans=1;
                return;
        }
        if(id>=len || pointer >=len1)
        return ;
        if(regex[id]=='*'||regex[id]=='+')
        {
                char cpyy[2];
                cpyy[0]=regex[id-1];
                cpyy[1]='\0';
                int len =1;
                int pointerr=pointer;
                if(regex[id]=='*')
                fun(id+1,pointer);
                for(int i=0;;i++)
                {
                        //printf("Here\n");
                       for(int k=0;k<len;k++)
                       copy[pointerr++]=cpyy[k];
                       copy[pointerr]='\0';
                       if(pointerr>len1)
                       break;
                       fun(id+1,pointerr);
                }
        
        }
        else
        {
                if(id<len-1 && regex[id+1]=='*'||regex[id+1]=='+')
                return fun(id+1,pointer);
                else
                {
                        
                        copy[pointer]=regex[id];
                        copy[pointer+1]='\0';
                        return fun(id+1,pointer+1);
                
                }
        
        }

}

int main()
{
        
        printf("Enter the Regular Expression :: \n");
        scanf("%s",regex);
        
        while(1)
        {
               copy[0]='\0';
               printf("Enter the Input String ($ to Exit)\n");
               scanf("%s",input);
               if(input[0]=='$')
                    break;
               len=strlen(regex);
               len1=strlen(input);
               check=0;
               ans=0;
               fun(0,0);
               if(ans==1)
                         printf("ACCEPTED\n");
               else
                         printf("NOT ACCEPTED\n");
        }

return 0;

}
