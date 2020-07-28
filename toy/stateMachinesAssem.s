	.arch msp430g2553

	.p2align 1,0

JT:
	.word default
	.word case1
	.word case2
	.word case3
	.word case4

	.text
	.global state_advance

state_advance:
	cmp.b #5,&state		;compare switch to 5
	jhs default		;if carry jump to default
	mov.b &state,r12
	add.b r12,r12		;make space
	mov JT(r12),r0

case1:
	add #1,redrawScreen	;set redraw = 1
	call #clearWindow
	call #drawCyanTriangle
	call #beep
	call #greenLights
	mov.b #0,&state		;set state = 0
	jmp end

case2:
	add #1,redrawScreen
	call #clearWindow
	call #drawRect
	call #song
	call #dimRed
	mov.b #0,&state
	jmp end

case3:
	add #1,redrawScreen
	call #clearWindow
	call #flagShape
	call #errorSong
	call #redLights
	mov.b #0,&state
	jmp end

case4:
	add #1,redrawScreen
	call #drawInit
	mov.b #0,&state
	jmp end

default:
	jmp end

end:
	ret
