NAME				=		abstractVM

CXX					=		g++

NOW 				:=	$(shell date +"%d %h %g:%R")



SRC		=	main.cpp \
			struc_of_type.cpp

OBJ					=		$(SRC:.cpp=.o)

CXXFLAGS			+= 	-Wall -Wextra -std=c++11 -g -fpic

INCLUDE				=	-I./include



all:		$(NAME)

$(NAME):	$(OBJ)
		@$(CXX) $(OBJ) -o $(NAME)
		@$(fclean)
clean:
		@$(RM) $(OBJ)

fclean:		clean
		@$(RM) $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
