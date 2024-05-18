#include "QuantumDevourer.h"

AQuantumDevourer::AQuantumDevourer()
{
    PrimaryActorTick.bCanEverTick = true;

    Health = 1000;
    IsDamageReduced = false;
    DamageTaken = 0;
    IsDead = false;
    BurnDuration = 0;
    EntangleDuration = 0;
    IsUsingLaser = false;
    EnhanceCooldown = 0;
    EntangleCooldown = 0;
    EchoCooldown = 0;
    IsUsingArm = false;
}

void AQuantumDevourer::BeginPlay()
{
    Super::BeginPlay();
}

void AQuantumDevourer::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AQuantumDevourer::CheckForDeath()
{
    if (Health <= 0)
    {
        IsDead = true;
        GetWorldTimerManager().SetTimer(DeathTimerHandle, this, &AQuantumDevourer::HandleDeath, 2.0f, false);
    }
}

void AQuantumDevourer::HandleDeath()
{
    SetActorLocation(FVector(700.0f, 0.0f, -502.0f));
    GetSprite()->SetFlipbook(DeathAnimation);
    GetSprite()->SetLooping(false);
    UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->GetCapsuleComponent()->SetMobility(EComponentMobility::Movable);
}

void AQuantumDevourer::TakeDamage(int Damage)
{
    int NewHealth = FMath::Max(Health - Damage, 0);
    DamageTaken = Health - NewHealth;
    Health = NewHealth;
}

void AQuantumDevourer::HandleAnimationFire()
{
    DamageTaken = 0;
    GetSprite()->SetFlipbook(FireAnimation);
    GetSprite()->SetLooping(false);
    IsUsingArm = true;

    if (EntangleDuration > 0)
    {
        TakeDamage(130);
    }
}

void AQuantumDevourer::HandleAnimationDeath()
{
    CheckForDeath();

    if (IsDead)
    {
        GetSprite()->SetFlipbook(DeathAnimation);
        GetSprite()->SetLooping(false);
        SetActorLocation(FVector(700.0f, 0.0f, -502.0f));
    }
    else
    {
        GetSprite()->SetFlipbook(IdleAnimation);
        GetSprite()->SetLooping(true);
    }

    GetSprite()->Play();
}

void AQuantumDevourer::HandleHeal()
{
    Health = FMath::Min(Health + 100, 1000);
    DamageTaken = 0;
    GetSprite()->SetFlipbook(HealAnimation);
}

void AQuantumDevourer::HandleAnimationLaser()
{
    BurnDuration = 3;
    DamageTaken = 0;
    GetSprite()->SetFlipbook(LaserAnimation);
    GetSprite()->SetLooping(false);
    IsUsingLaser = true;

    if (EntangleDuration > 0)
    {
        TakeDamage(100);
    }
}

void AQuantumDevourer::HandleAnimationBlock()
{
    Health = FMath::Min(Health + DamageTaken, 1000);
    DamageTaken = 0;
    GetSprite()->SetFlipbook(BlockAnimation);
    GetSprite()->SetLooping(false);
}