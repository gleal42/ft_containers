# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleal <gleal@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 17:10:14 by gleal             #+#    #+#              #
#    Updated: 2022/05/17 00:56:56 by gleal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98
CPPFLAGS := -Istl -Itests/inc
FT := -DFT=1
STD := -DFT=0

NAME_FT := ft_containers
NAME_STD := std_containers

SRCDIR := srcs/
OBJDIR := bin/
DEPDIR := deps/
TESTDIR := tests/$(SRCDIR)

SRCS := main.cpp
TESTS := test_stack.cpp

OBJS := $(SRCS:.cpp=.o) $(TESTS:.cpp=.o)
DEPS := $(OBJS:.o=.d)
FT_OBJS := $(addprefix ft_, $(OBJS))
STD_OBJS := $(addprefix std_, $(OBJS))

TESTS := $(addprefix $(TESTDIR), $(TESTS))
FT_OBJS := $(addprefix $(OBJDIR), $(FT_OBJS))
STD_OBJS := $(addprefix $(OBJDIR), $(STD_OBJS))
DEPS := $(addprefix $(DEPDIR), $(DEPS))

DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)/$*.d

all: $(NAME_FT) $(NAME_STD)

$(DEPDIR): ; mkdir -p $@
$(OBJDIR): ; mkdir -p $@

$(NAME_FT): $(FT_OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(FT_OBJS) $(FT) -o $@
bin/ft_%.o : %.cpp deps/%.d Makefile | $(OBJDIR) $(DEPDIR)
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(FT) -c -o $@ $<
bin/ft_%.o : tests/srcs/%.cpp deps/%.d Makefile | $(OBJDIR) $(DEPDIR)
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(FT) -c -o $@ $<

$(NAME_STD): $(STD_OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(STD_OBJS) $(STD) -o $@
bin/std_%.o : %.cpp deps/%.d Makefile | $(OBJDIR) $(DEPDIR)
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(STD) -c -o $@ $<
bin/std_%.o : tests/srcs/%.cpp deps/%.d Makefile | $(OBJDIR) $(DEPDIR)
	$(CXX) $(DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(STD) -c -o $@ $<


$(DEPS): Makefile
-include $(DEPS)

clean:
	$(RM) $(FT_OBJS) $(STD_OBJS)
	$(RM) $(DEPS)

fclean: clean
	$(RM) $(NAME_FT) $(NAME_STD)

resetclean: fclean clean
	$(RM) -r $(OBJDIR) $(DEPDIR)

re: fclean all

.PHONY: all clean fclean resetclean re
