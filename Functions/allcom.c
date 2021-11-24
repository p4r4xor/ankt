
void allcom(char argument[])
{   
    char* args[1000];
    long long int i=0,background=0;
    char* token; 
    char* rest = argument;
    while ((token = strtok_r(rest, " ", &rest))) 
    {
        if(strcmp(token,"&")==0)
        {
            background=1;
        }
        else
        {   args[i]=token;
            ++i;
        }
    }
    args[i]=NULL;
    long long int pid;
    int status;
    pid = fork();
    if(pid<0)
    {
        perror("Fork");
    }
    else if(pid==0)
    {   int k= execvp(args[0],args);
        if(k<0)
        {    printf("\nInvalid Command\n");
             return ;
        }

        exit(0);
    }
    else if(background==0)
    {
        waitpid(pid,&status,0);
    }
}