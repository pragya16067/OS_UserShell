
CFLAGS = -Wall -g

IP1 = ./bin/ls.c
OP1 = ./bin/ls

IP2 = ./bin/mkdir.c
OP2 = ./bin/mkdir

IP3 = ./bin/cat.c
OP3 = ./bin/cat

IP4 = ./bin/date.c
OP4 = ./bin/date

IP5 = ./bin/rm.c
OP5 = ./bin/rm
	
all: ush $(OP1) $(OP2) $(OP3) $(OP4) $(OP5)
	gcc ush.c -o ush
	gcc $(IP1) -o $(OP1)
	gcc $(IP2) -o $(OP2)
	gcc $(IP3) -o $(OP3)
	gcc $(IP4) -o $(OP4)
	gcc $(IP5) -o $(OP5)
	
	
.PHONY: clean
	
clean:
	rm -f ush $(OP1) $(OP2) $(OP3) $(OP4) $(OP5)



