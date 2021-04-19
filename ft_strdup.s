global ft_strdup
extern ft_strlen
extern malloc
extern ft_strcpy

ft_strdup:
		push		rdi			;push le contenu de rdi en haut de la pile
		call		ft_strlen	;stock la taille de rdi dans rax a l'aide de l'appel de strlen
		inc			rax			;incremente rax pour arriver sur la position du \0 dans la string
		mov			rdi,rax		;on met rdi a la meme valeur que rax(taille de la string + \0)
		call		malloc		;appelle de malloc pour malloc le nb(contenu rax) de caracteres
		mov			rdi, rax	;stock rax dans rdi
		pop			rsi			;recupere le contenu de rdi dans rsi
		jmp			ft_strcpy	;rentre directement dans strcpy pour copier rsi dans rdi (ret donc dans strcpy)

