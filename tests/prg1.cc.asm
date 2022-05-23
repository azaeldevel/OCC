start:
	mov     $1, %rax
	mov     $1, %rdi
	mov     $message, %rsi
	mov     $13, %rdx
	syscall  