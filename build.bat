@for %%f in (*.c) do @(
	clang -g -O0 %%~nf.c -o %%~nf.exe
	echo built %%~nf.exe
)