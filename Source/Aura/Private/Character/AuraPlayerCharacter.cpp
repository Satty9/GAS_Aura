// Copyright Oleg Pupchenko


#include "Character/AuraPlayerCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Player/AuraPlayerController.h"
#include "Player/AuraPlayerState.h"
#include "UI/HUD/AuraHUD.h"
#include "UI/WidgetController/AuraWidgetController.h"

AAuraPlayerCharacter::AAuraPlayerCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator (0.f, 400.f, 0.f); // rotation by Z with 400 speed
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AAuraPlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	// Init ability actor info for the Server
	InitAbilityActorInfo();
	
}

void AAuraPlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	// Init ability actor info for the Client
	InitAbilityActorInfo();
}

void AAuraPlayerCharacter::InitAbilityActorInfo()
{
	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);
	Cast<UAuraAbilitySystemComponent>(AuraPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();
	// Set pointers to objects in Player State
	AbilitySystemComponent =  CastChecked<UAuraAbilitySystemComponent>(AuraPlayerState->GetAbilitySystemComponent());
	AttributeSet =  CastChecked<UAuraAttributeSet>(AuraPlayerState->GetAttributeSet());

	if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if(AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			// TODO: make data class for FWidgetControllerParams to cut dependensies to AuraWidgetController;
			FWidgetControllerParams WCParams (AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
			AuraHUD->InitOverlay(WCParams);
		}
	}

	InitializePrimaryAttributes();
}
