// Copyright Oleg Pupchenko


#include "Character/AuraEnemyCharacter.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
}

void AAuraEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->CustomDepthStencilValue=CUSTOM_DEPTH_RED;
	if(Weapon)
	{
		GetMesh()->SetRenderCustomDepth(true);
		GetMesh()->CustomDepthStencilValue=CUSTOM_DEPTH_RED;
	}
}

void AAuraEnemyCharacter::UnHighlightActor()
{

	GetMesh()->SetRenderCustomDepth(false);
	if(Weapon)
	{
		GetMesh()->SetRenderCustomDepth(false);
	}
}

void AAuraEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}
