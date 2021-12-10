.equ LOCALID_GIOVANNI,    1
.equ LOCALID_SILPH_SCOPE, 2
.equ LOCALID_LIFT_KEY,    4


.equ NUM_DOOR_GRUNTS_DEFEATED, VAR_TEMP_1

RocketHideout_B4F_MapScripts:: @ 81612E8
	.byte 0


RocketHideout_B4F_OnLoad:: @ 81612EE
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_ne RocketHideout_B4F_EventScript_SetBarrier
	end

RocketHideout_B4F_EventScript_CountGruntDefeated:: @ 8161311
	addvar NUM_DOOR_GRUNTS_DEFEATED, 1
	return


RocketHideout_B4F_EventScript_SilphScope:: @ 8161363
	lock
	faceplayer
	removeobject LOCALID_SILPH_SCOPE
	giveitem ITEM_SILPH_SCOPE
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_BagIsFull
	release
	end

RocketHideout_B4F_EventScript_Grunt1:: @ 8161381
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_18, RocketHideout_B4F_Text_Grunt1Intro, RocketHideout_B4F_Text_Grunt1Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt1
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	release
	end

RocketHideout_B4F_EventScript_DefeatedGrunt1:: @ 816139D
	msgbox RocketHideout_B4F_Text_Grunt1PostBattle
	addobject LOCALID_LIFT_KEY
	clearflag FLAG_HIDE_LIFT_KEY
	release
	end

RocketHideout_B4F_EventScript_LiftKey:: @ 81613AD
	lock
	faceplayer
	setflag FLAG_CAN_USE_ROCKET_HIDEOUT_LIFT
	removeobject LOCALID_LIFT_KEY
	giveitem ITEM_LIFT_KEY
	compare VAR_RESULT, FALSE
	goto_if_eq EventScript_BagIsFull
	release
	end

RocketHideout_B4F_EventScript_Grunt2:: @ 81613CE
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_Text_Grunt2Intro, RocketHideout_B4F_Text_Grunt2Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt2
	msgbox RocketHideout_B4F_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_EventScript_DefeatedGrunt2:: @ 81613E9
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_Grunt3:: @ 8161418
	trainerbattle_single TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_Text_Grunt3Intro, RocketHideout_B4F_Text_Grunt3Defeat, RocketHideout_B4F_EventScript_DefeatedGrunt3
	msgbox RocketHideout_B4F_Text_Grunt3PostBattle, MSGBOX_AUTOCLOSE
	end

RocketHideout_B4F_EventScript_DefeatedGrunt3:: @ 8161433
	setvar NUM_DOOR_GRUNTS_DEFEATED, 0
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_16, RocketHideout_B4F_EventScript_CountGruntDefeated
	call_if_defeated TRAINER_TEAM_ROCKET_GRUNT_17, RocketHideout_B4F_EventScript_CountGruntDefeated
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_RemoveBarrier
	compare NUM_DOOR_GRUNTS_DEFEATED, 2
	call_if_eq RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval
	release
	end

RocketHideout_B4F_EventScript_DrawMapForBarrierRemoval:: @ 8161462
	playse SE_UNLOCK
	special DrawWholeMapView
	waitse
	return

RocketHideout_B4F_EventScript_SetBarrier:: @ 816146A
	setmetatile 17, 12, METATILE_SilphCo_HideoutBarrier_TopLeft_Floor, 1
	setmetatile 18, 12, METATILE_SilphCo_HideoutBarrier_TopRight_Floor, 1
	setmetatile 17, 13, METATILE_SilphCo_HideoutBarrier_BottomLeft, 1
	setmetatile 18, 13, METATILE_SilphCo_HideoutBarrier_BottomRight, 1
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	return

RocketHideout_B4F_EventScript_RemoveBarrier:: @ 81614A1
	setmetatile 17, 12, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 12, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 13, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 13, METATILE_SilphCo_HideoutFloor, 0
	setmetatile 17, 14, METATILE_SilphCo_HideoutFloor_ShadeFull, 0
	setmetatile 18, 14, METATILE_SilphCo_HideoutFloor, 0
	return
