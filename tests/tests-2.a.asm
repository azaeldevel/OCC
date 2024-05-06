const char* message;
int counter;
register char type;

greethings
{
	mov al , 'B';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'o';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'o';
	mov ah , 0x0e;
	int 0x10;
	mov al , 't';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'i';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'n';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'g';
	mov ah , 0x0e;
	int 0x10;
	mov al , '.';
	mov ah , 0x0e;
	int 0x10;
	mov al , '.';
	mov ah , 0x0e;
	int 0x10;
	
	ret;
}

float money;

disk
{

}

main
{
	call greethings;
}

loader
{

}
	
	
	
