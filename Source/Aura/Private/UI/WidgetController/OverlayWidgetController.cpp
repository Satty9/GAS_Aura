// Copyright Oleg Pupchenko


#include "UI/WidgetController/OverlayWidgetController.h"
#include "AbilitySystem/AuraAttributeSet.h"

void UOverlayWidgetController::BroadcastInitialValues()
{
	const UAuraAttributeSet* Set = CastChecked<UAuraAttributeSet>(AttributeSet);

	OnHealthChanged.Broadcast(Set->GetHealth());
	OnMaxHealthChanged.Broadcast(Set->GetMaxHealth());
	
}
