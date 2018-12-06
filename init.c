/*

	Chivalry os

	* Hive
	* Weather
	* Player Health 
	* Player Connect (Issue: Boots)
	* Player Spawn (Issue: Testing Phase)
	* Custom Mission
	
	Docementation & Useful Values and Strings
	
			//AKM
			//AK_WoodBttstck
			//AK_WoodHndgrd
			//Mag_AKM_30Rnd

			//SVD
			//Mag_SVD_10Rnd

			//UMP45
			//Mag_UMP_25Rnd

			//MP5K
			//MP5_PlasticHndgrd
			//MP5k_StockBttstck
			//Mag_MP5_30Rnd

			//CZ61
			//AK_Suppressor
			//Mag_CZ61_20Rnd

			//MakarovIJ70
			//Mag_IJ70_8Rnd

			//FNX45
			//Mag_FNX45_15Rnd

			//CZ75
			//Mag_CZ75_15Rnd

			//TacticalShirt_Black
			//M65Jacket_Black

			//HuntingBag
			//HuntingJacket_Autumn
			//HunterPants_Autumn

			//MountainBag_Red
			//CanvasPants_Red
			//TrackSuitJacket_Red
			//FirefightersPants_Black

			//PoliceJacket (PoliceJacketOrel)
			//PolicePants (PolicePantsOrel)

			//PrisonUniformJacket
			//PrisonUniformPants

			//TaloonBag_Blue
			//FirstAidKit
			//CanvasPants_Blue
			//MedicalScrubsPants_Blue
			//ParamedicJacket_Blue
			//MedicalScrubsShirt_Blue

			//TortillaBag
			//SmershBag
			//TTSKOPants
			//GorkaPants_Summer
			//GorkaEJacket_Summer (PautRev, Autumn, Flat)
			//USMCJacket_Desert (Woodland)
			//USMCPants_Woodland
			//BDUPants
			//M65Jacket_Khaki (Tan, Olive, Camo)

			//BUISOptic
			//M68Optic
			//M4_T3NRDSOptic
			//ReflexOptic
			//TLRLight
			//PistolSuppressor
			//ACOGOptic
			
			//CanisterGasoline
			//SparkPlug
*/

int SERVER_SPAWNID = 0;
int SCIRPT_RANDOM = 0;

//char WEAPON_SCOPE[5][16] = { "M4_T3NRDSOptic", "ACOGOptic", "BUISOptic", "M68Optic", "ReflexOptic" };

void main()
{

	Hive SERVER_HIVE = CreateHive();
	if (SERVER_HIVE)
	{
	
		SERVER_HIVE.InitOffline();
	}
	
	Weather SERVER_WEATHER = g_Game.GetWeather();

	SERVER_WEATHER.GetOvercast().SetLimits( 0.0 , 1.0 );
	SERVER_WEATHER.GetRain().SetLimits( 0.0 , 1.0 );
	SERVER_WEATHER.GetFog().SetLimits( 0.0 , 0.25 );

	SERVER_WEATHER.GetOvercast().SetForecastChangeLimits( 0.5, 0.8 );
	SERVER_WEATHER.GetRain().SetForecastChangeLimits( 0.1, 0.3 );
	SERVER_WEATHER.GetFog().SetForecastChangeLimits( 0.05, 0.10 );

	SERVER_WEATHER.GetOvercast().SetForecastTimeLimits( 3600 , 3600 );
	SERVER_WEATHER.GetRain().SetForecastTimeLimits( 300 , 300 );
	SERVER_WEATHER.GetFog().SetForecastTimeLimits( 3600 , 3600 );

	SERVER_WEATHER.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	SERVER_WEATHER.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
	SERVER_WEATHER.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0);
	
	SERVER_WEATHER.SetWindMaximumSpeed(30);
	SERVER_WEATHER.SetWindFunctionParams(0.1, 1.0, 50);
	
	CreateServerTimer();
}

class CustomMission: MissionServer
{	
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity PLAYER_ID;
		PLAYER_ID = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, PLAYER_ID);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI ITEM_SELECTED;
		ItemBase ITEM_LOCATION;
		
		player.RemoveAllItems();

		ITEM_SELECTED = player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());

		if(SERVER_SPAWNID == 0)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("AssaultBag_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("CargoPants_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M65Jacket_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
		
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M4A1");
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M4_OEBttstck");
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M4_PlasticHndgrd");
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M4_T3NRDSOptic");
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
		}
		else if(SERVER_SPAWNID == 1)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TortillaBag");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("GorkaPants_Summer");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("GorkaEJacket_Autumn");
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
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
		}
		else if(SERVER_SPAWNID == 2)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TortillaBag");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("GorkaPants_Summer");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("GorkaEJacket_Summer");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			
			ITEM_SELECTED = player.GetInventory().CreateInInventory("SVD");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			SCIRPT_RANDOM = Math.RandomInt(0,1);
			if(SCIRPT_RANDOM == 1)
			{
				ITEM_SELECTED = player.GetInventory().CreateInInventory("PSO1Optic");
			}
			else
			{
				ITEM_SELECTED = player.GetInventory().CreateInInventory("KashtanOptic");
			}
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
		}
		else if(SERVER_SPAWNID == 3)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("SmershBag");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TTSKOPants");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
				
			ITEM_SELECTED = player.GetInventory().CreateInInventory("UMP45");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
		}
		else if(SERVER_SPAWNID == 4)
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("SmershBag");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TTSKOPants");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
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
			SCIRPT_RANDOM = Math.RandomInt(0,4);
			if(SCIRPT_RANDOM == 0)
			{
				player.GetInventory().CreateInInventory("BUISOptic");
			}
			else if(SCIRPT_RANDOM == 1)
			{
				player.GetInventory().CreateInInventory("M68Optic");
			}
			else if(SCIRPT_RANDOM == 2)
			{
				player.GetInventory().CreateInInventory("M4_T3NRDSOptic");
			}
			else if(SCIRPT_RANDOM == 3)
			{
				player.GetInventory().CreateInInventory("ACOGOptic");
			}
			else
			{
				player.GetInventory().CreateInInventory("ReflexOptic");
			}
			ITEM_SELECTED = player.GetInventory().CreateInInventory("PistolSuppressor");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_MP5_30Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_MP5_15Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_MP5_15Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
		}
		else
		{
			ITEM_SELECTED = player.GetInventory().CreateInInventory("AssaultBag_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("CargoPants_Black");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("M65Jacket_Khaki");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
				
			ITEM_SELECTED = player.GetInventory().CreateInInventory("CZ61");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			SCIRPT_RANDOM = Math.RandomInt(0,4);
			if(SCIRPT_RANDOM == 0)
			{
				player.GetInventory().CreateInInventory("BUISOptic");
			}
			else if(SCIRPT_RANDOM == 1)
			{
				player.GetInventory().CreateInInventory("M68Optic");
			}
			else if(SCIRPT_RANDOM == 2)
			{
				player.GetInventory().CreateInInventory("M4_T3NRDSOptic");
			}
			else if(SCIRPT_RANDOM == 3)
			{
				player.GetInventory().CreateInInventory("ACOGOptic");
			}
			else
			{
				player.GetInventory().CreateInInventory("ReflexOptic");
			}
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);
			ITEM_SELECTED = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
			ITEM_LOCATION = ItemBase.Cast(ITEM_SELECTED);

			SERVER_SPAWNID = -1;
		}
		SERVER_SPAWNID++;
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}
