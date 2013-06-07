#!/bin/bash
sudo chmod 0666 /dev/bus/usb/001/004
gpio mode 0 up
STATE=$(gpio read 0)
echo $STATE
while [ $STATE -ne 0 ]
do
	clear
	echo Press button for start
	STATE=$(gpio read 0)
	sleep 0.1
done
echo Start bear rescue
./Plan/BearRescue > logRun
