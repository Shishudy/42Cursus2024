#!/bin/bash
arch=$(uname -a) #architecture + kernel
pcpu=$(grep "physical id" /proc/cpuinfo | sort | uniq | wc -l) #physical cpu = "physical id: x" x = socket for cpu - uniq x means +1 pcpu     
vcpu=$(grep "^processor" /proc/cpuinfo | wc -l) #virtual cpu = each "processor: x" in cpuinfo = 1 vcpu
sram=$(free --mega | awk '$1 == "Mem:" {print $2}') #server ram = free -m for MB ; awk prints what's in row x column y ('column1 == "row you want" {print column2}')
uram=$(free --mega | awk '$1 == "Mem:" {print $3}') #utilized ram
pram=$(free --mega | awk '$1 == "Mem:" {printf("%.2f%%\n"), $3/$2*100}') #percent ram = %.2f - print truncated (.) floating point number(f) with 2 decimals(2)
sdisk=$(df -BGB | grep '^/dev/' | grep -v '/boot$' | awk '{total += $2} END {print total}') #server disk = -BGB for GB blocks, grep all rows with dev(device) at start, exclude boot (all others are temp or virtual), add all values in row 2 and print
udisk=$(df -BMB | grep '^/dev/' | grep -v '/boot$' | awk '{used += $3} END {print used}') #utilized disk = -GMB for MB blocks
pdisk=$(df -BMB | grep '^/dev/' | grep -v '/boot$' | awk '{used += $3} {total += $2} END {printf("%d%%\n"), used/total*100}') #percent disk   
cpul=$(mpstat | grep all | awk '{printf "%.2f%%\n", 100 - $12}')
#cpul=$(top -bn1 | grep load | awk '{printf "%.2f%%\n", $(NF-2)}') #cpu usage or load?
lboot=$(who -b | awk '$1 == "system" {print $3 " " $4 " " $5}') #last boot
lvm=$(lsblk | grep 'lvm' | awk '{if ($1) {printf "Yes";exit} else {print "No";exit;}}') #lvm use
ctcp=$(ss -t | grep ESTAB | wc -l) #connections TCP
ulog=$(users | wc -w) #user log
nip=$(hostname -I) #network ip
mac=$(ip link show | grep ether | awk '{print $2}') #mac address
scmd=$(journalctl _COMM=sudo | grep COMMAND | wc -l) #sudo commands
wall "	#Architecture: $arch
        #CPU physical: $pcpu
        #vCPU: $vcpu
        #Memory Usage: $uram/${sram}MB ($pram)
        #Disk Usage: $udisk/${sdisk}GB ($pdisk)
        #CPU load: $cpul
        #Last boot: $lboot
        #LVM use: $lvm
        #Connexions TCP: $ctcp ESTABLISHED
        #User log: $ulog
        #Network: IP $nip ($mac)
        #Sudo: $scmd cmd"
