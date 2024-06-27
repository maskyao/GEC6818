# CROSS_COMPILE = arm-linux-
# SOURCES := $(patsubst %.c,%.o,$(wildcard ./src/*.c))
# TARGET	= aitalk
# BIN_TARGET = $(./bin)/$(TARGET)

# CFLAGS = -g -Wall -I$(./include)
# LDFLAGS := -L$(./libs)
# LDFLAGS += -lmsc -lrt -ldl -lpthread -lasound  -lstdc++

# $(BIN_TARGET): $(SOURCES)
# 	$(CROSS_COMPILE)gcc $(CFLAGS)  $^ -o $@ $(LDFLAGS)

# %.o: %.c
# 	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

# clean:
# 	@rm -f *.o $(BIN_TARGET)

# .PHONY:clean
    
# #common makefile foot

#common makefile header

DIR_INC = ./include
DIR_BIN = ./bin
DIR_LIB = ./libs

TARGET	= aitalk
BIN_TARGET = $(DIR_BIN)/$(TARGET)
OUTPUT := project

CROSS_COMPILE = arm-linux-
CFLAGS = -g -Wall -I$(DIR_INC)


LDFLAGS := -L$(DIR_LIB)
LDFLAGS += -lmsc -lrt -ldl -lpthread -lasound  -lstdc++

OBJECTS := $(patsubst %.c,%.o,$(wildcard ./src/*.c))

# all: $(OUTPUT)

$(OUTPUT) : $(OBJECTS)
	$(CROSS_COMPILE)gcc $(CFLAGS) $^ -o $@ $(LDFLAGS)

%.o : %.c
	$(CROSS_COMPILE)gcc -c $(CFLAGS) $< -o $@
clean:
	@rm -f *.o $(OUTPUT)

.PHONY:clean

#common makefile foot


# CROSS_COMPILE = arm-linux-
# CFLAGS := -I./include
# SOURCES := $(wildcard ./src/*.c)
# OUTPUT := project
# LIBS := -lpthread

# %.o: %.c
# 	$(CROSS_COMPILE)gcc $(CFLAGS) -c $< -o $@

# all: $(OUTPUT)

# $(OUTPUT): $(SOURCES:.c=.o)
# 	$(CROSS_COMPILE)gcc $^ $(LIBS) -o $@

# .PHONY: clean
# clean:
# 	rm -f $(OUTPUT) ./src/*.o