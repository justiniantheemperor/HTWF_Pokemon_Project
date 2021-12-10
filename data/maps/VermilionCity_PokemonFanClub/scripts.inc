.equ LOCALID_SILPH_SCOPE, 2

VermilionCity_PokemonFanClub_MapScripts:: @ 816B47E
	.byte 0


FinalInterview::
	lock
	call WalktoTable_Script
	waitmovement 0
	textcolor 0
	msgbox InterviewPt1
	textcolor 2
	msgbox GiveResume
	textcolor 0
	msgbox InterviewPt2
	trainerbattle_no_intro TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurDefeat
	msgbox PostBattle1
	call AbbyWalkIn_Script
	release
	end

WalktoTable_Script::
	applymovement OBJ_EVENT_ID_PLAYER, WalktoTable
	waitmovement 0
	return

WalktoTable:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_fast_up
	step_end

SSAnne_1F_Room5_EventScript_Arthur:: @ 8160C67
	trainerbattle_single TRAINER_GENTLEMAN_ARTHUR, SSAnne_1F_Room5_Text_ArthurIntro, SSAnne_1F_Room5_Text_ArthurDefeat
	msgbox SSAnne_1F_Room5_Text_ArthurPostBattle, MSGBOX_AUTOCLOSE
	return

AbbyWalkIn_Script::
	playse SE_DOOR
	addobject LOCALID_SILPH_SCOPE
	clearflag FLAG_HIDE_SILPH_SCOPE
	call AbbyWalktoDad_Script
	waitmovement 0
	textcolor 1
	msgbox AbbySpeak
	compare VAR_MAP_SCENE_ROUTE24, 0
	goto_if_eq FailInterview
	compare VAR_MAP_SCENE_ROUTE24, 1
	goto_if_eq WinInterview
	return


AbbyWalktoDad_Script::
	applymovement LOCALID_SILPH_SCOPE, WalktoDad
	waitmovement 0
	return

WalktoDad:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_left
	jump_2_left
	step_end

FailInterview::
	textcolor 1
	msgbox IknowYou
	textcolor 0
	msgbox Failed
	release
	end

WinInterview::
	textcolor 1
	msgbox HiPlayer
	textcolor 0
	msgbox Succeed
	fadescreenspeed FADE_TO_BLACK, 24
	special EnterHallOfFame
	release
	end
