FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = BtcExc

all:
	@clear
	@echo Sto creando gli oggetti...
	@c++ $(FLAGS) *.cpp -o $(NAME)
	@sleep 0.2
	@echo Done ✓

fclean:
	@clear
	@echo Sto cancellando...
	@-rm -f $(NAME)
	@-rm -rf $(NAME).dSYM
	@sleep 0.4
	@echo Done ✓

re: fclean all