#include "ScriptMgr.h"
#include "World.h"
#include "Player.h"
#include "Chat.h"
#include "Log.h"

namespace Multiverse
{
    class WorldHello : public WorldScript
    {
    public:
        WorldHello() : WorldScript("Multiverse_WorldHello") { }
        void OnStartup() override
        {
            LOG_INFO("module", "[Multiverse] WorldScript::OnStartup reached.");
        }
    };

    class PlayerLoginHello : public PlayerScript
    {
    public:
        PlayerLoginHello() : PlayerScript("Multiverse_PlayerLoginHello") { }

        void OnLogin(Player* player)  // no 'override' for x-compat
        {
            LOG_INFO("module", "[Multiverse] PlayerScript::OnLogin for {}", player ? player->GetName() : "<null>");
            if (player && player->GetSession())
                ChatHandler(player->GetSession()).SendSysMessage("|cff00ff00[Multiverse]|r Hello from the Multiverse module!");
        }
    };

    inline void RegisterAll()
    {
        new WorldHello();
        new PlayerLoginHello();
    }
}

extern "C" void AddSC_Multiverse_HelloWorld()
{
    LOG_INFO("module", "[Multiverse] AddSC_Multiverse_HelloWorld called.");
    Multiverse::RegisterAll();
}
