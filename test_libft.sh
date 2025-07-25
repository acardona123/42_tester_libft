#!/bin/bash

SCRIPT_DIR=$(cd "$(dirname "$0")" && pwd)
CURRENT_DIR=$(pwd)

if [ "$SCRIPT_DIR" != "$CURRENT_DIR" ]
then
	 echo -e "Erreur:\nle programme doit etre lance depuis son repertoire d'origine avec la commande 'bash test_libft.sh ...' (et non ./test_libft.sh ...). Ce dernier contient egalement le repertoire test_src/ contenant les fichiers sources utilises par le testeur. -> Ne pas deplacer ou modifier les elements au sein de ces repertoires."
	 exit 1
fi

if [ "$#" -ne 3 ]
then
   echo -e "Erreur: le programme requiert 3 arguments :\n  bash test_libft.sh <directory_containing_the_makefile> <directory_containing_the_c_files> <directory_containing_libft_h\"\n Exemple: bash test_libft.sh \"..\" \"../src\" \"../includes\""
   exit 1
fi

LIBFT_DIR=$1
SRC_DIR=$2
INCLUDES_DIR=$3

clear
echo -e "\e[3m====================================================\nTEST AUTOMATISE DE LIBFT\nProgramme realise par Alex Cardona\e[0m\n====================================================\n\n"

echo -e "/!\\ Ces tests sont des tests preliminaires, ils permettent de detecter les erreurs grossieres dans la norme, compilation, ou le resultat des fonctions.\nLes tests ne sont pas exaustifs et certains elements dont la protection des allocations dynamiques ne sont pas verifies.\n => Ce testeur ne dispense pas le correcteur de verifier le contenu du code de l'evalue ni de mener ses propres tests.\n\n"

GLOBAL_CHECK=1
OK="OK :)"
KO="KO :("
MANUAL="echo -e \"\e[1;106m/!\\ verification manuelle !!!\e[0m\""


#========================================
#Test de l'existance des fichiers


echo -e "\e[1;104m==== Presence des fichiers a rendre (facultatif) ====\e[0m\n"
FILE_LIST=( ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c )
LOCAL_CHECK=1
if [ -f $LIBFT_DIR/Makefile ]
then
	echo "    OK : Makefile"
else
	echo -e "\e[0;31m/!\ KO : Makefile\e[0m"
		LOCAL_CHECK=0
		GLOBAL_CHECK=0
fi
if [ -f $INCLUDES_DIR/libft.h ]
then
	echo "    OK : libft.h"
else
	echo -e "\e[0;31m/!\ KO : libft.h\e[0m"
		LOCAL_CHECK=0
		GLOBAL_CHECK=0
fi
for s in ${FILE_LIST[@]}
do
	if [ -f $SRC_DIR/$s ]
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
norminette $SRC_DIR $INCLUDES_DIR


#========================================
#Test du make :

echo -e "\n\n_______________________________________________\n\n\n"
echo -e "\e[1;104m==== Test du make ====\e[0m\n"
LOCAL_CHECK=1
make fclean --no-print-directory -C $LIBFT_DIR
rm -rf *.o
rm -f libft.a

echo -e "1) make :\e[3;100m"
make --no-print-directory -C $LIBFT_DIR
echo -e "\e[m--> Generation de la bibliotheque :"
if [ -f $LIBFT_DIR/libft.a ]
	then
		echo -e "\e[0;32m$OK\e[0m"
	else
		GLOBAL_CHECK=0
		LOCAL_CHECK=0
		echo -e "\e[0;31m$KO\e[0m"
fi

echo -e "\n2) make de nouveau :\e[3;100m"
make --no-print-directory -C $LIBFT_DIR
$MANUAL

echo -e "\n3) make de nouveau avec modification de fichiers :"
echo -e "Modification de ft_strdup.c :\e[3;100m"
touch $SRC_DIR/ft_strdup.c
make --no-print-directory -C $LIBFT_DIR
echo -e "\e[0mModification de libft.h :\e[3;100m"
touch $INCLUDES_DIR/libft.h
make --no-print-directory -C $LIBFT_DIR
echo -ne "\e[0m" 
$MANUAL

echo -e "\n4) clean :\e[3;100m"
touch $LIBFT_DIR/clean
make clean --no-print-directory -C $LIBFT_DIR
echo -e "\n\e[0m--> Gestion de clean :"
if [ -f ../$LIBFT_DIR/*.o ]
	then
		echo -e "\e[0;31m$KO  pb de phony ?\e[0m"
		GLOBAL_CHECK=0
		LOCAL_CHECK=0
	else
		echo -e "\e[0;32m$OK\e[0m"
fi
rm $LIBFT_DIR/clean

echo -e "\n5) fclean :\e[3;100m"
make --no-print-directory -C $LIBFT_DIR> /dev/null
touch $LIBFT_DIR/fclean
make fclean --no-print-directory -C $LIBFT_DIR
echo -e "\n\e[0m--> Gestion de fclean :"
if [ -f $LIBFT_DIR/**/*.o ] || [ -f $LIBFT_DIR/libft.a ]
	then
		echo -e "\e[0;31m$KO  pb de phony ?\e[0m"
		GLOBAL_CHECK=0
		LOCAL_CHECK=0
	else
		echo -e "\e[0;32m$OK\e[0m"
fi
rm $LIBFT_DIR/fclean

echo -e "\n6) re : \e[3;100m" 
make re --no-print-directory -C $LIBFT_DIR
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
cp $INCLUDES_DIR/libft.h .
echo -e "\e[1mTest automatique :\e[0m"
cc -g test_src/test_libft_functions_auto.c -L$LIBFT_DIR -lft -o test.exe
./test.exe
rm test.exe
echo -e "\n\e[1mTests avec verification par l'operateur :\e[0m"
echo "  verifier dans les differentes consoles que les msg voulus apparaissent bien :"
cc -g test_src/test_libft_functions_manual.c -L$LIBFT_DIR -lft -o test.exe
./test.exe
rm test.exe
rm libft.h