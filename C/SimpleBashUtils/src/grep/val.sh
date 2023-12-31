#!/bin/bash

COUNTER_SUCCESS=0
COUNTER_FAIL=0
DIFF_RES=""
echo "" > log.txt

for var in -v -c -l -n -h -o -i
do
  for var2 in -v -c -l -n -h -o -i
  do
      for var3 in -v -c -l -n -h -i -o
      do
        if [ $var != $var2 ] && [ $var2 != $var3 ] && [ $var != $var3 ]
        then
          # TEST1="for s21_grep.c Makefile $var $var2 $var3"
          # valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_grep $TEST1 > s21_grep.txt
          # grep $TEST1 > grep.txt
          # DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          # if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ]
          #   then
          #     (( COUNTER_SUCCESS++ ))
          #   else
          #     echo "$TEST1"
          #     (( COUNTER_FAIL++ ))
          # fi
          # rm s21_grep.txt grep.txt

          # TEST2="for s21_grep.c $var $var2 $var3"
          # valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_grep $TEST2 > s21_grep.txt
          # grep $TEST2 > grep.txt
          # DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          # if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ]
          #   then
          #     (( COUNTER_SUCCESS++ ))
          #   else
          #     echo "$TEST2"
          #     (( COUNTER_FAIL++ ))
          # fi
          # rm s21_grep.txt grep.txt

          # TEST3="-e for -e ^int s21_grep.c Makefile $var $var2 $var3"
          # valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_grep $TEST3 > s21_grep.txt
          # grep $TEST3 > grep.txt
          # DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          # if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ]
          #   then
          #     (( COUNTER_SUCCESS++ ))
          #   else
          #     echo "$TEST3"
          #     (( COUNTER_FAIL++ ))
          # fi
          # rm s21_grep.txt grep.txt

          # TEST4="-e for -e ^int s21_grep.c $var $var2 $var3"
          # valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_grep $TEST4 > s21_grep.txt
          # grep $TEST4 > grep.txt
          # DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          # if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ]
          #   then
          #     (( COUNTER_SUCCESS++ ))
          #   else
          #     echo "$TEST4"
          #     (( COUNTER_FAIL++ ))
          # fi
          # rm s21_grep.txt grep.txt

          TEST5="-e regex -e ^print s21_grep.c $var $var2 $var3 -f ./test_f.txt"
          valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_grep $TEST5 > s21_grep.txt
          grep $TEST5 > grep.txt
          DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ]
            then
              (( COUNTER_SUCCESS++ ))
            else
              echo "$TEST5"
              (( COUNTER_FAIL++ ))
          fi
          rm s21_grep.txt grep.txt

          # TEST6="-e while -e void s21_grep.c Makefile $var $var2 $var3 -f ./test_f.txt"
          # valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./s21_grep $TEST6 > s21_grep.txt
          # grep $TEST6 > grep.txt
          # DIFF_RES="$(diff -s s21_grep.txt grep.txt)"
          # if [ "$DIFF_RES" == "Файлы s21_grep.txt и grep.txt идентичны" ]
          #   then
          #     (( COUNTER_SUCCESS++ ))
          #   else
          #     echo "$TEST6"
          #     (( COUNTER_FAIL++ ))
          # fi
          # rm s21_grep.txt grep.txt

        fi
      done
  done
done

echo "SUCCESS: $COUNTER_SUCCESS"
echo "FAIL: $COUNTER_FAIL"

