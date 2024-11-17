/*
   Modify the fsize program to print the other information contained in the inode entry.

   Solution by Akil Adeshwar
   https://clc-wiki.net/wiki/K%26R2_solutions:Chapter_8:Exercise_5
*/

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <pwd.h>


#define MAX_PATH 1024

#ifndef DIRSIZ
#define DIRSIZ 14
#endif


void dirwalk( char *dir,void (*fcn)(char *)){

    char name[MAX_PATH];
    struct dirent *dp;
    DIR *dfd;

    if((dfd = opendir(dir))==NULL){
        puts("Error: Cannot open Directory");
        return;
    }
    puts(dir);
    // Get each dir entry
    while((dp=readdir(dfd)) != NULL){
        // Skip . and .. is redundant.
        if(strcmp(dp->d_name,".") == 0
           || strcmp(dp->d_name,"..") ==0 )
            continue;
        if(strlen(dir)+strlen(dp->d_name)+2 > sizeof(name))
            puts("Error: Name too long!");
        else{
            sprintf(name,"%s/%s",dir,dp->d_name);
            // Call fsize
            (*fcn)(name);
        }
    }
    closedir(dfd);
}

void fsize(char *name){
    struct stat stbuf;

    if(stat(name,&stbuf) == -1){
        puts("Error: Cannot get file stats!");
        return;
    }

    if((stbuf.st_mode & S_IFMT) == S_IFDIR){
        dirwalk(name,fsize);
    }
    struct passwd *pwd = getpwuid(stbuf.st_uid);
    //print file name,size and owner
    printf("%81d %s Owner: %s\n",(int)stbuf.st_size,name,pwd->pw_name);
}




int main(int argc,char *argv[]){

    if(argc==1)
        fsize(".");
    else
        while(--argc>0)
            fsize(*++argv);
    return 0;
}
