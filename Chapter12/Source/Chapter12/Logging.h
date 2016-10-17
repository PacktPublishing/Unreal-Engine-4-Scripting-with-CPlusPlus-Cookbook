#pragma once

#include "MessageLog.h"
#include "Developer/MessageLog/Public/MessageLogModule.h"

// For use with UE_LOG
// Formats:
//   UE_LOG( LogCh12, Display, TEXT( "Your info message" ) );
//   UE_LOG( LogCh12, Warning, TEXT( "Your message %d" ), 2941 );
//   UE_LOG( LogCh12, Error, TEXT( "Your message %f" ), 190.4f );
DECLARE_LOG_CATEGORY_EXTERN( LogCh12, Log, All );

//#define LOCTEXT_NAMESPACE "Chapter12"
//#define FTEXT(x) LOCTEXT( x, x )
#define FTEXTS(x) FText::FromString( x )
#define FS(x,...) FString::Printf( TEXT( x ), __VA_ARGS__ )
extern FName LoggerName;

// Functions for logging
void CreateLogger( FName logName );
void Error( FString msg );
void Warning( FString msg );
void Info( FString msg );
