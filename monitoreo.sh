#!/bin/bash
echo "Dame el nombre del proceso a monitorear"
read prog
echo "Estamos monitoreando el proceso llamado $prog"
numproc=$(ps -a|grep $prog |wc -l) #contar numero de lineas
if [ $numproc -gt 0 ]
then
	echo "Hay" $numproc "procesos llamados" $prog
  
  r=$(ps axo comm,stat|grep $prog|grep "R"|wc -l )
  s=$(ps axo comm,stat|grep $prog|grep "S"|wc -l )
  d=$(ps axo comm,stat|grep $prog|grep "D"|wc -l )
  z=$(ps axo comm,stat|grep $prog|grep "Z"|wc -l )

  echo "Hay $r procesos en estado R"
  echo "Hay $s procesos en estado S"
  echo "Hay $d procesos en estado D"
  echo "Hay $z procesos en estado Z"

  
	ps axo pid,comm,stat|grep $prog
	
	idprocpadre=$(ps -a |grep $prog |awk -F " " '{print $1}'|head -n 1) #obtiene la primer columna y su cabeza de la primera
	echo "El arbl de procesos es:"
	pstree -p $idprocpadre
	numhijos=$(pgrep -P $idprocpadre|wc -l)
    echo "El proceso $idprocpadre tiene $numhijos y son:"
	pgrep -P $idprocpadre
	
    readarray -t pids < <(pgrep -P "$idprocpadre")
	echo "mi primer elemento "
	echo "${pids[0]}"
	echo "El numero elementos en el arreglo es" 
	echo "${#pids[@]}"
	echo "iterando sobre todo el arreglo"
	for pid in "${pids[@]}"; do
		echo "Procesando el PID hijo: $pid"
		readarray -t pidsnietos < <(pgrep -P $pid)
		echo "El proceso $pid tiene  "${#pidsnietos[@]}" hijos"
		if [ "${#pidsnietos[@]}" -gt 0 ]
		then
			echo "Sus hijos son:"
			for pidn in "${pidsnietos[@]}"; do
				echo $pidn
			done
		fi
	done
	 
	 
else
	echo "No hay procesos llamados " $prog
	exit
	
fi
