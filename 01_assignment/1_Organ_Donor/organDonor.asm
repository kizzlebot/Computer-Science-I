	.text
.globl _main
_main:
LFB6:
	pushq	%rbp
LCFI0:
	movq	%rsp, %rbp
LCFI1:
	subq	$16, %rsp
LCFI2:
	movl	$0, %eax
	call	_readPatients
	movq	%rax, -8(%rbp)
	movl	$0, %eax
	call	_readDonorList
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rdi
	call	_orgPatientByOrgan
	movq	-8(%rbp), %rdi
	call	_printPatient
	movq	-8(%rbp), %rsi
	movq	-16(%rbp), %rdi
	call	_findPair
	movq	-16(%rbp), %rdi
	call	_free
	movq	-8(%rbp), %rdi
	call	_free
	leave
	ret
LFE6:
.globl _orgPatientByOrgan
_orgPatientByOrgan:
LFB7:
	pushq	%rbp
LCFI3:
	movq	%rsp, %rbp
LCFI4:
	subq	$80, %rsp
LCFI5:
	movq	%rdi, -72(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$100, -12(%rbp)
	movl	$0, -16(%rbp)
	movl	$0, -20(%rbp)
	jmp	L4
L5:
	incl	-16(%rbp)
	incl	-4(%rbp)
L4:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	L5
	movl	$0, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	L7
L8:
	movl	-4(%rbp), %eax
	movl	%eax, -24(%rbp)
	jmp	L9
L10:
	movl	-12(%rbp), %eax
	movslq	%eax,%rdx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rsi
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdi
	call	_strncmp
	testl	%eax, %eax
	jne	L11
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	28(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	28(%rax), %eax
	cmpl	%eax, %edx
	jle	L13
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -32(%rbp)
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movq	-32(%rbp), %rax
	movq	%rax, (%rdx)
	jmp	L11
L13:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	20(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	20(%rax), %eax
	cmpl	%eax, %edx
	jle	L15
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	28(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	28(%rax), %eax
	cmpl	%eax, %edx
	jne	L15
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -40(%rbp)
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movq	-40(%rbp), %rax
	movq	%rax, (%rdx)
	jmp	L11
L15:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	24(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	24(%rax), %eax
	cmpl	%eax, %edx
	jle	L18
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	20(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	20(%rax), %eax
	cmpl	%eax, %edx
	jne	L18
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	28(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	28(%rax), %eax
	cmpl	%eax, %edx
	jne	L18
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -48(%rbp)
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movq	-48(%rbp), %rax
	movq	%rax, (%rdx)
	jmp	L11
L18:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	24(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	24(%rax), %eax
	cmpl	%eax, %edx
	jne	L11
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	20(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	20(%rax), %eax
	cmpl	%eax, %edx
	jne	L11
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	28(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	28(%rax), %eax
	cmpl	%eax, %edx
	jne	L11
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	32(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	32(%rax), %eax
	cmpl	%eax, %edx
	jle	L25
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -56(%rbp)
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movq	-56(%rbp), %rax
	movq	%rax, (%rdx)
	jmp	L11
L25:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	32(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	32(%rax), %eax
	cmpl	%eax, %edx
	jne	L11
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	36(%rax), %edx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movl	36(%rax), %eax
	cmpl	%eax, %edx
	jle	L11
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, -64(%rbp)
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-72(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, (%rdx)
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rdx
	addq	-72(%rbp), %rdx
	movq	-64(%rbp), %rax
	movq	%rax, (%rdx)
L11:
	incl	-24(%rbp)
L9:
	movl	-24(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	L10
	incl	-4(%rbp)
L7:
	movl	-4(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	L8
	leave
	ret
LFE7:
	.cstring
LC0:
	.ascii "%s %s\12\0"
LC1:
	.ascii "No Match Found\0"
	.text
.globl _findPair
_findPair:
LFB8:
	pushq	%rbp
LCFI6:
	movq	%rsp, %rbp
LCFI7:
	subq	$32, %rsp
LCFI8:
	movq	%rdi, -24(%rbp)
	movq	%rsi, -32(%rbp)
	movl	$0, -4(%rbp)
	movl	$0, -8(%rbp)
	movl	$100, -12(%rbp)
	movl	$0, -16(%rbp)
	jmp	L33
L36:
	movl	-12(%rbp), %eax
	movslq	%eax,%rdx
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rsi
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdi
	call	_strncmp
	testl	%eax, %eax
	jne	L37
	movl	-12(%rbp), %eax
	movslq	%eax,%rdx
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	leaq	16(%rax), %rsi
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdi
	call	_strncmp
	testl	%eax, %eax
	jne	L37
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	40(%rax), %eax
	cmpl	$1, %eax
	je	L37
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$1, 40(%rax)
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rdx
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rsi
	leaq	LC0(%rip), %rdi
	movl	$0, %eax
	call	_printf
	movl	$0, -8(%rbp)
	jmp	L41
L37:
	incl	-8(%rbp)
L35:
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	L36
L41:
	movl	-8(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	L42
	leaq	LC1(%rip), %rdi
	call	_puts
	movl	$0, -8(%rbp)
L42:
	incl	-4(%rbp)
L33:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	L35
	leave
	ret
LFE8:
.globl _allocate
_allocate:
LFB9:
	pushq	%rbp
LCFI9:
	movq	%rsp, %rbp
LCFI10:
	pushq	%rbx
LCFI11:
	subq	$40, %rsp
LCFI12:
	movl	%edi, -36(%rbp)
	movl	-36(%rbp), %eax
	incl	%eax
	cltq
	leaq	0(,%rax,8), %rdi
	call	_malloc
	movq	%rax, -32(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -20(%rbp)
	jmp	L47
L48:
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rbx
	addq	-32(%rbp), %rbx
	movl	$48, %edi
	call	_malloc
	movq	%rax, (%rbx)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rbx
	movl	$20, %edi
	call	_malloc
	movq	%rax, (%rbx)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rbx
	movl	$20, %edi
	call	_malloc
	movq	%rax, 8(%rbx)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$0, 20(%rax)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$0, 24(%rax)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$0, 28(%rax)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$0, 32(%rax)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$0, 36(%rax)
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movl	$0, 40(%rax)
	incl	-20(%rbp)
L47:
	movl	-20(%rbp), %eax
	cmpl	-36(%rbp), %eax
	jl	L48
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	$0, (%rax)
	movq	-32(%rbp), %rax
	addq	$40, %rsp
	popq	%rbx
	leave
	ret
LFE9:
.globl _printPatient
_printPatient:
LFB10:
	pushq	%rbp
LCFI13:
	movq	%rsp, %rbp
LCFI14:
	movq	%rdi, -24(%rbp)
	movl	$0, -4(%rbp)
	jmp	L52
L53:
	incl	-4(%rbp)
L52:
	movl	-4(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	jne	L53
	leave
	ret
LFE10:
	.cstring
LC2:
	.ascii "%d\0"
LC3:
	.ascii "%s %s %s %d%c%d%c%d %d%c%d\0"
	.text
.globl _readPatients
_readPatients:
LFB11:
	pushq	%rbp
LCFI15:
	movq	%rsp, %rbp
LCFI16:
	subq	$96, %rsp
LCFI17:
	leaq	-8(%rbp), %rsi
	leaq	LC2(%rip), %rdi
	movl	$0, %eax
	call	_scanf
	movl	-8(%rbp), %edi
	call	_allocate
	movq	%rax, -24(%rbp)
	movl	$0, -12(%rbp)
	jmp	L57
L58:
	movl	-12(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rax
	leaq	16(%rax), %rcx
	movl	-12(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdx
	movl	-12(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rsi
	leaq	-1(%rbp), %rdi
	leaq	-48(%rbp), %r8
	leaq	-32(%rbp), %rax
	addq	$4, %rax
	movq	%rax, 40(%rsp)
	leaq	-1(%rbp), %rax
	movq	%rax, 32(%rsp)
	leaq	-32(%rbp), %rax
	movq	%rax, 24(%rsp)
	leaq	-48(%rbp), %rax
	addq	$8, %rax
	movq	%rax, 16(%rsp)
	leaq	-1(%rbp), %rax
	movq	%rax, 8(%rsp)
	leaq	-48(%rbp), %rax
	addq	$4, %rax
	movq	%rax, (%rsp)
	movq	%rdi, %r9
	leaq	LC3(%rip), %rdi
	movl	$0, %eax
	call	_scanf
	movl	-12(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-48(%rbp), %rax
	movq	%rax, 20(%rdx)
	movl	-40(%rbp), %eax
	movl	%eax, 28(%rdx)
	movl	-12(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-24(%rbp), %rax
	movq	(%rax), %rdx
	movq	-32(%rbp), %rax
	movq	%rax, 32(%rdx)
	incl	-12(%rbp)
L57:
	movl	-8(%rbp), %eax
	cmpl	%eax, -12(%rbp)
	jl	L58
	movq	-24(%rbp), %rax
	leave
	ret
LFE11:
	.cstring
LC4:
	.ascii "%s %s\0"
	.text
.globl _readDonorList
_readDonorList:
LFB12:
	pushq	%rbp
LCFI18:
	movq	%rsp, %rbp
LCFI19:
	pushq	%rbx
LCFI20:
	subq	$24, %rsp
LCFI21:
	movl	$0, -20(%rbp)
	movl	$0, -24(%rbp)
	leaq	-20(%rbp), %rsi
	leaq	LC2(%rip), %rdi
	movl	$0, %eax
	call	_scanf
	movl	-20(%rbp), %eax
	incl	%eax
	cltq
	leaq	0(,%rax,8), %rdi
	call	_malloc
	movq	%rax, -32(%rbp)
	jmp	L62
L63:
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	movq	%rax, %rbx
	addq	-32(%rbp), %rbx
	movl	$16, %edi
	call	_malloc
	movq	%rax, (%rbx)
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rbx
	movl	$21, %edi
	call	_malloc
	movq	%rax, (%rbx)
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rbx
	movl	$21, %edi
	call	_malloc
	movq	%rax, 8(%rbx)
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	8(%rax), %rdx
	movl	-24(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	(%rax), %rax
	movq	(%rax), %rsi
	leaq	LC4(%rip), %rdi
	movl	$0, %eax
	call	_scanf
	incl	-24(%rbp)
L62:
	movl	-20(%rbp), %eax
	cmpl	%eax, -24(%rbp)
	jl	L63
	movl	-20(%rbp), %eax
	cltq
	salq	$3, %rax
	addq	-32(%rbp), %rax
	movq	$0, (%rax)
	movq	-32(%rbp), %rax
	addq	$24, %rsp
	popq	%rbx
	leave
	ret
LFE12:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0x0
	.byte	0x1
	.ascii "zR\0"
	.byte	0x1
	.byte	0x78
	.byte	0x10
	.byte	0x1
	.byte	0x10
	.byte	0xc
	.byte	0x7
	.byte	0x8
	.byte	0x90
	.byte	0x1
	.align 3
LECIE1:
.globl _main.eh
_main.eh:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB6-.
	.set L$set$2,LFE6-LFB6
	.quad L$set$2
	.byte	0x0
	.byte	0x4
	.set L$set$3,LCFI0-LFB6
	.long L$set$3
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE1:
.globl _orgPatientByOrgan.eh
_orgPatientByOrgan.eh:
LSFDE3:
	.set L$set$5,LEFDE3-LASFDE3
	.long L$set$5
LASFDE3:
	.long	LASFDE3-EH_frame1
	.quad	LFB7-.
	.set L$set$6,LFE7-LFB7
	.quad L$set$6
	.byte	0x0
	.byte	0x4
	.set L$set$7,LCFI3-LFB7
	.long L$set$7
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$8,LCFI4-LCFI3
	.long L$set$8
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE3:
.globl _findPair.eh
_findPair.eh:
LSFDE5:
	.set L$set$9,LEFDE5-LASFDE5
	.long L$set$9
LASFDE5:
	.long	LASFDE5-EH_frame1
	.quad	LFB8-.
	.set L$set$10,LFE8-LFB8
	.quad L$set$10
	.byte	0x0
	.byte	0x4
	.set L$set$11,LCFI6-LFB8
	.long L$set$11
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$12,LCFI7-LCFI6
	.long L$set$12
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE5:
.globl _allocate.eh
_allocate.eh:
LSFDE7:
	.set L$set$13,LEFDE7-LASFDE7
	.long L$set$13
LASFDE7:
	.long	LASFDE7-EH_frame1
	.quad	LFB9-.
	.set L$set$14,LFE9-LFB9
	.quad L$set$14
	.byte	0x0
	.byte	0x4
	.set L$set$15,LCFI9-LFB9
	.long L$set$15
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$16,LCFI10-LCFI9
	.long L$set$16
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$17,LCFI12-LCFI10
	.long L$set$17
	.byte	0x83
	.byte	0x3
	.align 3
LEFDE7:
.globl _printPatient.eh
_printPatient.eh:
LSFDE9:
	.set L$set$18,LEFDE9-LASFDE9
	.long L$set$18
LASFDE9:
	.long	LASFDE9-EH_frame1
	.quad	LFB10-.
	.set L$set$19,LFE10-LFB10
	.quad L$set$19
	.byte	0x0
	.byte	0x4
	.set L$set$20,LCFI13-LFB10
	.long L$set$20
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$21,LCFI14-LCFI13
	.long L$set$21
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE9:
.globl _readPatients.eh
_readPatients.eh:
LSFDE11:
	.set L$set$22,LEFDE11-LASFDE11
	.long L$set$22
LASFDE11:
	.long	LASFDE11-EH_frame1
	.quad	LFB11-.
	.set L$set$23,LFE11-LFB11
	.quad L$set$23
	.byte	0x0
	.byte	0x4
	.set L$set$24,LCFI15-LFB11
	.long L$set$24
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$25,LCFI16-LCFI15
	.long L$set$25
	.byte	0xd
	.byte	0x6
	.align 3
LEFDE11:
.globl _readDonorList.eh
_readDonorList.eh:
LSFDE13:
	.set L$set$26,LEFDE13-LASFDE13
	.long L$set$26
LASFDE13:
	.long	LASFDE13-EH_frame1
	.quad	LFB12-.
	.set L$set$27,LFE12-LFB12
	.quad L$set$27
	.byte	0x0
	.byte	0x4
	.set L$set$28,LCFI18-LFB12
	.long L$set$28
	.byte	0xe
	.byte	0x10
	.byte	0x86
	.byte	0x2
	.byte	0x4
	.set L$set$29,LCFI19-LCFI18
	.long L$set$29
	.byte	0xd
	.byte	0x6
	.byte	0x4
	.set L$set$30,LCFI21-LCFI19
	.long L$set$30
	.byte	0x83
	.byte	0x3
	.align 3
LEFDE13:
	.subsections_via_symbols
