// Copyright Oleg Pupchenko


#include "Actor/AuraEffectActor.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemInterface.h"


AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;

	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));
}



void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();


}

void AAuraEffectActor::ApplyEffectToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* AbilitySystemComp = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(TargetActor);
	if (!AbilitySystemComp) { return; }

	check(GameplayEffectClass);
	FGameplayEffectContextHandle EffectContextHandle = AbilitySystemComp->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this);
	const FGameplayEffectSpecHandle EffectSpecHandle = AbilitySystemComp->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	AbilitySystemComp->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}


