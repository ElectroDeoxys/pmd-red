        .section .rodata

	.global gUnknown_8106A4C
gUnknown_8106A4C: @ 8106A4C
        .4byte 0

	.global gUnknown_8106A50
gUnknown_8106A50: @ 8106A50
        .4byte 1

	.global gUnknown_8106A54
gUnknown_8106A54: @ 8106A54
	.incbin "baserom.gba", 0x106A54, 0x38

	.global gUnknown_8106A8C
gUnknown_8106A8C: @ 8106A8C
	.incbin "baserom.gba", 0x106A8C, 0x3C

	.global gUnknown_8106AC8
gUnknown_8106AC8: @ 8106AC8
	.incbin "baserom.gba", 0x106AC8, 0x20

	.global gUnknown_8106AE8
gUnknown_8106AE8: @ 8106AE8
        .byte 0x00, 0x00, 0x01, 0x00

	.global gUnknown_8106AEC
gUnknown_8106AEC: @ 8106AEC
	.incbin "baserom.gba", 0x106AEC, 0x64

	.global gUnknown_8106B50
gUnknown_8106B50: @ 8106B50
        .string "{COLOR_1}%c%s\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106B60
gUnknown_8106B60: @ 8106B60
        .byte 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x50, 0x00, 0x01, 0x00, 0x00, 0x00

	.global gUnknown_8106B6C
gUnknown_8106B6C: @ 8106B6C
	.incbin "baserom.gba", 0x106B6C, 0x20

	.global gUnknown_8106B8C
gUnknown_8106B8C: @ 8106B8C
	.incbin "baserom.gba", 0x106B8C, 0x24

	.global gUnknown_8106BB0
gUnknown_8106BB0: @ 8106BB0
        .string "$t\0"
        .align 2,0

@ Red Heart Symbols
	.global gUnknown_8106BB4
gUnknown_8106BB4: @ 8106BB4
        .byte 0x87, 0x46, 0x00, 0x00

	.global gUnknown_8106BB8
gUnknown_8106BB8: @ 8106BB8
        .byte 0x87, 0x47, 0x00, 0x00

	.global gUnknown_8106BBC
gUnknown_8106BBC: @ 8106BBC
        .byte 0x87, 0x48, 0x00, 0x00

	.global gUnknown_8106BC0
gUnknown_8106BC0: @ 8106BC0
        .byte 0x87, 0x49, 0x00, 0x00

@ Yellow Heart Symbols
	.global gUnknown_8106BC4
gUnknown_8106BC4: @ 8106BC4
        .byte 0x87, 0x4A, 0x00, 0x00

	.global gUnknown_8106BC8
gUnknown_8106BC8: @ 8106BC8
        .byte 0x87, 0x4B, 0x00, 0x00

	.global gUnknown_8106BCC
gUnknown_8106BCC: @ 8106BCC
        .byte 0x87, 0x4C, 0x00, 0x00

	.global gUnknown_8106BD0
gUnknown_8106BD0: @ 8106BD0
        .byte 0x87, 0x4D, 0x00, 0x00

	.global gUnknown_8106BD4
gUnknown_8106BD4: @ 8106BD4
        .byte 0x87, 0x42, 0x24, 0x6d, 0x30, 0x23, 0x3d, 0x59, 0x24, 0x6d, 0x31, 0x00

	.global gUnknown_8106BE0
gUnknown_8106BE0: @ 8106BE0
        .byte 0x87, 0x40, 0x24, 0x6d, 0x30, 0x23, 0x3d, 0x59, 0x24, 0x6d, 0x31, 0x00

	.global gUnknown_8106BEC
gUnknown_8106BEC: @ 8106BEC
        .byte 0x87, 0x42, 0x24, 0x6d, 0x30, 0x00, 0x00, 0x00

	.global gUnknown_8106BF4
gUnknown_8106BF4: @ 8106BF4
        .byte 0x87, 0x40, 0x24, 0x6d, 0x30, 0x00, 0x00, 0x00, 0x01, 0x00, 0x0f, 0x00

	.global gUnknown_8106C00
gUnknown_8106C00: @ 8106C00
        .byte 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x12, 0x00, 0x08, 0x00, 0x08, 0x00, 0x00, 0x00, 0xfc, 0x6b, 0x10, 0x08

	.global gUnknown_8106C18
gUnknown_8106C18: @ 8106C18
        .byte 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x12, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0xfc, 0x6b, 0x10, 0x08

	.global gUnknown_8106C30
gUnknown_8106C30: @ 8106C30
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x0e, 0x00, 0x02, 0x00
        .byte 0x0e, 0x00, 0x10, 0x00
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x70, 0xf2, 0x02, 0x02

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x02, 0x00
        .byte 0x0a, 0x00, 0x02, 0x00
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8106C90
gUnknown_8106C90: @ 8106C90
        .string "????\0"
        .align 2,0

	.global gUnknown_8106C98
gUnknown_8106C98: @ 8106C98
        .string "{ARG_MOVE_ITEM_0}\0"
        .align 2,0

	.global gUnknown_8106C9C
gUnknown_8106C9C: @ 8106C9C
        .string "None\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106CAC
gUnknown_8106CAC: @ 8106CAC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x02, 0x00, 0x0E, 0x00
        .byte 0x1A, 0x00, 0x03, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8106CC4
gUnknown_8106CC4: @ 8106CC4
        .string "{ARG_MOVE_ITEM_0}\0"
        .align 2,0

	.global gUnknown_8106CC8
gUnknown_8106CC8: @ 8106CC8
        .byte 0x01, 0x00, 0x10, 0x00

	.global gUnknown_8106CCC
gUnknown_8106CCC: @ 8106CCC
        .string "{ARG_POKEMON_0}\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106CE8
gUnknown_8106CE8: @ 8106CE8
        .byte 0x10, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00
        .byte 0x1b, 0x00, 0x00, 0x00

	.global gUnknown_8106CF4
gUnknown_8106CF4: @ 8106CF4
        .byte 0x13, 0x00, 0x00, 0x00
        .byte 0x11, 0x00, 0x00, 0x00
        .byte 0x19, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106D08
gUnknown_8106D08: @ 8106D08
        .byte 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x12, 0x00, 0x0e, 0x00, 0x12, 0x00, 0x02, 0x00, 0x3c, 0xb4, 0x03, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8106D68
gUnknown_8106D68: @ 8106D68
        .byte 0x01, 0x00, 0x38, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x02, 0x00, 0x38, 0x00, 0x68, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8106D8C
gUnknown_8106D8C: @ 8106D8C
        .string "{COLOR_2}%d{ARG_POKEMON_0}\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106DA4
gUnknown_8106DA4: @ 8106DA4
        .byte 0x01, 0x00, 0x38, 0x00, 0x00, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x02, 0x00, 0x38, 0x00, 0x68, 0x00, 0x18, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8106DC8
gUnknown_8106DC8: @ 8106DC8
        .byte 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x02, 0x00, 0x02, 0x00, 0x11, 0x00, 0x0e, 0x00, 0x12, 0x00, 0x02, 0x00, 0x08, 0xf3, 0x02, 0x02, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
        .byte 0x15, 0x00, 0x04, 0x00, 0x07, 0x00, 0x04, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8106E28
gUnknown_8106E28: @ 8106E28
        .string "{ARG_POKEMON_0}\0"
        .align 2,0

	.global gUnknown_8106E2C
gUnknown_8106E2C: @ 8106E2C
        .byte 0x87, 0x42, 0x00, 0x00

	.global gUnknown_8106E30
gUnknown_8106E30: @ 8106E30
        .byte 0x87, 0x40, 0x00, 0x00

	.global gUnknown_8106E34
gUnknown_8106E34: @ 8106E34
        .string "{ARG_MOVE_ITEM_0}{COLOR_2 CYAN}$v02:{ARG_POKEMON_0}{END_COLOR_TEXT_2}\0"
        .align 2,0

	.global gUnknown_8106E48
gUnknown_8106E48: @ 8106E48
        .string "{ARG_MOVE_ITEM_0}{COLOR_2 YELLOW}$v02:{ARG_POKEMON_0}{END_COLOR_TEXT_2}\0"
        .align 2,0

	.global gUnknown_8106E5C
gUnknown_8106E5C: @ 8106E5C
        .string "Press {B_BUTTON}\n"
        .string "if OK.\0"
        .align 2,0

	.global gUnknown_8106E6C
gUnknown_8106E6C: @ 8106E6C
        .string "Say bye to\n"
        .string "$d0 more\0"
        .align 2,0

	.global gUnknown_8106E80
gUnknown_8106E80: @ 8106E80
        .byte 0x02, 0x00, 0x00, 0x00
        .byte 0x03, 0x00, 0x00, 0x00
        .byte 0x04, 0x00, 0x00, 0x00
        .byte 0x05, 0x00, 0x00, 0x00
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106E98
gUnknown_8106E98: @ 8106E98
        .string "palet\0"
        .align 2,0

	.global gUnknown_8106EA0
gUnknown_8106EA0: @ 8106EA0
        .string "ax%03d\0"
        .align 2,0

	.global gUnknown_8106EA8
gUnknown_8106EA8: @ 8106EA8
        .string "talkp%d\0"
        .align 2,0

	.global gUnknown_8106EB0
gUnknown_8106EB0: @ 8106EB0
        .string "talk%d\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0
        .string "pksdir0\0"
        .align 2,0

	.global gUnknown_8106EC8
gUnknown_8106EC8: @ 8106EC8
	.incbin "baserom.gba", 0x106EC8, 0x27

	.global gUnknown_8106EEF
gUnknown_8106EEF: @ 8106EEF
	.incbin "baserom.gba", 0x106EEF, 0xD

	.global gUnknown_8106EFC
gUnknown_8106EFC: @ 8106EFC
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x00, 0x00

	.global gUnknown_8106F04
gUnknown_8106F04: @ 8106F04
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x01, 0x00

	.global gUnknown_8106F0C
gUnknown_8106F0C: @ 8106F0C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x00, 0x02, 0x00

	.global gUnknown_8106F14
gUnknown_8106F14: @ 8106F14
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x80, 0x01, 0x00

	.global gUnknown_8106F1C
gUnknown_8106F1C: @ 8106F1C
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0x80, 0x00, 0x00

	.global gUnknown_8106F24
gUnknown_8106F24: @ 8106F24
	.incbin "baserom.gba", 0x106F24, 0x30

	.global gUnknown_8106F54
gUnknown_8106F54: @ 8106F54
        .byte 0x3C, 0x6F, 0x10, 0x08
        .byte 0x44, 0x6F, 0x10, 0x08
        .4byte gUnknown_8106F04
        .byte 0x4C, 0x6F, 0x10, 0x08

	.global gUnknown_8106F64
gUnknown_8106F64: @ 8106F64
        .byte 0x00, 0x00, 0x00, 0x00
        .byte 0x00, 0xC0, 0x00, 0x00
