# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gleal <gleal@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/16 17:10:14 by gleal             #+#    #+#              #
#    Updated: 2022/05/18 16:36:31 by gleal            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g
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
FT_OBJS := $(addprefix ft_, $(OBJS))
STD_OBJS := $(addprefix std_, $(OBJS))
FT_DEPS := $(FT_OBJS:.o=.d)
STD_DEPS := $(STD_OBJS:.o=.d)

TESTS := $(addprefix $(TESTDIR), $(TESTS))
FT_OBJS := $(addprefix $(OBJDIR), $(FT_OBJS))
FT_DEPS := $(addprefix $(DEPDIR), $(FT_DEPS))
FT_DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)ft_$*.d
STD_OBJS := $(addprefix $(OBJDIR), $(STD_OBJS))
STD_DEPS := $(addprefix $(DEPDIR), $(STD_DEPS))
STD_DEPFLAGS = -MT $@ -MMD -MP -MF $(DEPDIR)std_$*.d


all: $(NAME_STD) $(NAME_FT)

$(DEPDIR): ; mkdir -p $@
$(OBJDIR): ; mkdir -p $@

$(NAME_FT): $(FT_OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(FT_OBJS) $(FT) -o $@

bin/ft_%.o : %.cpp deps/ft_%.d Makefile | $(OBJDIR) $(DEPDIR)
	$(CXX) $(FT_DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(FT) -c -o $@ $<
bin/ft_%.o : tests/srcs/%.cpp deps/ft_%.d Makefile | $(OBJDIR) $(DEPDIR)
	$(CXX) $(FT_DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(FT) -c -o $@ $<

$(NAME_STD): $(STD_OBJS)
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) $(STD_OBJS) $(STD) -o $@
bin/std_%.o : %.cpp deps/std_%.d Makefile | $(OBJDIR) $(DEPDIR)
	$(CXX) $(STD_DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(STD) -c -o $@ $<
bin/std_%.o : tests/srcs/%.cpp deps/std_%.d Makefile | $(OBJDIR) $(DEPDIR)
	$(CXX) $(STD_DEPFLAGS) $(CXXFLAGS) $(CPPFLAGS) $(STD) -c -o $@ $<


$(FT_DEPS) $(STD_DEPS): Makefile
-include $(FT_DEPS) $(STD_DEPS)

clean:
	$(RM) $(FT_OBJS) $(STD_OBJS)
	$(RM) $(FT_DEPS) $(STD_DEPS)

fclean: clean
	$(RM) $(NAME_FT) $(NAME_STD)

resetclean: fclean clean
	$(RM) -r $(OBJDIR) $(DEPDIR)

re: fclean all

.PHONY: all clean fclean resetclean re
