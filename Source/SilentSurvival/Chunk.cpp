// Fill out your copyright notice in the Description page of Project Settings.


#include "Chunk.h"
#include "ProceduralMeshComponent.h"


// Sets default values
AChunk::AChunk()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AChunk::BeginPlay()
{
	Super::BeginPlay();
	
}

void AChunk::GenerateBlocks()
{
}

void AChunk::GenerateMesh()
{
}

void AChunk::ApplyMesh() const
{
}

bool AChunk::Check(FVector Position) const
{
	return false;
}

void AChunk::CreateFace(EDirection Direction, FVector Position) const
{
}

TArray<FVector> AChunk::GetFaceVertices(EDirection Direction, FVector Position) const
{
	return TArray<FVector>();
}

FVector AChunk::GetPositonInDirection(EDirection Direction, FVector Position) const
{
	return FVector();
}

int AChunk::GetBlockIndex(int X, int Y, int Z) const
{
	return 0;
}
