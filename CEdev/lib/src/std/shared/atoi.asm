	.ref _strtol
	.def _atoi
	.assume adl=1

; int atos(char *cp);

_atoi:
	pop	bc
	pop	de
	push	de
	push	bc
	ld	bc,10
	push	bc
	ld	c,b
	push	bc
	push	de
	call	_strtol
	pop	de
	pop	bc
	pop	bc
	ret
