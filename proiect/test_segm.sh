#!/bin/bash

g++ -std=c++11 -o RUN main.cpp node.cpp persoana.cpp sandbox.cpp trie.cpp -pthread
for i in {1..100}; 
do 
./RUN ;
echo $i
done


