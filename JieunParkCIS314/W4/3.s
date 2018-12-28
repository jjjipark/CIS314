	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_f
	.align	4, 0x90
_f:                                     ## @f
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	imull	$3, 8(%ebp), %eax
	popl	%ebp
	retl

	.globl	_g
	.align	4, 0x90
_g:                                     ## @g
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	subl	$16, %esp
	movl	12(%ebp), %edi
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	calll	_f
	movl	%eax, %esi
	movl	%edi, (%esp)
	calll	_f
	addl	%esi, %eax
	addl	$16, %esp
	popl	%esi
	popl	%edi
	popl	%ebp
	retl

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$8, %esp
	calll	L2$pb
L2$pb:
	popl	%eax
	leal	L_.str-L2$pb(%eax), %eax
	movl	%eax, (%esp)
	calll	_printf
	xorl	%eax, %eax
	addl	$8, %esp
	popl	%ebp
	retl

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"done"


.subsections_via_symbols
