.equ LOCALID_GIOVANNI,    13
.equ LOCALID_OLD_DYING_MAN,  14

CeladonCity_DepartmentStore_4F_MapScripts:: 
	map_script MAP_SCRIPT_ON_LOAD, RocketHideout_B4F_OnLoad
	.byte 0

RocketHideout_B4F_EventScript_Giovanni:: @ 8161317
	lock
	faceplayer
	message RocketHideout_B4F_Text_GiovanniIntro
	waitmessage
	playbgm MUS_ENCOUNTER_ROCKET, 0
	waitbuttonpress
	trainerbattle_no_intro TRAINER_BOSS_GIOVANNI, RocketHideout_B4F_Text_GiovanniDefeat
	msgbox RocketHideout_B4F_Text_GiovanniPostBattle
	fadescreen FADE_TO_BLACK
	closemessage
	removeobject LOCALID_GIOVANNI
	removeobject LOCALID_OLD_DYING_MAN
	setflag FLAG_HIDE_CELADON_ROCKETS
	fadescreen FADE_FROM_BLACK
	release
	end

CeladonCity_DepartmentStore_4F_EventScript_OldDyingMan:: @ 816BBEF
	msgbox old_man_dying, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_Youngster:: @ 816BBF8
	msgbox CeladonCity_DepartmentStore_4F_Text_CanRunAwayWithPokeDoll, MSGBOX_NPC
	end

CeladonCity_DepartmentStore_4F_EventScript_FloorSign:: @ 816BC01
	msgbox CeladonCity_DepartmentStore_4F_Text_FloorSign, MSGBOX_SIGN
	end

CeladonCity_DepartmentStore_4F_EventScript_Clerk:: @ 816BC0A
	goto_if_questlog EventScript_ReleaseEnd
	lock
	faceplayer
	message Text_MayIHelpYou
	waitmessage
	pokemart CeladonCity_DepartmentStore_4F_Items
	msgbox Text_PleaseComeAgain
	release
	end

	.align 2
CeladonCity_DepartmentStore_4F_Items:: @ 816BC30
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_NONE
	release
	end

