void pwd()
{
    char location[1000];
    getcwd(location,sizeof(location));
    printf("%s\n",location);
}