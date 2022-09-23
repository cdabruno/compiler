## FIXED INIT
.section	.rodata
.printstring:
 .string "%s"
.printintstring:
 .string "%d"
.printfloatstring:
 .string "%f"
.printcharstring:
 .string "%c"
.text


 ##TAC_UNKNOWN

 ##TAC_UNKNOWN

## TAC_FUNC_BEGIN
.globl _funz
_funz:
pushq  %rbp
movq   %rsp, %rbp

## TAC_FUNC_END
popq   %rbp
ret

 ##TAC_UNKNOWN

## TAC_FUNC_BEGIN
.globl _fun
_fun:
pushq  %rbp
movq   %rsp, %rbp

## TAC_COPY
movl   _5(%rip), %eax
movl	%eax, _a(%rip)
## TAC_COPY
movl   _777(%rip), %eax
movl	%eax, _b(%rip)
## TAC_PRINT_LIST
movl	_x(%rip), %eax
movl	%eax, %esi
leaq	.printintstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_callparams
movl   _2(%rip), %eax
movl	%eax, _z(%rip)
## TAC_callparams
movl   _3(%rip), %eax
movl	%eax, _n(%rip)
## TAC_FUNC_CALL
movl   $0, %eax
call   _funz

## TAC_PRINT_LIST
movl	_tempVar_0(%rip), %eax
movl	%eax, %esi
leaq	.printintstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_FUNC_END
popq   %rbp
ret

## TAC_FUNC_BEGIN
.globl main
main:
pushq  %rbp
movq   %rsp, %rbp

## TAC_PRINT_LIST
movl	_b(%rip), %eax
movl	%eax, %esi
leaq	.printintstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_PRINT_LIST
leaq	_str15(%rip), %rsi
leaq	.printstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_PRINT_LIST
leaq	_str10(%rip), %rsi
leaq	.printstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_AND
movl   _1(%rip), %eax
testl  %eax, %eax
je     _and0
movl   _3(%rip), %eax
testl  %eax, %eax
je     _and0
movl   $1, %eax
jmp    _and1
_and0:
movl   $0, %eax
_and1:
movl   %eax, _tempVar_1(%rip)

## TAC_PRINT_LIST
movl	_tempVar_1(%rip), %eax
movl	%eax, %esi
leaq	.printintstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_PRINT_LIST
movl	_a(%rip), %eax
movl	%eax, %esi
leaq	.printcharstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_FUNC_END
popq   %rbp
ret


##DATA SECTION
.data

_1:	.long	1
_2:	.long	2
_3:	.long	3
_5:	.long	5
_tempVar_0:	.long	0
_a:	.long	0
_b:	.long	0
_j:	.long	0
_n:	.long	0
_tempVar_1:	.long	0
_x:	.long	0
_z:	.long	0
_str15:	.string	"LLEGAL DEMAIS"
	.zero
_str10:	.string	"testando"
	.zero
_777:	.long	777
