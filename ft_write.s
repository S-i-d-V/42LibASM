global ft_write
extern __errno_location

ft_write:
		mov			rax, 1				;donne a rax la valeur de l'appel systeme write (1)
		syscall							;syscall
		cmp			rax, 0				;compare si rax a 0
		jl			error				;si rax est inferieur a zero on rentre dans error
		ret								;sinon on return rax
error:
		neg			rax					;la valeur de retour est en negatif donc on la repasse en positif
		mov			rdi, rax			;stock la valeur de retour dans rdi
		call		__errno_location	;appelle errno qui stock son adresse dans rax
		mov			[rax], rdi			;stock rdi (le retour du syscall) dans errno via rax
		mov			rax, -1				;passes rax a -1
		ret								;return rax
