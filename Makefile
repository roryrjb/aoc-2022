targets = $(patsubst %.c,%,$(wildcard *.c))

entrypoint: run

all: $(targets)

run: all
	@find . -maxdepth 1 -type f -executable -execdir {} \;
	
clean:
	@rm -vf $(targets)