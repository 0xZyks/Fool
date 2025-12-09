# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsignori <tsignori@student.42perpignan.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/19 17:05:12 by tsignori          #+#    #+#              #
#    Updated: 2025/11/19 17:07:28 by tsignori         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### CONFIG

NAME ?=

SRC_DIR := src
OBJ_DIR := obj
INC_DIR := includes

CC      := cc
CFLAGS  := -Wall -Wextra -Werror -I$(INC_DIR)

################################################################################
### AUTO SOURCES

SRC_FILES := $(shell find $(SRC_DIR) -type f -name "*.c")
OBJ_FILES := $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

################################################################################
### COLORS

RESET	:= \033[0m
RED		:= \033[1;31m
GREEN	:= \033[1;32m
BLUE	:= \033[1;34m
YELLOW	:= \033[1;33m

################################################################################
### NAME / MODE / PROTECTIONS

PHONY_GOALS := clean fclean re

ifneq ($(filter %.a,$(MAKECMDGOALS)),)
	NAME := $(filter %.a,$(MAKECMDGOALS))
endif

ifneq ($(filter-out $(PHONY_GOALS) %.a,$(MAKECMDGOALS)),)
	NAME := $(filter-out $(PHONY_GOALS) %.a,$(MAKECMDGOALS))
endif

ifeq ($(strip $(NAME)),)
	NAME := $(shell cat .build_name 2>/dev/null)
endif

ifneq ($(findstring .a,$(NAME)),)
	MODE = LIB
else
	MODE = EXE
endif

ifeq ($(MAKECMDGOALS),)
	ifeq ($(strip $(NAME)),)
		$(error Aucun nom fourni. Utilise NAME=prog ou NAME=lib.a)
	endif
endif

################################################################################
### CATCH-ALL (évite "Pas de règle pour fabriquer")

%:
	@true

################################################################################
### BUILD RULES

all: $(NAME)

$(NAME): $(OBJ_FILES)
ifeq ($(MODE),LIB)
	@echo "$(GREEN)[AR]$(RESET)  $@"
	@ar rcs $@ $(OBJ_FILES)
else
	@echo "$(GREEN)[LD]$(RESET)  $@"
	@$(CC) $(CFLAGS) $(OBJ_FILES) -o $@
endif
	@echo $(NAME) > .build_name

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@echo "$(BLUE)[CC]$(RESET)  $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

################################################################################
### CLEAN RULES

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)[RM]$(RESET) $(OBJ_DIR)"

fclean: clean
	@LAST=$$(cat .build_name 2>/dev/null); \
	if [ -n "$$LAST" ]; then \
		echo "$(RED)[RM]$(RESET) $$LAST"; \
		rm -f $$LAST; \
	fi
	@rm -f .build_name

re: fclean all

.PHONY: all clean fclean re
