

#include "FSM.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "FindNearestTorchService.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "Torch.h"

UFindNearestTorchService::UFindNearestTorchService(const class FObjectInitializer& PCIP) : Super(PCIP)
{
	NodeName = "Find Nearest Torch";
	NearestTorchExists.SelectedKeyName = "Nearest Torch Exists";
}


void UFindNearestTorchService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	TArray<AActor *> Torches;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATorch::StaticClass(), Torches);

	bool bNearestExists = false;
	float NearestDistance = -1;
	ATorch * Target = nullptr;

	for (int i = 1; i < Torches.Num(); i++)
	{
		float distance = FVector::DistSquared(OwnerComp.GetOwner()->GetActorLocation(), Torches[i]->GetActorLocation());

		ATorch * torch = Cast<ATorch>(Torches[i]);

		if(NearestDistance < 0 && torch->IsLighted())
		{ 
			NearestDistance = distance;
			Target = torch;
			bNearestExists = true;
		}
		else if (NearestDistance < distance && torch->IsLighted())
		{
			NearestDistance = distance;
			Target = torch;
			bNearestExists = true;
		}
	}

	OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Object>(BlackboardKey.GetSelectedKeyID(), Target);
	OwnerComp.GetBlackboardComponent()->SetValue<UBlackboardKeyType_Bool>(NearestTorchExists.GetSelectedKeyID(), bNearestExists);
}
