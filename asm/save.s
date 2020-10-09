	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_8011FA8
sub_8011FA8:
	push {r4,r5,lr}
	sub sp, 0x4
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	movs r1, 0x5
	bl MemoryAlloc
	adds r5, r0, 0
	movs r0, 0x1F
	str r0, [sp]
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	bl ReadSaveSector
	adds r2, r0, 0
	cmp r2, 0
	bne _08011FD8
	ldr r1, [r5, 0x14]
	ldr r0, _08011FF0
	cmp r1, r0
	beq _08011FD8
	movs r2, 0x4
_08011FD8:
	ldr r4, _08011FF4
	cmp r2, 0
	bne _08011FE0
	ldr r4, [r5, 0x18]
_08011FE0:
	adds r0, r5, 0
	bl MemoryFree
	adds r0, r4, 0
	add sp, 0x4
	pop {r4,r5}
	pop {r1}
	bx r1
	.align 2, 0
_08011FF0: .4byte 0x05071412
_08011FF4: .4byte 0x000f1209
	thumb_func_end sub_8011FA8

	thumb_func_start sub_8011FF8
sub_8011FF8:
	push {r4-r6,lr}
	sub sp, 0x4
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	movs r1, 0x5
	bl MemoryAlloc
	adds r5, r0, 0
	movs r0, 0x1F
	str r0, [sp]
	movs r6, 0
	mov r0, sp
	adds r1, r5, 0
	adds r2, r4, 0
	bl ReadSaveSector
	cmp r0, 0
	bne _08012028
	ldr r1, [r5, 0x14]
	ldr r0, _08012038
	cmp r1, r0
	bne _08012028
	movs r6, 0x1
_08012028:
	adds r0, r5, 0
	bl MemoryFree
	adds r0, r6, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_08012038: .4byte 0x05071412
	thumb_func_end sub_8011FF8

	thumb_func_start sub_801203C
sub_801203C:
	push {r4-r7,lr}
	adds r7, r0, 0
	adds r4, r1, 0
	ldr r0, _08012078
	movs r1, 0x5
	bl MemoryAlloc
	adds r6, r0, 0
	movs r0, 0x89
	lsls r0, 3
	adds r5, r6, r0
	ldr r0, _0801207C
	ldr r2, [r0]
	cmp r2, 0
	bne _08012084
	ldr r1, _08012080
	adds r0, r6, r1
	str r4, [r0]
	bl sub_8011C34
	movs r2, 0x83
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	bl GetRngState
	movs r2, 0x84
	lsls r2, 3
	adds r1, r6, r2
	b _0801209E
	.align 2, 0
_08012078: .4byte 0x000057d4
_0801207C: .4byte gUnknown_203B184
_08012080: .4byte 0x0000041c
_08012084:
	ldr r0, _080120C8
	adds r1, r6, r0
	ldr r0, [r2, 0x54]
	str r0, [r1]
	movs r0, 0x83
	lsls r0, 3
	adds r1, r6, r0
	ldr r0, [r2, 0x50]
	str r0, [r1]
	movs r0, 0x84
	lsls r0, 3
	adds r1, r6, r0
	ldr r0, [r2, 0x58]
_0801209E:
	str r0, [r1]
	ldr r2, _080120CC
	adds r1, r6, r2
	ldr r0, _080120D0
	str r0, [r1]
	bl sub_8011C4C
	adds r1, r0, 0
	ldr r2, _080120D4
	adds r0, r6, r2
	movs r2, 0x10
	bl strncpy
	ldr r0, _080120D8
	ldr r1, [r0]
	cmp r1, 0
	bne _080120DC
	adds r0, r6, 0x4
	bl sub_8002700
	b _080120E8
	.align 2, 0
_080120C8: .4byte 0x0000041c
_080120CC: .4byte 0x00000414
_080120D0: .4byte 0x05071412
_080120D4: .4byte 0x00000404
_080120D8: .4byte gUnknown_203B184
_080120DC:
	adds r0, r6, 0x4
	ldr r1, [r1, 0x4C]
	movs r2, 0x80
	lsls r2, 3
	bl MemoryCopy8
_080120E8:
	ldr r4, _080121A4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808ED78
	ldr r2, _080121A8
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	movs r4, 0x96
	lsls r4, 2
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_808F154
	movs r2, 0x85
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	subs r4, 0x80
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8091C68
	movs r2, 0x86
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	adds r0, r5, 0
	movs r1, 0x10
	bl sub_80921C4
	ldr r2, _080121AC
	adds r1, r6, r2
	str r0, [r1]
	adds r5, 0x10
	adds r0, r5, 0
	movs r1, 0x8
	bl sub_80927A8
	movs r2, 0x87
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, 0x8
	subs r4, 0xD8
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8097D60
	ldr r2, _080121B0
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	ldr r4, _080121B4
	adds r0, r5, 0
	adds r1, r4, 0
	bl sub_8095624
	movs r2, 0x88
	lsls r2, 3
	adds r1, r6, r2
	str r0, [r1]
	adds r5, r4
	ldr r1, _080121B8
	adds r0, r5, 0
	bl sub_80970D8
	ldr r2, _080121BC
	adds r1, r6, r2
	str r0, [r1]
	ldr r4, _080121C0
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl WriteSaveSector
	adds r5, r0, 0
	adds r0, r7, 0
	adds r1, r6, 0
	adds r2, r4, 0
	bl WriteSaveSector
	adds r4, r0, 0
	adds r0, r6, 0
	bl MemoryFree
	cmp r5, 0
	beq _080121C4
	adds r0, r5, 0
	b _080121CE
	.align 2, 0
_080121A4: .4byte 0x00004650
_080121A8: .4byte 0x00000424
_080121AC: .4byte 0x00000434
_080121B0: .4byte 0x0000043c
_080121B4: .4byte 0x00000594
_080121B8: .4byte 0x00000221
_080121BC: .4byte 0x00000444
_080121C0: .4byte 0x000057d4
_080121C4:
	cmp r4, 0
	bne _080121CC
	movs r0, 0
	b _080121CE
_080121CC:
	adds r0, r4, 0
_080121CE:
	pop {r4-r7}
	pop {r1}
	bx r1
	thumb_func_end sub_801203C

	thumb_func_start sub_80121D4
sub_80121D4:
	push {lr}
	bl WriteSaveSector
	pop {r1}
	bx r1
	thumb_func_end sub_80121D4

	thumb_func_start sub_80121E0
sub_80121E0:
	push {r4-r6,lr}
	sub sp, 0x4
	adds r5, r0, 0
	movs r6, 0x80
	lsls r6, 4
	adds r0, r6, 0
	movs r1, 0x5
	bl MemoryAlloc
	adds r4, r0, 0
	movs r0, 0x1F
	str r0, [sp]
	str r5, [r4, 0x18]
	bl sub_809769C
	ldr r0, [r0]
	str r0, [r4, 0x1C]
	ldr r0, _0801223C
	str r0, [r4, 0x14]
	bl sub_8011C4C
	adds r1, r0, 0
	adds r0, r4, 0x4
	movs r2, 0x10
	bl strncpy
	adds r0, r4, 0
	adds r0, 0x20
	movs r1, 0
	bl sub_80958E4
	mov r0, sp
	adds r1, r4, 0
	adds r2, r6, 0
	bl WriteSaveSector
	adds r5, r0, 0
	adds r0, r4, 0
	bl MemoryFree
	adds r0, r5, 0
	add sp, 0x4
	pop {r4-r6}
	pop {r1}
	bx r1
	.align 2, 0
_0801223C: .4byte 0x05071412
	thumb_func_end sub_80121E0

	thumb_func_start sub_8012240
sub_8012240:
	push {r4,r5,lr}
	movs r4, 0x80
	lsls r4, 4
	adds r0, r4, 0
	movs r1, 0x5
	bl MemoryAlloc
	adds r5, r0, 0
	movs r1, 0xFF
	movs r2, 0x4
	bl MemoryFill8
	bl sub_8011830
	movs r0, 0x1F
	adds r1, r5, 0
	adds r2, r4, 0
	bl WriteFlashData
	adds r4, r0, 0
	bl sub_8011854
	adds r0, r5, 0
	bl MemoryFree
	cmp r4, 0
	bne _0801227A
	movs r0, 0
	b _0801227C
_0801227A:
	movs r0, 0x2
_0801227C:
	pop {r4,r5}
	pop {r1}
	bx r1
	thumb_func_end sub_8012240

	thumb_func_start sub_8012284
sub_8012284:
	push {lr}
	bl sub_80122D0
	bl sub_80122F4
	bl sub_8012300
	pop {r0}
	bx r0
	thumb_func_end sub_8012284

	thumb_func_start sub_8012298
sub_8012298:
	push {lr}
	bl sub_80976A8
	bl sub_80122A8
	pop {r0}
	bx r0
	thumb_func_end sub_8012298

	thumb_func_start sub_80122A8
sub_80122A8:
	push {lr}
	bl sub_80122D0
	bl sub_80122F4
	bl sub_8012300
	bl sub_8012240
	pop {r0}
	bx r0
	thumb_func_end sub_80122A8

	thumb_func_start nullsub_33
nullsub_33:
	bx lr
	thumb_func_end nullsub_33

	thumb_func_start sub_80122C4
sub_80122C4:
	push {lr}
	bl sub_80122A8
	pop {r0}
	bx r0
	thumb_func_end sub_80122C4

	thumb_func_start sub_80122D0
sub_80122D0:
	push {lr}
	movs r0, 0
	bl sub_8011C28
	movs r0, 0x1
	negs r0, r0
	bl sub_8011C40
	bl sub_8097748
	ldr r0, _080122F0
	ldr r0, [r0]
	bl sub_8094FA8
	pop {r0}
	bx r0
	.align 2, 0
_080122F0: .4byte gUnknown_203B47C
	thumb_func_end sub_80122D0

	.align 2, 0 @ Don't pad with nop.
