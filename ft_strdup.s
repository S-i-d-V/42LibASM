global ft_strdup
extern __errno_location
extern ft_strlen
extern malloc
extern ft_strcpy

ft_strdup:
		call		ft_strlen	;ft_strlen stock la taille de rdi dans rax
		inc			rax			;incremente rax pour arriver sur la position du \0 dans la string
		push		rdi
		mov			rdi,rax		;on met rdi a la meme valeur que rax(taille de la string + \0)
		call		malloc		;appelle de malloc pour malloc le nb( contenu rax) de caracteres
		cmp			rax, 0		;on compare le retour de malloc avec zero
		jz			error		;si rax est inferieur a 0, on va dans la fonction error;
		mov			rdi, rax	;
		pop			rsi
		call		ft_strcpy
		ret

	error:
		neg			rax					;la valeur de retour est en negatif donc on la repasse en positif
		mov			rdi, rax			;stock la valeur de retour dans rdi
		call		__errno_location	;appelle errno qui stock son adresse dans rax
		mov			[rax], rdi			;stock rdi (le retour du syscall) dans errno via rax
		mov			rax, -1				;passes rax a -1
		ret								;return rax
