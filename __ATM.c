#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "_/lib/__ENV.h"
#include "_/lib/__WP.h"
#include "_/lib/__CUS.h"

char *  REQUIRE_USERNAME(){
    FILE * PR;
    static char FIELD[15];

    PR=popen(USER_NAME,"r");
    

    fgets(FIELD,sizeof(FIELD),PR);
    strip(FIELD);

    int EXITCODE=WEXITSTATUS(pclose(PR));

    if(EXITCODE == 0){

        if(strlen(FIELD) == 0 || strlen(FIELD) <2 || strlen(FIELD) > 12){
            system(WARN_USER);
            REQUIRE_USERNAME(EXITCODE);
        }
        return FIELD;
    }else if(EXITCODE == 1){
        return "EXIT";
    }

    fclose(PR);
    
}

char *  REQUIRE_PASSWORD(){
    FILE * PR;
    static char FIELD[10];
    PR=popen(USER_PASS,"r");
    fgets(FIELD,sizeof(FIELD),PR);
    strip(FIELD);
    int EXITCODE=WEXITSTATUS(pclose(PR));

    if(EXITCODE == 0){
        if(strlen(FIELD) == 0 || strlen(FIELD) <2 || strlen(FIELD) > 8){
            system(WARN_PASS);
            REQUIRE_PASSWORD();
        }
        return FIELD;
    }else {
        return "EXIT";
    }
    fclose(PR);
}


void AT_SYS_INTERFACE(){
    FILE * output;
    char FIELD[50];
    output=popen(MENU_AT_SYS,"r");

    fgets(FIELD,sizeof(FIELD),output);
    if(strcmp(FIELD,"NEW    USER") == 0){
        GAUGE_AT_SYS_2
        /*CREATE NEW ACCOUNT*/
        char * tlt  = REQUIRE_USERNAME();
        if(strcmp("EXIT",tlt) != 0){
            /*GET IF USER DECLINE NAME BOX DON'T SHOW PASSWORD*/
            char * t_c  = REQUIRE_PASSWORD();
            /*GET IF USER DECLINE PASSOWRD BOX */
            if(strcmp("EXIT",t_c) !=0){
                /*CREATE ACCOUNT*/
                
                /*GET IF ACCOUNT ALREADY EXIST*/
                int user=GET_IF_USER_ALREADY_EXIST(tlt);
                if(user  == 0){
                    /*PROCED TO THE CREATION*/
                    GAUGE_AT_SYS_3
                    /*WRITE IN DATABASE*/
                    INSERT_TO_DATABASE(tlt,t_c,0);
                    system(WARN_RULES);
                    
                }
                
            }
        }
        AT_SYS_INTERFACE();
    }
    fclose(output);
    
}
void system_state_write(int attempt){
    FILE * db_state;
    db_state=fopen("_/SYSTEM_STATE.db","w");
    time_t t = time(NULL);
    char * STATE_DATE=ctime(&t);
    fprintf(db_state,"%d;%s",attempt,STATE_DATE);
    fclose(db_state);
}
void INIT_DATABASE_LOGS(){
    FILE * db_logs;
    
    char * PATH_DATABASE="_/logs/";
    
    time_t t = time(NULL);
    char * STATE_DATE=ctime(&t);

    strip(STATE_DATE);
    strcat(STATE_DATE,".db");

    strcat(PATH_DATABASE,STATE_DATE);
    printf("%s",PATH_DATABASE);

    //db_logs=fopen(PATH_DATABASE,"w");
    fclose(db_logs);
}
int root_access(){
    
    FILE * output;
    output=popen(CRED_BOX_AT_SYS,"r");
    int SYSTEM_ROOT_ATTEMPT;
    if(output != NULL){
        
        char FIELD[50];
        fgets(FIELD,sizeof(FIELD),output);
        if(strcmp("root",FIELD) == 0){
            GAUGE_AT_SYS_2
            AT_SYS_INTERFACE();
        }else{
            system(WARNING_F_CRED);
            root_access();
        }
    }
    fclose(output);
}
int main(){
    INIT_DATABASE_LOGS();
    //GAUGE_AT_SYS_1
    //root_access();
    return 0;
}