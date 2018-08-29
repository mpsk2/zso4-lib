LIB_NAME = extacl.a
DEPS = extacl.h
OBJ = extacl.o
CFLAGS = -Wall
.PHONY: all

all: $(LIB_NAME)

$(LIB_NAME): $(OBJ)
	ar -rcs $(LIB_NAME) $(OBJ)

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm *.o *.a
