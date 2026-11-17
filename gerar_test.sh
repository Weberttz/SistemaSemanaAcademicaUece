#!/usr/bin/env bash

declare -a nomes=("Jonh" "Antônio" "Rafael" "Davi" "Marina" "Gabrielle" "Mell" "Maria" "Miguel" "Luís" "Arthur" "Marcelo" "Gabriel" "Pedro" "Thiciane" "Murilo")
declare -a sobrenomes=("Lima" "Souza" "Silva" "Filho" "Galdino" "Maia" "Aguiar" "Galdêncio" "Santos" "Oliveira" "Pereira" "Ferreira" "Alves")
declare -a atividades=()
declare -a codigos
declare -a matriculas
contador=1
min=1
max=32784

caminho="./tests/t06.in"
>$caminho

for i in {1..300}; do
    atividades+=("atividade_$i")
done

for atividade in ${atividades[@]}; do
    k=$(( $RANDOM % 50 + 1 ))
    codigos+=("$k")
    echo "CRIAR $contador $k $atividade" >> $caminho
    (( contador++ ))
done

for palavra in "${nomes[@]}"; do
    for sufixo in "${sobrenomes[@]}"; do
        a=$(( $RANDOM % 30 + 1))
        m=$(( $RANDOM % ($max - $min + 1) + $min ))
        matriculas+=("$m")
        echo "INSCREVER $a $m ${palavra}_${sufixo}"
    done >> $caminho
done

echo "FIM" >> $caminho

echo "Arquivo foi gerado com sucesso!"