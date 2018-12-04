
/*

	Black Beret Gaming Script

	* Hive
	* Weather
	* Player Health 
	* Player Connect
	* Player Spawn
	* Csutom Mission

*/

int server_spawn_id = 0;

void main()
{

	Hive ce = CreateHive();
	if ( ce )
		ce.InitOffline();

	Weather weather = g_Game.GetWeather();

	weather.GetOvercast().SetLimits( 0.0 , 1.0 );
	weather.GetRain().SetLimits( 0.0 , 1.0 );
	weather.GetFog().SetLimits( 0.0 , 0.25 );

	weather.GetOvercast().SetForecastChangeLimits( 0.5, 0.8 );
	weather.GetRain().SetForecastChangeLimits( 0.1, 0.3 );
	weather.GetFog().SetForecastChangeLimits( 0.05, 0.10 );

	weather.GetOvercast().SetForecastTimeLimits( 3600 , 3600 );
	weather.GetRain().SetForecastTimeLimits( 300 , 300 );
	weather.GetFog().SetForecastTimeLimits( 3600 , 3600 );

	weather.GetOvercast().Set( Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set( Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
	weather.GetFog().Set( Math.RandomFloatInclusive(0.0, 0.1), 0, 0);
	
	weather.SetWindMaximumSpeed(30);
	weather.SetWindFunctionParams(0.1, 1.0, 50);
}

class CustomMission: MissionServer
{	
/*
		void SetRandomHealth(EntityAI itemEnt)
	{
		int rndHlt = Math.RandomInt(40,100);
		itemEnt.SetHealth("","",rndHlt);
	}
*/
	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, string characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");//Creates random player
		Class.CastTo(m_player, playerEnt);
		
		GetGame().SelectPlayer(identity, m_player);
		
		return m_player;
	}
	
	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		EntityAI itemEnt;
		ItemBase itemBs;
		
		player.RemoveAllItems();
		
		itemEnt = player.GetInventory().CreateInInventory(shoesArray.GetRandomElement());

		if(server_spawn_id == 0)
		{
				itemEnt = player.GetInventory().CreateInInventory("AssaultBag_Black");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Black");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("M4A1");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("M4_OEBttstck");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("M4_PlasticHndgrd");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("CanisterGasoline");
				itemBs = ItemBase.Cast(itemEnt);		

		}
		else
		{
			if(server_spawn_id == 1)
			{
				itemEnt = player.GetInventory().CreateInInventory("TortillaBag");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("GorkaPants_Summer");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("GorkaEJacket_Autumn");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("AKM");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("AK_WoodBttstck");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("AK_WoodHndgrd");
				itemBs = ItemBase.Cast(itemEnt);
		
				itemEnt = player.GetInventory().CreateInInventory("Mag_AKM_30Rnd");
				itemBs = ItemBase.Cast(itemEnt);		
			}
			else
			{
				if(server_spawn_id == 2)
				{
					itemEnt = player.GetInventory().CreateInInventory("TortillaBag");
					itemBs = ItemBase.Cast(itemEnt);
			
					itemEnt = player.GetInventory().CreateInInventory("GorkaPants_Summer");
					itemBs = ItemBase.Cast(itemEnt);
			
					itemEnt = player.GetInventory().CreateInInventory("GorkaEJacket_Summer");
					itemBs = ItemBase.Cast(itemEnt);
			
					itemEnt = player.GetInventory().CreateInInventory("SVD");
					itemBs = ItemBase.Cast(itemEnt);
			
					itemEnt = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
	//				itemBs = ItemBase.Cast(itemEnt);
					itemEnt = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
	//				itemBs = ItemBase.Cast(itemEnt);
					itemEnt = player.GetInventory().CreateInInventory("Mag_SVD_10Rnd");
	//				itemBs = ItemBase.Cast(itemEnt);
				}
				else
				{
					if(server_spawn_id == 3)
					{
						itemEnt = player.GetInventory().CreateInInventory("SmershBag");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("TTSKOPants");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("TTsKOJacket_Camo");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("UMP45");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("BUISOptic");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("M68Optic");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("M4_T3NRDSOptic");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("ReflexOptic");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("ACOGOptic");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("TLRLight");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("PistolSuppressor");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
		//				itemBs = ItemBase.Cast(itemEnt);
						itemEnt = player.GetInventory().CreateInInventory("Mag_UMP_25Rnd");
		//				itemBs = ItemBase.Cast(itemEnt);
					}
					else
					{
						itemEnt = player.GetInventory().CreateInInventory("AssaultBag_Black");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("CargoPants_Black");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("M65Jacket_Khaki");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("CZ61");
						itemBs = ItemBase.Cast(itemEnt);
				
						itemEnt = player.GetInventory().CreateInInventory("AK_Suppressor");
		//				itemBs = ItemBase.Cast(itemEnt);
						itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
		//				itemBs = ItemBase.Cast(itemEnt);
						itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
		//				itemBs = ItemBase.Cast(itemEnt);
						itemEnt = player.GetInventory().CreateInInventory("Mag_CZ61_20Rnd");
		//				itemBs = ItemBase.Cast(itemEnt);
						
						server_spawn_id = -1;
					}
				}
			}
		}
		server_spawn_id++;

		itemEnt = player.GetInventory().CreateInInventory("SparkPlug");
		itemBs = ItemBase.Cast(itemEnt);

		if(Math.RandomFloatInclusive(0.0, 1.0) > 0.5)
		{

		}
		else
		{
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
		}
	}
};
  
Mission CreateCustomMission(string path)
{
	return new CustomMission();
}