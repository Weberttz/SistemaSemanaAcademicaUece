#!/usr/bin/env bash

declare -a atividades=()
declare -a codigos
declare -a matriculas
min=1
contador=1
max_capacidade=10

caminho="./tests/t06.in"
>$caminho

for i in {1..300}; do
    atividades+=("atividade_$i")
done

for atividade in ${atividades[@]}; do
    k=$(( $RANDOM % $max_capacidade + 1 ))
    codigos+=("$contador")
    echo "CRIAR $contador $k $atividade" >> $caminho
    (( contador++ ))
done

(( contador-- ))

for i in {1..5000}; do
    a=$(( $RANDOM % ($contador - $min + 1) + $min ))
    echo "INSCREVER $a $i nome_$i" >> $caminho
done

echo "FIM" >> $caminho

echo "Arquivo foi gerado com sucesso!"