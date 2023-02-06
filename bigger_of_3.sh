read -p "enter num1: " num1
read -p "enter num2: " num2
read -p "enter num3: " num3

if [ $num3 -lt $num1 ] && [ $num2 -lt $num1 ]
then
	echo "num1: $num1"
elif [ $num3 -lt $num2 ] && [ $num1 -lt $num2 ]
then
	echo "num2: $num2"
else
	echo "num3: $num3"
fi
