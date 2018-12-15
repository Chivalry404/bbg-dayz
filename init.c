#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Script_Resources.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Script_Callbacks.c"
#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Script_Mission.c"

void main()
{
	Weather SERVER_WEATHER = g_Game.GetWeather();

    SERVER_WEATHER.MissionWeather(false);    // false = use weather controller from Weather.c

    SERVER_WEATHER.GetOvercast().Set( Math.RandomFloatInclusive(0.4, 0.6), 1, 0);
    SERVER_WEATHER.GetRain().Set(0, 0, 1);
    SERVER_WEATHER.GetFog().Set( Math.RandomFloatInclusive(0.05, 0.1), 1, 0);

	Hive SERVER_HIVE = CreateHive();
	if(SERVER_HIVE)SERVER_HIVE.InitOffline();

	int year;
	int month;
	int day;
	int hour;
	int minute;

	GetGame().GetWorld().GetDate(year, month, day, hour, minute);

    if (((month <= 9) && (day < 20)) || ((month >= 10) && (day > 20)))
    {
        month = 9;
        day = 20;
		
		GetGame().GetWorld().SetDate(year, month, day, hour, minute);
	}
	ScriptCallback.OnGameModeInit();
}

class CustomMission: MissionServer
{	
	void SetRandomHealth(EntityAI itemEnt)
	{
		if ( itemEnt )
		{
			int rndHlt = Math.RandomInt(55,100);
			itemEnt.SetHealth("","",rndHlt);
		}
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		m_player.SetHealth(m_player.GetMaxHealth("", ""));
	    m_player.SetHealth("", "Blood", m_player.GetMaxHealth("", "Blood"));
		m_player.GetStatStamina().Set(1000);
		m_player.GetStatEnergy().Set(1000);
		m_player.GetStatWater().Set(1000);

		return m_player;
	}
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI ITEM_CONTAINER;
		EntityAI ITEM_SELECTED;
		ItemBase ITEM_LOCATION;

		player.RemoveAllItems(); 

		ScriptData.SCRIPT_RANDOM = Math.RandomInt(0, ScriptData.SERVER_MAX_SPAWNS - 1);
		player.SetPosition(ScriptData.SERVER_SPAWN[ScriptData.SCRIPT_RANDOM]);
		
		ScriptData.SCRIPT_RANDOM = Math.RandomInt(0, ScriptData.SERVER_MAX_ROLES - 1);
		
		if(ScriptData.SCRIPT_RANDOM == 0)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("AssaultBag_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("CargoPants_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M65Jacket_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M4A1");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M4_OEBttstck");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M4_PlasticHndgrd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M4_T3NRDSOptic");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
		}
		else if(ScriptData.SCRIPT_RANDOM == 1)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TortillaBag");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("GorkaPants_Summer");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("GorkaEJacket_Autumn");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MilitaryBoots_Brown");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			
			ITEM_SELECTED = player.GetInventory().CreateInInventory("AKM");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("AK_WoodBttstck");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("AK_WoodHndgrd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("AK_Suppressor");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_LOCATION.SetQuantity(3);
		}
		else if(ScriptData.SCRIPT_RANDOM == 2)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TortillaBag");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("GorkaPants_Summer");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("GorkaEJacket_Summer");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
				
			ITEM_SELECTED = player.GetInventory().CreateInInventory("SVD");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_LOCATION.SetQuantity(2);

			ScriptData.SCRIPT_RANDOM = Math.RandomInt(0,2);
			if(ScriptData.SCRIPT_RANDOM == 1)ITEM_SELECTED = player.GetInventory().CreateInInventory("PSO1Optic");
			else if(ScriptData.SCRIPT_RANDOM == 2)ITEM_SELECTED = player.GetInventory().CreateInInventory("KashtanOptic");
		}
		else if(ScriptData.SCRIPT_RANDOM == 3)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("SmershBag");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TTSKOPants");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
									
			ITEM_SELECTED = player.GetInventory().CreateInInventory("UMP45");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_LOCATION.SetQuantity(2);

			ScriptData.SCRIPT_RANDOM = Math.RandomInt(0,5);
			if(ScriptData.SCRIPT_RANDOM == 0)player.GetInventory().CreateInInventory("BUISOptic");
			else if(ScriptData.SCRIPT_RANDOM == 1)player.GetInventory().CreateInInventory("M68Optic");
			else if(ScriptData.SCRIPT_RANDOM == 2)player.GetInventory().CreateInInventory("M4_T3NRDSOptic");
			else if(ScriptData.SCRIPT_RANDOM == 3)player.GetInventory().CreateInInventory("ACOGOptic");
			else if(ScriptData.SCRIPT_RANDOM == 4)player.GetInventory().CreateInInventory("ReflexOptic");
		}
		else if(ScriptData.SCRIPT_RANDOM == 4)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("SmershBag");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TTSKOPants");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
							
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MP5K");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MP5_PlasticHndgrd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MP5k_StockBttstck");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MP5_RailHndgrd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MP5_Compensator");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("PistolSuppressor");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_LOCATION.SetQuantity(2);

			ScriptData.SCRIPT_RANDOM = Math.RandomInt(0,5);
			if(ScriptData.SCRIPT_RANDOM == 0)player.GetInventory().CreateInInventory("BUISOptic");
			else if(ScriptData.SCRIPT_RANDOM == 1)player.GetInventory().CreateInInventory("M68Optic");
			else if(ScriptData.SCRIPT_RANDOM == 2)player.GetInventory().CreateInInventory("M4_T3NRDSOptic");
			else if(ScriptData.SCRIPT_RANDOM == 3)player.GetInventory().CreateInInventory("ACOGOptic");
			else if(ScriptData.SCRIPT_RANDOM == 4)player.GetInventory().CreateInInventory("ReflexOptic");
		}
		else
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("AssaultBag_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("CargoPants_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M65Jacket_Khaki");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("MilitaryBoots_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
				
			ITEM_SELECTED = player.GetInventory().CreateInInventory("CZ61");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_LOCATION.SetQuantity(2);
		}
		ScriptCallback.OnPlayerSpawn(player);
/*		ITEM_CONTAINER = player.FindAttachmentBySlotName("Body");
		
		if(ITEM_CONTAINER)
		{
			ITEM_SELECTED = ITEM_CONTAINER.GetInventory().CreateInInventory("Rag");
			if(Class.CastTo(ITEM_SELECTED))
				ITEM_LOCATION.SetQuantity(4);

			SetRandomHealth(ITEM_SELECTED);
			
			ITEM_SELECTED = itemTop.GetInventory().CreateInInventory("RoadFlare");
			SetRandomHealth(ITEM_SELECTED);
		
			ITEM_SELECTED = itemTop.GetInventory().CreateInInventory("StoneKnife");
			SetRandomHealth(ITEM_SELECTED);
		}

		rand = Math.RandomFloatInclusive(0.0, 1.0);
		if(rand < 0.25)
			ITEM_SELECTED = player.GetInventory().CreateInInventory("SodaCan_Cola");
		else if(rand > 0.75)
			ITEM_SELECTED = player.GetInventory().CreateInInventory("SodaCan_Spite");
		else
			ITEM_SELECTED = player.GetInventory().CreateInInventory("SodaCan_Pipsi");
		
		SetRandomHealth(ITEM_SELECTED);

		rand = Math.RandomFloatInclusive(0.0, 1.0);
		if (rand < 0.35)
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Apple");
		else if( rand > 0.65)
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Pear");
		else
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Plum");
		
		SetRandomHealth(ITEM_SELECTED);
*/

/*

		EntityAI ITEM_SELECTED;
		ItemBase ITEM_LOCATION;

		ScriptData.SCRIPT_RANDOM = Math.RandomInt(0, ScriptData.SERVER_MAX_SPAWNS - 1);
		player.SetPosition(ScriptData.SERVER_SPAWN[ScriptData.SCRIPT_RANDOM]);

		if(ScriptData.SERVER_SPAWNID == 0)
		{

		}
		else if(ScriptData.SERVER_SPAWNID == 1)
		{ 
		}
		else if(ScriptData.SERVER_SPAWNID == 2)
		{
		}
		else if(ScriptData.SERVER_SPAWNID == 3)
		{
		}
		else if(ScriptData.SERVER_SPAWNID == 4)
		{
		}
		else
		{

			ScriptData.SERVER_SPAWNID = -1;
		}
		ScriptData.SERVER_SPAWNID++;
*/
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
