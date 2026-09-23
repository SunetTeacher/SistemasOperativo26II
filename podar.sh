#!/bin/bash
echo "Dame el nombre del proceso a podar"
read prog
echo "Estamos por podar procesos llamados $prog"
readarray -t poda < <(ps -a|grep $prog|awk -F " " '{print $1}')
for i in "${poda[@]}"; do
	numhijos=$(pgrep -P $i|wc -l)
	if [ $numhijos -eq 0 ]
	then 
		echo "El" $i  "no tiene hijos y se extingue"
		#kill -9 $i
	fi	
done
