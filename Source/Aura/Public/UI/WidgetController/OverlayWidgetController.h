// Copyright Oleg Pupchenko

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/AuraWidgetController.h"
#include "OverlayWidgetController.generated.h"

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeValueChangedSignature, float, NewAttributeValue);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnAttributeMaxValueChangedSignature, float, NewAttributeMaxValue);
/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class AURA_API UOverlayWidgetController : public UAuraWidgetController
{
	GENERATED_BODY()

public:
	virtual void BroadcastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;

	// Health
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeValueChangedSignature OnHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeMaxValueChangedSignature OnMaxHealthChanged;
	
	// Mana
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeValueChangedSignature OnManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnAttributeMaxValueChangedSignature OnMaxManaChanged;

protected:
	// Health
	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	// Mana
	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
	
};
