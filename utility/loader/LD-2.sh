{
    for ((i = 0 ; i <= 100 ; i+=5)); do
        sleep 0.02
        echo $i
    done
} | whiptail --gauge "CONNECTING TO THE NETWORK..." 6 50 0
