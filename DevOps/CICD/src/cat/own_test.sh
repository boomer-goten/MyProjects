ERRORS=0

TEST1='TEST1'
cat test1.txt > original_result.txt
./s21_cat test1.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST1 without flags"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST1 > original_result.txt
rm original_result.txt s21_result.txt

cat -e test1.txt > original_result.txt
./s21_cat -e test1.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST1 with -e"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST1 > original_result.txt
rm original_result.txt s21_result.txt

cat -E test1.txt > original_result.txt
./s21_cat -E test1.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST1 with -E"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST1 > original_result.txt
rm original_result.txt s21_result.txt

cat -t test1.txt > original_result.txt
./s21_cat -t test1.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST1 with -t"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST1 > original_result.txt
rm original_result.txt s21_result.txt

cat -T test1.txt > original_result.txt
./s21_cat -T test1.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST1 with -T"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST1 > original_result.txt
rm original_result.txt s21_result.txt

cat -n test1.txt > original_result.txt
./s21_cat -n test1.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST1 with -n"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST1 > original_result.txt
rm original_result.txt s21_result.txt

cat -b test1.txt > original_result.txt
./s21_cat -b test1.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST1 with -b"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST1 > original_result.txt
rm original_result.txt s21_result.txt

cat -s test1.txt > original_result.txt
./s21_cat -s test1.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST1 with -s"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST1 > original_result.txt
rm original_result.txt s21_result.txt

TEST2='TEST2'
cat file2.txt > original_result.txt
./s21_cat file2.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST2 without flags"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST2 > original_result.txt
rm original_result.txt s21_result.txt

cat -e file2.txt > original_result.txt
./s21_cat -e file2.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST2 with -e"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST2 > original_result.txt
rm original_result.txt s21_result.txt

cat -E file2.txt > original_result.txt
./s21_cat -E file2.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST2 with -E"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST2 > original_result.txt
rm original_result.txt s21_result.txt

cat -t file2.txt > original_result.txt
./s21_cat -t file2.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST2 with -t"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST2 > original_result.txt
rm original_result.txt s21_result.txt

cat -T file2.txt > original_result.txt
./s21_cat -T file2.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST2 with -T"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST2 > original_result.txt
rm original_result.txt s21_result.txt

cat -n file2.txt > original_result.txt
./s21_cat -n file2.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST2 with -n"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST2 > original_result.txt
rm original_result.txt s21_result.txt

cat -b file2.txt > original_result.txt
./s21_cat -b file2.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST2 with -b"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST2 > original_result.txt
rm original_result.txt s21_result.txt

cat -s file2.txt > original_result.txt
./s21_cat -s file2.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST2 with -s"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST2 > original_result.txt
rm original_result.txt s21_result.txt

TEST3='TEST3'
cat test3.txt > original_result.txt
./s21_cat test3.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST3 without flags"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST3 > original_result.txt
rm original_result.txt s21_result.txt

cat -e test3.txt > original_result.txt
./s21_cat -e test3.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST3 with -e"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST3 > original_result.txt
rm original_result.txt s21_result.txt

cat -E test3.txt > original_result.txt
./s21_cat -E test3.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST3 with -E"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST3 > original_result.txt
rm original_result.txt s21_result.txt

cat -t test3.txt > original_result.txt
./s21_cat -t test3.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST3 with -t"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST3 > original_result.txt
rm original_result.txt s21_result.txt

cat -T test3.txt > original_result.txt
./s21_cat -T test3.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST3 with -T"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST3 > original_result.txt
rm original_result.txt s21_result.txt

cat -n test3.txt > original_result.txt
./s21_cat -n test3.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST3 with -n"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST3 > original_result.txt
rm original_result.txt s21_result.txt

cat -b test3.txt > original_result.txt
./s21_cat -b test3.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST3 with -b"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST3 > original_result.txt
rm original_result.txt s21_result.txt

cat -s test3.txt > original_result.txt
./s21_cat -s test3.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST3 with -s"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST3 > original_result.txt
rm original_result.txt s21_result.txt

TEST5='TEST5'
cat test5.txt > original_result.txt
./s21_cat test5.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST5 without flags"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST5 > original_result.txt
rm original_result.txt s21_result.txt

cat -e test5.txt > original_result.txt
./s21_cat -e test5.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST5 with -e"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST5 > original_result.txt
rm original_result.txt s21_result.txt

cat -E test5.txt > original_result.txt
./s21_cat -E test5.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST5 with -E"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST5 > original_result.txt
rm original_result.txt s21_result.txt

cat -t test5.txt > original_result.txt
./s21_cat -t test5.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST5 with -t"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST5 > original_result.txt
rm original_result.txt s21_result.txt

cat -T test5.txt > original_result.txt
./s21_cat -T test5.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST5 with -T"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST5 > original_result.txt
rm original_result.txt s21_result.txt

cat -n test5.txt > original_result.txt
./s21_cat -n test5.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST5 with -n"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST5 > original_result.txt
rm original_result.txt s21_result.txt


TEST6='TEST6'
cat test6.txt > original_result.txt
./s21_cat test6.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST6 without flags"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST6 > original_result.txt
rm original_result.txt s21_result.txt

cat -e test6.txt > original_result.txt
./s21_cat -e test6.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST6 with -e"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST6 > original_result.txt
rm original_result.txt s21_result.txt

cat -E test6.txt > original_result.txt
./s21_cat -E test6.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST6 with -E"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST6 > original_result.txt
rm original_result.txt s21_result.txt

cat -t test6.txt > original_result.txt
./s21_cat -t test6.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST6 with -t"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST6 > original_result.txt
rm original_result.txt s21_result.txt

cat -T test6.txt > original_result.txt
./s21_cat -T test6.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST6 with -T"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST6 > original_result.txt
rm original_result.txt s21_result.txt

cat -n test6.txt > original_result.txt
./s21_cat -n test6.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST6 with -n"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST6 > original_result.txt
rm original_result.txt s21_result.txt

cat -b test6.txt > original_result.txt
./s21_cat -b test6.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST6 with -b"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST6 > original_result.txt
rm original_result.txt s21_result.txt

cat -s test6.txt > original_result.txt
./s21_cat -s test6.txt > s21_result.txt
cmp original_result.txt s21_result.txt || let ERRORS+=1 && echo "IN $TEST6 with -s"
# valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_cat $TEST6 > original_result.txt
rm original_result.txt s21_result.txt

echo "Total number of errors is $ERRORS."

if [[ $ERRORS -eq 0 ]]; then
    exit 0
else
    exit 1
fi