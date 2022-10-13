	.file	"in2.c"
	.text
	.globl	x
	.data
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	1067030938
	.globl	a
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.long	1067869798
	.section	.rodata
.LC0:
	.string	"%f"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:

	pushq	%rbp
	movq	%rsp, %rbp
	movss	a(%rip), %xmm0
	cvtss2sd	%xmm0, %xmm0
	leaq	.LC0(%rip), %rdi
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp

	ret

.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
