read -p "enter num1: " num1
read -p "enter num2: " num2

if [ $num2 -lt $num1 ]
then
	echo $num1
elif [ $num2 -eq $num1 ]
then
	echo "Equal"
else
	echo $num2
fi
