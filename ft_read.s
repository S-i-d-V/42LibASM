global ft_read
extern __errno_location

ft_read:
		cmp			rdx, 0							;compare le buffer size a 0
		jl			return							;si inferieur a 0 on return
		mov			rax, 0							;donne a rax la valeur de l'appel systeme read (0)
		syscall										;syscall
		cmp			rax, 0							;compare rax a 0
		jl			error							;si rax est inferieur a zero on rentre dans error
		ret											;sinon on return rax
return:
		mov			rax, -1
		ret
error:
		neg			rax								;la valeur de retour est en negatif donc on la repasse en positif
		mov			r9, rax							;stock la valeur de retour dans r9
		call		__errno_location wrt ..plt		;appelle errno qui stock son adresse dans rax (wrt ..plt car appel externe a la lib)
		mov			[rax], r9						;stock r9 (le retour du syscall) dans errno via rax
		mov			rax, -1							;passes rax a -1
		ret											;return l'operation en haut de la pile (rax)