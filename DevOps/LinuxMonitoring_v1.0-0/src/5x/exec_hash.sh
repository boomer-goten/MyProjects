#!/bin/bash
count_mem_three=1;
count_name_dir_three=1;
for entry in $(find $1 -type f -perm /a=x -exec du -S {} \; | sort -rnk1 | head -10 | xargs)
do
if [[ $count_mem_three -eq $count_name_dir_three ]]
then
MEM_three[$count_mem_three]=$entry
count_mem_three=$(( $count_mem_three + 1 ))
else
NAME_DIR_three[$count_name_dir_three]=$entry
count_name_dir_three=$(( $count_name_dir_three + 1 ))
fi
done
echo -e "TOP 10 executable files of the maximum size arranged in descending order (path, size and MD5 hash of file) "
echo -e "1  - ${NAME_DIR_three[1]}, ${MEM_three[1]} KB, $(md5sum ${NAME_DIR_three[1]} | cut -d " " -f 1 | xargs)"
echo -e "2  - ${NAME_DIR_three[2]}, ${MEM_three[2]} KB, $(md5sum ${NAME_DIR_three[2]} | cut -d " " -f 1 | xargs)"
echo -e "3  - ${NAME_DIR_three[3]}, ${MEM_three[3]} KB, $(md5sum ${NAME_DIR_three[3]} | cut -d " " -f 1 | xargs)"
echo -e "4  - ${NAME_DIR_three[4]}, ${MEM_three[4]} KB, $(md5sum ${NAME_DIR_three[4]} | cut -d " " -f 1 | xargs)"
echo -e "5  - ${NAME_DIR_three[5]}, ${MEM_three[5]} KB, $(md5sum ${NAME_DIR_three[5]} | cut -d " " -f 1 | xargs)"
echo -e "6  - ${NAME_DIR_three[6]}, ${MEM_three[6]} KB, $(md5sum ${NAME_DIR_three[6]} | cut -d " " -f 1 | xargs)"
echo -e "7  - ${NAME_DIR_three[7]}, ${MEM_three[7]} KB, $(md5sum ${NAME_DIR_three[7]} | cut -d " " -f 1 | xargs)"
echo -e "8  - ${NAME_DIR_three[8]}, ${MEM_three[8]} KB, $(md5sum ${NAME_DIR_three[8]} | cut -d " " -f 1 | xargs)"
echo -e "9  - ${NAME_DIR_three[9]}, ${MEM_three[9]} KB, $(md5sum ${NAME_DIR_three[9]} | cut -d " " -f 1 | xargs)"
echo -e "10 - ${NAME_DIR_three[10]}, ${MEM_three[10]} KB, $(md5sum ${NAME_DIR_three[10]} | cut -d " " -f 1 | xargs)"