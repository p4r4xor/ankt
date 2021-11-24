void cd(char arg[],char tilda[],char rem[])
{
    char location[1000];
    char temp[2000];
    char temp1[2000];
    getcwd(location,sizeof(location));
    if((strcmp(arg,"~")==0)||(strcmp(arg,"")==0))
    {
        chdir(tilda);
    }
    else if(strcmp(arg,"..")==0)
    {
        chdir("..");
    }
    else if(strcmp(arg,".")==0)
    {
        chdir(".");
    }
    else if(strcmp(arg,"-")==0)
    {
        chdir(rem);
    }
    else if(arg[0]=='~')
    {
        strcpy(temp,tilda);
        for(long long int i=1;i<strlen(arg);i++)
            temp1[i-1]=arg[i];
        strcat(temp,temp1);
        if( access(temp, F_OK ) != -1 ) 
        {
            chdir(temp);
        } 
        else 
        {
            printf("This Location Doesn't Exist\n");
        }
    }
    else
    {
        if( access(arg, F_OK ) != -1 ) 
        {
            chdir(arg);
        } 
        else 
        {
            printf("This Location Doesn't Exist\n");
        }
    }
    strcpy(rem,location);
}
