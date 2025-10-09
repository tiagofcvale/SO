function imprime_msg()
{
echo "A minha primeira funcao"
return 0
}

function date_and_name()
{
    echo "A data de hoje é: $(date "+%d/%m/%Y")"
    echo "O nome do computador é: $(hostname)"
    echo "O nome do utilizador é: $(whoami)"
}
imprime_msg
date_and_name   