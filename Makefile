.SUFFIXES:

SHELL = cmd.exe
CC := clang
CFLAGS := -g --target=x86_64-pc-windows-gnu -O0

targets = $(patsubst %.c,%.exe,$(wildcard *.c))

build: $(targets)

%.exe: %.c
	$(CC) $(CFLAGS) -o $@ $<

run: build
	@for %%i in (*.exe) do (%%i)
	
clean:
	del *.exe
