// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/StaticMeshActor.h"
#include "Talker.h"
#include "TalkingMesh.generated.h"

/**
 * 
 */
UCLASS()
class CHAPTER7_API ATalkingMesh : public AStaticMeshActor, public ITalker
{
	GENERATED_BODY()
public:
		ATalkingMesh();
		void StartTalking_Implementation();
};
