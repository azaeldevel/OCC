const char* message;
int counter;
register char type;
//b0 42 b4 0e cd 10 b0 6f
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
	
	ret;
}

float money;

disk
{

}

main
{
}

loader
{

}
	
	
	
