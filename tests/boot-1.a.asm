	
char actual 'A';
char actual2 ;
short counter 0;
long valor2 5;
byte test 1;
int flag2 1598;


main:
{
	MOV AL , 'B';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'o';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'o';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 't';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'i';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'n';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'g';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , ' ';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'b';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'y';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , ' ';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'A';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'z';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'a';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'e';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'l';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , ' ';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , 'R';
	MOV AH , 0x0e;
	int 0x10;
	MOV AL , '.';
	MOV AH , 0x0e;
	int 0x10;
	RET;
}

	
