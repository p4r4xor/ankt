#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include <errno.h>
#include <sys/utsname.h>  
#include <unistd.h>  
#include <libgen.h>
#include <dirent.h>
#include <signal.h>
#include <stdbool.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <grp.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "Functions/pwd.c"
#include "Functions/echo.c"
#include "Functions/cd.c"
#include "Functions/ls.c"
#include "Functions/pinfo.c"
#include "Functions/allcom.c"
#include "Functions/history.c"
#include "Functions/nightswatch.c"

void child_handler(int sig)
    {  
            pid_t pid;
            int status;
            char l[1000];
            pid_t k=waitpid(0, &status, WNOHANG);
            if(k>0)
            {    printf("\nPID No. : %d process has exited ",k);
                int stat = WEXITSTATUS(status);
                if(stat==0)
                    printf("normally\n");
                else
                    printf("abnormally\n");
            }
}
int infiniteloop(int argc, char *argv[])
{   long long int pid = getpid();
    struct utsname username;
    char user[64];
    char filepath[1000];
    char loc[1000];
    char rem[1000];
    long long int tildasize,i;
    getlogin_r(user,sizeof(user)-1);
    uname(&username);
    realpath(argv[0],filepath);
    char *tilda = dirname(filepath);
    //printf("%s\n",tilda);
    tildasize=strlen(tilda);
    getcwd(rem,sizeof(rem));
    
    while(1)
    {   
        getcwd(loc,sizeof(loc));
        //printf("%s\n",loc);
        long long int locsize = strlen(loc);
        int flag=0;
        if(locsize>tildasize)
        {   
            //printf("%c",loc[tildasize]);
            if(loc[tildasize]!='/')
                flag=1;
        }
        if(flag==0)
        {    for(i=0;i<tildasize;i++)
            {
                if(loc[i]==tilda[i])
                    flag=0;
                else
                {   
                    flag=1;
                    break;
                }
            }
        }
        if(locsize>tildasize)
        {   
            printf("%c",loc[tildasize]);
            if(loc[tildasize]!='/')
                flag=1;
        }
        printf("%s@%s:",user,username.sysname);
        if(flag==0)
        {
            printf("~");
            for(i=tildasize;i<locsize;i++)
                printf("%c",loc[i]);
        }
        else
        {
            printf("%s",loc);   
        }
        printf("> ");
        char *cmdline = (char*)malloc(1000*sizeof(char));
        char *fcmdline = (char*)malloc(1000*sizeof(char));
        scanf(" %[^\t\n]s",cmdline);
        history(cmdline,tilda);
        //printf("%s\n",cmdline);
        char* token;
        char* rest = cmdline;
        struct sigaction sa;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags = 0;
        sa.sa_handler = child_handler;

        sigaction(SIGCHLD, &sa, NULL);
        while((token = strtok_r(rest, ";", &rest)))
        {
            //printf("%s\n",token);
            char *tempcmdline= (char*)malloc(1000*sizeof(char));
            char *argument= (char*)malloc(1000*sizeof(char));
            char *command= (char*)malloc(1000*sizeof(char));
            long long int commandlength;
            long long int linelength,k=0;
            
            strcpy(tempcmdline,token);
            strcpy(fcmdline,tempcmdline);
            //printf("%s\n",tempcmdline);
            linelength=strlen(tempcmdline);
            char *token1 = strtok(tempcmdline," ");
            commandlength=strlen(token1);
            strcpy(command,token1);
            token1 = strtok(NULL," ");
            if(token1!=NULL)
            {   char *temp= (char*)malloc(1000*sizeof(char));
                strcpy(temp,token1);
                token1 = strtok(NULL," ");
                if (token1!=NULL)
                {
                    if((strcmp(token1,temp)!=0)&&((strcmp(token1,"-l")==0)||(strcmp(token1,"-a")==0))&&((strcmp(temp,"-l")==0)||(strcmp(temp,"-a")==0)))
                    {
                        strcpy(argument,"-la");
                    }
                }
                else
                strcpy(argument,temp); 
            }
            else
            {
                strcpy(argument,"");
            }
        // printf("%s\n",argument);
        // printf("%s, %s, %s",cmdline,command,argument);
            if(strcmp(command,"pwd")==0)
            {
                pwd();
            }
            else if(strcmp(command,"echo")==0)
            {
                echo(argument);
            }
            else if(strcmp(command,"cd")==0)
            {
                cd(argument,tilda,rem);
            }
            else if(strcmp(command,"ls")==0)
            {
                //printf("%s\n",argument);
                ls(argument,tilda);
            }
            else if(strcmp(command,"pinfo")==0)
            {
                pinfo(argument,pid,tilda);
            }
            else if(strcmp(command,"history")==0)
            {
                historyprint(tilda,argument);
            }
            else if(strcmp(command,"nightswatch")==0)
            {
                nightswatch(fcmdline);
            }
            else
            {
                allcom(fcmdline);
            }
        }
    }
}
int main(int argc, char *argv[])
{
    infiniteloop(argc, argv);
}