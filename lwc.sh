echo "Lines, Words, Characters in file"

for file in "$@"
do
  wc $file
done
