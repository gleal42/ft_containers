#!/bin/sh
VAL=$RANDOM
echo ft_containers:
./ft_containers $VAL ;

# echo
# echo std_containers:
# ./std_containers $VAL ;


./ft_containers $VAL > temp_ft
./std_containers $VAL > temp_std

DIFF=$(diff temp_ft temp_std)

echo $DIFF
echo DIFFERENCE between them:
if [ "$DIFF" ]
then
    echo "$DIFF\n"
    rm -f temp_std temp_ft
    exit 1
else
    echo "They are the same"
    rm -f temp_std temp_ft
    exit 0
fi
