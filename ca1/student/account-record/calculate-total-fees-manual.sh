# Split content from fee-details into 3 parts
read -p "Enter Annual fee: " annual_fees
read -p "Enter Pending fee: " pending_fees
read -p "Enter fine: " fine

total_fees=$(($annual_fees+$pending_fees+$fine))

echo "Annual fees: $annual_fees"
echo "Pending fees: $pending_fees"
echo "Fine: $fine"

response="The total due fee is: $total_fees"
echo $response
echo $response > calculated-fee-manual.txt
