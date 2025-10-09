#!/bin/bash
echo "O meu editor por omissão BASH $BASH \$BASH"
echo 'O meu editor por omissão BASH $BASH \$BASH'
echo $(( 5 + 5 ))
(( 5 > 0 )) && echo "cinco é maior do que zero"
today=$(date); echo $today

echo -e "\n\nTodos os ficheiros em /etc"
ls /etc

echo -e "\n\nTodos os ficheiros começados por \"a\""
ls /etc/a*

echo -e "\n\nTodos os ficheiros começados por \"a\" e têm mais de 3 caracteres"
ls /etc/a???*

echo -e "\n\nTodos os ficheiros em /etc que contenham conf"
#ls /etc | grep *conf*
ls -a /etc/*conf[!aeiou]*

