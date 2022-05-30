# MAKEFLAGS += --quiet

# Defining colors
WHT	= \033[0;37m
BLK	= \033[0;30m
RED	= \033[0;31m
YEL	= \033[0;33m
BLU	= \033[0;34m
GRN	= \033[0;32m
NC	= \033[0m

INC_DIR		= includes
SRC_DIR		= srcs
TEST_DIR	= test


SRC			= $(shell find $(SRC_DIR) -type f -name "*.cpp")
INC			= $(shell find $(INC_DIR) -type f -name "*.hpp")
TEST		= $(shell find $(TEST_DIR) -type f -name "*.cpp")

OBJ			= $(SRC:%.cpp=obj/%.o)
OBJ_TEST	= $(TEST:%.cpp=obj/%.o)

CCPP		= c++
CPPFLAGS	= -Wall -Wextra -Werror -std=c++98 -g
NAME		= main.out



# Rules

all:		$(NAME)

test:		$(OBJ_TEST)

obj/srcs/%.o:	$(SRC_DIR)/%.cpp $(INC) Makefile
				@mkdir -pv $(dir $@)
				@$(CCPP) $(CPPFLAGS) -I$(INC_DIR) -c $< -o $@

obj/test/%.o:	$(TEST_DIR)/%.cpp $(INC) Makefile

				$(eval FNAME=$(subst .o,,$@))
				@mkdir -pv $(dir $@)

				@$(CCPP) $(CPPFLAGS) -D_IS_TEST -I$(INC_DIR) -c $< -o $@
				@$(CCPP) $(CPPFLAGS) $@ -o $(FNAME)_ft
				@./$(FNAME)_ft > $(FNAME)_ft.log

				@$(CCPP) $(CPPFLAGS) -I$(INC_DIR) -c $< -o $@
				@$(CCPP) $(CPPFLAGS) $@ -o $(FNAME)_std
				@./$(FNAME)_std > $(FNAME)_std.log

				@(diff $(FNAME)_std.log $(FNAME)_ft.log > $(FNAME).diff \
				&& printf "$(GRN)$(FNAME).diff$(NC)\n" && rm $(FNAME).diff) \
				|| (printf "$(RED)$(FNAME).diff$(NC)\n" && cat $(FNAME).diff)

				@printf "$(YEL)[ ----- Time ----- ]$(NC)\n"
				@(time ./$(FNAME)_std > /dev/null) 2>&1 | grep "real" | sed 's/real/std/'
				@(time ./$(FNAME)_ft > /dev/null) 2>&1 | grep "real" | sed 's/real/ft /'

$(NAME):	$(OBJ)
				@$(CCPP) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
				@rm -vrf obj
				@rm -vrf $(OBJ_TEST)

fclean:		clean
				@rm -vrf $(NAME)
				@rm -vrf $(subst .o,,$(OBJ_TEST))

run:		all
				@./$(NAME)

re:			fclean all

.PHONY:		clean fclean run re test