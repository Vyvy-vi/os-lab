# Split content from fee-details into 3 parts
split fee-details.txt -l 1
annual_fees=`cat xab`
pending_fees=`cat xac`
fine=`cat xad`

rm -rf xaa xab xac xad

total_fees=$(($annual_fees+$pending_fees+$fine))

echo "Annual fees: $annual_fees"
echo "Pending fees: $pending_fees"
echo "Fine: $fine"

response="The total due fee is: $total_fees"
echo $response
echo $response > calculated-fee.txt
