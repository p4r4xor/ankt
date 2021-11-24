/*void month_finder(char month[])
{
    if(strcmp(month,"01")==0)
        printf(" Jan");
    else if(strcmp(month,"02")==0)
        printf(" Feb");
    else if(strcmp(month,"03")==0)
        printf(" Mar");
    else if(strcmp(month,"04")==0)
        printf(" Apr");
    else if(strcmp(month,"05")==0)
        printf(" May");
    else if(strcmp(month,"06")==0)
        printf(" Jun");
    else if(strcmp(month,"07")==0)
        printf(" Jul");
    else if(strcmp(month,"08")==0)
        printf(" Aug");
    else if(strcmp(month,"09")==0)
        printf(" Sep");
    else if(strcmp(month,"10")==0)
        printf(" Oct");
    else if(strcmp(month,"11")==0)
        printf(" Nov");
    else if(strcmp(month,"12")==0)
        printf(" Dec");
}*/
void ls(char arg[], char tilda[]) 
{ 
    if(strcmp(arg,"")==0)
    {
        struct dirent *directory_pointer;   
        DIR *directory_reader = opendir("."); 
    
        if (directory_reader == NULL)
        { 
            printf("Error : Could Not Open Directory\n"); 
            return ; 
        } 
        directory_pointer = readdir(directory_reader);
        while (directory_pointer!= NULL) 
        {      if(directory_pointer->d_name[0]!='.') 
                    printf("%s\n", directory_pointer->d_name); 
                directory_pointer = readdir(directory_reader);
        }
        closedir(directory_reader);     
        return;
    }
    else if(strcmp(arg,"-a")==0) 
    {
        
        struct dirent *directory_pointer;   
        DIR *directory_reader = opendir("."); 
    
        if (directory_reader == NULL)
        { 
            printf("Error : Could Not Open Directory\n"); 
            return ; 
        } 
        directory_pointer = readdir(directory_reader);
        while (directory_pointer!= NULL) 
        {   printf("%s\n", directory_pointer->d_name); 
            directory_pointer = readdir(directory_reader);
        }
        closedir(directory_reader);     
        return;
    
    }
    else if(strcmp(arg,"-l")==0) 
    {
        
        struct dirent *directory_pointer;   
        DIR *directory_reader = opendir("."); 
    
        if (directory_reader == NULL)
        { 
            printf("Error : Could Not Open Directory\n"); 
            return ; 
        } 
        directory_pointer = readdir(directory_reader);
        while (directory_pointer!= NULL) 
        {   
            if(directory_pointer->d_name[0]!='.')
            {   struct stat fileprop;
                char user[1000],t[1000],month[20],day[3],time[7];
                struct group *g;
                long long int gid;
                stat(directory_pointer->d_name,&fileprop);
                printf( (S_ISDIR(fileprop.st_mode)) ? "d" : "-");
                printf( (fileprop.st_mode & S_IRUSR) ? "r" : "-");
                printf( (fileprop.st_mode & S_IWUSR) ? "w" : "-");
                printf( (fileprop.st_mode & S_IXUSR) ? "x" : "-");
                printf( (fileprop.st_mode & S_IRGRP) ? "r" : "-");
                printf( (fileprop.st_mode & S_IWGRP) ? "w" : "-");
                printf( (fileprop.st_mode & S_IXGRP) ? "x" : "-");
                printf( (fileprop.st_mode & S_IROTH) ? "r" : "-");
                printf( (fileprop.st_mode & S_IWOTH) ? "w" : "-");
                printf( (fileprop.st_mode & S_IXOTH) ? "x" : "-");
                printf(" %ld",fileprop.st_nlink);
                getlogin_r(user,sizeof(user)-1);
                printf(" %s",user);
                gid=getgid();
                g=getgrgid(gid);
                printf(" %s",g->gr_name); 
                printf(" %ld",fileprop.st_size);
                strftime(month,100,"%m", localtime(&fileprop.st_mtime));
                if(strcmp(month,"01")==0)
                    printf(" Jan");
                else if(strcmp(month,"02")==0)
                    printf(" Feb");
                else if(strcmp(month,"03")==0)
                    printf(" Mar");
                else if(strcmp(month,"04")==0)
                    printf(" Apr");
                else if(strcmp(month,"05")==0)
                    printf(" May");
                else if(strcmp(month,"06")==0)
                    printf(" Jun");
                else if(strcmp(month,"07")==0)
                    printf(" Jul");
                else if(strcmp(month,"08")==0)
                    printf(" Aug");
                else if(strcmp(month,"09")==0)
                    printf(" Sep");
                else if(strcmp(month,"10")==0)
                    printf(" Oct");
                else if(strcmp(month,"11")==0)
                    printf(" Nov");
                else if(strcmp(month,"12")==0)
                    printf(" Dec");
                //month_finder(month);
                strftime(t,100,"%d %H:%M", localtime(&fileprop.st_mtime));
                printf(" %s", t);
                printf(" %s\n", directory_pointer->d_name); 
            }
            directory_pointer = readdir(directory_reader);
        }
        closedir(directory_reader);     
        return;
    }
    else if((strcmp(arg,"-la")==0)||(strcmp(arg,"-al")==0)) 
    {
        
        struct dirent *directory_pointer;   
        DIR *directory_reader = opendir("."); 
    
        if (directory_reader == NULL)
        { 
            printf("Error : Could Not Open Directory\n"); 
            return ; 
        } 
        directory_pointer = readdir(directory_reader);
        while (directory_pointer!= NULL) 
        {       
            struct stat fileprop;
            char user[1000],t[1000],month[20],day[3],time[7];
            struct group *g;
            long long int gid;
            stat(directory_pointer->d_name,&fileprop);
            printf( (S_ISDIR(fileprop.st_mode)) ? "d" : "-");
            printf( (fileprop.st_mode & S_IRUSR) ? "r" : "-");
            printf( (fileprop.st_mode & S_IWUSR) ? "w" : "-");
            printf( (fileprop.st_mode & S_IXUSR) ? "x" : "-");
            printf( (fileprop.st_mode & S_IRGRP) ? "r" : "-");
            printf( (fileprop.st_mode & S_IWGRP) ? "w" : "-");
            printf( (fileprop.st_mode & S_IXGRP) ? "x" : "-");
            printf( (fileprop.st_mode & S_IROTH) ? "r" : "-");
            printf( (fileprop.st_mode & S_IWOTH) ? "w" : "-");
            printf( (fileprop.st_mode & S_IXOTH) ? "x" : "-");
            printf(" %ld",fileprop.st_nlink);
            getlogin_r(user,sizeof(user)-1);
            printf(" %s",user);
            gid=getgid();
            g=getgrgid(gid);
            printf(" %s",g->gr_name); 
            printf(" %ld",fileprop.st_size);
            strftime(month,100,"%m", localtime(&fileprop.st_mtime));
            if(strcmp(month,"01")==0)
                printf(" Jan");
            else if(strcmp(month,"02")==0)
                printf(" Feb");
            else if(strcmp(month,"03")==0)
                printf(" Mar");
            else if(strcmp(month,"04")==0)
                printf(" Apr");
            else if(strcmp(month,"05")==0)
                printf(" May");
            else if(strcmp(month,"06")==0)
                printf(" Jun");
            else if(strcmp(month,"07")==0)
                printf(" Jul");
            else if(strcmp(month,"08")==0)
                printf(" Aug");
            else if(strcmp(month,"09")==0)
                printf(" Sep");
            else if(strcmp(month,"10")==0)
                printf(" Oct");
            else if(strcmp(month,"11")==0)
                printf(" Nov");
            else if(strcmp(month,"12")==0)
                printf(" Dec");
            //month_finder(month);
            strftime(t,100,"%d %H:%M", localtime(&fileprop.st_mtime));
            printf(" %s", t);
            printf(" %s\n", directory_pointer->d_name); 
            directory_pointer = readdir(directory_reader);
        }
        closedir(directory_reader);     
        return;
    }
    else if(arg[0]=='~')
    {
         char temp[2000],temp1[2000];
        strcpy(temp,tilda);
        printf("%s\n",temp);
        if(arg[1]!=' '&& arg[1]!='\0')
        {   for(long long int i=1;i<strlen(arg);i++)
                temp1[i-1]=arg[i];
            strcat(temp,temp1);
        }
        printf("%s\n",temp);
        if( access(temp, F_OK ) != -1 ) 
        {
            struct dirent *directory_pointer;   
            DIR *directory_reader = opendir(temp); 
        
            if (directory_reader == NULL)
            { 
                printf("Error : Could Not Open Directory\n"); 
                return ; 
            } 
            directory_pointer = readdir(directory_reader);
            while (directory_pointer!= NULL) 
            {      if(directory_pointer->d_name[0]!='.') 
                        printf("%s\n", directory_pointer->d_name); 
                    directory_pointer = readdir(directory_reader);
            }
            closedir(directory_reader);     
            return;
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
                struct dirent *directory_pointer;   
            DIR *directory_reader = opendir(arg); 
        
            if (directory_reader == NULL)
            { 
                printf("Error : Could Not Open Directory\n"); 
                return ; 
            } 
            directory_pointer = readdir(directory_reader);
            while (directory_pointer!= NULL) 
            {      if(directory_pointer->d_name[0]!='.') 
                        printf("%s\n", directory_pointer->d_name); 
                    directory_pointer = readdir(directory_reader);
            }
            closedir(directory_reader);     
            return;
        } 
        else 
        {
            printf("This Location Doesn't Exist\n");
        }
    }
} 
