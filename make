echo "Cleaning.."
./clean

echo "Compiling clock..." 
g++ puzzle.h myclock.h myclock.cpp solver.h clock.cpp -g -o clockTest.out -Wall -Wextra -pedantic &> clock.log
echo "Compiled clock"
cat clock.log

echo "Compiling water..." 
g++ puzzle.h mywater.h mywater.cpp solver.h water.cpp -g -o waterTest.out -Wall -Wextra -pedantic &> water.log
echo "Compiled water"
cat water.log

echo "Compiling lloyd..."
g++ puzzle.h mylloyd.h mylloyd.cpp solver.h lloyd.cpp -g -o lloydTest.out -Wall -Wextra -pedantic &> lloyd.log
echo "Compiled lloyd"
cat lloyd.log
