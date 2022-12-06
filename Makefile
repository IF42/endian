CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c18 -O2 
LIBS=

INCLUDE_PATH=/usr/include/
LIB_PATH=/usr/lib64

TARGET=linendian.a
CACHE=.cache
OUTPUT=$(CACHE)/release


MODULES += endian.o


TEST += test.o
TEST += endian.o


OBJ=$(addprefix $(CACHE)/,$(MODULES))
T_OBJ=$(addprefix $(CACHE),$(TEST))


all: env $(OBJ)
	ar -crs $(OUTPUT)/$(TARGET) $(OBJ)

%.o:
	$(CC) $(CFLAGS) -c $< -o $@


-include dep.list


exec: all
	$(OUTPUT)/$(TARGET)


.PHONY: env dep clean install


dep:
	$(CC) -MM src/*.c test/*.c | sed 's|[a-zA-Z0-9_-]*\.o|$(CACHE)/&|' > dep.list


test: env $(T_OBJ)
	$(CC) $(CFLAGS) $(T_OBJ) $(LIBS) -o $(OUTPUT)/test
	$(OUTPUT)/test


install:
	cp -v $(OUTPUT)/$(TARGET) $(LIB_PATH)/$(TARGET)
	cp -v src/endian.h $(INCLUDE_PATH)/endian.h


env:
	mkdir -pv $(CACHE)
	mkdir -pv $(OUTPUT)


clean: 
	rm -rvf $(CACHE)



