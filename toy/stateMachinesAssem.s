	.arch msp430g2553

	.p2align 1,0

JT:
	.word default
	.word case1
	.word case2
	.word case3
	.word case4

	.text
	.global stat_advance

state_advance:
	cmp #5,&state
	jhs default
	mov &state,r12
	add r12,r12
	mov JT(r12),r0

case1:
	
