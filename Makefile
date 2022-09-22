SRC = \
      	main.cpp

SRCSDIR = ./test

OBJDIR = $(SRCSDIR)/objects

SRCS = ${SRC:%.cpp=$(SRCSDIR)/%.cpp}

OBJS = $(SRCS:.cpp=.o)

NAME = ft_containers

CXX = c++

CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -I./include/

RM = rm -rf


$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) -o $@ ${OBJS}
	$(CXX) $(CXXFLAGS) -D NAMESPACE=std -o $@_std ${SRCS}

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)_std

re: fclean all

.PHONY: all clean fclean re
