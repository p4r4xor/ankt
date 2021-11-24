void pinfo(char arg[], long long int pid,char tilda[])
{
    if(strcmp(arg,"")==0)
    {
        FILE *fptr;
        char str[1000],loc[1000],final[2000];
        printf("pid -- %lld\n",pid);
        sprintf(str, "%lld", pid);
        strcpy(loc,"/proc/");
        strcat(loc,str);
        //printf("%s\n",loc);
        strcpy(str,"/status");
        strcpy(final,loc);
        strcat(final,str);
        fptr = fopen(final,"r");
        if(fptr == NULL)
        {
            printf("Error Please Check\n");
            fclose(fptr);
            return;
        }
        char buf[10];
        long long int flag=0;
        printf("Process Status -- ");
        while( fscanf(fptr, "%s", buf) != EOF )
        {
            
            if(flag==1)
            {
                printf("%s\n",buf);
                break;
            }
            if(strcmp(buf,"State:")==0)
                ++flag;
        }

        //printf("\n");
        fclose(fptr);
        strcpy(final,loc);
        strcpy(str,"/status");
        strcat(final,str);

        flag=0;
        printf("Memory -- ");
        FILE *fp = fopen(final,"r");
 
        flag=0;
 
        while( fscanf(fp, "%s", buf) != EOF )
        {
            
            if(flag==1)
            {
                printf("%s\n",buf);
                break;
            }
            if(strcmp(buf,"VmSize:")==0)
                ++flag;
        }
        char path[1000];
        strcpy(final,loc);
        strcpy(str,"/exe");
        strcat(final,str);
        realpath(final,path);
        printf("Executable Path -- ");
        long long int locsize = strlen(path);
        long long int tildasize = strlen(tilda);
        flag=0;
        long long int i;
        for(i=0;i<tildasize;i++)
        {
            if(path[i]==tilda[i])
                flag=0;
            else
            {   
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("~");
            for(i=tildasize;i<locsize;i++)
                printf("%c",path[i]);
        }
        else
        {
            if(strcmp(path,final)==0)
                printf("Can't Access Due To Permissions");
            else
                printf("%s",path);
        }
        printf("\n");
    }
    else
    {
        FILE *fptr;
        char str[1000],loc[1000],final[2000];
        printf("pid -- %s\n",arg);
        strcpy(str,arg);
        strcpy(loc,"/proc/");
        strcat(loc,str);
        //printf("%s\n",loc);
        strcpy(str,"/status");
        strcpy(final,loc);
        strcat(final,str);
        fptr = fopen(final,"r");
        if(fptr == NULL)
        {
            printf("Error Please Check\n");
            fclose(fptr);
            return;
        }
        char buf[10];
        long long int flag=0;
        printf("Process Status -- ");
        while( fscanf(fptr, "%s", buf) != EOF )
        {
            
            if(flag==1)
            {
                printf("%s\n",buf);
                break;
            }
            if(strcmp(buf,"State:")==0)
                ++flag;
        }

        //printf("\n");
        fclose(fptr);
        strcpy(final,loc);
        strcpy(str,"/status");
        strcat(final,str);

        flag=0;
        printf("Memory -- ");
        FILE *fp = fopen(final,"r");
 
        flag=0;
 
        while( fscanf(fp, "%s", buf) != EOF )
        {
            
            if(flag==1)
            {
                printf("%s\n",buf);
                break;
            }
            if(strcmp(buf,"VmSize:")==0)
                ++flag;
        }
        char path[1000];
        strcpy(final,loc);
        strcpy(str,"/exe");
        strcat(final,str);
        realpath(final,path);
        printf("Executable Path -- ");
        long long int locsize = strlen(path);
        long long int tildasize = strlen(tilda);
        flag=0;
        long long int i;
        for(i=0;i<tildasize;i++)
        {
            if(path[i]==tilda[i])
                flag=0;
            else
            {   
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("~");
            for(i=tildasize;i<locsize;i++)
                printf("%c",path[i]);
        }
        else
        {
            if(strcmp(path,final)==0)
                printf("Can't Access Due To Permissions");
            else
                printf("%s",path);
        }
        printf("\n");
    }
}