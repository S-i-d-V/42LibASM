global ft_strcmp

ft_strcmp:
	xor		rcx, rcx						;je met rcx a zero (si rcx = rcx = 0)
	xor		rax, rax						;je met rcx a zero (si rcx = rcx = 0)

loop:
	cmp		byte[rdi + rcx], 0				;compare ce byte avec 0 CONDITION DE SORTIE
	jz		return							;si c'est la fin de la string(if byte = 0 : return) CONDITION DE SORTIE
	cmp		byte[rsi + rcx], 0				;compare ce byte avec 0 CONDITION DE SORTIE
	jz		return							;si c'est la fin de la string(ce byte = 0 : return) CONDITION DE SORTIE
	mov		al, byte[rsi + rcx]				;stock dans al le byte[rsi + rcx] car al fait 8bits(1 byte)
	mov		bl, byte[rdi + rcx]				;stock dans al le byte[rdi + rcx] car al fait 8bits(1 byte)
	cmp		bl, al							;compare ce byte de rdi avec ce byte de rsi CONDITION DE SORTIE
	jnz		return							;si les deux ne sont pas egaux(if byte[rdi + rcx] != al)
	inc		rcx								;incremente ma boucle
	jmp		loop							;boucle

return:
	mov		rax, byte[rdi + rcx]		;moove le char ( 1 byte ) de rdi dans le repertoire de retour rax
	mov		rbx, byte[rsi + rcx]		;moove le char ( 1 byte ) de rsi dans le repertoire rbx (car de la meme taille que rax pour comparer)
	sub		rax, rbx					;fais la comparaison entre les deux bytes et stock dans le repertoire de retour rax
	ret									;return rax