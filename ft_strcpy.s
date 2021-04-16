global ft_strcpy

ft_strcpy:
	xor		rcx, rcx						;je met rcx a zero (si rcx = rcx = 0)

loop:
	cmp		byte [rsi + rcx], 0				;compare ce byte avec 0 CONDITION DE SORTIE
	jz		return 							;si c'est la fin de la string(si le byte est = a 0) CONDITION DE SORTIE
	mov		al, [rsi + rcx]					;stock dans al mon char src a copy
	mov		[rdi + rcx], al					;stock dans ma dest le char stocker dans al
	inc		rcx								;incremente ma loop
	jmp		loop							;boucle

return:
	mov		byte [rdi + rcx], 0				;ajout du /0
	mov		rax, rdi						;moove le repertoire dest rdi dans le repertoire de retour rax
	ret										;return l'operation en haut de la pile (rax)