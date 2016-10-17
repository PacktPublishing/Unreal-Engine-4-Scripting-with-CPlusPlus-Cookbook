// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter2.h"
#include "Chapter2GameMode.h"
#include "UserProfile.h"

AChapter2GameMode::AChapter2GameMode( const FObjectInitializer& PCIP ) : Super( PCIP )
{
  
}

void AChapter2GameMode::BeginPlay()
{
  AChapter2GameMode *gm = Cast<AChapter2GameMode>( GetWorld()->GetAuthGameMode() );

  if( gm )
  {
    // Using ConstructObject:
    UUserProfile* constructedobject = ConstructObject<UUserProfile>( UUserProfile::StaticClass() );

    // Using NewObject instead:
    UUserProfile* newobject = NewObject<UUserProfile>( GetTransientPackage(), UUserProfile::StaticClass() );
  }
}

