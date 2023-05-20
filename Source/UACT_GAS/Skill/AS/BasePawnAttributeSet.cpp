// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawnAttributeSet.h"

UBasePawnAttributeSet::UBasePawnAttributeSet():
	Health(100.0f),
	MaxHealth(100.0f),
	Stamina(100.0f),
	MaxStamina(100.0f)
{
	
}

void UBasePawnAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);

	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetStaminaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxStamina());
	}
}

void UBasePawnAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	
}
