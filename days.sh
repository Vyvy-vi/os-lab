read -p "Enter day: " day

case $day in
  Monday) echo "It's the start of the week";;
  Friday) echo "Thank goodness it's Friday!";;
  *) echo "Just another day";;
esac
