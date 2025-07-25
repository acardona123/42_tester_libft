# Libft Tester

## Description
Tester pour le projet libft (mandatory uniquement) de 42 qui vérifie :
- La conformité à la norme 42
- Le fonctionnement du Makefile
- Les fonctions principales (test automatique et vérification manuelle)

## Installation et  Utilisation
```bash
git clone git@github.com:acardona123/42_tester_libft.git
cd 42_tester_libft
bash test_libft.sh <libft_makefile_directory> <libft_c_files_directory> <libft_h_directory>
```
Arguments :
1. `<makefile_dir>` : Répertoire contenant le Makefile
2. `<c_files_dir>` : Répertoire contenant les fichiers .c de la lib (pour la norme)
3. `<libft_h_dir>` : Répertoire contenant le fichier libft.h (pour la norme)

## Fonctionnalités de test

### 1. Test de la norme (automatique)
Conformité du format avec la norme 42, réalisé automatiquement avec la Norminette 42.

### 2. Test du Makefile (manuel)
- `make` (compilation de base)
- `make clean`
- `make fclean` 
- `make re`
> ** ⚠️ Warning **
> La conformité du makefile par rapport au exigences du sujet est à vérifier manuellement.
> Vérifier les flags, que le makefile ne recompile pas inutilement, que la compilation soit faite avec `CC`, l'utiliation de `.PHONY`, etc

### 3. Tests automatiques
Fonctions testées automatiquement avec vérification des résultats :
`ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint` `ft_strlen` `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_strlcpy` `ft_strlcat` `ft_toupper` `ft_tolower` `ft_strchr` `ft_strrchr` `ft_strncmp` `ft_memchr` `ft_memcmp` `ft_strnstr` `ft_atoi` `ft_calloc` `ft_strdup` `ft_substr` `ft_strjoin` `ft_strtrim` `ft_split` `ft_itoa` `ft_strmapi` `ft_striteri`

### 4. Tests manuels
Fonctions nécessitant une vérification manuelle (comparaison du resultat obtenu avec celui attendu) :
`ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd`

## Sortie du test
À chaque étape (excepté la partie avec vérification manuelle) le tester emet des bilan indiquant si les tests ont été passés avec succès.

## Exemple complet
```bash
# Pour tester une libft située dans ~/project/libft/
cd ~/42_tester_libft/
bash test_libft.sh ~/project/libft/ ~/project/libft/src/ ~/project/libft/includes/
```