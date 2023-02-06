read -p "Enter limit: " lim
num=0
while [ $num -lt $lim ]
do
	printf "%i " $num
	num=`expr $num + 1`
done
printf "\n"
