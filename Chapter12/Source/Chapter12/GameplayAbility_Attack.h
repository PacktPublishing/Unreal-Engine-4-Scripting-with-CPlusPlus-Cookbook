#pragma once

#include "Runtime/GameplayAbilities/Public/Abilities/GameplayAbility.h"
#include "Runtime/GameplayAbilities/Public/Abilities/Tasks/AbilityTask.h"

#include "GameplayAbility_Attack.generated.h"

UCLASS(Blueprintable,BlueprintType)
class CHAPTER12_API UGameplayAbility_Attack : public UGameplayAbility
{
	GENERATED_BODY()
public:
  UGameplayAbility_Attack( const FObjectInitializer& PCIP ) : Super( PCIP )
  {
    //NetExecutionPolicy = EGameplayAbilityNetExecutionPolicy::LocalPredicted;
    //InstancingPolicy = EGameplayAbilityInstancingPolicy::NonInstanced;
  }

  /** Returns true if this ability can be activated right now. Has no side effects */
	virtual bool CanActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayTagContainer* SourceTags = nullptr, const FGameplayTagContainer* TargetTags = nullptr, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CanActivateAbility!" ) );
    return true;
  }

	/** Returns true if this ability can be triggered right now. Has no side effects */
	virtual bool ShouldAbilityRespondToEvent(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayEventData* Payload) const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack ShouldAbilityRespondToEvent!" ) );
    return true;
  }
	
	/** Returns the time in seconds remaining on the currently active cooldown. */
	virtual float GetCooldownTimeRemaining(const FGameplayAbilityActorInfo* ActorInfo) const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack GetCooldownTimeRemaining!" ) );
    return 0.f;
  }

	/** Returns the time in seconds remaining on the currently active cooldown and the original duration for this cooldown. */
	virtual void GetCooldownTimeRemainingAndDuration(FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, float& TimeRemaining, float& CooldownDuration) const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack GetCooldownTimeRemainingAndDuration!" ) );
    TimeRemaining = 0.f;
    CooldownDuration = 1.f;
  }

	virtual const FGameplayTagContainer* GetCooldownTags() const {
    return Super::GetCooldownTags();
  }
	
  /** Called when the ability is given to an AbilitySystemComponent */
	virtual void OnGiveAbility(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack ability granted!" ) );
    Super::OnGiveAbility(ActorInfo, Spec);
  }

	/** Called when the avatar actor is set/changes */
	virtual void OnAvatarSet(const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilitySpec& Spec) {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack avatarset!" ) );
    Super::OnAvatarSet(ActorInfo, Spec);
  }
	
	// --------------------------------------
	//	IGameplayTaskOwnerInterface
	// --------------------------------------	
	/** setup additional properties if given task is an AbilityTask */
	//virtual void OnTaskInitialized(UGameplayTask& Task) override {
  //  UE_LOG( LogTemp, Warning, TEXT( "ability_attack OnTaskInitialized!" ) );
  //  Super::OnTaskInitialized(Task);
  //}
	/** Called by an ability task, originating from this ability, when it starts */
	//virtual void OnTaskActivated(UGameplayTask& Task) override {
  //  UE_LOG( LogTemp, Warning, TEXT( "ability_attack OnTaskActivated!" ) );
  //  Super::OnTaskActivated(Task);
  //}

	/** Called by an ability task, originating from this ability, when it ends */
	//virtual void OnTaskDeactivated(UGameplayTask& Task) override {
  //  UE_LOG( LogTemp, Warning, TEXT( "ability_attack OnTaskDeactivated!" ) );
  //  Super::OnTaskDeactivated(Task);
  //}

	virtual UGameplayTasksComponent* GetGameplayTasksComponent(const UGameplayTask& Task) const override {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack GetGameplayTasksComponent!" ) );
    return Super::GetGameplayTasksComponent(Task);
  }
	//virtual AActor* GetOwnerActor(const UGameplayTask* Task) const override{
  //  UE_LOG( LogTemp, Warning, TEXT( "ability_attack GetOwnerActor!" ) );
  //  return Super::GetOwnerActor(Task);
  //}
	//virtual AActor* GetAvatarActor(const UGameplayTask* Task) const override{
  //  UE_LOG( LogTemp, Warning, TEXT( "ability_attack GetAvatarActor!" ) );
  //  return Super::GetAvatarActor(Task);
  //}

	// --------------------------------------
	//	Input
	// --------------------------------------

	/** Input binding stub. */
	virtual void InputPressed(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack inputpressed!" ) );
    Super::InputPressed(Handle, ActorInfo, ActivationInfo);
  }

	/** Input binding stub. */
	virtual void InputReleased(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack inputreleased!" ) );
    Super::InputReleased(Handle, ActorInfo, ActivationInfo);
  }

	/** Destroys instanced-per-execution abilities. Instance-per-actor abilities should 'reset'. 
  Any active ability state tasks receive the 'OnAbilityStateInterrupted' event. 
  Non instance abilities - what can we do? */
	virtual void CancelAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateCancelAbility) {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CancelAbility!" ) );
    Super::CancelAbility(Handle, ActorInfo, ActivationInfo, bReplicateCancelAbility);
  }

  virtual void ActivateAbility( const FGameplayAbilitySpecHandle Handle, 
    const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, 
    const FGameplayEventData* TriggerEventData )
  {
    UE_LOG( LogTemp, Warning, TEXT( "Activating ugameplayability_attack().. swings weapon!" ) );
    Super::ActivateAbility( Handle, ActorInfo, ActivationInfo, TriggerEventData );
  }
  /** Called on a predictive ability when the server confirms its execution */
  virtual void ConfirmActivateSucceed(){
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack ConfirmActivateSucceed!" ) );
    Super::ConfirmActivateSucceed();
  }

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	virtual void SendGameplayEvent(FGameplayTag EventTag, FGameplayEventData Payload){
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack SendGameplayEvent!" ) );
    Super::SendGameplayEvent(EventTag, Payload);
  }

  virtual bool CommitAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo){
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CommitAbility!" ) );
    return Super::CommitAbility(Handle, ActorInfo, ActivationInfo);
  }
	virtual bool CommitAbilityCooldown(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const bool ForceCooldown){
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CommitAbilityCooldown!" ) );
    return Super::CommitAbilityCooldown(Handle, ActorInfo, ActivationInfo, ForceCooldown);
  }
	virtual bool CommitAbilityCost(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo){
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CommitAbilityCost!" ) );
    return Super::CommitAbilityCost(Handle, ActorInfo, ActivationInfo);
  }

	/**
	 * The last chance to fail before commiting
	 *	-This will usually be the same as CanActivateAbility. Some abilities may need to do extra checks here if they are consuming extra stuff in CommitExecute
	 */
	virtual bool CommitCheck(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo){
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CommitCheck!" ) );
    return Super::CommitCheck(Handle, ActorInfo, ActivationInfo);
  }

	/** Does the commit atomically (consume resources, do cooldowns, etc) */
	virtual void CommitExecute(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo){
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CommitExecute!" ) );
    Super::CommitExecute(Handle, ActorInfo, ActivationInfo);
  }

	/** Do boilerplate init stuff and then call ActivateAbility */
	virtual void PreActivate(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, FOnGameplayAbilityEnded::FDelegate* OnGameplayAbilityEndedDelegate){
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack PreActivate!" ) );
    Super::PreActivate(Handle, ActorInfo, ActivationInfo, OnGameplayAbilityEndedDelegate);
  }
/** Native function, called if an ability ends normally or abnormally. If bReplicate is set to true, try to replicate the ending to the client/server */
	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, bool bReplicateEndAbility) {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack EndAbility!" ) );
    Super::EndAbility(Handle, ActorInfo, ActivationInfo, bReplicateEndAbility);
  }

  /** Returns true if this ability can be canceled */
	virtual bool CanBeCanceled() const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CanBeCanceled!" ) );
    return Super::CanBeCanceled();
  }

	/** Sets whether the ability should ignore cancel requests. Only valid on instanced abilities */
	UFUNCTION(BlueprintCallable, Category=Ability)
	virtual void SetCanBeCanceled(bool bCanBeCanceled){
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack SetCanBeCanceled!" ) );
    Super::SetCanBeCanceled(bCanBeCanceled);
  }

	/** Returns true if this ability is blocking other abilities */
	virtual bool IsBlockingOtherAbilities() const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack IsBlockingOtherAbilities!" ) );
    //return false; // by default, no doesn't block other abilities
    return Super::IsBlockingOtherAbilities();
  }

	/** Sets rather ability block flags are enabled or disabled. Only valid on instanced abilities */
	virtual void SetShouldBlockOtherAbilities(bool bShouldBlockAbilities) {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack SetShouldBlockOtherAbilities!" ) );
    Super::SetShouldBlockOtherAbilities(bShouldBlockAbilities);
  }

	/** Returns the gameplay effect used to determine cooldown */
	virtual UGameplayEffect* GetCooldownGameplayEffect() const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack GetCooldownGameplayEffect!" ) );
    return Super::GetCooldownGameplayEffect();
  }

  /** Checks cooldown. returns true if we can be used again. False if not */
	virtual bool CheckCooldown(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CheckCooldown!" ) );
    return true;
    //return Super::CheckCooldown( Handle, ActorInfo, OptionalRelevantTags );
  }

	/** Applies CooldownGameplayEffect to the target */
	virtual void ApplyCooldown(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack ApplyCooldown!" ) );
    Super::ApplyCooldown( Handle, ActorInfo, ActivationInfo );
  }

	/** Checks cost. returns true if we can pay for the ability. False if not */
	virtual bool CheckCost(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, OUT FGameplayTagContainer* OptionalRelevantTags = nullptr) const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack CheckCost!" ) );
    return true;
    //return Super::CheckCost( Handle, ActorInfo, OptionalRelevantTags );
  }

	/** Applies the ability's cost to the target */
	virtual void ApplyCost(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo) const {
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack ApplyCost!" ) );
    Super::ApplyCost( Handle, ActorInfo, ActivationInfo );
  }

  virtual void SetMovementSyncPoint(FName SyncName) { 
    UE_LOG( LogTemp, Warning, TEXT( "ability_attack SetMovementSyncPoint!" ) );
    Super::SetMovementSyncPoint(SyncName);
  }
  
};
