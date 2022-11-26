# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleal <gleal@student.42lisboa.com>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 17:10:14 by gleal             #+#    #+#              #
#    Updated: 2022/11/26 15:33:42 by gleal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -g -std=c++98 -fsanitize=address
CPPFLAGS := -Istl -Itests/inc -Istl/extra -fsanitize=address
FT := -DFT=1
STD := -DFT=0

NAME_FT := ft_containers
NAME_STD := std_containers

OBJ_D := bin/
DEP_D := deps/

SRCS := main.cpp \
		test_stack.cpp \
		test_vector.cpp \
		all.cpp \
		test_reverse_vector_iterator.cpp
OBJS := $(SRCS:.cpp=.o)

FT_OBJS := $(addprefix ft_, $(OBJS))
FT_DEPS := $(FT_OBJS:.o=.d)
FT_OBJS := $(addprefix $(OBJ_D), $(FT_OBJS))
FT_DEPS := $(addprefix $(DEP_D), $(FT_DEPS))
FT_DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_D)ft_$*.d

STD_OBJS := $(addprefix std_, $(OBJS))
STD_DEPS := $(STD_OBJS:.o=.d)
STD_OBJS := $(addprefix $(OBJ_D), $(STD_OBJS))
STD_DEPS := $(addprefix $(DEP_D), $(STD_DEPS))
STD_DEPFLAGS = -MT $@ -MMD -MP -MF $(DEP_D)std_$*.d

vpath %.cpp tests/srcs/

all: $(NAME_STD) $(NAME_FT)

debug_ft: CXXFLAGS+=-DDEBUG
debug_ft: ft_containers

debug: debug_ft $(NAME_STD)

$(DEP_D): ; mkdir -p $@
$(OBJ_D): ; mkdir -p $@

$(NAME_FT): $(FT_OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(FT_OBJS) $(FT) -o $@
bin/ft_%.o : %.cpp $(DEP_D)ft_%.d Makefile | $(OBJ_D) $(DEP_D)
	$(CXX) $(FT_DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(FT) -c -o $@ $<

$(NAME_STD): $(STD_OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(STD_OBJS) $(STD) -o $@
bin/std_%.o : %.cpp $(DEP_D)std_%.d Makefile | $(OBJ_D) $(DEP_D)
	$(CXX) $(STD_DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(STD) -c -o $@ $<

$(FT_DEPS) $(STD_DEPS): Makefile
-include $(FT_DEPS) $(STD_DEPS)

clean:
	$(RM) $(FT_OBJS) $(STD_OBJS)
	$(RM) $(FT_DEPS) $(STD_DEPS)

fclean: clean
	$(RM) $(NAME_FT) $(NAME_STD)

resetclean: fclean clean
	$(RM) -r $(OBJ_D) $(DEP_D)

re: fclean all

.PHONY: all debug clean fclean resetclean re debug_ft debug_std CXXFLAGS+=-DDEBUG
