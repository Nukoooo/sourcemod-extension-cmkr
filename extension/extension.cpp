#include "extension.h"

bool TestExtension::SDK_OnLoad(char* error, size_t maxlength, bool late)
{
    return true;

}

void TestExtension::SDK_OnUnload()
{
}
