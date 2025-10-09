#!/bin/bash
# Calculate the sum of a series of numbers.
SCORE="0"
SUM="0"
CONTADOR="0"
while true
do
	echo -n "Enter your score [0-10] ('q' to quit): "
	read SCORE;
	if (("$SCORE" < "0")) || (("$SCORE" > "10")); then
		echo "Try again: "
	elif [[ "$SCORE" == "q" ]]
	then
		echo "Sum: $SUM."
		MEDIA=$((SUM / CONTADOR))
		echo "Media: $MEDIA."
		break
	elif [[ "$SCORE" == "r" ]]
	then
		CONTADOR="0"
		SUM="0"
		echo "Valores resetados!"
		continue
	else
		SUM=$((SUM + SCORE))
		CONTADOR=$((CONTADOR + 1))
		
	fi
done
echo "Exiting."
