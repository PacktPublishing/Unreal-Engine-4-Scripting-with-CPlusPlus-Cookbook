#include "Chapter12.h"
#include "HttpDialog.h"
#include "Runtime/UMG/Public/Components/ProgressBar.h"

UHttpDialog::UHttpDialog( const FObjectInitializer& PCIP ) : Super( PCIP )
{
  progressBar = PCIP.CreateDefaultSubobject<UProgressBar>
    ( this, TEXT("UHttpDialog") );
}

void UHttpDialog::OnWidgetRebuilt()
{
  Super::OnWidgetRebuilt();
  progressBar = (UProgressBar*)GetWidgetFromName( TEXT("progressBar1") );

  GetTransientPackage();
}


