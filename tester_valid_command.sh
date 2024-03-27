#!/bin/bash

echo -e "\033[0;92m"
echo -e "test: 1"
echo -e "\033[0;93m"
echo -e "< Makefile /cat/ | grep CC > outfile"
< Makefile /cat/ | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile /cat/ 'grep CC' outfile"
./pipex Makefile /cat/ 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 2"
echo -e "\033[0;93m"
echo -e "< Makefile ./cat/ | grep CC > outfile"
< Makefile ./cat/ | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile ./cat/ 'grep CC' outfile"
./pipex Makefile ./cat/ 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 3"
echo -e "\033[0;93m"
echo -e "< Makefile cat/ | grep CC > outfile"
< Makefile cat/ | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile cat/ 'grep CC' outfile"
./pipex Makefile cat/ 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 4"
echo -e "\033[0;93m"
echo -e "< Makefile grep CC | /cat/ > outfile"
< Makefile grep CC | /cat/ > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile 'grep CC' /cat/ outfile"
./pipex Makefile 'grep CC' /cat/ outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 5"
echo -e "\033[0;93m"
echo -e "< Makefile grep CC | ./cat/ > outfile"
< Makefile grep CC | ./cat/ > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile 'grep CC' ./cat/ outfile"
./pipex Makefile 'grep CC' ./cat/ outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 6"
echo -e "\033[0;93m"
echo -e "< Makefile grep CC | cat/ > outfile"
< Makefile grep CC | cat/ > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile 'grep CC' cat/ outfile"
./pipex Makefile 'grep CC' cat/ outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 7"
echo -e "\033[0;93m"
echo -e "< /cat/ cat | grep CC > outfile"
< /cat/ cat | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex /cat/ cat 'grep CC' outfile"
./pipex /cat/ cat 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 8"
echo -e "\033[0;93m"
echo -e "< ./cat/ cat | grep CC > outfile"
< ./cat/ cat | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex ./cat/ cat 'grep CC' outfile"
./pipex ./cat/ cat 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 9"
echo -e "\033[0;93m"
echo -e "< cat/ cat | grep CC > outfile"
< cat/ cat | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex cat/ cat 'grep CC' outfile"
./pipex cat/ cat 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 10"
echo -e "\033[0;93m"
echo -e "< Makefile cat | grep CC > /cat/"
< Makefile cat | grep CC > /cat/
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile cat 'grep CC' /cat/"
./pipex Makefile cat 'grep CC' /cat/
echo -e "\033[0m"$?
sleep 0.1
