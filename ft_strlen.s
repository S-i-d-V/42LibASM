global ft_strlen

ft_strlen:
	xor		rcx, rcx						;je met rcx a zero (si rcx = rcx = 0)

count:
	cmp		byte [rdi + rcx], 0				;compare ce byte avec 0 CONDITION DE SORTIE
	jz		return 							;si c'est la fin de la string(ZF = 1 si le byte est = a 0) CONDITION DE SORTIE
	inc		rcx 							;incremente mon compteur
	jmp		count							;boucle

return:
	mov		rax, rcx						;moove la valeur de rcx dans le repertoire de retour rax
	ret										;return rax
