.equ LOCALID_MIGUEL,  1

CeladonCity_DepartmentStore_3F_MapScripts:: @ 816BB84
	.byte 0

CeladonCity_Nerd_Script::
	lock
	textcolor 0
	msgbox Nerd_Hey
	call Nerd_WalktoPlayer_Script
	applymovement LOCALID_MIGUEL, Movement_WalkInPlaceFastestRight
	msgbox Nerd_Situation
	call MtMoon_B2F_EventScript_BattleMiguel
	release
	end

Nerd_WalktoPlayer_Script::
	applymovement OBJ_EVENT_ID_PLAYER, Nerd_WalktoPlayer
	waitmovement 0
	return

Nerd_WalktoPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

CeladonCity_DepartmentStore_3F_EventScript_CounterTutor:: @ 816BB85
	goto EventScript_CounterTutor
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid1:: @ 816BB8B
	msgbox CeladonCity_DepartmentStore_3F_Text_OTStandsForOriginalTrainer, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid2:: @ 816BB94
	msgbox CeladonCity_DepartmentStore_3F_Text_BuddyTradingKangaskhanForHaunter, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_GBAKid3:: @ 816BB9D
	msgbox CeladonCity_DepartmentStore_3F_Text_HaunterEvolvedOnTrade, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_LittleGirl:: @ 816BBA6
	msgbox CeladonCity_DepartmentStore_3F_Text_CanIdentifyTradeMonsByID, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_3F_EventScript_SuperNES:: @ 816BBAF
	msgbox CeladonCity_DepartmentStore_3F_Text_ItsSuperNES, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV1:: @ 816BBB8
	msgbox CeladonCity_DepartmentStore_3F_Text_AnRPG, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV2:: @ 816BBC1
	msgbox CeladonCity_DepartmentStore_3F_Text_SportsGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV3:: @ 816BBCA
	msgbox CeladonCity_DepartmentStore_3F_Text_PuzzleGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_TV4:: @ 816BBD3
	msgbox CeladonCity_DepartmentStore_3F_Text_FightingGame, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_FloorSign:: @ 816BBDC
	msgbox CeladonCity_DepartmentStore_3F_Text_TVGameShop, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_3F_EventScript_Poster:: @ 816BBE5
	msgbox CeladonCity_DepartmentStore_3F_Text_RedGreenBothArePokemon, MSGBOX_SIGN
	end
