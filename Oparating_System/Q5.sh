#! /usr/bin/bash

read -p "First birthday: " b1
read -p "Second birthday: " b2
day1="${b1:0:2}"
day2="${b2:0:2}"
month1="${b1:3:2}"
month2="${b2:3:2}"
yr1="${b1:6:4}"
yr2="${b2:6:4}"

dayDiff=$((day1-day2))
if [ $dayDiff -lt 0 ]
then
	dayDiff=$((dayDiff * -1))
fi
monthDiff=$((month1 - month2))
if [ $monthDiff -lt 0 ]
then
	monthDiff=$((monthDiff * -1))
fi
yrDiff=$((yr2 - yr1))

if [ $yrDiff -lt 0 ]
then    
	yrDiff=$((yrDiff * -1))
fi
monthDiff=$((monthDiff * 30))
yrDiff=$((yrDiff * 365))
days=$((dayDiff + monthDiff + yrDiff))
leap=0

for(( i=$yr1;i<$yr2;i++ ));do
	if [ $((i % 100)) -eq 0 ]
	then
		if [ $((i % 400)) -eq 0 ]
		then
			(( leap++ ))
		fi
	else
		if [ $((i % 4)) -eq 0 ]
		then
			((leap++))
		fi
	fi
done

days=$((days + leap))

rem=$((days % 7))
if [ $rem -eq 0 ]
then
	echo "Born on the same day!"
else 
	echo "Not born on the same day!"
fi

age1=$((2022 * 365 + 8 * 30 + 19 - yr1 * 365 - month1 * 30 - day1))
age2=$((2022 * 365 + 8 * 30 + 19 - yr2 * 365 - month2 * 30 - day2))

ageYr1=$((age1 / 365))
ageYr2=$((age2 / 365))
age1=$((age1 % 365))
age2=$((age2 % 365))
ageMon1=$((age1 / 30))
ageMon2=$((age2 / 30))
ageDay1=$((age1 % 30))
ageDay2=$((age2 % 30))

echo -e "First Age : $ageYr1 years $ageMon1 months $ageDay1 days\nSecond Age : $ageYr2 years $ageMon2 months $ageDay2 days"

