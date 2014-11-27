rm test.out compile.log
g++ *.h *.cpp -g -o test.out &> compile.log
cat compile.log
