#!/bin/bash
echo "Enter Choice.. 0 for Even Sem, 1 for Odd Sem, Any other to quit :"
read input_var
if [ "$input_var" -eq "0" ]
then
./Evensem/Algorithm/evensem.exe
elif [ "$input_var" = "1" ]
then
./Oddsem/Algorithm/oddsem.exe
else
exit
fi
