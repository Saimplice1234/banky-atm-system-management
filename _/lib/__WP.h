#define GAUGE_AT_SYS_1\
    system("bash utility/loader/LD-1.sh");

#define GAUGE_AT_SYS_2\
    system("bash utility/loader/LD-2.sh");

#define GAUGE_AT_SYS_3\
    system("bash utility/loader/LD-3.sh");

#define CRED_BOX_AT_SYS "whiptail --nocancel --passwordbox 'ENTER THE ADMIN ATM ACCESS PASSWORD' 8 78 --title 'ATM ACCESS PIN' 3>&1 1>&2 2>&3"

#define WARNING_F_CRED "whiptail --textbox --scrolltext _/info/CRED.txt 12 78"

#define RULES_AT_SYS   "whiptail --textbox --scrolltext _/info/WARN.txt 10 78"

#define MENU_AT_SYS \
"whiptail --nocancel --title 'BANKY' --menu 'WHICH TRANSACTION YOU NEED TO MAKE?' 18 58 10 \
    'NEW    USER' '  -------------Create An Account' \
    'DELETE USER' '  -------------Delete An Account' \
    'BLOCK'       '  -------------Block  An Account' \
    'TRANSACTION' '  -------------------Transaction' \
    'BALANCE'     '  Show the balance of An Account' \
    'DEPOSIT'     '  ------Put Funds In The Account' \
    'WITHDRAW'    '  -Withdraw Funds In The Account' \
    'TRANSFER'    '  -----Transfer Funds to Account' \
    'WARNING'     '  ---------Show Rules Of The ATM' \
    'REPORT'      '  --Report An Error From The ATM' 3>&1 1>&2 2>&3"

#define USER_NAME "whiptail --title 'NEW USER NAME' --inputbox 'ENTER NEW ATM USERNAME' 8 40 3>&1 1>&2 2>&3"

#define USER_PASS "whiptail --passwordbox 'SET A PASSOWRD FOR YOUR NEW ACCOUNT' 8 56 --title 'NEW USER PASSWORD' 3>&1 1>&2 2>&3"

#define WARN_USER "whiptail --textbox --scrolltext _/info/WARNUSER.txt 10 78"

#define WARN_PASS "whiptail --textbox --scrolltext _/info/WARNPASS.txt 10 78"

#define WARN_RULES "whiptail --textbox --scrolltext _/info/WARN.txt 10 78"

#define WARN_ALREADY_EXIST_ACCOUNT "whiptail --textbox --scrolltext _/info/WARN_AlrExist.txt 10 78"

