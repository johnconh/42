# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    01_test_invalid_args.sh                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jdasilva <jdasilva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/05 15:44:50 by isojo-go          #+#    #+#              #
#    Updated: 2023/01/12 17:12:41 by jdasilva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#! bin/zsh

# Noff Args
echo "\033[0;93m    ---------- number off args ----------\033[0;39m"
echo "\033[0;94m../philo\033[0;39m"
../philo
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../philo 1\033[0;39m"
../philo 1
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../philo 1 2\033[0;39m"
../philo 1 2
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../philo 1 2 3\033[0;39m"
../philo 1 2 3
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../philo 1 2 3 4 5 6\033[0;39m"
../philo 1 2 3 4 5 6
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

# Args only positive ints
echo "\033[0;93m    ---------- args are not positive ints ----------\033[0;39m"
echo "\033[0;94m../philo 1 2 3 xxx\033[0;39m"
../philo 1 2 3 xxx
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../philo 1 2 3 4.5\033[0;39m"
../philo 1 2 3 4.5
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../philo 1 2 3 -4\033[0;39m"
../philo 1 2 3 -4
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../philo 1 2 3 2147483648\033[0;39m"
../philo 1 2 3 2147483648
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

# scope issue
echo "\033[0;93m    ---------- scope issues ----------\033[0;39m"
echo "\033[0;94m../philo 0 2 3 4\033[0;39m"
../philo 0 2 3 4
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../philo 1 0 3 4\033[0;39m"
../philo 1 0 3 4
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;94m../philo 1 2 3 4 0\033[0;39m"
../philo 1 2 3 4 0
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

# empty args
echo "\033[0;93m    ---------- empty args ----------\033[0;39m"
echo "\033[0;94m../philo \"\" 2 3 4 5\033[0;39m"
../philo "" 2 3 4 5
echo "\033[0;96mInput error? Press a key to continue\033[0;39m"
read ans

echo "\033[0;92mAll tests completed!"
