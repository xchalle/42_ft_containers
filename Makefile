SRC = \
      	main.cpp \
	map/test_map_capacity.cpp \
	map/test_map.cpp \
	map/test_map_element_access.cpp \
	map/test_map_iterator.cpp \
	map/test_map_lookup.cpp \
	map/test_map_modifiers.cpp \
	map/test_map_non_member.cpp \
	map/test_map_observers.cpp \
	set/test_set_capacity.cpp \
	set/test_set.cpp \
	set/test_set_iterator.cpp \
	set/test_set_lookup.cpp \
	set/test_set_modifiers.cpp \
	set/test_set_non_member.cpp \
	stack/test_stack.cpp \
	vector/test_vector_capacity.cpp \
	vector/test_vector_element_access.cpp \
	vector/test_vector_iterators.cpp \
	vector/test_vector_modifiers.cpp \
	vector/test_vector_non_member.cpp  


SRCSDIR = ./test

OBJDIR_FT = $(SRCSDIR)/objects_ft
OBJDIR_STD = $(SRCSDIR)/objects_std

SRCS = ${SRC:%.cpp=$(SRCSDIR)/%.cpp}

OBJS_FT : $(SRCS)
	$(CXX) $(CXXFLAGS) -DNAMESPACE=ft -c $(SRCS)
OBJS_STD : $(SRCS)
	$(CXX) $(CXXFLAGS) -DNAMESPACE=std -c $(SRCS)

NAME = ft_containers

CXX = c++

CXXFLAGS= -Wall -Wextra -Werror -std=c++98 -I./include/ -I./test/include/

RM = rm -rf


$(NAME): $(OBJS_FT) $(OBJS_STD) 
	$(CXX) $(CXXFLAGS) -DNAMESPACE=ft -o $@ ${OBJS_FT}
	$(CXX) $(CXXFLAGS) -DNAMESPACE=std -o $@_std ${OBJS_STD}

all: $(NAME)

clean:
	$(RM) $(OBJS_FT)
	$(RM) $(OBJS_STD)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME)_std

re: fclean all

.PHONY: all clean fclean re
