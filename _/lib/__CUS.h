#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "__WP.h"

#define __MAX_CRED__ 3

struct _AT_schem {
  char * __A;
  char * __C;
  int  __K;  
};

struct _AT_schem __AT_CRED_V(char buf[400]){
  
  static char * __CREDENTIAL[__MAX_CRED__ ];
  struct _AT_schem  CRED;
  int __SIZE_CRED=__MAX_CRED__;
  int __CX=0;
  char *token = strtok(buf, ";");
  while (token != NULL){
    __CREDENTIAL[__CX]=token;
    token = strtok(NULL, ";");
    __CX=-(~__CX);
  }
  CRED.__A=__CREDENTIAL[0];
  CRED.__C=__CREDENTIAL[1];
  CRED.__K=atoi(__CREDENTIAL[2]);
  return CRED;
}

int GET_IF_USER_ALREADY_EXIST(char * USERNAME){
    FILE * db;
    db=fopen("_/ENV_SYSTEM.db","r");
    char buf[50];
    
    while (fgets(buf,sizeof(buf),db)){
        /*PARSE USER IN THE DATABASE*/
        struct _AT_schem _P=__AT_CRED_V(buf);

        if(strcmp(_P.__A,USERNAME) == 0){
            /*SHOW USER WARNING FOR ATTEMPTING TO CREATE ALREADY EXIST ACCOUNT*/
            system(WARN_ALREADY_EXIST_ACCOUNT);
            fclose(db);
            return 1;
        }
    }
    fclose(db);
    return 0;
          
}

void INSERT_TO_DATABASE(char * USERNAME,char * PIN,int FUNDS){
    FILE * db;
    db=fopen("_/ENV_SYSTEM.db","a");
    fprintf(db,"%s;%s;%d\n",USERNAME,PIN,FUNDS);
    fclose(db); 
}