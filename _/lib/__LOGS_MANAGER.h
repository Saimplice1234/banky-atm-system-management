#include <stdio.h>
#include <stdlib.h>
#include <time.h>


char * INIT_DATABASE_LOGS(){

    FILE * DB_LOGS;
    char * path_base="_/logs/";
    static char   path[40];

    time_t t = time(NULL);
    char * state_date=ctime(&t);
    struct DATE_PARSED d=remove_word_at(state_date,0);
    
    snprintf(path, sizeof(path), "%s%s%s%s%s",path_base,d.__week,d.__day,d.__month,d.__year);
    DB_LOGS=fopen(path,"a");
    
    fprintf(DB_LOGS,"%d\n",0);
    fclose(DB_LOGS);

    return path;
    
}
int GET_LAST_STATE_SYSTEM(char * DATABASE_LINK){
    FILE * LOGS_DIRECTORY;
    LOGS_DIRECTORY = fopen(DATABASE_LINK,"r");
    char buf[2];
    fscanf(LOGS_DIRECTORY,"%[^\n]",buf);
    fclose(LOGS_DIRECTORY);
    return atoi(buf);
}
int WRITE_LOGS(char * DATABASE_LINK){
    /*INCREMENT THE LAST STATE OF THE SYSTEM*/
    int last_state=GET_LAST_STATE_SYSTEM(DATABASE_LINK);
    FILE * LOGS_DIRECTORY;
    LOGS_DIRECTORY = fopen(DATABASE_LINK,"w");
    last_state=-(~last_state);
    fprintf(LOGS_DIRECTORY,"%d\n",last_state);
    fclose(LOGS_DIRECTORY);
    return last_state;
}