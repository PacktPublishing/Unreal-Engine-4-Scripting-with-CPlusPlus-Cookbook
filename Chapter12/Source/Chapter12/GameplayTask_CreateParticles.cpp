#include "Chapter12.h"
#include "GameplayTask_CreateParticles.h"
#include "Logging.h"

// Like a constructor.
UGameplayTask_CreateParticles* UGameplayTask_CreateParticles::ConstructTask(
  TScriptInterface<IGameplayTaskOwnerInterface> TaskOwner, 
  UParticleSystem* particleSystem,
  FVector location )
{
  UGameplayTask_CreateParticles* task = NewTask<UGameplayTask_CreateParticles>( TaskOwner );
  // Fill fields
  if( task )
  {
    task->ParticleSystem = particleSystem;
    task->Location = location;
  }
  return task;
}

void UGameplayTask_CreateParticles::Activate()
{
  Super::Activate();
  Info( "Created emitter" );
  UGameplayStatics::SpawnEmitterAtLocation( GetWorld(), 
    ParticleSystem, Location );
}


