{
    for ((i = 0 ; i <= 100 ; i+=5)); do
        sleep 0.02
        echo $i
    done
} | whiptail --gauge "CREATING THE ACCOUNT..." 6 50 0
