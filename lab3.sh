#!/bin/sh
 ## CMPSC 474 /CMPEN 441

 #File Name: Begin with "project" and then the project number, for example, proj3.sh

 #Academic Integrity Statement: I certify that, while others may have assisted me in brain storming, debugging and validating this program, the program itself is my own work. I understand that submitting code which is the work of other individuals is a violation of the course Academic Integrity Policy and may result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. I also understand that if I knowingly give my original work to another individual that it could also result in a zero credit for the assignment, or course failure and a report to the Academic Dishonesty Board. See Academic Integrity Procedural Guidelines at:  https://psbehrend.psu.edu/intranet/faculty-resources/academic-integrity/academic-integrity-procedural-guidelines

 #Assisted by and Assisted line numbers:

 #
 #Your Name: Thomas Roseman
 #
 #Your PSU user ID:  924584317
 #
 #CMPSC474 Spring 2016
 #
 #Due Time: Time, Day-of-week, Month Day, Year
 #
 #Time of Last Modification: 2-4-16 11:49
 #
 #
 # Your codes are here.


## If the input file does not exist create it
if [! -f $1]; then
    dialog --inputbox "Enter your name:" 8 40 2>$1
    echo ":">>$1
    dialog --inputbox "Enter your Phone:" 8 40 2>>$1
    echo ":">>$1
    dialog --inputbox "Enter your address:" 8 40 2>>$1
else
    ## Does exist give options to edit
    permission=stat -c %a $1
    if [permission -ge 600  ]; then
        result=$(dialog --menu "Choose one:" 10 30 3 1 AddEntry 2 DeleteEntry 3 ViewEntry 4 Exit
        case $result in
            ##AddEntry
            1)
            typeofentry=$(dialog --menu "Choose one:" 10 30 3 1 Name 2 Phone 3 Address)
            IFS=:
            read name phone address
            case $typeofentry in
                1) if [$name=""]; then
                    name=$(dialog --inputbox "Enter your name:" 8 40 2)
                    echo $name":"$phone":"$address>$1
                fi;;
                2) if [$phone=""]; then
                    phone=$(dialog --inputbox "Enter your phone:" 8 40 2)
                    echo $name":"$phone":"$address>$1
                fi;;
                3) if [$address=""]; then
                    address=$(dialog --inputbox "Enter your address:" 8 40 2)
                    echo $name":"$phone":"$address>$1
                fi;;
            esac
            ;;
            ##DeleteEntry
            2) typeofentry=$(dialog --menu "Choose one:" 10 30 3 1 Name 2 Phone 3 Address)
            IFS=:
            read name phone address;;
            case $typeofentry in
                1) if [$name=""]; then
                    echo "Blank"
                else
                    echo ":"$phone":"$address>$1
                fi;;
                2) if [$phone=""]; then
                    echo "Blank"
                else
                    echo $name":"":"$address>$1
                fi;;
                3) if [$address=""]; then
                    echo "Blank"
                else
                    echo $name":"$phone":">$1
                fi;;
            esac
            ;;
            ##ViewEntry
            3) ;;
            ##Exit
            4) exit 0;;
        esac
    fi

fi
