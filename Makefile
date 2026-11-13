# My third makefile

# Name of the project
PROJ_NAME=programa

# .c files
C_SOURCE=$(wildcard ./src/*.c)

# .h files
H_SOURCE=$(wildcard ./include/*.h)

# Object files
OBJ=$(subst .c,.o,$(subst src,objects,$(C_SOURCE)))

# Compiler and linker
CC=gcc

# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -std=c11   \
         -pedantic  \
		 -O3        \
		 -I ./include

# Command used at clean target
RM = rm -rf

#
# Compilation and linking
#
all: checkEmpty objFolder $(PROJ_NAME)

checkEmpty:
	@ if [ -z "$(C_SOURCE)" ]; then \
		echo "Erro: Nenhum arquivo .c encontrado em ./src/"; \
		exit 1; \
	fi
	@ for file in $(C_SOURCE) $(H_SOURCE); do \
		if [ ! -s "$$file" ]; then \
			echo "Erro: O arquivo '$$file' está vazio!"; \
			exit 1; \
		fi; \
	done

$(PROJ_NAME): $(OBJ)
	@ echo 'Building binary using GCC linker: $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./objects/%.o: ./src/%.c ./include/%.h
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./objects/main.o: ./src/main.c $(H_SOURCE)
	@ echo 'Building target using GCC compiler: $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects

clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects

.PHONY: all clean checkFolder objFolder