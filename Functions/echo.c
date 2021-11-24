void echo(char arg[])
{
    long long int flag=0;
    if(arg[0]=='"')
    {   long long int count,i;
        for(i=0;i<strlen(arg);i++)
        {
            if(arg[i]!='"')
            {
                break;
            }
        }
        count=i;
        for(i=strlen(arg)-count;i<strlen(arg);i++)
        {
            if(arg[i]!='"')
            {    flag=1;
                 break;    
            }
        }
        if(flag==1)
        {
            printf("Error in Input\n");
            return ;
        }
        for(i=count;i<strlen(arg)-count;i++)
            printf("%c",arg[i]);
    }
    else if(arg[0]=='\'')
    {   long long int count,i;
        for(i=0;i<strlen(arg);i++)
        {
            if(arg[i]!='\'')
            {
                break;
            }
        }
        count=i;
        for(i=strlen(arg)-count;i<strlen(arg);i++)
        {
            if(arg[i]!='\'')
            {    flag=1;
                 break;    
            }
        }
        if(flag==1)
        {
            printf("Error in Input\n");
            return ;
        }
        for(i=count;i<strlen(arg)-count;i++)
            printf("%c",arg[i]);
    }
    else
    {
        printf("%s",arg);
    }
    printf("\n");
}