	
char actual 'A';
char actual2 ;
short counter 0;
long valor2 5;
byte test 1;


boot:

	mov 'B' al;
	mov 0x0e ah;
	int 0x10;
	mov 'o' al;
	mov 0x0e ah;
	int 0x10;
	mov 'o' al;
	mov 0x0 ah;
	int 0x10;
	mov 't' al;
	mov 0x0e ah;
	int 0x10;
	mov 'i' al;
	mov 0x0e ah;
	int 0x10;
	mov 'n' al;
	mov 0x0 ah;
	int 0x10;
	mov 'g' al;
	mov 0xEe ah;
	int 0x10;