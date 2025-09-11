// modules/multiverse/src/loader.cpp
void AddSC_Multiverse_HelloWorld(); // from your HelloWorld.cpp

// This symbol is how AzerothCore discovers and registers your module scripts
extern "C" void Addmod_multiverseScripts()
{
    AddSC_Multiverse_HelloWorld();
}
