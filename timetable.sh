#!/bin/bash
echo "Enter Choice.. 0 for Even Sem, 1 for Odd Sem, Any other to quit :"
read input_var
if [ "$input_var" -eq "0" ]
then
cd Evensem/Algorithm
g++ evensem.cpp -o evensem
./evensem
elif [ "$input_var" = "1" ]
then
cd Oddsem/Algorithm
g++ oddsem.cpp -o oddsem
./oddsem
else
exit
fi
