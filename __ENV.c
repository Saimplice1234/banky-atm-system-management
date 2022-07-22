#include <stdio.h>;
#include <stdlib.h>;
#include <string.h>;
#include "_/lib/__ENV.h";

#define _FRAME_ "_/00/__FRAME__.txt"
#define _MOD_F_ "r"
#define _MODPF_ "%c"
#define __MAX_CRED__ 3

struct _AT_schem {
  char * __A;
  char * __C;
  int  __K;  
};

void ____00000000000000000(){
    char   __L0000__;
    FILE * __FRAME__;
    __FRAME__=fopen(_FRAME_,_MOD_F_);
    if(__FRAME__ == NULL)
        exit(0);

    __L0000__ = fgetc(__FRAME__);
    while (__L0000__ != EOF)
    {
        printf (_MODPF_, __L0000__);
        __L0000__= fgetc(__FRAME__);
    }
    fclose(__FRAME__);
    printf("\n\n");
}

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
int main(){
    
    int atm_Tr=0;
    static int CR=0;
    static int AE=0;
    printf("%s","\033[01m");
    ____00000000000000000();
    
    while(1){

        printf(__ENV_BUFF(0),"\033[01m"); //BUFFER_0
        scanf("%d",&atm_Tr);
      
        if(atm_Tr == 1 && CR < 1){
          
          char tlt  [255];
          char t_c  [255];
          printf(__ENV_BUFF(1)); //BUFFER_1
          scanf("%s",tlt);
          
          while(strlen(tlt) < 1 || strlen(tlt) > 10){
            printf(__ENV_BUFF(2)); //BUFFER_2
            printf(__ENV_BUFF(1)); //BUFFER_1
            scanf("%s",tlt);
          }
          
          printf(__ENV_BUFF(3)); //BUFFER_3
          scanf("%s",t_c);
          
          while(strlen(t_c) < 1 || strlen(t_c) > 15){
            printf(__ENV_BUFF(4)); //BUFFER_4
            printf(__ENV_BUFF(5)); //BUFFER_5
            scanf("%s",t_c);
          }
          
          FILE * db;
          db=fopen("_/00.db","r");
          unsigned FLAG=0;
          char buf[400];
          
          while (fgets(buf,sizeof(buf),db)){
              struct _AT_schem _P=__AT_CRED_V(buf);
              if(strcmp(_P.__A,tlt) == 0){
                printf("\033[0;33m");
                *&FLAG=1;
                //BUFFER_6
                printf(__ENV_BUFF(6)
                  ,"\033[01m"
                );
                printf("\033[0;0m");
                AE=-(~AE);
              }
          }
          
          if(*&FLAG == 0){
            CR=-(~CR);
            fprintf(db,"%s;%s;%d\n",tlt,t_c,0);
            printf("\033[0;32m");
            //BUFFER_7
            printf(__ENV_BUFF(7),
              "\033[01m"
            );
            printf("\033[0;0m");
          }
          fclose(db);
          
        }else if(atm_Tr == 1 && CR == 1){
          printf("\033[0;33m");
          //BUFFER_8
          printf(__ENV_BUFF(8),
             "\033[01m"
          );
          printf("\033[0;0m");
        }
    }
    return 0;
}