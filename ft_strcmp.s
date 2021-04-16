global ft_strcmp

ft_strcmp:
	xor		ecx, ecx					;initialise ecx a 0
	xor		eax, eax					;initialise eax a 0

loop:
	mov		al, byte[rdi]				;stock dans al(qui sont les 8derniers bits de eax) le char dest a comparer.
	cmp		al, 0						;compare al a 0 pour savoir si on est en fin de string
	je		return						;si egal a 0 rentre dans return
	cmp		al, byte[rsi]				;compare al(byte[rdi]) a byte[rsi]
	jne		return						;si non egal rentre dans return
	inc		rdi							;incremente mes caracteres
	inc		rsi							;incremente mes caracteres
	jmp		loop						;boucle

return:
	mov			cl, byte [rsi]			;stock dans al(qui sont les 8derniers bits de ecx) le char src a comparer.
	sub			eax, ecx				;soustrait eax(al) et cl(ecx) et stock le resultat dans eax(ax)
	ret									;return l'operation en haut de la pile (eax)