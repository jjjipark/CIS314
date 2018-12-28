#include <stdio.h>

int f(int x) {
    return 3*x;
}
int g(int a, int b) {

    return f(a) + f(b);
}

int main(void){
	g(1,2);
	printf("done");
}



//_f:                                     ## @f
//## BB#0:
		// x at 8(%ebp)
//	pushl	%ebp				// Save the old base pointer value.
//	movl	%esp, %ebp			// Set the new base pointer value.
//	imull	$3, 8(%ebp), %eax	// eax = x*3
//	popl	%ebp				// finish
//	retl						// return
//
//	.globl	_g
//	.align	4, 0x90
//_g:                                     ## @g
//## BB#0:
//		// b at 12(%ebp), a at 8(%ebp)
//	pushl	%ebp				// Save the old base pointer value.	
//	movl	%esp, %ebp			// Set the new base pointer value.
//	pushl	%edi				// Save the values of registers that the function
//	pushl	%esi				// 
//	subl	$16, %esp			// Make room for one 16-byte local variable(why 16bits?)
//	movl	12(%ebp), %edi		// edi <-b  //edi used, restore at end
//	movl	8(%ebp), %eax		// eax <-a  // eax used without first saving
//	movl	%eax, (%esp)		// a
//	calll	_f					// f(a)
//	movl	%eax, %esi			// %esi<- f(a)
//	movl	%edi, (%esp)		// b
//	calll	_f					// f(b)
//	addl	%esi, %eax			// f(a)+ f(b)
//	addl	$16, %esp
//	popl	%esi				// 
//	popl	%edi				//  Recover register values
//	popl	%ebp
//	retl


