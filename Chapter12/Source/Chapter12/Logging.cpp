#include "Chapter12.h"
#include "Logging.h"

DEFINE_LOG_CATEGORY( LogCh12 );

FName LoggerName( "LogChapter12" );

void CreateLogger( FName logName )
{
  FMessageLogModule& MessageLogModule = FModuleManager::LoadModuleChecked<FMessageLogModule>("MessageLog");
  FMessageLogInitializationOptions InitOptions;
  InitOptions.bShowPages = true;
  InitOptions.bShowFilters = true;
  FText LogListingName = FTEXTS( "Chapter 12's Log Listing" );
  MessageLogModule.RegisterLogListing( logName, LogListingName, InitOptions );
  
  // Create it. It gets cached inside the FMessageLog object, so there's
  // no need to retain a local copy of the variable inside your codebase.
  FMessageLog logger = FMessageLog( logName );
  logger.NewPage( LogListingName );
  logger.Info( FTEXTS( "an info message" ) );
  logger.Warning( FTEXTS( "a warning message" ) );
  
  // You can also retrieve your FMessageLog object from FMessageLog() ctor
  FMessageLog( logName ).Error( FTEXTS( "an error message" ) );
}

void Error( FString msg )
{
  FMessageLog( LoggerName ).Error( FText::FromString( msg ) );
}

void Warning( FString msg )
{
  FMessageLog( LoggerName ).Warning( FText::FromString( msg ) );
}

void Info( FString msg )
{
  FMessageLog( LoggerName ).Info( FText::FromString( msg ) );
}