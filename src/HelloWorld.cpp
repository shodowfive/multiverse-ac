#include "ScriptMgr.h"
#include "Player.h"
#include "Chat.h"

class Multiverse_HelloWorld : public PlayerScript
{
public:
    Multiverse_HelloWorld() : PlayerScript("Multiverse_HelloWorld") { }

    void OnLogin(Player* player) override
    {
        if (!player) return;
        ChatHandler(player->GetSession()).SendSysMessage("Hello World from the Multiverse module!");
    }
};

void AddSC_Multiverse_HelloWorld()
{
    new Multiverse_HelloWorld();
}
