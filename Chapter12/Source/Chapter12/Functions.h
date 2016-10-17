#pragma once

#include "GameFramework/Actor.h"

typedef FIntPoint /* as simply */ FIntVector2; // C++ type => ALIAS
typedef FIntVector /* as simply */ FIntVector3;


// Includes 0..max-1 (excludes max)
inline int randInt( int max )
{
	return FMath::Rand()%max;
}

// Includes min..max-1 (excludes max)
inline int randInt( int min, int max )
{
	return min + FMath::Rand()%( max - min );
}

// Rand between [0.f,1.f]
inline float randFloat()
{
  return FMath::FRand();
}

// Rand between [min,max]
inline float randFloat( float min, float max )
{
  return min + randFloat()*(max-min);
}

inline FVector randVec( const FVector& min, const FVector& max )
{
  FBox box( min, max );
  return FMath::RandPointInBox( box );
}

inline FIntVector2 operator%( const FIntVector2& a, const FIntVector2& b )
{
	return FIntVector2( a.X % b.X, a.Y % b.Y );
}

// Includes min..max-1 (excludes max)
inline FIntVector2 randInt( FIntVector2 min, FIntVector2 max )
{
	return min + FIntVector2( FMath::Rand(), FMath::Rand() )%( max - min );
}

template <typename T> T* GetActorsComponentByClass(AActor* actor)
{
  const TArray<UActorComponent*>& components = actor->GetComponents();
  for( int i = 0; i < components.Num(); i++ )
    if( T* comp = Cast< T >( components[i] ) )
      return comp;
  
  Warning( FS( "Actor %s has no components with class %s",
    *actor->GetName(), *T::StaticClass()->GetName() ) );
  return 0; // Not found
}

template <typename T> TArray<T*> GetActorsComponentsByClass(AActor* actor)
{
  TArray<T*> results;
  const TSet<UActorComponent*>& components = actor->GetComponents();
  for( UActorComponent* comp : components )
  {
    if( T* TComponent = Cast< T >( comp ) )
      results.Push( TComponent );
  }

  if( !results.Num() )
  {
    Warning( FS( "Actor %s has no components with class %s",
      *actor->GetName(), *T::StaticClass()->GetName() ) );
  }

  return results;
}