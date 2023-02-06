read -p "Enter name: " name
echo $((3==3))
case $name in
	"ram") echo "hi ram, shyam is your friend";;
	"shyam") echo "hi shyam, ram is your friend";;
	"rakesh") echo "hi rakesh, ramesh is your friend";;
	"ramesh") echo "hi ramesh, rakesh is your friend";;
	*) echo "hi $name, No one is your friend";;
esac
