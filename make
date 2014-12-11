echo "Cleaning.."
./clean

echo "Compiling clock..." 
g++ puzzle.h myclock.h myclock.cpp solver.h clock.cpp -g -o clock -Wall -Wextra -pedantic &> clock.log
echo "Compiled clock"
cat clock.log

echo "Compiling water..." 
g++ puzzle.h mywater.h mywater.cpp solver.h water.cpp -g -o water -Wall -Wextra -pedantic &> water.log
echo "Compiled water"
cat water.log

echo "Compiling lloyd..."
g++ puzzle.h mylloyd.h mylloyd.cpp solver.h lloyd.cpp -g -o lloyd -Wall -Wextra -pedantic &> lloyd.log
echo "Compiled lloyd"
cat lloyd.log

echo "Compiling vclock..." 
g++ puzzle.h myvclock.h myvclock.cpp solver.h vclock.cpp -g -o vclock -Wall -Wextra -pedantic &> vclock.log
echo "Compiled vclock"
cat vclock.log
