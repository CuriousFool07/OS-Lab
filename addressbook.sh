#!/bin/bash

echo "===address book==="

cont=1

while [ $cont -eq 1 ]
do
    echo "1.create record"
    echo "2.insert record"
    echo "3.delete record"
    echo "4.display record"
    echo "5.search record"
    echo "7.exit"

    echo "enter choice"
    read choice

    case $choice in

    1)
        echo "enter address book name"
        read filename

        if [ -s $filename ]
        then
            echo "file exist"
        else
            touch $filename
            echo -e "address book created successfully $filename"
        fi
        ;;

    2)
        echo "enter filename"
        read filename
        echo "enter the number of students"
        read count

        for ((i=1;i<=count;i++))
        do
            echo "Enter ID, Name and Mobile Number and city:"
            read id name mobile city

            while [[ ! $mobile =~ ^[0-9]{10}$ ]]
            do
                echo "Invalid mobile number"
                echo "Enter mobile number again:"
                read mobile
            done

            echo -e "\n$id\t$name\t$mobile\t$city" >> $filename
            echo "Record inserted successfully"
        done
        ;;

    3)
        echo "enter filename"
        read filename

        if [ -f $filename ]
        then
            echo "Enter id to delete"
            read id
            grep -v "^$id" $filename > temp
            mv temp $filename
            echo "Record deleted"
        else
            echo "file does not exist"
        fi
        ;;

    4)
        echo "enter filename"
        read filename

        if [ -s $filename ]
        then
            cat $filename
        else
            echo "file does not exist"
        fi
        ;;

    5)
        echo "enter filename"
        read filename
        echo "enter name"
        read name

        if grep -q "$name" $filename
        then
            grep "$name" $filename
            echo "record found"
        else
            echo "record not found"
        fi
        ;;

    6)
        echo "exiting"
        cont=0
        ;;

    *)
        echo "invalid choice"
        ;;

    esac
done
