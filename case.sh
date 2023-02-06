read -p "Enter number in text form: " num

case $num in
	"one") echo "Number is 1.";;
	"two") echo "Number is 2.";;
	"three") echo "Number is 3.";;
	*) echo "No Number";;
esac
