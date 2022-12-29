# we need to override .SUFFIXES to get rid of default
# GNU make behaviour when dealing with C
# we need to treat each .c source file as an individual unit
# that creates its own executable
.SUFFIXES:

# we're on windows and we want to use cmd.exe, we define
# it explictly otherwise if somehow sh.exe gets into our
# %PATH% it'll use that by default
# see: https://git.savannah.gnu.org/cgit/make.git/tree/README.W32#n175
SHELL = cmd.exe

# also we're using clang specifically
CC = clang

# ...also using clang's MinGW backend
CFLAGS := -g --target=x86_64-pc-windows-gnu -O0

targets = $(patsubst %.c,%.exe,$(wildcard *.c))

build: $(targets)

%.exe: %.c
	$(CC) $(CFLAGS) -o $@ $<

run: build
	@for %%i in (*.exe) do (%%i)
	
clean:
	del *.exe
