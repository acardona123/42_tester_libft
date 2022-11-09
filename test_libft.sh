#!/bin/bash

clear
echo -e "\e[3m====================================================\nTEST AUTOMATISE DE LIBFT\nProgramme réalisé par Alex Cardona\e[0m\n====================================================\n\n"

GLOBAL_CHECK=1
OK="OK :)"
KO="KO :("
MANUAL="echo -e \"\e[1;106m/!\\ Verification manuelle !!!\e[0m\""


#========================================
#Test de l'existance des fichiers


echo -e "\e[1;104m==== Présence des fichiers a rendre ====\e[0m\n"
FILE_LIST=( Makefile libft.h ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c  )
LOCAL_CHECK=1
for s in ${FILE_LIST[@]}
do
	if [ -f $s ]
	then
		echo "    OK : $s"
	else
		echo -e "\e[0;31m/!\ KO : $s\e[0m"
		LOCAL_CHECK=0
		GLOBAL_CHECK=0
	fi
done
echo -e "\e[1m==> Resultat du test de presence des fichiers :"
if [ "$LOCAL_CHECK" == "0" ]
then
	echo -e "\e[1;31m\t$KO\e[0m"
else
	echo -e "\e[1;32m\t$OK\e[0m"
fi


#========================================
#Test de norminette

echo -e "\n\n_______________________________________________\n\n\n"
echo -e "\e[1;104m==== Norminette ====\e[0m\n"
norminette ft_*.c


#========================================
#Test du make :

echo -e "\n\n_______________________________________________\n\n\n"
echo -e "\e[1;104m==== Test du make ====\e[0m\n"
LOCAL_CHECK=1
rm -rf *.o
rm -f libft.a

echo -e "1) make :\e[3;100m"
make 
echo -e "\e[m--> Generation de la bibliotheque :"
if [ -f libft.a ]
	then
		echo -e "\e[0;32m$OK\e[0m"
	else
		GLOBAL_CHECK=0
		LOCAL_CHECK=0
		echo -e "\e[0;31m$KO\e[0m"
fi

echo -e "\n2) make de nouveau :\e[3;100m"
make
$MANUAL

echo -e "\n3) make de nouveau avec modification de ft_strdup.c :"
echo "Tester les commandes suivantes :"
echo "touch ft_strdup.c && make"
echo "touch libft.h && make"
$MANUAL

echo -e "\n4) clean :\e[3;100m"
touch clean
make clean
echo -e "\n\e[m--> Gestion de clean :"
if [ -f *.o ]
	then
		echo -e "\e[0;31m$KO  pb de phony ?\e[0m"
		GLOBAL_CHECK=0
		LOCAL_CHECK=0
	else
		echo -e "\e[0;32m$OK\e[0m"
fi
rm clean

echo -e "\n5) fclean :\e[3;100m"
make > /dev/null
touch fclean
make fclean
echo -e "\n\e[m--> Gestion de fclean :"
if [ -f *.o ] || [ -f libft.a ]
	then
		echo -e "\e[0;31m$KO  pb de phony ?\e[0m"
		GLOBAL_CHECK=0
		LOCAL_CHECK=0
	else
		echo -e "\e[0;32m$OK\e[0m"
fi
rm fclean

echo -e "\n6) re : \e[3;100m" 
make re
$MANUAL


echo -e "\n\e[1m==> Bilan du make (partie auto seulement, voir points de controles manuels):"
if [ "$LOCAL_CHECK" == "0" ]
then
	echo -e "\e[1;31m\t$KO\e[0m"
else
	echo -e "\e[1;32m\t$OK\e[0m"
fi


#========================================
#Test des fonctions

echo -e "\n\n_______________________________________________\n\n\n"
echo -e "\e[1;104m==== Test des fonctions ====\e[0m\n"
echo -e "\e[1mTest automatique :\e[0m"
gcc -g test_libft_functions_auto.c -L. -lft -o test.exe
./test.exe
rm test.exe
echo -e "\n\e[1mTests avec verification par l'operateur :\e[0m"
echo "  Verifier dans les differentes consoles que les msg voulus apparaissent bien :"
gcc -g test_libft_functions_manual.c -L. -lft -o test.exe
./test.exe
rm test.exe