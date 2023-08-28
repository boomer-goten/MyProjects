#!/bin/bash
count_mem_two=1;
count_name_dir_two=1;
for entry in $(find $1 -type f -exec du -S {} \; | sort -rnk1 | head -10 | xargs)
do
if [[ $count_mem_two -eq $count_name_dir_two ]]
then
MEM_two[$count_mem_two]=$entry
count_mem_two=$(( $count_mem_two + 1 ))
else
NAME_DIR_two[$count_name_dir_two]=$entry
count_name_dir_two=$(( $count_name_dir_two + 1 ))
fi
done
echo -e "TOP 10 files of maximum size arranged in descending order (path, size and type):"
echo -e "1  - ${NAME_DIR_two[1]}, ${MEM_two[1]} KB, $(file ${NAME_DIR_two[1]} | cut -d ":" -f 2 | xargs)"
echo -e "2  - ${NAME_DIR_two[2]}, ${MEM_two[2]} KB, $(file ${NAME_DIR_two[2]} | cut -d ":" -f 2 | xargs)"
echo -e "3  - ${NAME_DIR_two[3]}, ${MEM_two[3]} KB, $(file ${NAME_DIR_two[3]} | cut -d ":" -f 2 | xargs)"
echo -e "4  - ${NAME_DIR_two[4]}, ${MEM_two[4]} KB, $(file ${NAME_DIR_two[4]} | cut -d ":" -f 2 | xargs)"
echo -e "5  - ${NAME_DIR_two[5]}, ${MEM_two[5]} KB, $(file ${NAME_DIR_two[5]} | cut -d ":" -f 2 | xargs)"
echo -e "6  - ${NAME_DIR_two[6]}, ${MEM_two[6]} KB, $(file ${NAME_DIR_two[6]} | cut -d ":" -f 2 | xargs)"
echo -e "7  - ${NAME_DIR_two[7]}, ${MEM_two[7]} KB, $(file ${NAME_DIR_two[7]} | cut -d ":" -f 2 | xargs)"
echo -e "8  - ${NAME_DIR_two[8]}, ${MEM_two[8]} KB, $(file ${NAME_DIR_two[8]} | cut -d ":" -f 2 | xargs)"
echo -e "9  - ${NAME_DIR_two[9]}, ${MEM_two[9]} KB, $(file ${NAME_DIR_two[9]} | cut -d ":" -f 2 | xargs)"
echo -e "10 - ${NAME_DIR_two[10]}, ${MEM_two[10]} KB, $(file ${NAME_DIR_two[10]} | cut -d ":" -f 2 | xargs)"