	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_swap
	.align	4, 0x90
_swap:                                  ## @swap
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	movl	12(%ebp), %eax
	movl	8(%ebp), %ecx
	movl	(%ecx), %edx
	movl	(%eax), %esi
	movl	%esi, (%ecx)
	movl	%edx, (%eax)
	popl	%esi
	popl	%ebp
	retl

	.globl	_transpose
	.align	4, 0x90
_transpose:                             ## @transpose
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$28, %esp
	movl	$0, -16(%ebp)           ## 4-byte Folded Spill
	movl	8(%ebp), %edi
	movl	%edi, %ebx
	.align	4, 0x90
LBB1_1:                                 ## %.preheader
                                        ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB1_2 Depth 2
	movl	%ebx, -24(%ebp)         ## 4-byte Spill
	movl	%edi, -20(%ebp)         ## 4-byte Spill
	cmpl	$0, -16(%ebp)           ## 4-byte Folded Reload
	movl	$0, %esi
	jle	LBB1_3
	.align	4, 0x90
LBB1_2:                                 ##   Parent Loop BB1_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	calll	_swap
	incl	%esi
	addl	$16, %ebx
	addl	$4, %edi
	cmpl	%esi, -16(%ebp)         ## 4-byte Folded Reload
	jne	LBB1_2
LBB1_3:                                 ## %._crit_edge
                                        ##   in Loop: Header=BB1_1 Depth=1
	movl	-16(%ebp), %eax         ## 4-byte Reload
	incl	%eax
	movl	%eax, -16(%ebp)         ## 4-byte Spill
	movl	-24(%ebp), %ebx         ## 4-byte Reload
	addl	$4, %ebx
	movl	-20(%ebp), %edi         ## 4-byte Reload
	addl	$16, %edi
	cmpl	$4, %eax
	jne	LBB1_1
## BB#4:
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl

	.globl	_arrayPrinter
	.align	4, 0x90
_arrayPrinter:                          ## @arrayPrinter
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$28, %esp
	calll	L2$pb
L2$pb:
	popl	%eax
	xorl	%ecx, %ecx
	movl	8(%ebp), %edi
	leal	L_.str-L2$pb(%eax), %edx
	movl	%edx, -24(%ebp)         ## 4-byte Spill
	leal	L_.str1-L2$pb(%eax), %ebx
	leal	L_str-L2$pb(%eax), %eax
	movl	%eax, -28(%ebp)         ## 4-byte Spill
	.align	4, 0x90
LBB2_1:                                 ## =>This Loop Header: Depth=1
                                        ##     Child Loop BB2_2 Depth 2
	movl	%edi, -20(%ebp)         ## 4-byte Spill
	movl	%ecx, -16(%ebp)         ## 4-byte Spill
	movl	-24(%ebp), %eax         ## 4-byte Reload
	movl	%eax, (%esp)
	calll	_printf
	movl	$4, %esi
	.align	4, 0x90
LBB2_2:                                 ##   Parent Loop BB2_1 Depth=1
                                        ## =>  This Inner Loop Header: Depth=2
	movl	(%edi), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	calll	_printf
	addl	$4, %edi
	decl	%esi
	jne	LBB2_2
## BB#3:                                ##   in Loop: Header=BB2_1 Depth=1
	movl	-28(%ebp), %eax         ## 4-byte Reload
	movl	%eax, (%esp)
	calll	_puts
	movl	-16(%ebp), %ecx         ## 4-byte Reload
	incl	%ecx
	movl	-20(%ebp), %edi         ## 4-byte Reload
	addl	$16, %edi
	cmpl	$4, %ecx
	jne	LBB2_1
## BB#4:
	movl	$10, (%esp)
	calll	_putchar
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl

	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	subl	$80, %esp
	calll	L3$pb
L3$pb:
	popl	%eax
	movl	L___stack_chk_guard$non_lazy_ptr-L3$pb(%eax), %esi
	movl	(%esi), %ecx
	movl	%ecx, -12(%ebp)
	movsd	(l_main.A-L3$pb)+56(%eax), %xmm0 ## xmm0 = mem[0],zero
	movsd	%xmm0, -20(%ebp)
	movsd	(l_main.A-L3$pb)+48(%eax), %xmm0 ## xmm0 = mem[0],zero
	movsd	%xmm0, -28(%ebp)
	movsd	(l_main.A-L3$pb)+40(%eax), %xmm0 ## xmm0 = mem[0],zero
	movsd	%xmm0, -36(%ebp)
	movsd	(l_main.A-L3$pb)+32(%eax), %xmm0 ## xmm0 = mem[0],zero
	movsd	%xmm0, -44(%ebp)
	movsd	(l_main.A-L3$pb)+24(%eax), %xmm0 ## xmm0 = mem[0],zero
	movsd	%xmm0, -52(%ebp)
	movsd	(l_main.A-L3$pb)+16(%eax), %xmm0 ## xmm0 = mem[0],zero
	movsd	%xmm0, -60(%ebp)
	movsd	(l_main.A-L3$pb)+8(%eax), %xmm0 ## xmm0 = mem[0],zero
	movsd	%xmm0, -68(%ebp)
	movsd	l_main.A-L3$pb(%eax), %xmm0 ## xmm0 = mem[0],zero
	movsd	%xmm0, -76(%ebp)
	leal	-76(%ebp), %edi
	movl	%edi, (%esp)
	calll	_arrayPrinter
	movl	%edi, (%esp)
	calll	_transpose
	movl	%edi, (%esp)
	calll	_arrayPrinter
	movl	(%esi), %eax
	cmpl	-12(%ebp), %eax
	jne	LBB3_2
## BB#1:
	xorl	%eax, %eax
	addl	$80, %esp
	popl	%esi
	popl	%edi
	popl	%ebp
	retl
LBB3_2:
	calll	___stack_chk_fail

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"[ "

L_.str1:                                ## @.str1
	.asciz	"%d "

L_.str2:                                ## @.str2
	.asciz	"]\n"

L_.str3:                                ## @.str3
	.asciz	"\n"

	.section	__TEXT,__const
	.align	2                       ## @main.A
l_main.A:
	.long	1                       ## 0x1
	.long	1                       ## 0x1
	.long	1                       ## 0x1
	.long	1                       ## 0x1
	.long	2                       ## 0x2
	.long	2                       ## 0x2
	.long	2                       ## 0x2
	.long	2                       ## 0x2
	.long	3                       ## 0x3
	.long	3                       ## 0x3
	.long	3                       ## 0x3
	.long	3                       ## 0x3
	.long	4                       ## 0x4
	.long	4                       ## 0x4
	.long	4                       ## 0x4
	.long	4                       ## 0x4

	.section	__TEXT,__cstring,cstring_literals
L_str:                                  ## @str
	.asciz	"]"


	.section	__IMPORT,__pointers,non_lazy_symbol_pointers
L___stack_chk_guard$non_lazy_ptr:
	.indirect_symbol	___stack_chk_guard
	.long	0

.subsections_via_symbols
