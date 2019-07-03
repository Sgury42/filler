#!/bin/bash
LOGIN="sgury"

echo "\033[1;31m
          :::   :::      :::    :::       ::::::::       :::    :::       :::::::::       ::::::::       ::::::::         :::   :::
         :+:+: :+:+:     :+:    :+:      :+:    :+:      :+:    :+:       :+:    :+:     :+:    :+:     :+:    :+:       :+:+: :+:+:
        +:+ +:+:+ +:+    +:+    +:+      +:+             +:+    +:+       +:+    +:+     +:+    +:+     +:+    +:+      +:+ +:+:+ +:+
        +#+  +:+  +#+    +#+    +:+      +#++:++#++      +#++:++#++       +#++:++#:      +#+    +:+     +#+    +:+      +#+  +:+  +#+
        +#+       +#+    +#+    +#+             +#+      +#+    +#+       +#+    +#+     +#+    +#+     +#+    +#+      +#+       +#+
        #+#       #+#    #+#    #+#      #+#    #+#      #+#    #+#       #+#    #+#     #+#    #+#     #+#    #+#      #+#       #+#
        ###       ###     ########        ########       ###    ###       ###    ###      ########       ########       ###       ###     \033[0m
                                                              \033[32mCreated by roliveir\033[0m\n\n"

echo "				      \|||/      " "          \|||/      " "          \|||/      " "          \|||/      "
echo "				      (o o)      " "          (o o)      " "          (o o)      " "          (o o)      "
echo "				.~ooO~~(_)~~~~~~." "    .~ooO~~(_)~~~~~~." "    .~ooO~~(_)~~~~~~." "    .~ooO~~(_)~~~~~~."
echo "				|      \033[1;34mGNL\033[0m      |" "    |     \033[1;34mFILLIT\033[0m    |" "    |     \033[1;34mFT_LS\033[0m     |" "    |   \033[1;34mMINISHELL\033[0m   |"
echo "				| \033[1;31mCRASHES:    1\033[0m |" "    | \033[1;31mCRASHES:    3\033[0m |" "    | \033[1;31mCRASHES:    0\033[0m |" "    | \033[1;31mCRASHES:    2\033[0m |"
echo "				| \033[1;32mOK:         1\033[0m |" "    | \033[1;32mOK:         0\033[0m |" "    | \033[1;32mOK:         0\033[0m |" "    | \033[1;32mOK:         0\033[0m |"
echo "				'~~~~~~~~~~~ooO~'" "    '~~~~~~~~~~~ooO~'" "    '~~~~~~~~~~~ooO~'" "    '~~~~~~~~~~~ooO~'"
echo "				    |___|___|    " "        |___|___|    " "        |___|___|    " "        |___|___|    "
echo "				     ||   ||     " "         ||   ||     " "         ||   ||     " "         ||   ||     "
echo "				    ooO   Ooo    " "        ooO   Ooo    " "        ooO   Ooo    " "        ooO   Ooo    \n"

echo "				      \|||/      " "          \|||/      " "          \|||/      " "          \|||/      "
echo "				      (o o)      " "          (o o)      " "          (o o)      " "          (o o)      "
echo "				.~ooO~~(_)~~~~~~." "    .~ooO~~(_)~~~~~~." "    .~ooO~~(_)~~~~~~." "    .~ooO~~(_)~~~~~~."
echo "				|     \033[1;34mPRINTF\033[0m    |" "    |    \033[1;34mFILLER\033[0m     |" "    |   \033[1;34mPUSH_SWAP\033[0m   |" "    |     \033[1;34mLEM_IN\033[0m    |"
echo "				| \033[1;31mCRASHES:    0\033[0m |" "    | \033[1;31mCRASHES:    4\033[0m |" "    | \033[1;31mCRASHES:    1\033[0m |" "    | \033[1;31mCRASHES:    0\033[0m |"
echo "				| \033[1;32mOK:         0\033[0m |" "    | \033[1;32mOK:         0\033[0m |" "    | \033[1;32mOK:         1\033[0m |" "    | \033[1;32mOK:         0\033[0m |"
echo "				'~~~~~~~~~~~ooO~'" "    '~~~~~~~~~~~ooO~'" "    '~~~~~~~~~~~ooO~'" "    '~~~~~~~~~~~ooO~'"
echo "				    |___|___|    " "        |___|___|    " "        |___|___|    " "        |___|___|    "
echo "				     ||   ||     " "         ||   ||     " "         ||   ||     " "         ||   ||     "
echo "				    ooO   Ooo    " "        ooO   Ooo    " "        ooO   Ooo    " "        ooO   Ooo    \n"

echo "				      \|||/      " "          \|||/      "
echo "				      (o o)      " "          (o o)      "
echo "				.~ooO~~(_)~~~~~~." "    .~ooO~~(_)~~~~~~."
echo "				|    \033[1;34mCOREWAR\033[0m    |" "    |      \033[1;34mFDF\033[0m      |"
echo "				| \033[1;31mCRASHES:    1\033[0m |" "    | \033[1;31mCRASHES:    2\033[0m |"
echo "				| \033[1;32mOK:         0\033[0m |" "    | \033[1;32mOK:         0\033[0m |"
echo "				'~~~~~~~~~~~ooO~'" "    '~~~~~~~~~~~ooO~'"
echo "				    |___|___|    " "        |___|___|    "
echo "				     ||   ||     " "         ||   ||     "
echo "				    ooO   Ooo    " "        ooO   Ooo    \n"

echo "\033[32m----------NORME----------\033[0m"
read $VAR

norminette ../filler
echo "\033[32m----------NORME SUITE----------\033[0m"
read $VAR

find ../filler -name '*.c' -exec cat {} \; | grep "\+\n"
find ../filler -name '*.c' -exec cat {} \; | grep "\*\n"
find ../filler -name '*.c' -exec cat {} \; | grep "\-\n"
find ../filler -name '*.c' -exec cat {} \; | grep "\ \/\n"
find ../filler -name '*.c' -exec cat {} \; | grep "\&\n"
find ../filler -name '*.c' -exec cat {} \; | grep "\|\n"
find ../filler -name '*.c' -exec cat {} \; | grep "\%\n"
echo "\033[32m----------AUTEUR----------\033[0m"
read $VAR

cat -e ../filler/auteur
echo "\033[32m----------MAKE----------\033[0m"
read $VAR

make re -C ../filler
make clean -C ../filler
echo "\033[32m----------FONCTIONS----------\033[0m"
read $VAR

echo "\033[33mFonction autorisees:\nwrite\nread\nmalloc\nerror\nfree\nstrerror\033[0m"
nm -u ../filler/$LOGIN.filler
echo "\033[32m----------MALLOC----------\033[0m"
read $VAR

find ../filler -name '*.c' -exec cat {} \; | grep "join"
find ../filler -name '*.c' -exec cat {} \; | grep "strnew"
find ../filler -name '*.c' -exec cat {} \; | grep "strdup"
find ../filler -name '*.c' -exec cat {} \; | grep "malloc"
find ../filler -name '*.c' -exec cat {} \; | grep "lstnew"
find ../filler -name '*.c' -exec cat {} \; | grep "strsub"
echo "\033[32m----------INCLUDES----------\033[0m"
read $VAR

find ../filler -name '*.*' -exec cat {} \; | grep "include"
echo "\033[32m----------TEST ERREUR FACILE----------\033[0m"
read $VAR

./../filler/$LOGIN.filler
./../filler/$LOGIN.filler < file/error1
./../filler/$LOGIN.filler < file/error2
./../filler/$LOGIN.filler < /dev/null

echo "\033[32m----------TEST ERREUR MOYEN----------\033[0m"
read $VAR

./../filler/$LOGIN.filler < file/error3
./../filler/$LOGIN.filler < file/error4
./../filler/$LOGIN.filler < file/error5
./../filler/$LOGIN.filler < file/error6

echo "\033[32m----------TEST ERREUR DIFFICILE----------\033[0m"
read $VAR

./../filler/$LOGIN.filler < file/error7
./../filler/$LOGIN.filler < file/error8
./../filler/$LOGIN.filler < file
./../filler/$LOGIN.filler < /dev/random


echo "\033[32m----------TEST FACILE----------\033[0m"
read $VAR

./resources/filler_vm -f resources/maps/map00 -p1 resources/players/champely.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/champely.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/champely.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/abanlin.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/abanlin.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/abanlin.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/grati.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/grati.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/grati.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/hcao.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/hcao.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/hcao.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/superjeannot.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/superjeannot.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/superjeannot.filler -p2 ../filler/$LOGIN.filler

echo "\033[31mTEST FACILE\033[0m"
read $VAR

./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $:VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map01 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"

echo "\033[31mSUITE\033[0m"
read $VAR

./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map00 -p1 resources/players/carli.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
echo "\033[31mSUITE\033[0m"
read $VAR
./resources/filler_vm -f resources/maps/map02 -p1 resources/players/superjeannot.filler -p2 ../filler/$LOGIN.filler
echo "\033[32mX doit gagner\033[0m\n"
read $VAR
./resources/filler_vm -f resources/maps/map02 -p2 resources/players/superjeannot.filler -p1 ../filler/$LOGIN.filler
echo "\033[32mO doit gagner\033[0m\n"
read $VAR

echo "\033[32m----------TEST LEAKS FACILE----------\033[0m"
read $VAR

valgrind ./../filler/$LOGIN.filler
valgrind ./../filler/$LOGIN.filler < file/error1
valgrind ./../filler/$LOGIN.filler < file/error2
valgrind ./../filler/$LOGIN.filler < /dev/null

echo "\033[32m----------TEST LEAKS MOYEN----------\033[0m"
read $VAR

valgrind ./../filler/$LOGIN.filler < file/error3
valgrind ./../filler/$LOGIN.filler < file/error4
valgrind ./../filler/$LOGIN.filler < file/error5
valgrind ./../filler/$LOGIN.filler < file/error6

echo "\033[32m----------TEST LEAKS DIFFICILE----------\033[0m"
read $VAR

valgrind ./../filler/$LOGIN.filler < file/error7
valgrind ./../filler/$LOGIN.filler < file/error8
valgrind ./../filler/$LOGIN.filler < file
valgrind ./../filler/$LOGIN.filler < /dev/random
