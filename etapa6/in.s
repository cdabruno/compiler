	.file	"in.c"
	.text
	.globl	int_um
	.data
	.align 4
	.type	int_um, @object
	.size	int_um, 4
int_um:
	.long	1
	.globl	int_dois
	.align 4
	.type	int_dois, @object
	.size	int_dois, 4
int_dois:
	.long	2
	.globl	int_res
	.align 4
	.type	int_res, @object
	.size	int_res, 4
int_res:
	.long	50
	.text
	.globl	sum
	.type	sum, @function
sum:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	int_um(%rip), %edx
	movl	int_dois(%rip), %eax
	addl	%edx, %eax
	movl	%eax, int_res(%rip)
	nop
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
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
