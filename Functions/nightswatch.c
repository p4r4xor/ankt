int k=0;
char ch='\0';
/*void sig_handler(int signo)
{   printf("%d",signo);
  if (signo == SIGINT)
    k=1;
}*/
bool keydown() {
    struct termios oldt, newt;
    int bytes;

    tcgetattr(STDIN_FILENO, &oldt);

    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    ioctl(STDIN_FILENO, FIONREAD, &bytes);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return bytes > 0;
}
void nightswatch(char argument[])
{
    ch = '\0';
    //printf("%s\n",argument);
    char* arg[1000];
    char* token;
    char* rest=argument;
    int i=0;
    while ((token = strtok_r(rest, " ", &rest))) 
    {
        arg[i]=token;
        ++i; 
    }
    if(i>4)
    {
        printf("Error Too Many Arguments\n");
        return;
    }
    else if((strcmp(arg[1],"-n")!=0)||((strcmp(arg[3],"interrupt")!=0)&&(strcmp(arg[3],"dirty")!=0)))
    {
        printf("Error Wrong Arguments\n");
        return;
    }
    /*if (signal(SIGINT, sig_handler) == SIG_ERR)
  printf("\ncan't catch SIGINT\n");*/
    int time = atoi(arg[2]);
    if(strcmp(arg[3],"interrupt")==0)
    {           FILE* fp;
                char buf[1000];
                fp = fopen("/proc/interrupts","r");
                if(fp == NULL)
                    {
                        printf("Error In File Opening Please Check\n");
                        fclose(fp);
                        return;
                    }
                    
                fgets(buf,1000,fp);
                char* token1 = strtok(buf," ");
                printf("\t");
                for(i=0;i<8;i++)
                {
                    printf("%s\t",token1);
                     token1 = strtok(NULL," ");
                } 
                printf("\n");
            fclose(fp);
            k=0;
            while(1)
            {   if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                FILE* fptr;
                char buf[1000];
                fptr = fopen("/proc/interrupts","r");
                if(fptr == NULL)
                    {
                        printf("Error In File Opening Please Check\n");
                        fclose(fptr);
                        return;
                    }
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                fgets(buf,1000,fptr);
                fgets(buf,1000,fptr);
                fgets(buf,1000,fptr);
                char* token = strtok(buf," ");
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                printf("\t");
                token = strtok(NULL," ");
                for(i=0;i<8;i++)
                {
                    printf("%s\t",token);
                     token = strtok(NULL," ");
                } 
                printf("\n");
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                sleep(time);
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                fclose(fptr);
            }
    }
    else if (strcmp(arg[3],"dirty")==0)
    {       while(1)
            {   
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                FILE* fptr;
                char buf[1000];
                fptr = fopen("/proc/meminfo","r");
                if(fptr == NULL)
                    {
                        printf("Error In File Opening Please Check\n");
                        //fclose(fptr);
                        return;
                    }
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                for(int i=0 ; i<=16;i++)
                {
                    fgets(buf,1000,fptr);
                } 
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                char* token=strtok(buf," ");
                token = strtok(NULL," ");
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                printf("%s ",token);
                token = strtok(NULL," ");
                printf("%s",token);
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                sleep(time);
                if(keydown())
                    ch = getchar();
                if(ch=='q')
                    break;
                fclose(fptr);
            }
    }
    printf("\n");
}