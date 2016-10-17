// Fill out your copyright notice in the Description page of Project Settings.

#include "Chapter1.h"
#include "Chapter1GameMode.h"

AChapter1GameMode::AChapter1GameMode( const FObjectInitializer& PCIP ) : Super( PCIP )
{

}

void AChapter1GameMode::BeginPlay()
{
  Super::BeginPlay();

  // Basic UE_LOG message
  UE_LOG(LogTemp, Warning, TEXT("Some warning message") );
  
  // UE_LOG message with arguments
  int intVar = 5;
  float floatVar = 3.7f;
  FString fstringVar = "an fstring variable";
  UE_LOG(LogTemp, Warning, TEXT("Text, %d %f %s"), intVar, floatVar, *fstringVar );

  // FString::Printf() method
  FString name = "Tim";
  int32 mana = 450;
  FString string = FString::Printf( TEXT( "Name = %s Mana = %d" ), *name, mana );

  TArray< FStringFormatArg > args;
  args.Add( FStringFormatArg( name ) );
  args.Add( FStringFormatArg( mana ) );
  string = FString::Format( TEXT( "Name = {0} Mana = {1}" ), args );
  UE_LOG( LogTemp, Warning, TEXT( "Your string: %s" ), *string );
}


