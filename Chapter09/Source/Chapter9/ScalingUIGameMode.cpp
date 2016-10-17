// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter9.h"
#include "ScalingUIGameMode.h"
#include "ScalingUIPlayerController.h"
#include "CustomHUD.h"



AScalingUIGameMode::AScalingUIGameMode()
	:AGameMode()
{
	HUDClass = ACustomHUD::StaticClass();
	PlayerControllerClass = AScalingUIPlayerController::StaticClass();
}
