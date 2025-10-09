#!/bin/bash
# select structure to create menus
select arg in $@
do
	if [[ -z "$arg" ]]; then
        	echo "Opção inválida. A sair..."
        	break
   	 fi
	echo "You picked $arg ($REPLY)."
done
