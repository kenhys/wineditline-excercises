all: test_readline$(EXEEXT)

test_readline$(EXEEXT): test_readline.c
	gcc test_readline.c `pkg-config --cflags wineditline` `pkg-config --libs wineditline` -o test_readline$(EXEEXT)
