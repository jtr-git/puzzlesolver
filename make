echo "Cleaning.."
./clean
echo "Compiling clock..." 
g++ solver.h myclock.h myclock.cpp clock.cpp -g -o clockTest.out &> clock.log
echo "Compiled clock"
cat clock.log
echo "Compiling water..." 
g++ solver.h mywater.h mywater.cpp water.cpp -g -o waterTest.out &> water.log
echo "Compiled water"
cat water.log
