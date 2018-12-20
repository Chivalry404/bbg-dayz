/*

	Chivalry's Test Script

*/

class ScriptData
{
	static int SCRIPT_RANDOM = 0;
	static int SERVER_MAX_SPAWNS = 21;
	static int SERVER_MAX_WEAPONS = 9;
	static int SERVER_MAX_ROLES = 10;
	static int SERVER_SPAWNID = 0;
	static int SERVER_WEAPONID = 5;
	
	static vector SERVER_SPAWN[21];
	static string SERVER_WEAPON[10];
	static string SERVER_WEAPON_AMMO[12];
	static string SERVER_AMMO[16];
	static string SERVER_SCOPE[6];

	static string SERVER_PANTS[10];
	static string SERVER_JACKETS[10];
	static string SERVER_BOOTS[10];
	static string SERVER_HELMET[10];
	static string SERVER_BACKPACK[10];
	static string SERVER_DRINK[10];
	static string SERVER_FOOD[10];
	static string SERVER_TOOLS[10];
	static string SERVER_KNIFE[10];
}

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
	// CREATE OBJECTS
  	Object obj; 
	obj = GetGame().CreateObject("Land_Misc_DeerStand1", "8087.44 1.0 3259.0");
	obj.SetOrientation("55.999985 0.000000 0.000000");
	obj.SetPosition("8080.44 12.0 3252.0");
	// CREATE SPAWN POINTS
	ScriptData.SERVER_SPAWN[0] = ("8080.44 6 3252";
	ScriptData.SERVER_SPAWN[1] = ("8099.5 6 3260.5";
	ScriptData.SERVER_SPAWN[2] = ("8011.0 6 3083.0";
	ScriptData.SERVER_SPAWN[3] = ("8011.0 6 3106.0";
	ScriptData.SERVER_SPAWN[4] = ("8017.5 6 3106.0";
	ScriptData.SERVER_SPAWN[5] = ("8127.15 6 3236.0";
	ScriptData.SERVER_SPAWN[6] = ("8147.5 6 3227.0";
	ScriptData.SERVER_SPAWN[7] = ("8206.5 6 3220.0";
	ScriptData.SERVER_SPAWN[8] = ("8229.5 6 3160.0";
	ScriptData.SERVER_SPAWN[9] = ("8192.5 6 3088.0";
	ScriptData.SERVER_SPAWN[10] = ("8065.5 5 3071.0";
	ScriptData.SERVER_SPAWN[11] = ("8018.5 5 2960.0";
	ScriptData.SERVER_SPAWN[12] = ("8023.5 5 3022.0";
	ScriptData.SERVER_SPAWN[13] = ("8009.5 6 3089.0";
	ScriptData.SERVER_SPAWN[14] = ("8173.5 7 3046.0";
	ScriptData.SERVER_SPAWN[15] = ("8178.5 6.1 2999.0";
	ScriptData.SERVER_SPAWN[16] = ("8130.5 4.5 2975.0";
	ScriptData.SERVER_SPAWN[17] = ("8148.5 4.5 2914.0";
	ScriptData.SERVER_SPAWN[18] = ("8114.5 3 2903.0";
	ScriptData.SERVER_SPAWN[19] = ("8057.5 3 2892.0";
	ScriptData.SERVER_SPAWN[20] = ("8043.5 3 2902.0";
	// CREATE PANTS ARRAY // BDUPants
	ScriptData.SERVER_PANTS[0] = "CargoPants_Black"; 		// BLACK
	ScriptData.SERVER_PANTS[1] = "GorkaPants_Summer";		// GORKA
	ScriptData.SERVER_PANTS[2] = "USMCPants_Woodland";		// USMC - PATROL
	ScriptData.SERVER_PANTS[3] = "TTSKOPants"; 				// TSKO
	ScriptData.SERVER_PANTS[4] = "NBCPantsGray";			// NBC
	ScriptData.SERVER_PANTS[5] = "HunterPants_Autumn"; 		// HUNTER
	ScriptData.SERVER_PANTS[6] = "PrisonUniformPants"; 		// PRISONER
	ScriptData.SERVER_PANTS[7] = "PolicePants"; 			// POLICE
	ScriptData.SERVER_PANTS[8] = "ParamedicPants_Blue"; 	// PARAMEDIC
	ScriptData.SERVER_PANTS[9] = "FirefightersPants_Black"; // FIREMAN
	// CREATE JACKET ARRAY
	ScriptData.SERVER_JACKETS[0] = "M65Jacket_Black";
	ScriptData.SERVER_JACKETS[1] = "GorkaEJacket_Autumn";
	ScriptData.SERVER_JACKETS[2] = "USMCJacket_Woodland";
	ScriptData.SERVER_JACKETS[3] = "TTsKOJacket_Camo";
	ScriptData.SERVER_JACKETS[4] = "NBCJacketGray";
	ScriptData.SERVER_JACKETS[5] = "HuntingJacket_Autumn";
	ScriptData.SERVER_JACKETS[6] = "PrisonUniformJacket";
	ScriptData.SERVER_JACKETS[7] = "PoliceJacket";
	ScriptData.SERVER_JACKETS[8] = "ParamedicJacket_Blue";
	ScriptData.SERVER_JACKETS[9] = "FirefighterJacket_Black";
	// CREATE BOOT ARRAY
	ScriptData.SERVER_BOOTS[0] = "MilitaryBoots_Black";
	ScriptData.SERVER_BOOTS[1] = "MilitaryBoots_Brown";
	ScriptData.SERVER_BOOTS[2] = "MilitaryBoots_Black";
	ScriptData.SERVER_BOOTS[3] = "TTSKOBoots";
	ScriptData.SERVER_BOOTS[4] = "NBCBootsGray";
	ScriptData.SERVER_BOOTS[5] = "Wellies_Green";
	ScriptData.SERVER_BOOTS[6] = "Sneakers_Gray";
	ScriptData.SERVER_BOOTS[7] = "MilitaryBoots_Black";
	ScriptData.SERVER_BOOTS[8] = "MilitaryBoots_Black";
	ScriptData.SERVER_BOOTS[9] = "Wellies_Black";
	// CREATE HELMET ARRAY
	ScriptData.SERVER_HELMET[0] = "BallisticHelmet_Black"; // black
	ScriptData.SERVER_HELMET[1] = "GorkaHelmet";
	ScriptData.SERVER_HELMET[2] = "Ssh68Helmet"; // ZSh3PilotHelmet = white BallisticHelmet_Green
	ScriptData.SERVER_HELMET[3] = "PilotkaCap";
	ScriptData.SERVER_HELMET[4] = "Mich2001Helmet";
	ScriptData.SERVER_HELMET[5] = "Mich2001Helmet";
	ScriptData.SERVER_HELMET[6] = "PrisonerCap";
	ScriptData.SERVER_HELMET[7] = "PoliceCap";
	ScriptData.SERVER_HELMET[8] = "Headtorch_Black";
	ScriptData.SERVER_HELMET[9] = "FirefightersHelmet_White";
	// CREATE BACKPACK ARRAY // PlateCarrierVest
	ScriptData.SERVER_BACKPACK[0] = "UKAssVest_Black"; // AssaultBag_BlackAliceBag_Black
	ScriptData.SERVER_BACKPACK[1] = "TortillaBag"; // UKAssVest_Olive UKAssVest_Khaki 
	ScriptData.SERVER_BACKPACK[2] = "UKAssVest_Camo"; // MORE CAMO
	ScriptData.SERVER_BACKPACK[3] = "AssaultBag_Ttsko"; // AliceBag_Black AliceBag_Camo AliceBag_Green
	ScriptData.SERVER_BACKPACK[4] = "UKAssVest_Camo"; // SmershBag SMALL THINGS? LIGHT GREEN
	ScriptData.SERVER_BACKPACK[5] = "HuntingBag"; // AmmoBox
	ScriptData.SERVER_BACKPACK[6] = "ChildBag_Blue";
	ScriptData.SERVER_BACKPACK[7] = "PoliceVest";
	ScriptData.SERVER_BACKPACK[8] = "PoliceVest";
	ScriptData.SERVER_BACKPACK[9] = "PoliceVest";
	// CREATE FOOD ARRAY
	ScriptData.SERVER_FOOD[0] = "TacticalBaconCan"; 		// BLACK
	ScriptData.SERVER_FOOD[1] = "TacticalBaconCan"; 		// GORKA
	ScriptData.SERVER_FOOD[2] = "TacticalBaconCan"; 		// USMC - PATROL
	ScriptData.SERVER_FOOD[3] = "TacticalBaconCan"; 		// TSKO
	ScriptData.SERVER_FOOD[4] = "TacticalBaconCan"; 		// NBC
	ScriptData.SERVER_FOOD[5] = "SardinesCan";      		// HUNTER
	ScriptData.SERVER_FOOD[6] = "Pot";              		// PRISONER
	ScriptData.SERVER_FOOD[7] = "Rice";             		// POLICE
	ScriptData.SERVER_FOOD[8] = "Rice";             		// PARAMEDIC
	ScriptData.SERVER_FOOD[9] = "Rice";             		// FIREMAN
	// CREATE DRINK ARRAY
	ScriptData.SERVER_DRINK[0] = "Canteen";
	ScriptData.SERVER_DRINK[1] = "Canteen";
	ScriptData.SERVER_DRINK[2] = "Canteen";
	ScriptData.SERVER_DRINK[3] = "Canteen";
	ScriptData.SERVER_DRINK[4] = "Canteen";
	ScriptData.SERVER_DRINK[5] = "SodaCan_Spite"; // SodaCan_Kvass
	ScriptData.SERVER_DRINK[6] = "SodaCan_Pipsi";
	ScriptData.SERVER_DRINK[7] = "WaterBottle"; // POLICE
	ScriptData.SERVER_DRINK[8] = "SodaCan_Cola";
	ScriptData.SERVER_DRINK[9] = "WaterBottle";
	// CREATE KNIFE ARRAY
	ScriptData.SERVER_KNIFE[0] = "CombatKnife";
	ScriptData.SERVER_KNIFE[1] = "CombatKnife";
	ScriptData.SERVER_KNIFE[2] = "CombatKnife";
	ScriptData.SERVER_KNIFE[3] = "CombatKnife";
	ScriptData.SERVER_KNIFE[4] = "CombatKnife";
	ScriptData.SERVER_KNIFE[5] = "HuntingKnife";
	ScriptData.SERVER_KNIFE[6] = "StoneKnife";
	ScriptData.SERVER_KNIFE[7] = "WoodAxe";
	ScriptData.SERVER_KNIFE[8] = "Hatchet";
	ScriptData.SERVER_KNIFE[9] = "HuntingKnife";
	// CREATE TOOL ARRAY
	ScriptData.SERVER_TOOLS[0] = "WeaponCleaningKit"; // Wrench Tripod TireRepairKit Rangefinder
	ScriptData.SERVER_TOOLS[1] = "GorkaHelmetVisor";
	ScriptData.SERVER_TOOLS[2] = "FirefighterAxe_Black";
	ScriptData.SERVER_TOOLS[3] = "WeaponCleaningKit";
	ScriptData.SERVER_TOOLS[4] = "WeaponCleaningKit";
	ScriptData.SERVER_TOOLS[5] = "WoodAxe";
	ScriptData.SERVER_TOOLS[6] = "StoneKnife";
	ScriptData.SERVER_TOOLS[7] = "WeaponCleaningKit";
	ScriptData.SERVER_TOOLS[8] = "Battery9V";
	ScriptData.SERVER_TOOLS[9] = "FirefighterAxe";

	// CREATE WEAPON ARRAY
	ScriptData.SERVER_WEAPON[0] = "M4A1"; // M4A1_Black M4A1_Green M4_CarryHandleOptic M4_CQBBttstck M4_MPBttstck M4_MPHndgrd
	// M4_OEBttstck M4_PlasticHndgrd M4_RISHndgrd M4_RISHndgrd_Black M4_RISHndgrd_Green M4_Suppressor
	ScriptData.SERVER_WEAPON[1] = "AKM"; // AK74_Hndgrd AK74_WoodBttstck AK_FoldingBttstck 
	// AK_FoldingBttstck_Black AK_FoldingBttstck_Green AK_PlasticBttstck AK_PlasticBttstck_Black AK_PlasticBttstck_Green
	// AK_PlasticHndgrd AK_RailHndgrd AK_RailHndgrd_BlackAK_RailHndgrd_Black AK_RailHndgrd_Green AK_Suppressor
	// AK_WoodBttstck AK_WoodBttstck_Black AK_WoodBttstck_Camo AK_WoodHndgrd AK_WoodHndgrd_Black AK_WoodHndgrd_Camo
	// Mag_AKM_30Rnd
	ScriptData.SERVER_WEAPON[2] = "CZ61"; // Mag_CZ61_20Rnd PistolSuppressor TLRLight UniversalLight
	ScriptData.SERVER_WEAPON[3] = "FNX45"; // Mag_FNX45_15Rnd
	ScriptData.SERVER_WEAPON[4] = "MakarovIJ70"; // Mag_IJ70_8Rnd
	ScriptData.SERVER_WEAPON[5] = "Mosin9130"; // Mosin9130_Black Mosin9130_Camo Mosin9130_Green
	ScriptData.SERVER_WEAPON[6] = "MP5K"; // MP5k_StockBttstck MP5_Compensator MP5_PlasticHndgrd MP5_RailHndgrd
	ScriptData.SERVER_WEAPON[7] = "SVD"; // 
	ScriptData.SERVER_WEAPON[8] = "UMP45"; // 
	//ScriptData.SERVER_WEAPON[3] = "CZ75"; // Mag_CZ75_15Rnd // broken?  CZ75
	//ScriptData.SERVER_WEAPON[5] = "Izh18";
	//ScriptData.SERVER_WEAPON[6] = "Mp133Shotgun";
	// makarove  mp5 Mag_MP5_30Rnd unknown Mag_STANAG_30Rnd Mag_SVD_10Rnd Mag_UMP_25Rnd
	// CREATE WEAPON AMMO ARRAY
	ScriptData.SERVER_WEAPON_AMMO[0] = "Mag_STANAG_30Rnd";
	ScriptData.SERVER_WEAPON_AMMO[1] = "Mag_AKM_30Rnd";
	ScriptData.SERVER_WEAPON_AMMO[2] = "Mag_CZ61_20Rnd";
	ScriptData.SERVER_WEAPON_AMMO[3] = "Mag_FNX45_15Rnd";
	ScriptData.SERVER_WEAPON_AMMO[4] = "Mag_IJ70_8Rnd";
	ScriptData.SERVER_WEAPON_AMMO[5] = "Ammo_762x54";
	ScriptData.SERVER_WEAPON_AMMO[6] = "Mag_MP5_30Rnd";
	ScriptData.SERVER_WEAPON_AMMO[7] = "Mag_SVD_10Rnd";
	ScriptData.SERVER_WEAPON_AMMO[8] = "Mag_UMP_25Rnd";
	//ScriptData.SERVER_WEAPON_AMMO[3] = "Mag_CZ75_15Rnd";
	//ScriptData.SERVER_WEAPON_AMMO[5] = "Ammo_762x54";
	//ScriptData.SERVER_WEAPON_AMMO[6] = "AmmoBox_00buck_10rnd";
	// CREATE AMMO ARRAY
	ScriptData.SERVER_AMMO[0] = "Ammo_9x19";
	ScriptData.SERVER_AMMO[1] = "Ammo_762x54";
	ScriptData.SERVER_AMMO[2] = "Ammo_762x39";
	ScriptData.SERVER_AMMO[3] = "Ammo_556x45";
	ScriptData.SERVER_AMMO[4] = "Ammo_45ACP";
	ScriptData.SERVER_AMMO[5] = "Ammo_380";
	ScriptData.SERVER_AMMO[6] = "Ammo_12gaSlug";
	ScriptData.SERVER_AMMO[7] = "Ammo_12gaPellets";
	ScriptData.SERVER_AMMO[8] = "AmmoBox_9x19_25rnd"; 		//
	ScriptData.SERVER_AMMO[9] = "AmmoBox_762x54_20Rnd"; 	//
	ScriptData.SERVER_AMMO[10] = "AmmoBox_762x39_20Rnd"; 	// 
	ScriptData.SERVER_AMMO[11] = "AmmoBox_556x45_20Rnd"; 	// 
	ScriptData.SERVER_AMMO[12] = "AmmoBox_45ACP_25rnd"; 	// 
	ScriptData.SERVER_AMMO[13] = "AmmoBox_380_35rnd"; 		// mp5
	ScriptData.SERVER_AMMO[14] = "AmmoBox_12gaSlug_10Rnd"; 	// SVD
	ScriptData.SERVER_AMMO[15] = "AmmoBox_00buck_10rnd"; 	// SHOTGUN
	// CREATE SCOPE ARRAY
	ScriptData.SERVER_SCOPE[0] = "ACOGOptic";
	ScriptData.SERVER_SCOPE[1] = "KazuarOptic";
	ScriptData.SERVER_SCOPE[2] = "KobraOptic";
	ScriptData.SERVER_SCOPE[3] = "M68Optic";
	ScriptData.SERVER_SCOPE[4] = "PSO1Optic";
	ScriptData.SERVER_SCOPE[5] = "PUScopeOptic";
}

/*
class CustomSpawn : DayZGame
{	
	override void ClientSpawning(bool newChar)
	{
		CancelQueueTime();
		ClientSpawningFinished(newChar);
		// countdown on the spawning screen
		if (m_queueTime >= 6)
		{
			m_queueTime = 5;
		}
		else if (m_queueTime >= 0) // count all the way to zero
		{
		#ifndef NO_GUI	
			string text = "#dayz_game_spawning_in" + " " + m_queueTime.ToString() + " " + "#dayz_game_seconds";
			GetUIManager().ScreenFadeIn(0, text, FadeColors.BLACK, FadeColors.WHITE);
		#endif
			m_queueTime--;
		}
		else
		{
			// hide spawning text
			CancelQueueTime();
			ClientSpawningFinished(newChar);
		}
		return true;
	}
}
*/

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
		player.RemoveAllItems(); 
 
		EntityAI itemTop;
		EntityAI itemWeap;
		EntityAI itemEnt;
		ItemBase itemBs;
		float rand;
		
//		ScriptData.SCRIPT_RANDOM = Math.RandomInt(0, ScriptData.SERVER_MAX_ROLES - 1);

		itemEnt = player.GetInventory().CreateInInventory(ScriptData.SERVER_PANTS[ScriptData.SCRIPT_RANDOM]);
		itemEnt = player.GetInventory().CreateInInventory(ScriptData.SERVER_JACKETS[ScriptData.SCRIPT_RANDOM]);
		itemEnt = player.GetInventory().CreateInInventory(ScriptData.SERVER_BOOTS[ScriptData.SCRIPT_RANDOM]);
		itemEnt = player.GetInventory().CreateInInventory(ScriptData.SERVER_HELMET[ScriptData.SCRIPT_RANDOM]);
		itemEnt = player.GetInventory().CreateInInventory(ScriptData.SERVER_BACKPACK[ScriptData.SCRIPT_RANDOM]);
		itemEnt = player.GetInventory().CreateInInventory(ScriptData.SERVER_FOOD[ScriptData.SCRIPT_RANDOM]);
		itemEnt = player.GetInventory().CreateInInventory(ScriptData.SERVER_DRINK[ScriptData.SCRIPT_RANDOM]);
		itemEnt = player.GetInventory().CreateInInventory(ScriptData.SERVER_TOOLS[ScriptData.SCRIPT_RANDOM]);
		itemEnt = player.GetInventory().CreateInInventory(ScriptData.SERVER_KNIFE[ScriptData.SCRIPT_RANDOM]);

		itemTop = player.FindAttachmentBySlotName("Body");
		
//		ScriptData.SCRIPT_RANDOM = Math.RandomInt(0, ScriptData.SERVER_MAX_WEAPONS - 1);
//		itemWeap = player.GetHumanInventory().CreateInHands(ScriptData.SERVER_WEAPON[ScriptData.SCRIPT_RANDOM]);
		itemWeap = player.GetHumanInventory().CreateInHands(ScriptData.SERVER_WEAPON[ScriptData.SERVER_WEAPONID]);
		if(itemTop)
		{
			itemEnt = itemTop.GetInventory().CreateInInventory("Rag");
			if(Class.CastTo(itemBs, itemEnt))
				itemBs.SetQuantity(4);
			SetRandomHealth(itemEnt);
			
			
//			itemEnt = itemTop.GetInventory().CreateInInventory("M4_OEBttstck");
//			itemEnt = itemTop.GetInventory().CreateInInventory("M4_PlasticHndgrd");
//			itemEnt = itemTop.GetInventory().CreateInInventory("M4_T3NRDSOptic");
//			itemEnt = itemTop.GetInventory().CreateInInventory(ScriptData.SERVER_WEAPON_AMMO[ScriptData.SCRIPT_RANDOM]);
			itemEnt = itemTop.GetInventory().CreateInInventory(ScriptData.SERVER_WEAPON_AMMO[ScriptData.SERVER_WEAPONID]);
		}
		ScriptData.SCRIPT_RANDOM = Math.RandomInt(0, ScriptData.SERVER_MAX_SPAWNS - 1);
//		player.SetPosition(ScriptData.SERVER_SPAWN[ScriptData.SCRIPT_RANDOM]);
		player.SetPosition(ScriptData.SERVER_SPAWN[0]);
		
		ScriptData.SERVER_WEAPONID++;
		
		if(ScriptData.SERVER_WEAPONID > ScriptData.SERVER_MAX_WEAPONS - 1)
		{
			ScriptData.SERVER_WEAPONID = 0;
		}
		ScriptData.SERVER_SPAWNID++;
		
		if(ScriptData.SERVER_SPAWNID > ScriptData.SERVER_MAX_ROLES - 1)
		{
			ScriptData.SERVER_SPAWNID = 0;
		}
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}

/*

	Weapons, Clothing & Useful Items
	
	Mosin9130 (Black, Camo, Green)

	AKM, AK_WoodBttstck, AK_WoodHndgrd, Mag_AKM_30Rnd
	SVD, Mag_SVD_10Rnd
	UMP45, Mag_UMP_25Rnd
	MP5K, MP5_PlasticHndgrd, MP5k_StockBttstck, Mag_MP5_30Rnd
	CZ61, AK_Suppressor, Mag_CZ61_20Rnd

	Mp133Shotgun

	MakarovIJ70, Mag_IJ70_8Rnd
	FNX45, Mag_FNX45_15Rnd
	CZ75, Mag_CZ75_15Rnd

	MountainBag_Red, CanvasPants_Red, TrackSuitJacket_Red, FirefightersPants_Black
	PoliceJacket (PoliceJacketOrel), PolicePants (PolicePantsOrel), PoliceVest, PoliceCap, StunBaton
	PrisonUniformJacket, PrisonUniformPants, PrisonerCap
	SurgicalGloves_White (Blue, LightBlue, Green), SurgicalMask, TaloonBag_Blue, MedicalScrubsPants_Blue, MedicalScrubsShirt_Blue			
	HuntingBag, HuntingJacket_Autumn, HunterPants_Autumn, Rangefinder, Matchbox
	
	BDUPants
	GorkaPants_Summer, GorkaEJacket_Summer (PautRev, Autumn, Flat)
	M65Jacket_Khaki (Black, Tan, Olive, Camo)
	TacticalShirt_Black (Grey, Olive, Tan), TacticalGloves_Beige (Black, Green)
	TTSKOPants, TTsKOJacket_Camo, TTSKOBoots
	UKAssVest_Olive (Khaki, Camo, Black)
	USMCJacket_Desert (Woodland), USMCPants_Woodland (Desert)
	
	TortillaBag, SmershBag
	MilitaryBoots_Redpunk (Beige, Bacl, Green, Bluerock, Brown)
	MilitaryBeret_CDF (ChDKZ, NZ, Red, UN)
	ZSh3PilotHelmet, Ssh68Helmet, TankerHelmet, PilotkaCap, Mich2001Helmet
	ACOGOptic, BUISOptic, M68Optic, M4_T3NRDSOptic, ReflexOptic, PUScopeOptic, PSO1Optic
	PistolSuppressor, TLRLight, Tripod, TacticalGoggles, WeaponCleaningKit
	SmershVest
	Torch
	Thermometer, FirstAidKit, StartKitIV, SalineBag, SalineBagIV, PainkillerTablets, Morphine
	CanisterGasoline, SparkPlug, TireRepairKit

*/

/*
	Coding Examples & Reference
	
	#include "$CurrentDir:\\mpmissions\\dayzOffline.chernarusplus\\Script_Mission.c"

*/
