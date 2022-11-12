cd ~/week01
echo "Anastasia" > file.txt
cd ~/week10
link ~/week01/file.txt _ex2.txt 
find ~/week01/file.txt -inum $(stat -c "%i" ~/week01/file.txt) > ex2.txt
find ~/week01/file.txt -inum $(stat -c "%i" ~/week01/file.txt) -exec rm {} \; >> ex2.txt
