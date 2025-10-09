if [[ $# -lt 1 || $# -gt 1 ]]
then 
	echo "Apenas 1 argumento tem de ser especeficado"
	echo "No uso de -r tem de ser especeficado o diretório"
fi

if [[ "$1" -eq "-r" ]]
then	
	if [[ $# -ne 2 ]]
	then
		echo "Tem de ser especeficado o diretório"
	fi
	pasta = "$1"
	for f in "$pasta"/*
	do
		nome = $(basename "$f")
		if [[ $nome == new_* ]]
		then
			nome_nome = "${nome#new_}" #remove o prefixo
			mv "$f" "$pasta/$novo_nome"
		fi
	done
	echo "Prefixo removido em $pasta"
else
	pasta = "$1"
	for f in "$pasta"/*
	do
		nome = $(basename "$f")
		if [[ $nome != new_* ]]
		then
			mv "$f" "$pasta/new_$nome"
		fi
	done
	echo "Prefixo adicionado em $pasta"
fi
