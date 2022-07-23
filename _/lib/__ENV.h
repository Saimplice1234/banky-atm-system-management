struct __ENV_BUFFER{

    char * EXC_L_TLT_BUFFER; 

    char * EXC_L_CRE_BUFFER; 

    char * SYS_AT_BUFFER; 

    char * ACC_PRT_BUFFER; 

    char * CRE_PRT_BUFFER; 

    char * CRE_PRT_FORMATED_BUFFER; 

    char * ERR_ALR_EX_BUFFER; 

    char * SUC_ACC_CRE_BUFFER; 

    char * EXC_ACC_CNT;

};

char * __ENV_BUFF(int BUF_COD){

    struct __ENV_BUFFER sys;

    sys.SYS_AT_BUFFER           = "%sroot? ";

    sys.EXC_L_TLT_BUFFER        = "--root?EXCEED LENGHT **TLT**\n";

    sys.EXC_L_CRE_BUFFER        = "--root?EXCEED LENGHT **CRED**\n";

    sys.ACC_PRT_BUFFER          = "--root?tlt-acc :";

    sys.CRE_PRT_BUFFER          = "--root?cred-acc:";

    sys.ERR_ALR_EX_BUFFER       = "%s--root?ATM ACCOUNT **ALREADY EXIST**\n";

    sys.SUC_ACC_CRE_BUFFER      = "%s--root?ATM ACCOUNT **CREATED**\n";

    sys.EXC_ACC_CNT             = "%s--root?CAN'T CREATE MORE THAN 1 **ACCOUNT**\n";

    sys.CRE_PRT_FORMATED_BUFFER ="--root?cred-acc :";

    if(BUF_COD == 0){

        return sys.SYS_AT_BUFFER;
        
    }else if(BUF_COD == 1){

        return sys.ACC_PRT_BUFFER;

    }else if(BUF_COD == 2){

        return sys.EXC_L_TLT_BUFFER;

    }else if(BUF_COD == 3){

        return sys.CRE_PRT_BUFFER;

    }else if(BUF_COD ==4){

        return sys.EXC_L_CRE_BUFFER;

    }else if(BUF_COD == 5){

        return sys.CRE_PRT_FORMATED_BUFFER;

    }else if(BUF_COD == 6){

        return sys.ERR_ALR_EX_BUFFER;

    }else if(BUF_COD == 7){

        return sys.SUC_ACC_CRE_BUFFER;

    }else if(BUF_COD ==8){
        
        return sys.EXC_ACC_CNT;
    }
}
void strip(char* string) {
    int check;
    int i=0;
    int j=0;
    while(string[i]!='\0'){
   check=0;
   if(string[i]==' '){
      j=i;
      while(string[j-1]!='\0'){
         string[j] = string[j+1];
         j++;
      }
      check = 1;
   }
   if(check==0)
   i++;
}
}

struct DATE_PARSED{
    char * __week;
    char * __month;
    char * __day;
    char * __hour;
    char * __year;
};

struct DATE_PARSED remove_word_at(char * str,int idx){

    char * __WORDS[5];
    struct DATE_PARSED parsed;
    char *token = strtok(str, " ");
    int __CX=0;
    while (token != NULL){
        __WORDS[__CX]=token;
        token = strtok(NULL, " ");
        __CX=-(~__CX);
        
    }
    parsed.__week  = __WORDS[0];
    parsed.__month = __WORDS[1];
    parsed.__day   = __WORDS[2];
    parsed.__hour  = __WORDS[3];
    parsed.__year  = __WORDS[4];

    return parsed;
}