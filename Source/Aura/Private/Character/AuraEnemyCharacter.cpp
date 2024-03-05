// Copyright Oleg Pupchenko


#include "Character/AuraEnemyCharacter.h"

#include "Aura/Aura.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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
