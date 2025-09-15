#include "ScriptMgr.h"
#include "Chat.h"

using namespace Acore::ChatCommands;

class multiverse_commandscript : public CommandScript
{
public:
    multiverse_commandscript() : CommandScript("multiverse_commandscript") { }

    ChatCommandTable GetCommands() const override
    {
        static ChatCommandTable mvSub{
            { "ping", SEC_GAMEMASTER, Console::No,
              [](ChatHandler* h, char const*) -> bool {
                  h->PSendSysMessage("|cff00ff00[Multiverse]|r pong");
                  return true;
              } }
        };
        static ChatCommandTable root{
            { "mv", SEC_GAMEMASTER, Console::No, nullptr, mvSub }
        };
        return root;
    }
};

extern "C" void Multiverse_RegisterAll(); // from HelloWorld.cpp

extern "C" void Multiverse_RegisterCommands()
{
    new multiverse_commandscript();
    // Also ensure our base scripts are registered even if only command hook is called:
    Multiverse_RegisterAll();
}
