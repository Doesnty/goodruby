VerdanturfTown_Mart_EventObjects:: @ 8386B70
	object_event 1, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 3, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, Common_EventScript_StandardMart, 0
	object_event 2, EVENT_OBJ_GFX_BOY_2, 0, 5, 4, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, VerdanturfTown_Mart_EventScript_153EEE, 0
	object_event 3, EVENT_OBJ_GFX_OLD_WOMAN_1, 0, 8, 5, 3, MOVEMENT_TYPE_FACE_LEFT, 0, 0, 0, 0, VerdanturfTown_Mart_EventScript_153EF7, 0
	object_event 4, EVENT_OBJ_GFX_LASS, 0, 1, 5, 3, MOVEMENT_TYPE_FACE_UP, 1, 1, 0, 0, VerdanturfTown_Mart_EventScript_153F00, 0
	object_event 5, EVENT_OBJ_GFX_MART_EMPLOYEE, 0, 1, 2, 3, MOVEMENT_TYPE_FACE_RIGHT, 0, 0, 0, 0, VerdanturfTown_Mart_EventScript_153EBC, 0

VerdanturfTown_Mart_MapWarps:: @ 8386BD0
	warp_def 3, 7, 0, 1, MAP_VERDANTURF_TOWN
	warp_def 4, 7, 0, 1, MAP_VERDANTURF_TOWN

VerdanturfTown_Mart_MapEvents:: @ 8386BE0
	map_events VerdanturfTown_Mart_EventObjects, VerdanturfTown_Mart_MapWarps, 0x0, 0x0
