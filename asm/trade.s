	.include "constants/gba_constants.inc"
	.include "constants/species_constants.inc"
	.include "asm/macros.inc"

	.syntax unified

	.text

.ifdef ENGLISH
	.set sub_804A96C_alt, sub_804A96C
.endif

	thumb_func_start sub_804ACF4
sub_804ACF4: @ 804ACF4
	push {r4-r7,lr}
	mov r7, r9
	mov r6, r8
	push {r6,r7}
	lsls r0, 24
	lsrs r0, 24
	mov r8, r0
	cmp r0, 0
	beq _0804AD0C
	cmp r0, 0x1
	beq _0804ADA0
	b _0804AE2C
_0804AD0C:
	movs r7, 0
	ldr r1, _0804AD4C @ =gUnknown_03004824
	ldr r0, [r1]
	adds r0, 0x42
	ldrb r0, [r0]
	cmp r7, r0
	blt _0804AD1C
	b _0804AE2C
_0804AD1C:
	adds r6, r1, 0
	movs r5, 0
	mov r9, r5
_0804AD22:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, _0804AD50 @ =gPlayerParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	adds r1, r0, 0
	cmp r1, 0x1
	bne _0804AD54
	ldr r0, [r6]
	adds r0, 0x51
	adds r0, r5
	mov r2, r9
	strb r2, [r0]
	ldr r0, [r6]
	adds r0, 0x5D
	adds r0, r5
	b _0804AD84
	.align 2, 0
_0804AD4C: .4byte gUnknown_03004824
_0804AD50: .4byte gPlayerParty
_0804AD54:
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	adds r1, r0, 0
	cmp r1, 0
	bne _0804AD72
	ldr r0, [r6]
	adds r0, 0x51
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, 0x5D
	adds r0, r5
	b _0804AD84
_0804AD72:
	ldr r0, [r6]
	adds r0, 0x51
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, 0x5D
	adds r0, r5
	mov r1, r9
_0804AD84:
	strb r1, [r0]
	ldr r0, _0804AD9C @ =gUnknown_03004824
	adds r5, 0x1
	adds r7, 0x1
	ldr r0, [r0]
	adds r0, 0x42
	add r0, r8
	ldrb r0, [r0]
	cmp r7, r0
	blt _0804AD22
	b _0804AE2C
	.align 2, 0
_0804AD9C: .4byte gUnknown_03004824
_0804ADA0:
	movs r7, 0
	ldr r1, _0804ADE0 @ =gUnknown_03004824
	ldr r0, [r1]
	adds r0, 0x43
	ldrb r0, [r0]
	cmp r7, r0
	bge _0804AE2C
	adds r6, r1, 0
	movs r5, 0x6
	movs r2, 0
	mov r9, r2
_0804ADB6:
	movs r0, 0x64
	adds r1, r7, 0
	muls r1, r0
	ldr r0, _0804ADE4 @ =gEnemyParty
	adds r4, r1, r0
	adds r0, r4, 0
	movs r1, 0x2D
	bl GetMonData
	adds r1, r0, 0
	cmp r1, 0x1
	bne _0804ADE8
	ldr r0, [r6]
	adds r0, 0x51
	adds r0, r5
	mov r2, r9
	strb r2, [r0]
	ldr r0, [r6]
	adds r0, 0x5D
	adds r0, r5
	b _0804AE18
	.align 2, 0
_0804ADE0: .4byte gUnknown_03004824
_0804ADE4: .4byte gEnemyParty
_0804ADE8:
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	adds r1, r0, 0
	cmp r1, 0
	bne _0804AE06
	ldr r0, [r6]
	adds r0, 0x51
	adds r0, r5
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, 0x5D
	adds r0, r5
	b _0804AE18
_0804AE06:
	ldr r0, [r6]
	adds r0, 0x51
	adds r0, r5
	movs r1, 0x1
	strb r1, [r0]
	ldr r0, [r6]
	adds r0, 0x5D
	adds r0, r5
	mov r1, r9
_0804AE18:
	strb r1, [r0]
	ldr r0, _0804AE38 @ =gUnknown_03004824
	adds r5, 0x1
	adds r7, 0x1
	ldr r0, [r0]
	adds r0, 0x42
	add r0, r8
	ldrb r0, [r0]
	cmp r7, r0
	blt _0804ADB6
_0804AE2C:
	pop {r3,r4}
	mov r8, r3
	mov r9, r4
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804AE38: .4byte gUnknown_03004824
	thumb_func_end sub_804ACF4

	thumb_func_start sub_804AE3C
sub_804AE3C: @ 804AE3C
	push {r4-r7,lr}
	lsls r0, 24
	lsrs r0, 24
	cmp r0, 0
	beq _0804AE4C
	cmp r0, 0x1
	beq _0804AEAC
	b _0804AF00
_0804AE4C:
	movs r6, 0
	ldr r1, _0804AEA4 @ =gUnknown_03004824
	ldr r0, [r1]
	adds r0, 0x42
	ldrb r0, [r0]
	cmp r6, r0
	bcs _0804AF00
	adds r7, r1, 0
_0804AE5C:
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, _0804AEA8 @ =gPlayerParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r0, r5, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	bl GetHPBarLevel
	ldr r1, [r7]
	adds r1, 0x69
	adds r1, r6
	strb r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, [r7]
	adds r0, 0x42
	ldrb r0, [r0]
	cmp r6, r0
	bcc _0804AE5C
	b _0804AF00
	.align 2, 0
_0804AEA4: .4byte gUnknown_03004824
_0804AEA8: .4byte gPlayerParty
_0804AEAC:
	movs r6, 0
	ldr r1, _0804AF08 @ =gUnknown_03004824
	ldr r0, [r1]
	adds r0, 0x43
	ldrb r0, [r0]
	cmp r6, r0
	bcs _0804AF00
	adds r7, r1, 0
_0804AEBC:
	movs r0, 0x64
	adds r4, r6, 0
	muls r4, r0
	ldr r0, _0804AF0C @ =gEnemyParty
	adds r4, r0
	adds r0, r4, 0
	movs r1, 0x39
	bl GetMonData
	lsls r0, 16
	lsrs r5, r0, 16
	adds r0, r4, 0
	movs r1, 0x3A
	bl GetMonData
	adds r1, r0, 0
	lsls r0, r5, 16
	asrs r0, 16
	lsls r1, 16
	asrs r1, 16
	bl GetHPBarLevel
	ldr r1, [r7]
	adds r1, 0x6F
	adds r1, r6
	strb r0, [r1]
	adds r0, r6, 0x1
	lsls r0, 16
	lsrs r6, r0, 16
	ldr r0, [r7]
	adds r0, 0x43
	ldrb r0, [r0]
	cmp r6, r0
	bcc _0804AEBC
_0804AF00:
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804AF08: .4byte gUnknown_03004824
_0804AF0C: .4byte gEnemyParty
	thumb_func_end sub_804AE3C

	thumb_func_start sub_804AF10
sub_804AF10: @ 804AF10
	push {r4-r7,lr}
	mov r7, r8
	push {r7}
	movs r5, 0
_0804AF18:
	movs r4, 0
	ldr r2, _0804AF7C @ =gUnknown_03004824
	ldr r0, [r2]
	adds r0, 0x42
	adds r0, r5
	adds r1, r5, 0x1
	mov r8, r1
	ldrb r0, [r0]
	cmp r4, r0
	bge _0804AF6A
	adds r6, r2, 0
	lsls r0, r5, 1
	adds r0, r5
	lsls r7, r0, 1
_0804AF34:
	ldr r2, [r6]
	adds r3, r4, r7
	adds r0, r2, 0
	adds r0, 0x34
	adds r0, r3
	ldrb r1, [r0]
	lsls r0, r1, 4
	adds r0, r1
	lsls r0, 2
	ldr r1, _0804AF80 @ =gSprites
	adds r0, r1
	adds r2, 0x69
	adds r2, r3
	ldrb r2, [r2]
	movs r1, 0x4
	subs r1, r2
	lsls r1, 24
	lsrs r1, 24
	bl sub_809D824
	adds r4, 0x1
	ldr r0, [r6]
	adds r0, 0x42
	adds r0, r5
	ldrb r0, [r0]
	cmp r4, r0
	blt _0804AF34
_0804AF6A:
	mov r5, r8
	cmp r5, 0x1
	ble _0804AF18
	pop {r3}
	mov r8, r3
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804AF7C: .4byte gUnknown_03004824
_0804AF80: .4byte gSprites
	thumb_func_end sub_804AF10

	thumb_func_start sub_804AF84
sub_804AF84: @ 804AF84
	push {r4,lr}
	movs r2, 0
	ldr r4, _0804AFB0 @ =gSaveBlock1 + 0x3110
	ldr r3, _0804AFB4 @ =gUnknown_03004824
_0804AF8C:
	adds r1, r2, r4
	ldrb r0, [r1]
	cmp r0, 0
	bne _0804AFA2
	ldr r0, [r3]
	adds r0, 0xB5
	adds r0, r2
	ldrb r0, [r0]
	cmp r0, 0
	beq _0804AFA2
	strb r0, [r1]
_0804AFA2:
	adds r2, 0x1
	cmp r2, 0xA
	ble _0804AF8C
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0804AFB0: .4byte gSaveBlock1 + 0x3110
_0804AFB4: .4byte gUnknown_03004824
	thumb_func_end sub_804AF84

	thumb_func_start sub_804AFB8
sub_804AFB8: @ 804AFB8
	push {r4-r7,lr}
	mov r7, r10
	mov r6, r9
	mov r5, r8
	push {r5-r7}
	sub sp, 0x4
	mov r9, r0
	mov r8, r1
	mov r10, r2
	lsls r3, 24
	lsrs r6, r3, 24
	adds r0, r6, 0x3
	lsrs r6, r0, 2
	ldr r7, _0804B054 @ =gTileBuffer
	mov r0, sp
	movs r5, 0
	strh r5, [r0]
	lsls r4, r6, 6
	movs r0, 0x80
	lsls r0, 17
	orrs r4, r0
	mov r0, sp
	adds r1, r7, 0
	adds r2, r4, 0
	bl CpuSet
	mov r0, sp
	adds r0, 0x2
	strh r5, [r0]
	mov r2, r9
	ldrb r1, [r2, 0xD]
	lsls r1, 5
	adds r1, r7
	adds r2, r4, 0
	bl CpuSet
	mov r0, r9
	adds r1, r7, 0
	mov r2, r10
	bl sub_8004E3C
	movs r4, 0
	cmp r4, r6
	bcs _0804B042
_0804B010:
	lsls r0, r4, 7
	adds r0, r7, r0
	lsls r1, r4, 8
	add r1, r8
	movs r2, 0x40
	bl CpuSet
	lsls r0, r4, 2
	mov r1, r9
	ldrb r1, [r1, 0xD]
	adds r0, r1
	lsls r0, 5
	adds r0, r7, r0
	lsls r1, r4, 3
	adds r1, 0x4
	lsls r1, 5
	add r1, r8
	movs r2, 0x40
	bl CpuSet
	adds r0, r4, 0x1
	lsls r0, 24
	lsrs r4, r0, 24
	cmp r4, r6
	bcc _0804B010
_0804B042:
	add sp, 0x4
	pop {r3-r5}
	mov r8, r3
	mov r9, r4
	mov r10, r5
	pop {r4-r7}
	pop {r0}
	bx r0
	.align 2, 0
_0804B054: .4byte gTileBuffer
	thumb_func_end sub_804AFB8

	.align 2, 0 @ Don't pad with nop.
