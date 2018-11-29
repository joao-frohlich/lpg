#!/bin/bash
cd functions
gcc -c op_basicas.c
gcc -c soma_sub.c
gcc -c transpo.c
gcc -c multi.c
gcc -c multiesc.c
gcc -c iguais.c
gcc -c simetrica.c
mv op_basicas.o ../
mv soma_sub.o ../
mv transpo.o ../
mv multi.o ../
mv multiesc.o ../
mv iguais.o ../
mv simetrica.o ../
cd ../
gcc -c main.c
gcc -o main main.o op_basicas.o soma_sub.o transpo.o multi.o multiesc.o iguais.o simetrica.o
rm main.o
rm op_basicas.o
rm soma_sub.o
rm transpo.o
rm multi.o
rm multiesc.o
rm iguais.o
rm simetrica.o
