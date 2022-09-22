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

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o ${<:.cpp=.o}

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
