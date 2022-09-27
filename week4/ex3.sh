cd ~/week4
gcc ex3.c 
./a.out 3 &
echo "n=3:"
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
./a.out 5 &
echo "n=5"
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
sleep 5
pstree $$
