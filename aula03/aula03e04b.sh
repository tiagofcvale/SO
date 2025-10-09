#!/bin/bash
# This script does a very simple test for checking disk space.

# Obter a linha com maior ocupação (maior %)
line=$(df -h | grep -vE '^Filesystem|tmpfs|cdrom' | awk '{print $5 " " $1}' | sort -n | tail -1)

# Extrair percentagem e partição
space=$(echo $line | awk '{print $1}' | tr -d '%')
partition=$(echo $line | awk '{print $2}')

echo "Partition with highest usage: $partition"
echo "Largest occupied space = $space%"

# Analisar o espaço
case $space in
  [0-6][0-9]) # espaço < 70%
    Message="All OK."
    ;;
  7[0-9]) # 70% <= espaço < 80%
    Message="Cleaning out. One partition is $space% full."
    ;;
  8[0-9]) # 80% <= espaço < 90%
    Message="Better buy a new disk. One partition is $space% full."
    ;;
  9[0-8]) # 90% <= espaço < 99%
    Message="Warning! One partition is $space% full."
    ;;
  99) # espaço = 99%
    Message="I'm drowning here! There's a partition at $space%!"
    ;;
  100)
    Message="Disk totally full!"
    ;;
  *)
    Message="I seem to be running with a non-existent disk..."
    ;;
esac

echo "$Message (Partition: $partition)"

