
legal:
	.string	"aaa"
	.zero	1
.LC0:
	.string	"%s"
	.globl	main
	.type	main, @function
main:


	pushq	%rbp
	movq	%rsp, %rbp

	leaq	legal(%rip), %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	
	movl	$0, %eax
	popq	%rbp

	ret


