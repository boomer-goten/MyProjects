#!/bin/bash
START=$(date +%s%N)
ECHO_VVOD="./proverka_na_vvod.sh"
if [ ! -f "$ECHO_VVOD" ]; then
echo "$ECHO_VVOD not found"
exit 1
fi
source "$ECHO_VVOD"
cd $1 > /dev/null
total_numbers_of_dir=$(find -type d | wc -l)
total_numbers_of_files=$(find -type f | wc -l)
cd - > /dev/null
count_mem=1;
count_name_dir=1;
for entry in $(du -S $1 | sort -rnk1 | head -5 | xargs)
do
if [[ $count_mem -eq $count_name_dir ]]
then
MEM[$count_mem]=$entry
count_mem=$(( $count_mem + 1 ))
else
NAME_DIR[$count_name_dir]=$entry
count_name_dir=$(( $count_name_dir + 1 ))
fi
done
Configuration_files=$(find $1 -type f -name "*.conf" | wc -l)
Text_files=$(find $1 -type f -name "*.txt" | wc -l)
Exec_files=$(find $1 -type f -perm /a=x | wc -l)
Log_files=$(find $1 -type f -name "*.log" | wc -l)
Archive_files=$(find $1 -type f -name "*.tar" -o -name "*.deb" -o -name "*.pack" | wc -l)
Symbolic_links=$(ls -alR $1 | grep "^l" | wc -l)
echo "Total number of folders (including all nested ones) = $total_numbers_of_dir"
echo "TOP 5 folders of maximum size arranged in descending order (path and size):"
echo -e "1 - ${NAME_DIR[1]}, ${MEM[1]} KB"
echo -e "2 - ${NAME_DIR[2]}, ${MEM[2]} KB"
echo -e "3 - ${NAME_DIR[3]}, ${MEM[3]} KB"
echo -e "4 - ${NAME_DIR[4]}, ${MEM[4]} KB"
echo -e "5 - ${NAME_DIR[5]}, ${MEM[5]} KB"
echo "Total number of files = $total_numbers_of_files"
echo "Number of:"
echo "Configuration files (with the .conf extension) = $Configuration_files"
echo "Text files = $Text_files"
echo "Executable files = $Exec_files"
echo "Log files (with the extension .log) = $Log_files"
echo "Archive files = $Archive_files"
echo "Symbolic links = $Symbolic_links"
ECHO_FILES="./files_10.sh"
if [ ! -f "$ECHO_FILES" ]; then
echo "$ECHO_FILES not found"
exit 1
fi
source "$ECHO_FILES"
ECHO_HASH="./exec_hash.sh"
if [ ! -f "$ECHO_HASH" ]; then
echo "$ECHO_HASH not found"
exit 1
fi
source "$ECHO_HASH"
END=$(date +%s%N)
DIFF=$((($END - $START)/1000000))
if [ $DIFF -ge 1000 ]
then
DIFF=$(bc<<<"scale=1;$DIFF/1000")
echo "$DIFF"
else
DIFF=$(bc<<<"scale=1;$DIFF/1000")
echo "0$DIFF"
fi