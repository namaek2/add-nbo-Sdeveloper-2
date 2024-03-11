TARGET=add-nbo
CSSFLAGS=-g

all: $(TARGET)

SRCS = add-nbo.c main.c
OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(LINK.c) $^ $(LOADLIBES) $(LDLIBS) -o $@

clean:
	rm -f $(TARGET)
	rm -f *.o

