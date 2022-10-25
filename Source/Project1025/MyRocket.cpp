// Fill out your copyright notice in the Description page of Project Settings.


#include "MyRocket.h"
#include "MyPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFrameWork/ProjectileMovementComponent.h"
#include "Particles/ParticleEmitter.h"

// Sets default values
AMyRocket::AMyRocket()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Box = CreateDefaultSubobject<UBoxComponent> (TEXT ("Box"));
	RootComponent = Box;
	Box->SetGenerateOverlapEvents (true);
		Box->OnComponentBeginOverlap.AddDynamic (this, &AMyRocket::OnOverlapBegin);

	Rocket = CreateDefaultSubobject<UStaticMeshComponent> (TEXT ("Rocket"));
	Rocket->SetupAttachment (Box);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> SM_Rocket (TEXT
	("StaticMesh'/Game/P38/Meshes/SM_Rocket.SM_Rocket'"));
	if (SM_Rocket.Succeeded ())
	{
		Rocket->SetStaticMesh (SM_Rocket.Object);
		Rocket->SetRelativeRotation (FRotator (-90, 0, 0));
		Rocket->SetRelativeLocation (FVector (0, 0, 0));
			//LocalOffset (FVector (0, 0, 0));
			//SetlocalLocation(FVector(0,0,0));
	}


	Movement = CreateDefaultSubobject<UProjectileMovementComponent> (TEXT ("Movement"));
	Movement->InitialSpeed = 1000;
	Movement->MaxSpeed = 1000;
	Movement->ProjectileGravityScale = 0;
	//Box->OnComponentBeginOverlap.AddDynamic (this, &ALightSwitchCodeOnly::OnOverlapBegin);
	
}

// Called when the game starts or when spawned
void AMyRocket::BeginPlay()
{
	Super::BeginPlay();
	SetLifeSpan (5);
	
}

// Called every frame
void AMyRocket::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//LifeSpanExpired()
}

void AMyRocket::OnOverlapBegin (UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		GEngine->AddOnScreenDebugMessage (-1, 5.f, FColor::Red, TEXT ("Overlap Begin"));
		//GEngine->AddOnScreenDebugMessage (-1, 5.f, FColor::Magenta, TEXT ());
		GEngine->AddOnScreenDebugMessage (0, 10.0f, FColor::Red, TEXT ("Hello World"));
		
		OtherActor->Destroy ();
	}
	
}


