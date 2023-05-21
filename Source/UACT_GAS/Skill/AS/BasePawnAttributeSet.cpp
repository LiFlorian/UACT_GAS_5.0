// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawnAttributeSet.h"

#include "Net/UnrealNetwork.h"

UBasePawnAttributeSet::UBasePawnAttributeSet():
	Health(100.0f),
	MaxHealth(100.0f),
	Stamina(100.0f),
	MaxStamina(100.0f)
{
	
}

void UBasePawnAttributeSet::OnRep_Health(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePawnAttributeSet, Health, OldValue);
}

void UBasePawnAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePawnAttributeSet, MaxHealth, OldValue);
}

void UBasePawnAttributeSet::OnRep_Stamina(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePawnAttributeSet, Stamina, OldValue);
}

void UBasePawnAttributeSet::OnRep_MaxStamina(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBasePawnAttributeSet, MaxStamina, OldValue);
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

void UBasePawnAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(UBasePawnAttributeSet, Health);
	DOREPLIFETIME(UBasePawnAttributeSet, MaxHealth);
	DOREPLIFETIME(UBasePawnAttributeSet, Stamina);
	DOREPLIFETIME(UBasePawnAttributeSet, MaxStamina);
}
