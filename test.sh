echo "start testing:"

cat -b test.txt > cat.txt
./s21_cat -b test.txt > s21_cat.txt

echo "OUTPUT: cat -b test.txt"
echo "OUTPUT: ./s21_cat -b test.txt"

diff_output=$(diff cat.txt s21_cat.txt)

if [ -z "$diff_output" ]; then
    echo -e "STATUS: OK\n"
else
    echo -e "STATUS: FAIL\n"
fi



cat -e test.txt > cat.txt
./s21_cat -e test.txt > s21_cat.txt

echo "OUTPUT: cat -e test.txt"
echo "OUTPUT: ./s21_cat -e test.txt"

diff_output=$(diff cat.txt s21_cat.txt)

if [ -z "$diff_output" ]; then
    echo -e "STATUS: OK\n"
else
    echo -e "STATUS: FAIL\n"
fi



cat -n test.txt > cat.txt
./s21_cat -n test.txt > s21_cat.txt

echo "OUTPUT: cat -n test.txt"
echo "OUTPUT: ./s21_cat -n test.txt"

diff_output=$(diff cat.txt s21_cat.txt)

if [ -z "$diff_output" ]; then
    echo -e "STATUS: OK\n"
else
    echo -e "STATUS: FAIL\n"
fi

cat -s test.txt > cat.txt
./s21_cat -s test.txt > s21_cat.txt

echo "OUTPUT: cat -s test.txt"
echo "OUTPUT: ./s21_cat -s test.txt"

diff_output=$(diff cat.txt s21_cat.txt)

if [ -z "$diff_output" ]; then
    echo -e "STATUS: OK\n"
else
    echo -e "STATUS: FAIL\n"
fi


cat -t test.txt > cat.txt
./s21_cat -t test.txt > s21_cat.txt

echo "OUTPUT: cat -t test.txt"
echo "OUTPUT: ./s21_cat -t test.txt"

diff_output=$(diff cat.txt s21_cat.txt)

if [ -z "$diff_output" ]; then
    echo -e "STATUS: OK\n"
else
    echo -e "STATUS: FAIL\n"
fi
