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
	cmp #5,&state
	jhs default
	mov &state,r12
	add r12,r12
	mov JT(r12),r0

case1:
	add #1,redrawScreen
	call #clearWindow
	call #drawCyanTriangle
	call #beep
	call #greenLights
	jmp end

case2:
	add #1,redrawScreen
	call #clearWindow
	call #drawRect
	call #song
	call #dimRed
	jmp end

case3:
	add #1,redrawScreen
	call #clearWindow
	call #flagShape
	call #errorSong
	call #redLights
	jmp end

case4:
	add #1,redrawScreen
	call #drawInit
	call #buzzer_off
	jmp end

default:
	jmp end

end:
	ret
