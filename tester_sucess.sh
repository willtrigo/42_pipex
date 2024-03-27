#!/bin/bash

echo -e "\033[0;92m"
echo -e "test: 1"
echo -e "\033[0;93m"
echo -e "< Makefile cat | grep CC > outfile"
< Makefile cat | grep CC > outfile
echo -e "\033[0m"$?
echo -en "\033[0;93m"
echo -e "./pipex Makefile cat 'grep CC' outfile"
./pipex Makefile cat 'grep CC' outfile
echo -e "\033[0m"$?
sleep 0.1
