MauvilleCity_GameCorner_MapScripts:: @ 8156A33
	.byte 0

MauvilleCity_GameCorner_EventScript_156A34:: @ 8156A34
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_181C35, 4
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156B32
	message MauvilleCity_GameCorner_Text_181CB4
	waitmessage
	showmoneybox 0, 0
	nop
	showcoinsbox 0, 5
	goto MauvilleCity_GameCorner_EventScript_156A60

MauvilleCity_GameCorner_EventScript_156A60:: @ 8156A60
	multichoicedefault 15, 0, 49, 0, 0
	switch RESULT
	case 0, MauvilleCity_GameCorner_EventScript_156AAE
	case 1, MauvilleCity_GameCorner_EventScript_156AF0
	goto MauvilleCity_GameCorner_EventScript_156B4C
	end

@ 8156A87
	multichoicedefault 15, 0, 49, 1, 0
	switch RESULT
	case 0, MauvilleCity_GameCorner_EventScript_156AAE
	case 1, MauvilleCity_GameCorner_EventScript_156AF0
	goto MauvilleCity_GameCorner_EventScript_156B4C
	end

MauvilleCity_GameCorner_EventScript_156AAE:: @ 8156AAE
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, 9950
	goto_if_ge MauvilleCity_GameCorner_EventScript_156B5C
	checkmoney 0x3e8, 0
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156B3C
	givecoins 50
	takemoney 0x3e8, 0
	updatemoneybox 0, 0
	nop
	updatecoinsbox 0, 5
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181CFE, 4
	hidemoneybox 0, 0
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156AF0:: @ 8156AF0
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, 9500
	goto_if_ge MauvilleCity_GameCorner_EventScript_156B5C
	checkmoney 0x2710, 0
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156B3C
	givecoins 500
	takemoney 0x2710, 0
	updatemoneybox 0, 0
	nop
	updatecoinsbox 0, 5
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181CFE, 4
	hidemoneybox 0, 0
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156B32:: @ 8156B32
	msgbox MauvilleCity_GameCorner_Text_181C53, 4
	release
	end

MauvilleCity_GameCorner_EventScript_156B3C:: @ 8156B3C
	msgbox MauvilleCity_GameCorner_Text_181D28, 4
	hidemoneybox 0, 0
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156B4C:: @ 8156B4C
	msgbox MauvilleCity_GameCorner_Text_181D73, 4
	hidemoneybox 0, 0
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156B5C:: @ 8156B5C
	msgbox MauvilleCity_GameCorner_Text_181D57, 4
	hidemoneybox 0, 0
	hidecoinsbox 0, 5
	release
	end

MauvilleCity_GameCorner_EventScript_156B6C:: @ 8156B6C
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_181DE1, 4
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_156B88
	release
	end

MauvilleCity_GameCorner_EventScript_156B88:: @ 8156B88
	message MauvilleCity_GameCorner_Text_181E17
	waitmessage
	showcoinsbox 0, 0
	setvar VAR_TEMP_1, 0
	goto MauvilleCity_GameCorner_EventScript_156BA6

MauvilleCity_GameCorner_EventScript_156B9B:: @ 8156B9B
	message MauvilleCity_GameCorner_Text_181E17
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_156BA6

MauvilleCity_GameCorner_EventScript_156BA6:: @ 8156BA6
	multichoice 12, 0, 48, 0
	switch RESULT
	case 0, MauvilleCity_GameCorner_EventScript_156BE2
	case 1, MauvilleCity_GameCorner_EventScript_156BF0
	case 2, MauvilleCity_GameCorner_EventScript_156BFE
	case 3, MauvilleCity_GameCorner_EventScript_156D0D
	goto MauvilleCity_GameCorner_EventScript_156D0D
	end

MauvilleCity_GameCorner_EventScript_156BE2:: @ 8156BE2
	setvar VAR_TEMP_1, 1
	bufferdecorationname 0, 88
	goto MauvilleCity_GameCorner_EventScript_156C0C

MauvilleCity_GameCorner_EventScript_156BF0:: @ 8156BF0
	setvar VAR_TEMP_1, 2
	bufferdecorationname 0, 89
	goto MauvilleCity_GameCorner_EventScript_156C0C

MauvilleCity_GameCorner_EventScript_156BFE:: @ 8156BFE
	setvar VAR_TEMP_1, 3
	bufferdecorationname 0, 90
	goto MauvilleCity_GameCorner_EventScript_156C0C

MauvilleCity_GameCorner_EventScript_156C0C:: @ 8156C0C
	msgbox MauvilleCity_GameCorner_Text_181E33, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_156D0D
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_156C46
	case 2, MauvilleCity_GameCorner_EventScript_156C80
	case 3, MauvilleCity_GameCorner_EventScript_156CBA
	end

MauvilleCity_GameCorner_EventScript_156C46:: @ 8156C46
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 1000
	goto_if_lt MauvilleCity_GameCorner_EventScript_156CF4
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156D02
	takecoins 1000
	givedecoration DECOR_TREECKO_DOLL
	updatecoinsbox 0, 0
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181E49, 4
	goto MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156C80:: @ 8156C80
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 1000
	goto_if_lt MauvilleCity_GameCorner_EventScript_156CF4
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156D02
	takecoins 1000
	givedecoration DECOR_TORCHIC_DOLL
	updatecoinsbox 0, 0
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181E49, 4
	goto MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156CBA:: @ 8156CBA
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 1000
	goto_if_lt MauvilleCity_GameCorner_EventScript_156CF4
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156D02
	takecoins 1000
	givedecoration DECOR_MUDKIP_DOLL
	updatecoinsbox 0, 0
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181E49, 4
	goto MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156CF4:: @ 8156CF4
	msgbox MauvilleCity_GameCorner_Text_181E76, 4
	goto MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156D02:: @ 8156D02
	call MauvilleCity_GameCorner_EventScript_1A02B8
	goto MauvilleCity_GameCorner_EventScript_156B9B
	end

MauvilleCity_GameCorner_EventScript_156D0D:: @ 8156D0D
	msgbox MauvilleCity_GameCorner_Text_181EC2, 4
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_156D1A:: @ 8156D1A
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_181DE1, 4
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_156D36
	release
	end

MauvilleCity_GameCorner_EventScript_156D36:: @ 8156D36
	message MauvilleCity_GameCorner_Text_181E17
	waitmessage
	showcoinsbox 0, 0
	setvar VAR_TEMP_1, 0
	goto MauvilleCity_GameCorner_EventScript_156D54

MauvilleCity_GameCorner_EventScript_156D49:: @ 8156D49
	message MauvilleCity_GameCorner_Text_181E17
	waitmessage
	goto MauvilleCity_GameCorner_EventScript_156D54

MauvilleCity_GameCorner_EventScript_156D54:: @ 8156D54
	multichoice 12, 0, 55, 0
	switch RESULT
	case 0, MauvilleCity_GameCorner_EventScript_156DA6
	case 1, MauvilleCity_GameCorner_EventScript_156DB4
	case 2, MauvilleCity_GameCorner_EventScript_156DC2
	case 3, MauvilleCity_GameCorner_EventScript_156DD0
	case 4, MauvilleCity_GameCorner_EventScript_156DDE
	case 5, MauvilleCity_GameCorner_EventScript_156F77
	goto MauvilleCity_GameCorner_EventScript_156F77
	end

MauvilleCity_GameCorner_EventScript_156DA6:: @ 8156DA6
	setvar VAR_TEMP_1, 1
	bufferitemname 0, ITEM_TM32_DRAIN_PUNCH
    checkitem ITEM_TM32_DRAIN_PUNCH, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156DEC
    goto MauvilleCity_GameCorner_EventScript_AlreadyHaveTM

MauvilleCity_GameCorner_EventScript_156DB4:: @ 8156DB4
	setvar VAR_TEMP_1, 2
	bufferitemname 0, ITEM_TM54_FIRE_PUNCH
    checkitem ITEM_TM54_FIRE_PUNCH, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156DEC
    goto MauvilleCity_GameCorner_EventScript_AlreadyHaveTM

MauvilleCity_GameCorner_EventScript_156DC2:: @ 8156DC2
	setvar VAR_TEMP_1, 3
	bufferitemname 0, ITEM_TM55_ICE_PUNCH
    checkitem ITEM_TM55_ICE_PUNCH, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156DEC
    goto MauvilleCity_GameCorner_EventScript_AlreadyHaveTM

MauvilleCity_GameCorner_EventScript_156DD0:: @ 8156DD0
	setvar VAR_TEMP_1, 4
	bufferitemname 0, ITEM_TM56_THUNDER_PUNCH
    checkitem ITEM_TM56_THUNDER_PUNCH, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156DEC
    goto MauvilleCity_GameCorner_EventScript_AlreadyHaveTM

MauvilleCity_GameCorner_EventScript_156DDE:: @ 8156DDE
	setvar VAR_TEMP_1, 5
	bufferitemname 0, ITEM_TM90_SUBSTITUTE
    checkitem ITEM_TM90_SUBSTITUTE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156DEC
    goto MauvilleCity_GameCorner_EventScript_AlreadyHaveTM

MauvilleCity_GameCorner_EventScript_AlreadyHaveTM::
    msgbox MauvilleCity_GameCorner_Text_AlreadyHaveTM, 4
    goto MauvilleCity_GameCorner_EventScript_156D49

MauvilleCity_GameCorner_EventScript_156DEC:: @ 8156DEC
	msgbox MauvilleCity_GameCorner_Text_181E33, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_156F77
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_156E3C
	case 2, MauvilleCity_GameCorner_EventScript_156E76
	case 3, MauvilleCity_GameCorner_EventScript_156EB0
	case 4, MauvilleCity_GameCorner_EventScript_156EEA
	case 5, MauvilleCity_GameCorner_EventScript_156F24
	end

MauvilleCity_GameCorner_EventScript_156E3C:: @ 8156E3C
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 2500
	goto_if_lt MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM32_DRAIN_PUNCH, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156F6C
	takecoins 2500
	giveitem ITEM_TM32_DRAIN_PUNCH, 1
	updatecoinsbox 0, 0
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	goto MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156E76:: @ 8156E76
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 2500
	goto_if_lt MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM54_FIRE_PUNCH, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156F6C
	takecoins 2500
	giveitem ITEM_TM54_FIRE_PUNCH, 1
	updatecoinsbox 0, 0
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	goto MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156EB0:: @ 8156EB0
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 2500
	goto_if_lt MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM55_ICE_PUNCH, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156F6C
	takecoins 2500
	giveitem ITEM_TM55_ICE_PUNCH, 1
	updatecoinsbox 0, 0
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	goto MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156EEA:: @ 8156EEA
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 2500
	goto_if_lt MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM56_THUNDER_PUNCH, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156F6C
	takecoins 2500
	giveitem ITEM_TM56_THUNDER_PUNCH, 1
	updatecoinsbox 0, 0
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	goto MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156F24:: @ 8156F24
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 9950
	goto_if_lt MauvilleCity_GameCorner_EventScript_156F5E
	checkitemspace ITEM_TM90_SUBSTITUTE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_156F6C
	takecoins 9950
	giveitem ITEM_TM90_SUBSTITUTE, 1
	updatecoinsbox 0, 0
	playse SE_REGI
	msgbox MauvilleCity_GameCorner_Text_181F08, 4
	goto MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156F5E:: @ 8156F5E
	msgbox MauvilleCity_GameCorner_Text_181E76, 4
	goto MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156F6C:: @ 8156F6C
	call MauvilleCity_GameCorner_EventScript_1A02A5
	goto MauvilleCity_GameCorner_EventScript_156D49
	end

MauvilleCity_GameCorner_EventScript_156F77:: @ 8156F77
	msgbox MauvilleCity_GameCorner_Text_181EC2, 4
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_156F84:: @ 8156F84
	msgbox MauvilleCity_GameCorner_Text_1821C1, 2
	end

MauvilleCity_GameCorner_EventScript_156F8D:: @ 8156F8D
	msgbox MauvilleCity_GameCorner_Text_1821F3, 2
	end

MauvilleCity_GameCorner_EventScript_156F96:: @ 8156F96
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_STARTER_DOLL, MauvilleCity_GameCorner_EventScript_157072
	msgbox MauvilleCity_GameCorner_Text_181F3D, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_157068
	switch VAR_STARTER_MON
	case 0, MauvilleCity_GameCorner_EventScript_156FDB
	case 1, MauvilleCity_GameCorner_EventScript_157005
	case 2, MauvilleCity_GameCorner_EventScript_15702F
	end

MauvilleCity_GameCorner_EventScript_156FDB:: @ 8156FDB
	bufferdecorationname 1, DECOR_TREECKO_DOLL
	checkdecorspace DECOR_TREECKO_DOLL
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_157059
	msgbox MauvilleCity_GameCorner_Text_181F89, 4
	givedecoration_std DECOR_TREECKO_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_157072
	end

MauvilleCity_GameCorner_EventScript_157005:: @ 8157005
	bufferdecorationname 1, DECOR_TORCHIC_DOLL
	checkdecorspace DECOR_TORCHIC_DOLL
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_157059
	msgbox MauvilleCity_GameCorner_Text_181F89, 4
	givedecoration_std DECOR_TORCHIC_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_157072
	end

MauvilleCity_GameCorner_EventScript_15702F:: @ 815702F
	bufferdecorationname 1, DECOR_MUDKIP_DOLL
	checkdecorspace DECOR_MUDKIP_DOLL
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_157059
	msgbox MauvilleCity_GameCorner_Text_181F89, 4
	givedecoration_std DECOR_MUDKIP_DOLL
	setflag FLAG_RECEIVED_STARTER_DOLL
	goto MauvilleCity_GameCorner_EventScript_157072
	end

MauvilleCity_GameCorner_EventScript_157059:: @ 8157059
	call MauvilleCity_GameCorner_EventScript_1A02B8
	msgbox MauvilleCity_GameCorner_Text_181F97, 4
	release
	end

MauvilleCity_GameCorner_EventScript_157068:: @ 8157068
	msgbox MauvilleCity_GameCorner_Text_181FBC, 4
	release
	end

MauvilleCity_GameCorner_EventScript_157072:: @ 8157072
	msgbox MauvilleCity_GameCorner_Text_181FE9, 4
	release
	end

MauvilleCity_GameCorner_EventScript_15707C:: @ 815707C
	lock
	faceplayer
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_15709C
	msgbox MauvilleCity_GameCorner_Text_18201E, 4
	goto MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_15709C:: @ 815709C
	goto_if_set FLAG_RECEIVED_20_COINS, MauvilleCity_GameCorner_EventScript_1570CA
	checkcoins VAR_TEMP_1
	compare VAR_TEMP_1, 1
	goto_if_ge MauvilleCity_GameCorner_EventScript_1570CA
	setflag FLAG_RECEIVED_20_COINS
	givecoins 20
	msgbox MauvilleCity_GameCorner_Text_18208E, 4
	playse SE_REGI
	goto MauvilleCity_GameCorner_EventScript_1570CA
	end

MauvilleCity_GameCorner_EventScript_1570CA:: @ 81570CA
	msgbox MauvilleCity_GameCorner_Text_1820DD, 4
	goto MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_1570D8:: @ 81570D8
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_182120, 4
	goto MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_1570E8:: @ 81570E8
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_18217C, 4
	goto MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_1570F8:: @ 81570F8
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_182241, 4
	goto MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_157108:: @ 8157108
	closemessage
	applymovement LAST_TALKED, MauvilleCity_GameCorner_Movement_1A083D
	waitmovement 0
	release
	end

MauvilleCity_GameCorner_EventScript_157115:: @ 8157115
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_182272, 4
	goto MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_157125:: @ 8157125
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_1822F4, 4
	goto MauvilleCity_GameCorner_EventScript_157108
	end

MauvilleCity_GameCorner_EventScript_157135:: @ 8157135
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 0
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157155:: @ 8157155
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 1
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157175:: @ 8157175
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 2
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157195:: @ 8157195
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 3
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_1571B5:: @ 81571B5
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 4
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_1571D5:: @ 81571D5
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 5
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_1571F5:: @ 81571F5
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 6
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157215:: @ 8157215
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 7
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157235:: @ 8157235
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 8
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157255:: @ 8157255
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 9
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157275:: @ 8157275
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 10
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_157295:: @ 8157295
	lockall
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 0
	goto_if_eq MauvilleCity_GameCorner_EventScript_1572B5
	setvar VAR_SPECIAL_4, 11
	specialvar RESULT, GetSlotMachineId
	playslotmachine RESULT
	releaseall
	end

MauvilleCity_GameCorner_EventScript_1572B5:: @ 81572B5
	msgbox MauvilleCity_GameCorner_Text_182420, 4
	releaseall
	end

MauvilleCity_GameCorner_EventScript_MonPrizesStart::
	lock
	faceplayer
	msgbox MauvilleCity_GameCorner_Text_181DE1, 4
	checkitem ITEM_COIN_CASE, 1
	compare RESULT, 1
	goto_if_eq MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst
	release
	end

MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst:
	message MauvilleCity_GameCorner_Text_181E17
	waitmessage
	showcoinsbox 0, 0
	setvar VAR_TEMP_1, 0
	goto MauvilleCity_GameCorner_EventScript_MonPrizes

MauvilleCity_GameCorner_EventScript_MonPrizes:
    multichoice 12, 0, 73, 0
    switch RESULT
	case 0, MauvilleCity_GameCorner_EventScript_MeowthConfirm
	case 1, MauvilleCity_GameCorner_EventScript_SphealConfirm
	case 2, MauvilleCity_GameCorner_EventScript_JigglypuffConfirm
	case 3, MauvilleCity_GameCorner_EventScript_EeveeConfirm
	case 4, MauvilleCity_GameCorner_EventScript_PorygonConfirm
	goto MauvilleCity_GameCorner_EventScript_156D0D
	end
    
MauvilleCity_GameCorner_EventScript_MeowthConfirm:
	setvar VAR_TEMP_1, 1
    bufferspeciesname 0, SPECIES_MEOWTH
	goto MauvilleCity_GameCorner_EventScript_MonConfirm
    
MauvilleCity_GameCorner_EventScript_SphealConfirm:
	setvar VAR_TEMP_1, 2
    bufferspeciesname 0, SPECIES_SPHEAL
	goto MauvilleCity_GameCorner_EventScript_MonConfirm
    
MauvilleCity_GameCorner_EventScript_JigglypuffConfirm:
	setvar VAR_TEMP_1, 3
    bufferspeciesname 0, SPECIES_JIGGLYPUFF
	goto MauvilleCity_GameCorner_EventScript_MonConfirm
    
MauvilleCity_GameCorner_EventScript_EeveeConfirm:
	setvar VAR_TEMP_1, 4
    bufferspeciesname 0, SPECIES_EEVEE
	goto MauvilleCity_GameCorner_EventScript_MonConfirm
    
MauvilleCity_GameCorner_EventScript_PorygonConfirm:
	setvar VAR_TEMP_1, 5
    bufferspeciesname 0, SPECIES_PORYGON
	goto MauvilleCity_GameCorner_EventScript_MonConfirm

MauvilleCity_GameCorner_EventScript_MonConfirm:
	msgbox MauvilleCity_GameCorner_Text_181E33, MSGBOX_YESNO
	compare RESULT, NO
	goto_if_eq MauvilleCity_GameCorner_EventScript_156F77
	switch VAR_TEMP_1
	case 1, MauvilleCity_GameCorner_EventScript_Meowth
	case 2, MauvilleCity_GameCorner_EventScript_Spheal
	case 3, MauvilleCity_GameCorner_EventScript_Jigglypuff
	case 4, MauvilleCity_GameCorner_EventScript_Eevee
	case 5, MauvilleCity_GameCorner_EventScript_Porygon
	end
    
MauvilleCity_GameCorner_EventScript_Meowth:
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 120
	goto_if_lt MauvilleCity_GameCorner_EventScript_NoCoinsForMon
	getpartysize
	copyvar VAR_SPECIAL_4, RESULT
	takecoins 120
	updatecoinsbox 0, 0
	playse SE_REGI
    waitse
    setvar VAR_SPECIAL_3, SPECIES_MEOWTH
    bufferspeciesname 0, SPECIES_MEOWTH
	givemon SPECIES_MEOWTH, 18, ITEM_NONE, 0x0, 0x0, 0
    goto MauvilleCity_GameCorner_EventScript_GiveMonMerge
    
MauvilleCity_GameCorner_EventScript_Spheal:
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 520
	goto_if_lt MauvilleCity_GameCorner_EventScript_NoCoinsForMon
	getpartysize
	copyvar VAR_SPECIAL_4, RESULT
	takecoins 520
	updatecoinsbox 0, 0
	playse SE_REGI
    waitse
    setvar VAR_SPECIAL_3, SPECIES_SPHEAL
    bufferspeciesname 0, SPECIES_SPHEAL
	givemon SPECIES_SPHEAL, 19, ITEM_NONE, 0x0, 0x0, 0
    goto MauvilleCity_GameCorner_EventScript_GiveMonMerge
    
MauvilleCity_GameCorner_EventScript_Jigglypuff:
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 1030
	goto_if_lt MauvilleCity_GameCorner_EventScript_NoCoinsForMon
	getpartysize
	copyvar VAR_SPECIAL_4, RESULT
	takecoins 1030
	updatecoinsbox 0, 0
	playse SE_REGI
    waitse
    setvar VAR_SPECIAL_3, SPECIES_JIGGLYPUFF
    bufferspeciesname 0, SPECIES_JIGGLYPUFF
	givemon SPECIES_JIGGLYPUFF, 20, ITEM_NONE, 0x0, 0x0, 0
    goto MauvilleCity_GameCorner_EventScript_GiveMonMerge
    
MauvilleCity_GameCorner_EventScript_Eevee:
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 2700
	goto_if_lt MauvilleCity_GameCorner_EventScript_NoCoinsForMon
	getpartysize
	copyvar VAR_SPECIAL_4, RESULT
	takecoins 2700
	updatecoinsbox 0, 0
	playse SE_REGI
    waitse
    setvar VAR_SPECIAL_3, SPECIES_EEVEE
    bufferspeciesname 0, SPECIES_EEVEE
	givemon SPECIES_EEVEE, 22, ITEM_NONE, 0x0, 0x0, 0
    goto MauvilleCity_GameCorner_EventScript_GiveMonMerge
    
MauvilleCity_GameCorner_EventScript_Porygon:
	checkcoins VAR_TEMP_2
	compare VAR_TEMP_2, 7777
	goto_if_lt MauvilleCity_GameCorner_EventScript_NoCoinsForMon
	getpartysize
	copyvar VAR_SPECIAL_4, RESULT
	takecoins 7777
	updatecoinsbox 0, 0
	playse SE_REGI
    waitse
    setvar VAR_SPECIAL_3, SPECIES_PORYGON
    bufferspeciesname 0, SPECIES_PORYGON
	givemon SPECIES_PORYGON, 25, ITEM_NONE, 0x0, 0x0, 0
    goto MauvilleCity_GameCorner_EventScript_GiveMonMerge

MauvilleCity_GameCorner_EventScript_GiveMonMerge::
    compare RESULT, 0
    goto_if_eq MauvilleCity_GameCorner_EventScript_GiveMonParty
    compare RESULT, 1
    goto_if_eq MauvilleCity_GameCorner_EventScript_GiveMonPC
    release
    end

MauvilleCity_GameCorner_EventScript_GiveMonParty::
    call MauvilleCity_GameCorner_EventScript_GiftMonFanfare
    msgbox CommonText_NicknameRecievedPokemon, MSGBOX_YESNO
    compare RESULT, NO
    goto_if_eq MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst
    call Common_EventScript_NameRecievedPartyMon
    goto MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst

MauvilleCity_GameCorner_EventScript_GiveMonPC::
    call MauvilleCity_GameCorner_EventScript_GiftMonFanfare
    msgbox CommonText_NicknameRecievedPokemon, MSGBOX_YESNO
    bufferspeciesname 1, VAR_SPECIAL_3
    compare RESULT, NO
    goto_if_eq MauvilleCity_GameCorner_EventScript_GiveMonSendToPC
    call Common_EventScript_NameReceivedBoxMon
    goto MauvilleCity_GameCorner_EventScript_GiveMonSendToPC

MauvilleCity_GameCorner_EventScript_GiveMonSendToPC::
    call Common_EventScript_TransferredToPC
    goto MauvilleCity_GameCorner_EventScript_MonPrizesStartFirst

MauvilleCity_GameCorner_EventScript_GiftMonFanfare::	
    playfanfare MUS_FANFA4
	message MauvilleCity_GameCorner_Text_GetMon
	waitfanfare
	waitmessage
    return

MauvilleCity_GameCorner_EventScript_NoRoom:
	msgbox MauvilleCity_GameCorner_Text_NoRoom, 4
	hidecoinsbox 0, 0
	release
	end

MauvilleCity_GameCorner_EventScript_NoCoinsForMon:
	msgbox MauvilleCity_GameCorner_Text_181E76, 4
	goto MauvilleCity_GameCorner_EventScript_MonPrizes
	end
