// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter9.h"
#include "CustomHudPlayerController.h"
#include "SlateHUDGameMode.h"




ASlateHUDGameMode::ASlateHUDGameMode()
	:Super()
{
	PlayerControllerClass = ACustomHUDPlayerController::StaticClass();
}
