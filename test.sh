make re
gcc -o ex -Wall -Werror -Wextra $1 ftprintf.a -Iincludes
#clear
echo -e "\n/********************************************************\ \n|\t\t\t\t\t\t\t | \n| \t\t    File output on $1 \t\t |\n|\t\t\t\t\t\t\t | \n\********************************************************/ \n\n" 
./ex #| cat -e
echo -e "\n\n"
rm ex