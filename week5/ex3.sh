
gcc ex3.c -pthread 
/bin/time -p -o ex3.txt ./a.out 10000000 1 
/bin/time -a -p -o ex3.txt ./a.out 10000000 2
/bin/time -a -p -o ex3.txt ./a.out 10000000 4
/bin/time -a -p -o ex3.txt ./a.out 10000000 10
/bin/time -a -p -o ex3.txt ./a.out 10000000 100

