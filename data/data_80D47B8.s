	.section .rodata

@ START code_80130A8


	.global gUnknown_80D48A0
gUnknown_80D48A0: @ 80D48A0
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00

	.global gUnknown_80D48AC
gUnknown_80D48AC: @ 80D48AC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D48C4
gUnknown_80D48C4: @ 80D48C4
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0f, 0x00
        .byte 0x1a, 0x00, 0x05, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D48DC
gUnknown_80D48DC: @ 80D48DC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x08, 0x00
        .byte 0x1a, 0x00, 0x05, 0x00
        .byte 0x07, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_80D48F4
gUnknown_80D48F4: @ 80D48F4
        .byte 0x3A, 0x20, 0x00, 0x00 @ maybe just a colon and space

	.global gUnknown_80D48F8
gUnknown_80D48F8: @ 80D48F8
        .string "????\0"
        .align 2,0

	.global gUnknown_80D4900
gUnknown_80D4900: @ 80D4900
        .string "%d\0"
        .align 2,0

	.global gUnknown_80D4904
gUnknown_80D4904: @ 80D4904
        .string "%*d\0"
        .align 2,0

	.global gUnknown_80D4908
gUnknown_80D4908: @ 80D4908
        .string "%0*d\0"
        .align 2,0

	.global gUnknown_80D4910
gUnknown_80D4910: @ 80D4910
        .string "$\0"

@ END code_80130A8
