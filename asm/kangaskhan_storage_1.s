	.include "constants/gba_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

	thumb_func_start sub_80175FC
sub_80175FC:
	push {r4-r7,lr}
	ldr r4, _0801767C
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08017680
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x2
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _08017684
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x3
	str r0, [r3, 0x30]
	ldr r0, _08017688
	ldr r0, [r0]
	str r0, [r3, 0x34]
	movs r0, 0x6
	str r0, [r3, 0x38]
	ldr r0, _0801768C
	ldr r0, [r0]
	str r0, [r3, 0x3C]
	str r1, [r3, 0x40]
	movs r6, 0x4
	str r2, [r3, 0x44]
	str r1, [r3, 0x48]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_08017648:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08017658
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x18]
	cmp r1, r0
	beq _080176B2
_08017658:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08017648
	movs r5, 0
	cmp r5, r6
	bge _080176B2
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08017690
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x18]
	b _080176B2
	.align 2, 0
_0801767C: .4byte gUnknown_203B208
_08017680: .4byte gUnknown_80D4958
_08017684: .4byte gUnknown_80D4964
_08017688: .4byte gUnknown_80D4970
_0801768C: .4byte gUnknown_80D4934
_08017690:
	adds r5, 0x1
	cmp r5, r6
	bge _080176B2
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08017690
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x18]
_080176B2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80175FC

	thumb_func_start sub_80176B8
sub_80176B8:
	push {r4-r7,lr}
	ldr r4, _08017724
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _08017728
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x2
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _0801772C
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x6
	str r0, [r3, 0x30]
	movs r6, 0x2
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_080176F2:
	ldrh r0, [r2]
	cmp r0, 0
	bne _08017702
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x1C]
	cmp r1, r0
	beq _08017752
_08017702:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _080176F2
	movs r5, 0
	cmp r5, r6
	bge _08017752
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _08017730
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x1C]
	b _08017752
	.align 2, 0
_08017724: .4byte gUnknown_203B208
_08017728: .4byte gUnknown_80D4958
_0801772C: .4byte gUnknown_80D4970
_08017730:
	adds r5, 0x1
	cmp r5, r6
	bge _08017752
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _08017730
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x1C]
_08017752:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80176B8

	thumb_func_start sub_8017758
sub_8017758:
	push {r4-r7,lr}
	ldr r4, _080177C4
	ldr r0, [r4]
	adds r0, 0x4C
	movs r1, 0
	movs r2, 0xA
	bl MemoryFill16
	ldr r3, [r4]
	movs r2, 0
	ldr r0, _080177C8
	ldr r0, [r0]
	str r0, [r3, 0x24]
	movs r0, 0x3
	str r0, [r3, 0x28]
	movs r1, 0x1
	ldr r0, _080177CC
	ldr r0, [r0]
	str r0, [r3, 0x2C]
	movs r0, 0x6
	str r0, [r3, 0x30]
	movs r6, 0x2
	str r2, [r3, 0x34]
	str r1, [r3, 0x38]
	movs r5, 0
	mov r12, r3
	adds r3, 0x28
	mov r2, r12
	adds r2, 0x4C
_08017792:
	ldrh r0, [r2]
	cmp r0, 0
	bne _080177A2
	ldr r1, [r3]
	mov r7, r12
	ldr r0, [r7, 0x20]
	cmp r1, r0
	beq _080177F2
_080177A2:
	adds r3, 0x8
	adds r2, 0x2
	adds r5, 0x1
	cmp r5, r6
	blt _08017792
	movs r5, 0
	cmp r5, r6
	bge _080177F2
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0x4C
	ldrh r0, [r0]
	cmp r0, 0
	bne _080177D0
	ldr r0, [r1, 0x28]
	str r0, [r1, 0x20]
	b _080177F2
	.align 2, 0
_080177C4: .4byte gUnknown_203B208
_080177C8: .4byte gUnknown_80D4964
_080177CC: .4byte gUnknown_80D4970
_080177D0:
	adds r5, 0x1
	cmp r5, r6
	bge _080177F2
	ldr r2, [r4]
	lsls r0, r5, 1
	adds r1, r2, 0
	adds r1, 0x4C
	adds r1, r0
	ldrh r0, [r1]
	cmp r0, 0
	bne _080177D0
	lsls r0, r5, 3
	adds r1, r2, 0
	adds r1, 0x28
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0x20]
_080177F2:
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_8017758

	thumb_func_start sub_80177F8
sub_80177F8:
	ldr r0, _0801781C
	ldr r1, [r0]
	movs r3, 0
	ldr r0, _08017820
	ldr r0, [r0]
	str r0, [r1, 0x24]
	movs r0, 0x4
	str r0, [r1, 0x28]
	movs r2, 0x1
	ldr r0, _08017824
	ldr r0, [r0]
	str r0, [r1, 0x2C]
	movs r0, 0x5
	str r0, [r1, 0x30]
	str r3, [r1, 0x34]
	str r2, [r1, 0x38]
	bx lr
	.align 2, 0
_0801781C: .4byte gUnknown_203B208
_08017820: .4byte gUnknown_80D4920
_08017824: .4byte gUnknown_80D4928
	thumb_func_end sub_80177F8

	thumb_func_start sub_8017828
sub_8017828:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080178C8
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08017842
	ldr r0, _08017854
	ldr r0, [r0]
	str r1, [r0, 0x18]
_08017842:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08017862
	cmp r0, 0x2
	bgt _08017858
	cmp r0, 0x1
	beq _080178C2
	b _080178C8
	.align 2, 0
_08017854: .4byte gUnknown_203B208
_08017858:
	cmp r0, 0x3
	beq _0801788E
	cmp r0, 0x6
	beq _080178BA
	b _080178C8
_08017862:
	bl sub_8090A34
	cmp r0, 0
	bne _08017872
	movs r0, 0x5
	bl UpdateKangaskhanStorageState
	b _080178C8
_08017872:
	movs r0, 0
	bl sub_801CF50
	lsls r0, 24
	cmp r0, 0
	beq _08017886
	movs r0, 0x8
	bl UpdateKangaskhanStorageState
	b _080178C8
_08017886:
	movs r0, 0xB
	bl UpdateKangaskhanStorageState
	b _080178C8
_0801788E:
	movs r0, 0x1
	bl sub_801CF14
	lsls r0, 24
	cmp r0, 0
	beq _080178A2
	movs r0, 0x7
	bl UpdateKangaskhanStorageState
	b _080178C8
_080178A2:
	bl sub_8090A34
	cmp r0, 0x13
	ble _080178B2
	movs r0, 0x6
	bl UpdateKangaskhanStorageState
	b _080178C8
_080178B2:
	movs r0, 0x14
	bl UpdateKangaskhanStorageState
	b _080178C8
_080178BA:
	movs r0, 0x2
	bl UpdateKangaskhanStorageState
	b _080178C8
_080178C2:
	movs r0, 0x3
	bl UpdateKangaskhanStorageState
_080178C8:
	add sp, 0x4
	pop {r0}
	bx r0
	thumb_func_end sub_8017828

	thumb_func_start sub_80178D0
sub_80178D0:
	push {r4,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _0801791E
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080178F4
	cmp r0, 0x4
	bgt _080178EE
	cmp r0, 0x1
	beq _08017918
	b _0801791E
_080178EE:
	cmp r0, 0x5
	beq _08017918
	b _0801791E
_080178F4:
	ldr r4, _08017914
	ldr r0, [r4]
	adds r0, 0xC
	bl sub_80917B8
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_80911F8
	bl sub_80910B4
	movs r0, 0x13
	bl UpdateKangaskhanStorageState
	b _0801791E
	.align 2, 0
_08017914: .4byte gUnknown_203B208
_08017918:
	movs r0, 0xE
	bl UpdateKangaskhanStorageState
_0801791E:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_80178D0

	thumb_func_start sub_8017928
sub_8017928:
	push {lr}
	sub sp, 0x8
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _080179A2
	ldr r0, [sp]
	cmp r0, 0x4
	beq _0801794C
	cmp r0, 0x4
	bgt _08017946
	cmp r0, 0x1
	beq _0801799C
	b _080179A2
_08017946:
	cmp r0, 0x5
	beq _0801799C
	b _080179A2
_0801794C:
	ldr r0, _0801798C
	ldr r1, [r0]
	ldr r0, _08017990
	ldr r3, [r0]
	ldrb r0, [r3, 0xE]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrb r2, [r3, 0xD]
	ldrh r0, [r1]
	subs r0, r2
	strh r0, [r1]
	ldrb r2, [r3, 0xE]
	ldr r1, _08017994
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r2
	str r0, [sp, 0x4]
	ldrb r1, [r3, 0xD]
	lsls r1, 8
	ldr r2, _08017998
	ands r0, r2
	orrs r0, r1
	str r0, [sp, 0x4]
	add r0, sp, 0x4
	bl sub_8091274
	movs r0, 0x1D
	bl UpdateKangaskhanStorageState
	b _080179A2
	.align 2, 0
_0801798C: .4byte gUnknown_203B460
_08017990: .4byte gUnknown_203B208
_08017994: .4byte 0xffffff00
_08017998: .4byte 0xffff00ff
_0801799C:
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_080179A2:
	add sp, 0x8
	pop {r0}
	bx r0
	thumb_func_end sub_8017928

	thumb_func_start sub_80179A8
sub_80179A8:
	push {r4-r7,lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08017A12
	ldr r0, [sp]
	cmp r0, 0x4
	beq _080179CC
	cmp r0, 0x4
	bgt _080179C6
	cmp r0, 0x1
	beq _08017A0C
	b _08017A12
_080179C6:
	cmp r0, 0x5
	beq _08017A0C
	b _08017A12
_080179CC:
	movs r5, 0
	ldr r6, _08017A08
	movs r7, 0
_080179D2:
	adds r0, r5, 0
	bl sub_801AED0
	cmp r0, 0
	beq _080179F2
	lsls r4, r5, 2
	ldr r0, [r6]
	adds r0, r4
	bl sub_80917B8
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0, 0x2]
	ldr r0, [r6]
	adds r0, r4
	strb r7, [r0]
_080179F2:
	adds r5, 0x1
	cmp r5, 0x13
	ble _080179D2
	bl sub_80910B4
	bl sub_801AE84
	movs r0, 0x13
	bl UpdateKangaskhanStorageState
	b _08017A12
	.align 2, 0
_08017A08: .4byte gUnknown_203B460
_08017A0C:
	movs r0, 0xE
	bl UpdateKangaskhanStorageState
_08017A12:
	add sp, 0x4
	pop {r4-r7}
	pop {r0}
	bx r0
	thumb_func_end sub_80179A8

	thumb_func_start sub_8017A1C
sub_8017A1C:
	push {r4-r6,lr}
	sub sp, 0x8
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08017AEE
	ldr r0, [sp]
	cmp r0, 0x4
	beq _08017A40
	cmp r0, 0x4
	bgt _08017A3A
	cmp r0, 0x1
	beq _08017AE8
	b _08017AEE
_08017A3A:
	cmp r0, 0x5
	beq _08017AE8
	b _08017AEE
_08017A40:
	movs r5, 0
	ldr r6, _08017A88
_08017A44:
	lsls r0, r5, 24
	lsrs r4, r0, 24
	adds r0, r4, 0
	bl sub_801CFE0
	cmp r0, 0
	beq _08017ACE
	ldr r1, _08017A8C
	ldr r0, [sp, 0x4]
	ands r0, r1
	orrs r0, r4
	str r0, [sp, 0x4]
	add r4, sp, 0x4
	ldrb r0, [r4]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08017AA2
	ldr r2, _08017A90
	ldr r1, [r2]
	ldrb r0, [r4]
	lsls r0, 1
	adds r1, 0x50
	adds r1, r0
	ldrh r1, [r1]
	cmp r1, 0x63
	bls _08017A94
	ldr r0, [sp, 0x4]
	ands r0, r6
	movs r1, 0xC6
	lsls r1, 7
	b _08017A9C
	.align 2, 0
_08017A88: .4byte 0xffff00ff
_08017A8C: .4byte 0xffffff00
_08017A90: .4byte gUnknown_203B460
_08017A94:
	lsls r1, 24
	lsrs r1, 16
	ldr r0, [sp, 0x4]
	ands r0, r6
_08017A9C:
	orrs r0, r1
	str r0, [sp, 0x4]
	b _08017AB0
_08017AA2:
	ldr r0, [sp, 0x4]
	ands r0, r6
	movs r1, 0x80
	lsls r1, 1
	orrs r0, r1
	str r0, [sp, 0x4]
	ldr r2, _08017AE4
_08017AB0:
	ldr r3, [r2]
	add r0, sp, 0x4
	ldrb r1, [r4]
	lsls r1, 1
	adds r3, 0x50
	adds r3, r1
	ldr r1, [sp, 0x4]
	lsrs r1, 8
	lsls r1, 24
	lsrs r1, 24
	ldrh r2, [r3]
	subs r2, r1
	strh r2, [r3]
	bl sub_8091274
_08017ACE:
	adds r5, 0x1
	cmp r5, 0xEF
	ble _08017A44
	bl sub_80910B4
	bl sub_801CF94
	movs r0, 0x1D
	bl UpdateKangaskhanStorageState
	b _08017AEE
	.align 2, 0
_08017AE4: .4byte gUnknown_203B460
_08017AE8:
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_08017AEE:
	add sp, 0x8
	pop {r4-r6}
	pop {r0}
	bx r0
	thumb_func_end sub_8017A1C

	thumb_func_start sub_8017AF8
sub_8017AF8:
	push {lr}
	movs r0, 0x1
	bl sub_801A6E8
	cmp r0, 0x3
	beq _08017B14
	cmp r0, 0x3
	bhi _08017B0E
	cmp r0, 0x2
	beq _08017B78
	b _08017B82
_08017B0E:
	cmp r0, 0x4
	beq _08017B50
	b _08017B82
_08017B14:
	bl sub_801AEA8
	cmp r0, 0
	beq _08017B2A
	movs r0, 0
	bl sub_8099690
	movs r0, 0x12
	bl UpdateKangaskhanStorageState
	b _08017B82
_08017B2A:
	bl sub_801A8AC
	ldr r1, _08017B48
	ldr r2, [r1]
	str r0, [r2, 0x10]
	ldr r1, _08017B4C
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0xC]
	movs r0, 0xF
	bl UpdateKangaskhanStorageState
	b _08017B82
	.align 2, 0
_08017B48: .4byte gUnknown_203B208
_08017B4C: .4byte gUnknown_203B460
_08017B50:
	bl sub_801A8AC
	ldr r1, _08017B70
	ldr r2, [r1]
	str r0, [r2, 0x10]
	ldr r1, _08017B74
	ldr r1, [r1]
	lsls r0, 2
	adds r1, r0
	ldr r0, [r1]
	str r0, [r2, 0xC]
	movs r0, 0x10
	bl UpdateKangaskhanStorageState
	b _08017B82
	.align 2, 0
_08017B70: .4byte gUnknown_203B208
_08017B74: .4byte gUnknown_203B460
_08017B78:
	bl sub_801A928
	movs r0, 0x1
	bl UpdateKangaskhanStorageState
_08017B82:
	pop {r0}
	bx r0
	thumb_func_end sub_8017AF8

	thumb_func_start sub_8017B88
sub_8017B88:
	push {r4,lr}
	movs r0, 0x1
	bl sub_801CA08
	cmp r0, 0x2
	beq _08017C10
	cmp r0, 0x2
	bhi _08017B9E
	cmp r0, 0x1
	beq _08017C1C
	b _08017C22
_08017B9E:
	cmp r0, 0x3
	beq _08017BA8
	cmp r0, 0x4
	beq _08017BE4
	b _08017C22
_08017BA8:
	bl sub_801CFB8
	cmp r0, 0
	beq _08017BB8
	movs r0, 0x1C
	bl UpdateKangaskhanStorageState
	b _08017C22
_08017BB8:
	bl sub_801CB24
	ldr r4, _08017BE0
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC
	ldrb r1, [r1, 0x14]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	movs r0, 0x19
	bl UpdateKangaskhanStorageState
	b _08017C22
	.align 2, 0
_08017BE0: .4byte gUnknown_203B208
_08017BE4:
	bl sub_801CB24
	ldr r4, _08017C0C
	ldr r1, [r4]
	strb r0, [r1, 0x14]
	ldr r1, [r4]
	adds r0, r1, 0
	adds r0, 0xC
	ldrb r1, [r1, 0x14]
	movs r2, 0
	bl sub_8090A8C
	ldr r1, [r4]
	movs r0, 0x1
	strb r0, [r1, 0xD]
	movs r0, 0x1A
	bl UpdateKangaskhanStorageState
	b _08017C22
	.align 2, 0
_08017C0C: .4byte gUnknown_203B208
_08017C10:
	bl sub_801CBB8
	movs r0, 0x1
	bl UpdateKangaskhanStorageState
	b _08017C22
_08017C1C:
	movs r0, 0
	bl sub_801AD34
_08017C22:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017B88

	thumb_func_start sub_8017C28
sub_8017C28:
	push {r4,lr}
	movs r0, 0
	bl sub_801CA08
	ldr r4, _08017C54
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	ldr r0, [r4]
	adds r0, 0xA8
	bl sub_8013BBC
	cmp r0, 0x1
	beq _08017C58
	cmp r0, 0x1
	bcc _08017C76
	cmp r0, 0x2
	beq _08017C70
	cmp r0, 0x3
	beq _08017C5E
	b _08017C76
	.align 2, 0
_08017C54: .4byte gUnknown_203B208
_08017C58:
	bl sub_8017598
	b _08017C76
_08017C5E:
	ldr r0, [r4]
	adds r1, r0, 0
	adds r1, 0xA8
	ldr r1, [r1]
	strb r1, [r0, 0xD]
	movs r0, 0x1B
	bl UpdateKangaskhanStorageState
	b _08017C76
_08017C70:
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_08017C76:
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017C28

	thumb_func_start sub_8017C7C
sub_8017C7C:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801A6E8
	ldr r4, _08017CBC
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08017CAC
	ldr r0, [r4]
	adds r0, 0x58
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08017CAC
	ldr r0, [r4]
	str r1, [r0, 0x1C]
_08017CAC:
	ldr r0, [sp]
	cmp r0, 0x2
	beq _08017CC6
	cmp r0, 0x2
	bgt _08017CC0
	cmp r0, 0x1
	beq _08017D14
	b _08017D1A
	.align 2, 0
_08017CBC: .4byte gUnknown_203B208
_08017CC0:
	cmp r0, 0x6
	beq _08017D06
	b _08017D1A
_08017CC6:
	movs r0, 0
	bl sub_8099690
	ldr r4, _08017CE4
	ldr r0, [r4]
	ldrb r0, [r0, 0xE]
	bl sub_8091524
	lsls r0, 24
	cmp r0, 0
	bne _08017CE8
	movs r0, 0x9
	bl UpdateKangaskhanStorageState
	b _08017D1A
	.align 2, 0
_08017CE4: .4byte gUnknown_203B208
_08017CE8:
	ldr r0, [r4]
	ldr r0, [r0, 0x10]
	bl sub_801ADA0
	lsls r0, 24
	cmp r0, 0
	bne _08017CFE
	movs r0, 0xA
	bl UpdateKangaskhanStorageState
	b _08017D1A
_08017CFE:
	movs r0, 0x11
	bl UpdateKangaskhanStorageState
	b _08017D1A
_08017D06:
	movs r0, 0
	bl sub_8099690
	movs r0, 0x10
	bl UpdateKangaskhanStorageState
	b _08017D1A
_08017D14:
	movs r0, 0xE
	bl UpdateKangaskhanStorageState
_08017D1A:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017C7C

	thumb_func_start sub_8017D24
sub_8017D24:
	push {r4,lr}
	sub sp, 0x4
	movs r0, 0
	str r0, [sp]
	bl sub_801CA08
	ldr r4, _08017D64
	ldr r0, [r4]
	adds r0, 0x58
	bl sub_8012FD8
	lsls r0, 24
	cmp r0, 0
	bne _08017D54
	ldr r0, [r4]
	adds r0, 0x58
	mov r1, sp
	bl sub_8013114
	ldr r1, [sp]
	cmp r1, 0x1
	beq _08017D54
	ldr r0, [r4]
	str r1, [r0, 0x20]
_08017D54:
	ldr r0, [sp]
	cmp r0, 0x3
	beq _08017D6E
	cmp r0, 0x3
	bgt _08017D68
	cmp r0, 0x1
	beq _08017DB0
	b _08017DB6
	.align 2, 0
_08017D64: .4byte gUnknown_203B208
_08017D68:
	cmp r0, 0x6
	beq _08017DA8
	b _08017DB6
_08017D6E:
	bl sub_8090A34
	cmp r0, 0x13
	ble _08017D82
	bl sub_801CBB8
	movs r0, 0x6
	bl UpdateKangaskhanStorageState
	b _08017DB6
_08017D82:
	ldr r0, _08017D9C
	ldr r0, [r0]
	ldrb r0, [r0, 0xE]
	bl sub_8090A60
	lsls r0, 24
	cmp r0, 0
	beq _08017DA0
	movs r0, 0x18
	bl UpdateKangaskhanStorageState
	b _08017DB6
	.align 2, 0
_08017D9C: .4byte gUnknown_203B208
_08017DA0:
	movs r0, 0x1B
	bl UpdateKangaskhanStorageState
	b _08017DB6
_08017DA8:
	movs r0, 0x1A
	bl UpdateKangaskhanStorageState
	b _08017DB6
_08017DB0:
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_08017DB6:
	add sp, 0x4
	pop {r4}
	pop {r0}
	bx r0
	thumb_func_end sub_8017D24

	thumb_func_start sub_8017DC0
sub_8017DC0:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08017DD8
	cmp r0, 0x3
	bhi _08017DD8
	bl sub_801B450
	movs r0, 0xE
	bl UpdateKangaskhanStorageState
_08017DD8:
	pop {r0}
	bx r0
	thumb_func_end sub_8017DC0

	thumb_func_start sub_8017DDC
sub_8017DDC:
	push {lr}
	bl sub_801B410
	cmp r0, 0x1
	bls _08017DF4
	cmp r0, 0x3
	bhi _08017DF4
	bl sub_801B450
	movs r0, 0x17
	bl UpdateKangaskhanStorageState
_08017DF4:
	pop {r0}
	bx r0
	thumb_func_end sub_8017DDC

	thumb_func_start sub_8017DF8
sub_8017DF8:
	push {lr}
	sub sp, 0x4
	mov r0, sp
	bl sub_80144A4
	cmp r0, 0
	bne _08017E10
	ldr r0, _08017E18
	ldr r0, [r0]
	ldr r0, [r0, 0x8]
	bl UpdateKangaskhanStorageState
_08017E10:
	add sp, 0x4
	pop {r0}
	bx r0
	.align 2, 0
_08017E18: .4byte gUnknown_203B208
	thumb_func_end sub_8017DF8

        .align 2,0
