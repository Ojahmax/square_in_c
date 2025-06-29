#!/bin/sh

# Convert FT_NBR1 from base 5 to decimal
nbr1=$(echo $FT_NBR1 | tr "\'\"\?\!\\" "01234")
dec1=$(echo "ibase=5; $nbr1" | bc)

# Convert FT_NBR2 from base 5 to decimal
nbr2=$(echo $FT_NBR2 | tr "mrdoc" "01234")
dec2=$(echo "ibase=5; $nbr2" | bc)

# Add the two decimal numbers
sum=$(echo "$dec1 + $dec2" | bc)

# Convert the sum to base 13 and map to gtaio luSnemf characters
base13=$(echo "obase=13; $sum" | bc | tr "0123456789ABC" "gtaio luSnemf")

echo $base13
