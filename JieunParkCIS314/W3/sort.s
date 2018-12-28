.pos 0 
init:   
    irmovl Stack, %esp      # Set up stack pointer  
    irmovl Stack, %ebp      # Set up base pointer   
    call Main               # Execute main program
    halt
    
# Array of 10 elements
    .pos 0x104
    .align 4    
array:  
    .long 0x0002
    .long 0x0001
    .long 0x0004
    .long 0x0005
    .long 0x0003
    .long 0x0002
    .long 0x0001
    .long 0x0004
    .long 0x0005
    .long 0x0003

Main:   
    pushl %ebp 
    rrmovl %esp, %ebp
    irmovl $5, %eax 
    pushl %eax          # push array length
    irmovl array, %edx
    pushl %edx          # push &array
    call sort           
    rrmovl %ebp, %esp
    popl %ebp
    ret 

_sortArray:                             ## @sortArray
	pushl	%ebp
	rrmovl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	mrmovl	12(%ebp), %esi     #length
	#cmpl	$2, %esi
	irmovl	$2, %ebx
	subl	%ebx, %esi
	jl	LBB1_8
## BB#1:
	mrmovl	8(%ebp), %edi	 	# array
	#leal	-1(%esi), %eax
	irmovl	$-1, %ecx
	addl	%ecx, %esi	# lenth -1
	rrmovl	%esi, %eax 	# eax = length-1
	rmmovl	%eax, -20(%ebp)      
	xorl	%ebx, %ebx		#i = 0
	.align	4, 0x90
LBB1_2:                                 
	rrmovl	%ebx, %edx	#edx(min) = i
	rmmovl	%edx, -16(%ebp)  #       
	#leal	1(%edx), %ebx
	irmovl	$1, %ecx
	addl	%ecx, %edx	#edx(j) = edx+1
	rrmovl	%edx, %ebx	#ebx<= edx(j)
	subl	%esi, %ebx  # j-length
	#cmpl	%esi, %ebx
	rrmovl	%ebx, %ecx	# ecx(min) = j
	jge	LBB1_7
	.align	4, 0x90
LBB1_3:                               
	#movl	(%edi,%edx,4), %eax #arr[j]
	addl	%edx, %edx
	addl	%edx, %edx
	addl	%edi, %edx
	mrmovl	%edx, %eax	#array[j]
	addl	%ecx, %ecx
	addl	%ecx, %ecx
	addl	%edi, %ecx	#array[min]
	#rrmovl	%ecx, %
	#cmpl	(%edi,%ecx,4), %eax
	subl	%ecx, %eax
	rrmovl	%ecx, %eax     
	jg	LBB1_5
## BB#4:                                
	rrmovl	%edx, %eax	
LBB1_5:                                 
	#incl	%ecx		#j++
	irmovl	$1, %edx
	addl	%edx, %ecx	#j++
	#cmpl	%ecx, %esi
	subl	%ecx, %esi	#length - j
	rrmovl	%eax, %edx
	jne	LBB1_3
## BB#6:                                
	#cmpl	-16(%ebp), %eax	#min:i
	mrmovl	-16(%ebp), %edx    
	subl	%edx, %eax             
	je	LBB1_7
## BB#9:                               
	mrmovl	-16(%ebp), %ecx   #ecx= min     
	#leal	(%edi,%ecx,4), %ecx	#arrary[min]
	addl	%ecx, %ecx
	addl	%ecx, %ecx
	addl	%edi, %ecx	#arrary[min]
	#leal	(%edi,%eax,4), %eax #arrary[i]
	addl	%eax, %eax
	addl	%eax, %eax
	addl	%edi, %eax	#arrary[i]
	rmmovl	%eax, 4(%esp)
	rmmovl	%ecx, (%esp)
	call	_swap		#swap(array[i],array[min])
LBB1_7:                                 
	#cmpl	-20(%ebp), %ebx
	mrmovl	-20(%ebp), %eax
	subl	%eax, %ebx         
	jl	LBB1_2
LBB1_8:                                
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	ret


_swap:                                  ## @swap
## BB#0:
	pushl	%ebp
	rrmovl	%esp, %ebp
	pushl	%esi
	mrmovl	12(%ebp), %eax
	mrmovl	8(%ebp), %ecx
	mrmovl	(%ecx), %edx
	mrmovl	(%eax), %esi
	rmmovl	%esi, (%ecx)
	rmmovl	%edx, (%eax)
	popl	%esi
	popl	%ebp
	ret


end:
    popl %esi  # restores esi
    popl %edi  # restores edi
    popl %ebx  # restores ebx    
    rrmovl %ebp, %esp
    popl %ebp
    ret


.pos 0x100
Stack:

