void history(char cmdline[],char tilda[])
{
    char location[1000],temp[1000];
    strcpy(location,tilda);
    strcpy(temp,tilda);
    strcat(location,"/Functions/history.txt");
    strcat(temp,"/Functions/temp.txt");
    char buf[1000];
    int count = 0;
    FILE *fptr;
    fptr = fopen(location,"ab+");
    while( fgets(buf, 1000, fptr) != NULL )
    {
        count++;
        //printf("%d",count);
    }
    if(count<20)
    {
        fprintf(fptr,"%s\n",cmdline);
        fclose(fptr);
    }
    else
    {   count=0;
        fclose(fptr);
        FILE *fptr1;
        FILE *fptr2;
        fptr1 = fopen(location,"ab+");
        fptr2 = fopen(temp,"ab+");
        while( fgets(buf, 1000, fptr1) != NULL )
        {
            ++count;
            if(count==1)
                ;
            else
            {
                fprintf(fptr2,"%s",buf);
            }
        }
        fprintf(fptr2,"%s\n",cmdline);
        fclose(fptr1);
        fclose(fptr2);
        remove(location);
        rename(temp,location);
    }    
}
void historyprint(char tilda[],char arg[])
{   char location[1000],temp[1000];
    strcpy(location,tilda);
    strcat(location,"/Functions/history.txt");
    char buf[1000];
    FILE *fptr3;
    FILE *fptr4;
    fptr4 = fopen(location,"ab+");
    int num=0;
    while(fgets(buf, 1000, fptr4)!= NULL)
    {   num++;
    }
    fclose(fptr4);
    fptr3 = fopen(location,"ab+");
    if(strcmp(arg,"")==0)
    {   int count=0;
        if(num>=10)
        {    while(fgets(buf, 1000, fptr3)!= NULL)
            {   count++;
                if(count>(num-10))
                    printf("%s",buf);
            }
        }
        else
        {
          while(fgets(buf, 1000, fptr3)!= NULL)
            {  printf("%s",buf);
            }  
        }
    }
    else if(arg[0]=='-')
    {
        int x = arg[1] - '0';
        if((arg[2]!='\0'))
        {    int y = arg[2] - '0';
             x = 10*x+y;
        } 
        if(x>20 || arg[3]!='\0'||x>num)
        {
            printf("Error Only %d commands saved\n",num);
            fclose(fptr3);
            return;
        }
        //printf("%d\n",x);
        int check = num-x;
        //printf("%d\n",check);
        int count=0;
        while(fgets(buf, 1000, fptr3)!= NULL)
        {    count++;
             
             if(count>check)
                printf("%s",buf);
        }
    }
    else
    {
        printf("Error in Input\n");
    }
    fclose(fptr3);
}