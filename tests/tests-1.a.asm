	
print
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
	mov al , ' ';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'b';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'y';
	mov ah , 0x0e;
	int 0x10;
	mov al , ' ';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'A';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'z';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'a';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'e';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'l';
	mov ah , 0x0e;
	int 0x10;
	mov al , ' ';
	mov ah , 0x0e;
	int 0x10;
	mov al , 'R';
	mov ah , 0x0e;
	int 0x10;
	mov al , '.';
	mov ah , 0x0e;
	int 0x10;
	ret;
}

main
{
	//https://github.com/FRosner/FrOS/blob/minimal-c-kernel/disk.asm
	ret;
}

	
	
	
