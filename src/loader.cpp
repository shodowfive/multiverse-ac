#include "Log.h"

extern "C" void AddSC_Multiverse_HelloWorld();

static void MultiverseRegister()
{
    LOG_INFO("module", "[Multiverse] MultiverseRegister(): dispatching AddSC_Multiverse_HelloWorld()");
    AddSC_Multiverse_HelloWorld();
}

extern "C" void AddmultiverseScripts()
{
    LOG_INFO("module", "[Multiverse] AddmultiverseScripts() entrypoint called.");
    MultiverseRegister();
}

extern "C" void AddMultiverseScripts()
{
    LOG_INFO("module", "[Multiverse] AddMultiverseScripts() entrypoint called.");
    MultiverseRegister();
}

extern "C" void Addmod_multiverseScripts()
{
    LOG_INFO("module", "[Multiverse] Addmod_multiverseScripts() entrypoint called.");
    MultiverseRegister();
}
