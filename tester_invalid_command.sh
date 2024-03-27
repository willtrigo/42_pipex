#!/bin/bash

echo -e "\033[0;92m"
echo -e "test: 1"
echo -e "\033[0;93m"
echo -e "< Makefile /cat/ | grepppp CC > outfile"
< Makefile /cat/ | grepppp CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile /cat/ 'grepppp CC' outfile"
./pipex Makefile /cat/ 'grepppp CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 2"
echo -e "\033[0;93m"
echo -e "< Makefile ./cat/ | grepppp CC > outfile"
< Makefile ./cat/ | grepppp CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile ./cat/ 'grepppp CC' outfile"
./pipex Makefile ./cat/ 'grepppp CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 3"
echo -e "\033[0;93m"
echo -e "< Makefile cat/ | grepppp CC > outfile"
< Makefile cat/ | grepppp CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile cat/ 'grepppp CC' outfile"
./pipex Makefile cat/ 'grepppp CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 4"
echo -e "\033[0;93m"
echo -e "< Makefile grepppp CC | /cat/ > outfile"
< Makefile grepppp CC | /cat/ > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile 'grepppp CC' /cat/ outfile"
./pipex Makefile 'grepppp CC' /cat/ outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 5"
echo -e "\033[0;93m"
echo -e "< Makefile grepppp CC | ./cat/ > outfile"
< Makefile grepppp CC | ./cat/ > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile 'grepppp CC' ./cat/ outfile"
./pipex Makefile 'grepppp CC' ./cat/ outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 6"
echo -e "\033[0;93m"
echo -e "< Makefile grepppp CC | cat/ > outfile"
< Makefile grepppp CC | cat/ > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile 'grepppp CC' cat/ outfile"
./pipex Makefile 'grepppp CC' cat/ outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 7"
echo -e "\033[0;93m"
echo -e "< /cat/ cat | grepppp CC > outfile"
< /cat/ cat | grepppp CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex /cat/ cat 'grepppp CC' outfile"
./pipex /cat/ cat 'grepppp CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 8"
echo -e "\033[0;93m"
echo -e "< ./cat/ cat | grepppp CC > outfile"
< ./cat/ cat | grepppp CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex ./cat/ cat 'grepppp CC' outfile"
./pipex ./cat/ cat 'grepppp CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 9"
echo -e "\033[0;93m"
echo -e "< cat/ cat | grepppp CC > outfile"
< cat/ cat | grepppp CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex cat/ cat 'grepppp CC' outfile"
./pipex cat/ cat 'grepppp CC' outfile
echo -e "\033[0m"$?
sleep 0.1

echo -e "\033[0;92m"
echo -e "test: 10"
echo -e "\033[0;93m"
echo -e "< Makefile cat | grepppp CC > /cat/"
< Makefile cat | grepppp CC > /cat/
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile cat 'grepppp CC' /cat/"
./pipex Makefile cat 'grepppp CC' /cat/
echo -e "\033[0m"$?
sleep 0.1
