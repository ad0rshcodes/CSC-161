CC := clang
CFLAGS := 
LDFLAGS := -lm

all: data-rep float-loop trap-rule

clean:
	rm -f data-rep float-loop trap-rule

data-rep: data-rep.c
	$(CC) $(CFLAGS) -o data-rep data-rep.c $(LDFLAGS)

float-loop: float-loop.c
	$(CC) $(CFLAGS) -o float-loop float-loop.c $(LDFLAGS)

trap-rule: trap-rule.c
	$(CC) $(CFLAGS) -o trap-rule trap-rule.c $(LDFLAGS)

.PHONY: all clean
