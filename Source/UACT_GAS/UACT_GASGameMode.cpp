// Copyright Epic Games, Inc. All Rights Reserved.

#include "UACT_GASGameMode.h"
#include "UACT_GASCharacter.h"
#include "UObject/ConstructorHelpers.h"

AUACT_GASGameMode::AUACT_GASGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
