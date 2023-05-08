read -p "Enter shape: " shape

case $shape in
  square)
    read -p "Enter side: " side
    echo Area of $shape is $(($side * $side));;
  rectangle)
    read -p "Enter length: " length
    read -p "Enter breadth: " breadth
    echo Area of $shape is $(($length * $breadth));;
  circle)
    read -p "Enter radius: " radius
    echo Area of $shape is $((22 * radius * radius / 7));;
  *) "Invalid shape";;
esac
