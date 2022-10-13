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


## TAC_FUNC_BEGIN
.globl main
main:
pushq  %rbp
movq   %rsp, %rbp

## TAC_COPY
movl   _'x'(%rip), %eax
movl	%eax, _c(%rip)
## TAC_COPY
movl   _2(%rip), %eax
movl	%eax, _a(%rip)
## TAC_SUB
movl   _a(%rip), %edx
movl	_i(%rip), %eax
subl	%eax, %edx
movl	%edx, %eax
movl	%edx, _tempVar_0(%rip)

## TAC_COPY
movl   _tempVar_0(%rip), %eax
movl	%eax, _a(%rip)
## TAC_COPY
movl   _5(%rip), %eax
movl	%eax, _a(%rip)
## TAC_READ_ARR
movzbl	_55(%rip), %eax
movb	%al, 0+_v(%rip)

## TAC_EXPR_ARR
movzbl	8+_v(%rip), %eax
movb	%al, _tempVar_1(%rip)

## TAC_PRINT_LIST
movl	_tempVar_1(%rip), %eax
movl	%eax, %esi
leaq	.printintstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_PRINT_LIST
movl	_a(%rip), %eax
movl	%eax, %esi
leaq	.printintstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_PRINT_LIST
movl	_a(%rip), %eax
movl	%eax, %esi
leaq	.printintstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_COPY
movl   _2(%rip), %eax
movl	%eax, _i(%rip)
## TAC_PRINT_LIST
leaq	_str22(%rip), %rsi
leaq	.printstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_READ
leaq	_a(%rip), %rsi
leaq	.printintstring(%rip), %rdi
movl	$0, %eax
call	__isoc99_scanf@PLT

## TAC_PRINT_LIST
leaq	_str27(%rip), %rsi
leaq	.printstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_READ_ARR
leaq	4+_v(%rip), %rsi
leaq	.printintstring(%rip), %rdi
movl	$0, %eax
call	__isoc99_scanf@PLT

## TAC_LABEL
_label_0:
## TAC_GT
movl   _i(%rip), %edx
movl   _0(%rip), %eax
cmp    %eax, %edx
setg  %al
movzbl	%al, %eax
movl	%eax, _tempVar_2(%rip)
## TAC_JUMP_FALSE
movl   _tempVar_2(%rip), %eax
cmpl   $1, %eax
jne    _label_1
## TAC_callparams
movl   _i(%rip), %eax
movl	%eax, _x(%rip)
## TAC_FUNC_CALL
movl   $0, %eax
call   _incn
movl   %eax, _tempVar_3(%rip)

## TAC_COPY
movl   _tempVar_3(%rip), %eax
movl	%eax, _i(%rip)
## TAC_PRINT_LIST
leaq	_str5(%rip), %rsi
leaq	.printstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_JUMP
jmp    _label_0
## TAC_LABEL
_label_1:
## TAC_EQ
movl   _a(%rip), %edx
movl   _15(%rip), %eax
cmp    %eax, %edx
sete  %al
movzbl	%al, %eax
movl	%eax, _tempVar_4(%rip)
## TAC_JUMP_FALSE
movl   _tempVar_4(%rip), %eax
cmpl   $1, %eax
jne    _label_2
## TAC_SUM
movl   _a(%rip), %edx
movl	_1(%rip), %eax
addl	%edx, %eax
movl	%eax, _tempVar_5(%rip)

## TAC_COPY
movl   _tempVar_5(%rip), %eax
movl	%eax, _a(%rip)
## TAC_PRINT_LIST
leaq	_str12(%rip), %rsi
leaq	.printstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_LABEL
_label_2:
## TAC_EQ
movl   _i(%rip), %edx
movl   _100(%rip), %eax
cmp    %eax, %edx
sete  %al
movzbl	%al, %eax
movl	%eax, _tempVar_6(%rip)
## TAC_JUMP_FALSE
movl   _tempVar_6(%rip), %eax
cmpl   $1, %eax
jne    _label_3
## TAC_PRINT_LIST
leaq	_str24(%rip), %rsi
leaq	.printstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_JUMP
jmp    _label_4
## TAC_LABEL
_label_3:
## TAC_PRINT_LIST
leaq	_str7(%rip), %rsi
leaq	.printstring(%rip), %rdi
movl	$0, %eax
call	printf@PLT

## TAC_LABEL
_label_4:
## TAC_FUNC_END
popq   %rbp
ret

 ##TAC_UNKNOWN

## TAC_FUNC_BEGIN
.globl _incn
_incn:
pushq  %rbp
movq   %rsp, %rbp

## TAC_SUM
movl   _x(%rip), %edx
movl	_1(%rip), %eax
addl	%edx, %eax
movl	%eax, _tempVar_7(%rip)

## TAC_COPY
movl   _tempVar_7(%rip), %eax
movl	%eax, _x(%rip)
## TAC_RETURN
movl   _x(%rip), %eax

## TAC_FUNC_END
popq   %rbp
ret


##DATA SECTION
.data

_0:	.long	0
_1:	.long	1
_2:	.long	2
_5:	.long	5
_tempVar_0:	.long	0
_str12:	.string	"A era=15\n"
	.zero
_tempVar_1:	.long	0
_tempVar_2:	.long	0
_str27:	.string	"Digite mais um numero: \n"
	.zero
_tempVar_3:	.long	0
_tempVar_4:	.long	0
_tempVar_5:	.long	0
_tempVar_6:	.long	0
_tempVar_7:	.long	0
_str7:	.string	"OK!\n"
	.zero
_10:	.long	10
_str5:	.string	"a\n"
	.zero
_100:	.long	100
_15:	.long	15
_str22:	.string	"Digite um numero: \n"
	.zero
_'A':	.long	'A'
_'x':	.long	'x'
_'a':	.long	'a'
_str24:	.string	"Nao tem como isso...\n"
	.zero
_55:	.long	55
_c:	.long	'x'
_d:	.long	100
_a:	.long	'A'
_i:	.long	1
_v:
	.long	'a'
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
	.long	0
_matrix:
_x:	.long	0
