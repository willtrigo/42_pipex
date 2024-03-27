#!/bin/bash

echo -e "\033[0;92m"
echo -e "test: 1"
echo -e "\033[0;93m"
echo -e "< Makefile /srca/ | grep CC > outfile"
< Makefile /srca/ | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile /srca/ 'grep CC' outfile"
./pipex Makefile /srca/ 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 2"
echo -e "\033[0;93m"
echo -e "< Makefile ./srca/ | grep CC > outfile"
< Makefile ./srca/ | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile ./srca/ 'grep CC' outfile"
./pipex Makefile ./srca/ 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 3"
echo -e "\033[0;93m"
echo -e "< Makefile srca/ | grep CC > outfile"
< Makefile srca/ | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile srca/ 'grep CC' outfile"
./pipex Makefile srca/ 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 4"
echo -e "\033[0;93m"
echo -e "< Makefile grep CC | /srca/ > outfile"
< Makefile grep CC | /srca/ > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile 'grep CC' /srca/ outfile"
./pipex Makefile 'grep CC' /srca/ outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 5"
echo -e "\033[0;93m"
echo -e "< Makefile grep CC | ./srca/ > outfile"
< Makefile grep CC | ./srca/ > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile 'grep CC' ./srca/ outfile"
./pipex Makefile 'grep CC' ./srca/ outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 6"
echo -e "\033[0;93m"
echo -e "< Makefile grep CC | srca/ > outfile"
< Makefile grep CC | srca/ > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile 'grep CC' srca/ outfile"
./pipex Makefile 'grep CC' srca/ outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 7"
echo -e "\033[0;93m"
echo -e "< /srca/ cat | grep CC > outfile"
< /srca/ cat | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex /srca/ cat 'grep CC' outfile"
./pipex /srca/ cat 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 8"
echo -e "\033[0;93m"
echo -e "< ./srca/ cat | grep CC > outfile"
< ./srca/ cat | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex ./srca/ cat 'grep CC' outfile"
./pipex ./srca/ cat 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 9"
echo -e "\033[0;93m"
echo -e "< srca/ cat | grep CC > outfile"
< srca/ cat | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex srca/ cat 'grep CC' outfile"
./pipex srca/ cat 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 10"
echo -e "\033[0;93m"
echo -e "< Makefile cat | grep CC > /srca/"
< Makefile cat | grep CC > /srca/
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile cat 'grep CC' /srca/"
./pipex Makefile cat 'grep CC' /srca/
echo -e "\033[0m"$?
sleep 0.1
